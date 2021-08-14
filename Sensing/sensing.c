#include "../Sensing/sensing.h"

//mode and oversampling config for BME280
uint8_t ctrlMeas = 0x25;
uint8_t ctrlHum = 0x1;

//mode and oversampling config for LIS3MDL

// power down
uint8_t ctrlMagnetometerPowerDown = LIS3MDL_MODE_POWERDOWN;
uint8_t ctrlMagnetometerSingle = LIS3MDL_MODE_SINGLE;
uint8_t ctrlMagnetometerContinous = LIS3MDL_MODE_CONTINOUS;

//								BATTERY LEVELS AND FLAGS

uint16_t batteryLevels[] = { 3600, 3750, 3800, 3850, 3950, 4020, 4110 };
uint8_t batteryLowFlag = 0;

uint8_t i2cTimeout = 200;

//								DATA MODIFICATORS
volatile int8_t temperatureCompensation = -7;
volatile int16_t pressureReference = 1026;


int32_t offsetADC = -75;
int32_t offsetMagnetometerX = -2000;
int32_t offsetMagnetometerY = 2000;

float gainVoltagePassive = 1.06;

void float2Text(char *str, float input) {

	int ones = (uint16_t) input;
	float hundreadths = input - ones;
	int hundreadths2 = hundreadths * 100;

	sprintf(str, "%d.%d", ones, hundreadths2);

}

void sensingInit() {

	HAL_ADC_Start_DMA(&hadc1, (uint32_t*) adcReading, 3);

	uint8_t dig_T[6];
	uint8_t dig_P[18];
	uint8_t dig_H_1;
	uint8_t dig_H_2_6[7];

	//								REDING CALIBRATION DATA

	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_DIG_T1, 1, dig_T, 6,
			i2cTimeout);
	dig_T1 = ((uint16_t) dig_T[0] | (uint16_t) dig_T[1] << 8);
	dig_T2 = ((int16_t) dig_T[2] | (int16_t) dig_T[3] << 8);
	dig_T3 = ((int16_t) dig_T[4] | (int16_t) dig_T[4] << 8);

	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_DIG_P1, 1, dig_P, 18,
			i2cTimeout);
	dig_P1 = ((uint16_t) dig_P[0] | (uint16_t) dig_P[1] << 8);
	dig_P2 = ((int16_t) dig_P[2] | (int16_t) dig_P[3] << 8);
	dig_P3 = ((int16_t) dig_P[4] | (int16_t) dig_P[5] << 8);
	dig_P4 = ((int16_t) dig_P[6] | (int16_t) dig_P[7] << 8);
	dig_P5 = ((int16_t) dig_P[8] | (int16_t) dig_P[9] << 8);
	dig_P6 = ((int16_t) dig_P[10] | (int16_t) dig_P[11] << 8);
	dig_P7 = ((int16_t) dig_P[12] | (int16_t) dig_P[13] << 8);
	dig_P8 = ((int16_t) dig_P[14] | (int16_t) dig_P[15] << 8);
	dig_P9 = ((int16_t) dig_P[16] | (int16_t) dig_P[17] << 8);

	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_DIG_H1, 1, &dig_H_1, 1,
			i2cTimeout);
	dig_H1 = ((unsigned char) dig_H_1);

	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_DIG_H2, 1, dig_H_2_6, 7,
			i2cTimeout);
	dig_H2 = ((int16_t) dig_H_2_6[0] | (int16_t) dig_H_2_6[1] << 8);
	dig_H3 = ((unsigned char) dig_H_2_6[2]);

	dig_H4 =
			(((int16_t) dig_H_2_6[3]) << 4 | (((int16_t) dig_H_2_6[4]) & 0x0f));
	dig_H5 = (((int16_t) dig_H_2_6[4]) >> 4 | ((int16_t) dig_H_2_6[5]) << 4);
	dig_H6 = ((unsigned char) dig_H_2_6[6]);

}

void sensingRead(void) {

	//								ADC READINGS

	HAL_ADC_Start_DMA(&hadc1, (uint32_t*) adcReading, 3);

	uint32_t voltageBatteryRaw;
	float voltagePassiveRaw;
	float voltageDropRaw;
	float currentRaw;
	float resistanceRaw;

	voltageBatteryRaw = ((3300 * adcReading[0]) / 4095) * 2;

	if (voltageBatteryRaw < batteryLevels[0])
		batteryState = 8;
	if (voltageBatteryRaw >= batteryLevels[0]
			&& voltageBatteryRaw < batteryLevels[1])
		batteryState = 7;
	if (voltageBatteryRaw >= batteryLevels[1]
			&& voltageBatteryRaw < batteryLevels[2])
		batteryState = 6;
	if (voltageBatteryRaw >= batteryLevels[2]
			&& voltageBatteryRaw < batteryLevels[3])
		batteryState = 5;
	if (voltageBatteryRaw >= batteryLevels[3]
			&& voltageBatteryRaw < batteryLevels[4])
		batteryState = 4;
	if (voltageBatteryRaw >= batteryLevels[4]
			&& voltageBatteryRaw < batteryLevels[5])
		batteryState = 3;
	if (voltageBatteryRaw >= batteryLevels[5]
			&& voltageBatteryRaw < batteryLevels[6])
		batteryState = 2;
	if (voltageBatteryRaw >= batteryLevels[6])
		batteryState = 1;

	memset(voltagePassive, 0, 5);
	if (adcReading[1] > 100) {
		voltagePassiveRaw = ((((3.3 * ((float) adcReading[1] +offsetADC)) / 4095) * 40)) * gainVoltagePassive;
	} else {
		voltagePassiveRaw = 0;
	}

	if (voltagePassiveRaw == 0) {
		sprintf(voltagePassive, "--");
	} else {
		float2Text(voltagePassive, voltagePassiveRaw);
	}

	memset(voltageDrop, 0, 5);
	if (adcReading[2] < 3200) {
		voltageDropRaw = ((3.3 * ((float) adcReading[2] +offsetADC)) / 4095);

//		voltageDropRaw = voltageDropRaw - 0.59; //offset correction

	} else {
		voltageDropRaw = 0;
	}

	if (voltageDropRaw == 0) {
		sprintf(voltageDrop, "--");
	} else {
		float2Text(voltageDrop, voltageDropRaw);
	}

	memset(resistance, 0, 5);
	currentRaw = (3.3 - voltageDropRaw) / 10000;
	resistanceRaw = (voltageDropRaw / currentRaw)/1000;

	if (voltageDropRaw == 0) {
		sprintf(resistance, "--");
	} else {
		float2Text(resistance, resistanceRaw);
	}

//								BME280 READINGS

//I2C read data
	uint8_t temperatureMSB = 0;
	uint8_t temperatureLSB = 0;
	uint8_t temperatureXLSB = 0;

	uint8_t pressureMSB = 0;
	uint8_t pressureLSB = 0;
	uint8_t pressureXLSB = 0;

	uint8_t humidityMSB = 0;
	uint8_t humidityLSB = 0;

	//adc data
	BME280_S32_t temperatureADC = 0;
	BME280_S32_t pressureADC = 0;
	BME280_S32_t humidityADC = 0;

	//configure oversampling for hum
	if (HAL_I2C_Mem_Write(&hi2c1, BME280_ADDR, BME280_CTRL_HUM, 1, &ctrlHum, 1,
			50) != HAL_OK) {
		Error_Handler();
	};

	//configure oversampling for press, temp
	//configure mode as force
	if (HAL_I2C_Mem_Write(&hi2c1, BME280_ADDR, BME280_CTRL_MEAS, 1, &ctrlMeas,
			1, 50) != HAL_OK) {
		Error_Handler();
		;
	}

//wait for end
	HAL_Delay(70);

	//HUMIDITY

	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_HUM_MSB, 1, &humidityMSB, 1,
			i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_HUM_LSB, 1, &humidityLSB, 1,
			i2cTimeout);

	humidityADC = (((int32_t) humidityMSB << 8) | (int32_t) humidityLSB);

	humidityValue = BME280_compensate_H_int32(humidityADC) / 1024;

	//TEMPERATURE

	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_TEMP_MSB, 1, &temperatureMSB,
			1, i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_TEMP_LSB, 1, &temperatureLSB,
			1, i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_TEMP_XLSB, 1, &temperatureXLSB,
			1, i2cTimeout);

	temperatureADC =
			((((int32_t) temperatureMSB << 12) | ((int32_t) temperatureLSB << 4)
					| ((int32_t) temperatureXLSB >> 4)));

	temperatureValue = (BME280_compensate_T_int32(temperatureADC) / 100)
			+ temperatureCompensation;

	//PRESSURE

	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_PRESS_MSB, 1, &pressureMSB, 1,
			i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_PRESS_LSB, 1, &pressureLSB, 1,
			i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, BME280_ADDR, BME280_PRESS_XLSB, 1, &pressureXLSB,
			1, i2cTimeout);

	pressureADC = ((((int32_t) pressureMSB << 12) | ((int32_t) pressureLSB << 4)
			| ((int32_t) pressureXLSB >> 4)));

	pressureValue = BME280_compensate_P_int64(pressureADC) / 256;

	/*
	 * barometrical formula:
	 *
	 * p = p0 exp ( -(uhg/RT )
	 * h= -(RT/gu)*ln(p/p0)
	 *
	 * p- pressure[Pa]
	 * p0- reference pressure[Pa]
	 * u- molar mass of air[kg/mol]
	 * h- altitude[m]
	 * g- Earth acceleration[m/s^2]
	 * R- gas constant[J/(mol*K)]
	 * T- air temperature[K]
	 *
	 */

	altitudeValue = -((8.314 * ((float) temperatureValue + 273.15))
			/ (10 * 0.0289))
			* log((float) pressureValue / ((float) pressureReference * 100));

	pressureValue = pressureValue / 100;

	//								LIS3MDL READINGS

	//magnetometer data
	uint8_t magnetXLSB = 0;
	uint8_t magnetXMSB = 0;

	uint8_t magnetYLSB = 0;
	uint8_t magnetYMSB = 0;

	int16_t magneticFieldXADC;
	int16_t magneticFieldYADC;

	if (HAL_I2C_Mem_Write(&hi2c1, LIS3MDL_ADDR, LIS3MDL_CTRL_REG_3, 1,
			&ctrlMagnetometerContinous, 1, i2cTimeout) != HAL_OK) {
		Error_Handler();
	};

	HAL_Delay(20);

	HAL_I2C_Mem_Read(&hi2c1, LIS3MDL_ADDR, LIS3MDL_OUT_X_L, 1, &magnetXLSB, 1,
			i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, LIS3MDL_ADDR, LIS3MDL_OUT_X_H, 1, &magnetXMSB, 1,
			i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, LIS3MDL_ADDR, LIS3MDL_OUT_Y_L, 1, &magnetYLSB, 1,
			i2cTimeout);
	HAL_I2C_Mem_Read(&hi2c1, LIS3MDL_ADDR, LIS3MDL_OUT_Y_H, 1, &magnetYMSB, 1,
			i2cTimeout);

	magneticFieldXADC = (int16_t) magnetXMSB << 8 | (int16_t) magnetXLSB;
	magneticFieldYADC = (int16_t) magnetYMSB << 8 | (int16_t) magnetYLSB;

	//								LIS3MDL OFFSET CORRECTION

//	//for 4 Gs
	magneticFieldXADC = magneticFieldXADC  + offsetMagnetometerX;
	magneticFieldYADC = magneticFieldYADC + offsetMagnetometerY;

//	magneticFieldXADC = 0;
//	magneticFieldYADC = 0;

	//								LIS3MDL DECREASE VALUE

	uint16_t magneticFieldDivider = 90;

	magneticFieldX = magneticFieldXADC / magneticFieldDivider;
	magneticFieldY = magneticFieldYADC / ((float) magneticFieldDivider * 1.66);

	if (magneticFieldX > 18)
		magneticFieldX = 18;
	if (magneticFieldX < -18)
		magneticFieldX = -18;

	if (magneticFieldY > 12)
		magneticFieldY = 12;
	if (magneticFieldY < -12)
		magneticFieldY = -12;

	//								LIS3MDL SEND SLEEP COMMAND

	HAL_I2C_Mem_Write(&hi2c1, LIS3MDL_ADDR, LIS3MDL_CTRL_REG_3, 1,
			&ctrlMagnetometerPowerDown, 1, i2cTimeout);

}

//compensation formulas from datasheet
// Returns temperature in DegC, resolution is 0.01 DegC. Output value of “5123” equals 51.23 DegC.
// t_fine carries fine temperature as global value

BME280_S32_t BME280_compensate_T_int32(BME280_S32_t adc_T) {
	BME280_S32_t var1, var2, T;
	var1 = ((((adc_T >> 3) - ((BME280_S32_t) dig_T1 << 1)))
			* ((BME280_S32_t) dig_T2)) >> 11;
	var2 = (((((adc_T >> 4) - ((BME280_S32_t) dig_T1))
			* ((adc_T >> 4) - ((BME280_S32_t) dig_T1))) >> 12)
			* ((BME280_S32_t) dig_T3)) >> 14;
	t_fine = var1 + var2;
	T = (t_fine * 5 + 128) >> 8;
	return T;
}
// Returns pressure in Pa as unsigned 32 bit integer in Q24.8 format (24 integer bits and 8 fractional bits).
// Output value of “24674867” represents 24674867/256 = 96386.2 Pa = 963.862 hPa
BME280_U32_t BME280_compensate_P_int64(BME280_S32_t adc_P) {
	BME280_S64_t var1, var2, p;
	var1 = ((BME280_S64_t) t_fine) - 128000;
	var2 = var1 * var1 * (BME280_S64_t) dig_P6;
	var2 = var2 + ((var1 * (BME280_S64_t) dig_P5) << 17);
	var2 = var2 + (((BME280_S64_t) dig_P4) << 35);
	var1 = ((var1 * var1 * (BME280_S64_t) dig_P3) >> 8)
			+ ((var1 * (BME280_S64_t) dig_P2) << 12);
	var1 = (((((BME280_S64_t) 1) << 47) + var1)) * ((BME280_S64_t) dig_P1)
			>> 33;
	if (var1 == 0) {
		return 0; // avoid exception caused by division by zero
	}
	p = 1048576 - adc_P;
	p = (((p << 31) - var2) * 3125) / var1;
	var1 = (((BME280_S64_t) dig_P9) * (p >> 13) * (p >> 13)) >> 25;
	var2 = (((BME280_S64_t) dig_P8) * p) >> 19;
	p = ((p + var1 + var2) >> 8) + (((BME280_S64_t) dig_P7) << 4);
	return (BME280_U32_t) p;
}
// Returns humidity in %RH as unsigned 32 bit integer in Q22.10 format (22 integer and 10 fractional bits).
// Output value of “47445” represents 47445/1024 = 46.333 %RH
BME280_U32_t BME280_compensate_H_int32(BME280_S32_t adc_H) {
	BME280_S32_t v_x1_u32r;
	v_x1_u32r = (t_fine - ((BME280_S32_t) 76800));

	v_x1_u32r =
			(((((adc_H << 14) - (((BME280_S32_t) dig_H4) << 20)
					- (((BME280_S32_t) dig_H5) * v_x1_u32r))
					+ ((BME280_S32_t) 16384)) >> 15)
					* (((((((v_x1_u32r * ((BME280_S32_t) dig_H6)) >> 10)
							* (((v_x1_u32r * ((BME280_S32_t) dig_H3)) >> 11)
									+ ((BME280_S32_t) 32768))) >> 10)
							+ ((BME280_S32_t) 2097152))
							* ((BME280_S32_t) dig_H2) + 8192) >> 14));
	v_x1_u32r = (v_x1_u32r
			- (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7)
					* ((BME280_S32_t) dig_H1)) >> 4));
	v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
	v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
	return (BME280_U32_t) (v_x1_u32r >> 12);
}
