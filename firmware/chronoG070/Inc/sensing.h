#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#ifndef SENSING_H
#define SENSING_H

I2C_HandleTypeDef hi2c1;
ADC_HandleTypeDef hadc1;

//									BME280 MAIN ADDRESS, STATUS AND CONTROL REGISTER
#define BME280_ADDR (0x77<<1)
#define BME280_CTRL_MEAS 0xF4
#define BME280_CTRL_HUM 0xF2


//									BME280 DATA REGISTERS
#define BME280_HUM_MSB 0xFD
#define BME280_HUM_LSB 0xFE

#define BME280_TEMP_MSB 0xFA
#define BME280_TEMP_LSB 0xFB
#define BME280_TEMP_XLSB 0xFC

#define BME280_PRESS_MSB 0xF7
#define BME280_PRESS_LSB 0xF8
#define BME280_PRESS_XLSB 0xF9

//									BME280 STATUS REGISTER
#define BME280_STATUS 0xF3

//									BME280 COMPENSATION DATA
#define BME280_DIG_T1 0x88


#define BME280_DIG_P1 0x8E


#define BME280_DIG_H1 0xA1
#define BME280_DIG_H2 0xE1


//									BME280 DATA TYPES
#define BME280_U32_t uint32_t
#define BME280_S32_t int32_t
#define BME280_S64_t int64_t


//									LIS3MDL
#define LIS3MDL_ADDR 0x1C<<1
#define LIS3MDL_CTRL_REG_3 0x22

#define LIS3MDL_OUT_X_L 0x28
#define LIS3MDL_OUT_X_H 0x29

#define LIS3MDL_OUT_Y_L 0x2A
#define LIS3MDL_OUT_Y_H 0x2B


#define LIS3MDL_MODE_POWERDOWN 0x03
#define LIS3MDL_MODE_SINGLE 0x01
#define LIS3MDL_MODE_CONTINOUS 0x00

#define MAGNETIC_FIELD_MEASURES 100




//									BME280 VARIABLES FOR COMPENSATION DATA
uint16_t dig_T1;
int16_t dig_T2;
int16_t dig_T3;

uint16_t dig_P1;
int16_t dig_P2;
int16_t dig_P3;
int16_t dig_P4;
int16_t dig_P5;
int16_t dig_P6;
int16_t dig_P7;
int16_t dig_P8;
int16_t dig_P9;

unsigned char dig_H1;
int16_t dig_H2;
unsigned char dig_H3;
int16_t dig_H4;
int16_t dig_H5;
unsigned char dig_H6;

BME280_S32_t t_fine;


//									BME280 MODE CONFIG
uint8_t ctrlMeas;
uint8_t ctrlHum;

//									LIS3MDL
uint8_t ctrlMagnetometerPowerDown;
uint8_t ctrlMagnetometerSingle;
uint8_t ctrlMagnetometerContinous;




//									DATA OUTPUT
BME280_S32_t temperatureValue;
BME280_U32_t pressureValue;
BME280_U32_t humidityValue;

uint8_t batteryState;

int16_t magneticFieldX;
int16_t magneticFieldY;

int16_t magneticFieldContainerX[MAGNETIC_FIELD_MEASURES];
int16_t magneticFieldContainerY[MAGNETIC_FIELD_MEASURES];
int16_t magneticFieldCounter;

int16_t magneticFieldCenterX;
int16_t magneticFieldCenterY;

int16_t magneticFieldMinX;
int16_t magneticFieldMaxX;
int16_t magneticFieldMinY;
int16_t magneticFieldMaxY;


int16_t azimuth;

//									DATA MODIFICATORS
volatile int8_t temperatureCompensation;
volatile int16_t pressureReference;
volatile int32_t altitudeValue;

//									DATA ADC

volatile uint16_t adcReading[3];


char voltagePassive[5]; //voltometer
char voltageDrop[5]; //ohmometer
char resistance[5];

//private
uint16_t batteryLevels[7];

//global
volatile uint8_t flagBatteryLow;
volatile uint8_t flagBatteryWarningPrinted;

//I2C timeout
//private
uint8_t i2cTimeout;



void sensingRead(void);
void sensingInit(void);
void float2Text(char *str, float input);

int16_t findMax(int16_t *data, uint16_t size);
int16_t findMin(int16_t *data, uint16_t size);


BME280_S32_t BME280_compensate_T_int32(BME280_S32_t adc_T);
BME280_U32_t BME280_compensate_P_int64(BME280_S32_t adc_P);
BME280_U32_t BME280_compensate_H_int32(BME280_S32_t adc_H);

#endif
