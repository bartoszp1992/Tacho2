#include "interface.h"
//#include <math.h>
#include <stdlib.h>

uint8_t layoutsCounter = 5; //how many layouts are programmed

void interfaceSelectLayout(uint8_t l) {

	if (l == 1) { //simple

		showBarometer = 1;
		showBatteryState = 0;
		showChrono = 0;
		showNaviDigital = 0;
		showNaviAnalog = 0;
		showDate = 1;
		showHigrometer = 0;
		showSeconds = 0;
		showThermometer = 0;
		showDigitalInterface = 0;
		showMeter = 0;
		showMoonPhase = 1;
		LPMode = 1;

		//sensor readings positions
		temperatureX = 38;
		temperatureY = 44;

		humidityX = 130;
		humidityY = 75;

		pressureX = 17;
		pressureY = 50;

		//compass and altitude
		compassX = 55;
		compassY = 100;

		//date position
		dateX = 153;
		dateY = 95;

		batteryStateStartX = 135;
		batteryStateStartY = 135;

		pointerShadowShift = 2;

		chronoDecimalsStartX = 100;
		chronoDecimalsStartY = 50;

		chronoMinutesStartX = 100;
		chronoMinutesStartY = 150;

		secondsStartX = 100;
		secondsStartY = 150;

		mainStartX = 100;
		mainStartY = 100;

		compassBoardRadius = 25;

		mainBoardRadius = 97;
		smallBoardRadius = 28;

		//pointers lengths

		hourPointerLength = 55;
		minutePointerLength = 80;
		secondPointerLength = 20;

		chronoDecimalsPointerLength = 20;
		chronoMinutesPointerLength = 20;
		chronoSecondsPointerLength = 80;

		batteryStatePointerLength = 35;
		pressurePointerLength = 100;

		compassPointerLength = 18;

		//index lengths
		secondsIndexLength = 4;
		chronoMinutesIndexLength = 2;
		chronoDecimalsIndexLength = 4;
		mainIndexLength = 10;

		batteryStateIndexLength = 15;

		//pointer shifts
		batteryPointerShift = 20;
		pressurePointerShift = 85;

		//moon Phase
		moonPhaseX = 100;
		moonPhaseY = 50;
		moonPhaseRadius = 15;
	}

	else if (l == 2) { //navi

		showBarometer = 1;
		showBatteryState = 1;
		showChrono = 1;
		showNaviDigital = 0;
		showNaviAnalog = 1;
		showDate = 1;
		showHigrometer = 1;
		showSeconds = 0;
		showThermometer = 1;
		showDigitalInterface = 0;
		showMeter = 0;
		showMoonPhase = 1;
		LPMode = 1;

		//sensor readings positions

		temperatureX = 38;
		temperatureY = 44;

		humidityX = 130;
		humidityY = 75;

		pressureX = 17;
		pressureY = 50;

		//compass and altitude
		compassX = 55;
		compassY = 100;

		//date position
		dateX = 153;
		dateY = 95;

		batteryStateStartX = 135;
		batteryStateStartY = 135;

		pointerShadowShift = 2;

		chronoDecimalsStartX = 100;
		chronoDecimalsStartY = 50;

		chronoMinutesStartX = 100;
		chronoMinutesStartY = 150;

		secondsStartX = 100;
		secondsStartY = 150;

		mainStartX = 100;
		mainStartY = 100;

		compassBoardRadius = 25;

		mainBoardRadius = 97;
		smallBoardRadius = 28;

		//pointers lengths

		hourPointerLength = 55;
		minutePointerLength = 80;
		secondPointerLength = 20;

		chronoDecimalsPointerLength = 20;
		chronoMinutesPointerLength = 20;
		chronoSecondsPointerLength = 80;

		batteryStatePointerLength = 35;
		pressurePointerLength = 100;

		compassPointerLength = 18;

		//index lengths
		secondsIndexLength = 4;
		chronoMinutesIndexLength = 2;
		chronoDecimalsIndexLength = 4;
		mainIndexLength = 10;

		batteryStateIndexLength = 15;

		//pointer shifts
		batteryPointerShift = 20;
		pressurePointerShift = 85;

		//moon Phase
		moonPhaseX = 150;
		moonPhaseY = 50;
		moonPhaseRadius = 10;
	}

	else if (l == 3) { //digital

		showBarometer = 0;
		showBatteryState = 1;
		showChrono = 1;
		showNaviDigital = 0;
		showNaviAnalog = 0;
		showDate = 1;
		showHigrometer = 0;
		showSeconds = 0;
		showThermometer = 0;
		showDigitalInterface = 1;
		showMeter = 0;
		showMoonPhase = 0;
		LPMode = 1;

		digitalX = 60;
		digitalY = 25;

		//sensor readings positions

		temperatureX = 85;
		temperatureY = 30;

		humidityX = 130;
		humidityY = 75;

		pressureX = 17;
		pressureY = 50;

		//compass and altitude
		compassX = 30;
		compassY = 78;

		//date position
		dateX = 153;
		dateY = 95;

		batteryStateStartX = 135;
		batteryStateStartY = 135;

		pointerShadowShift = 2;

		chronoDecimalsStartX = 50;
		chronoDecimalsStartY = 100;

		chronoMinutesStartX = 100;
		chronoMinutesStartY = 150;

		secondsStartX = 100;
		secondsStartY = 150;

		mainStartX = 100;
		mainStartY = 100;

		mainBoardRadius = 97;
		smallBoardRadius = 28;

		//pointers lengths

		hourPointerLength = 55;
		minutePointerLength = 80;
		secondPointerLength = 20;

		chronoDecimalsPointerLength = 20;
		chronoMinutesPointerLength = 20;
		chronoSecondsPointerLength = 80;

		batteryStatePointerLength = 35;
		pressurePointerLength = 100;

		compassPointerLength = 20;

		//index lengths
		secondsIndexLength = 4;
		chronoMinutesIndexLength = 2;
		chronoDecimalsIndexLength = 4;
		mainIndexLength = 10;

		batteryStateIndexLength = 15;

		//pointer shifts
		batteryPointerShift = 20;
		pressurePointerShift = 85;
	}

	else if (l == 4) { //seconds

		showBarometer = 1;
		showBatteryState = 1;
		showChrono = 1;
		showNaviDigital = 0;
		showNaviAnalog = 0;
		showDate = 1;
		showHigrometer = 1;
		showSeconds = 1;
		showThermometer = 1;
		showDigitalInterface = 0;
		showMeter = 0;
		showMoonPhase = 1;
		LPMode = 1;

		temperatureX = 38;
		temperatureY = 44;

		humidityX = 130;
		humidityY = 75;

		pressureX = 17;
		pressureY = 50;

		//date position
		dateX = 153;
		dateY = 95;

		batteryStateStartX = 135;
		batteryStateStartY = 135;

		pointerShadowShift = 2;

		chronoDecimalsStartX = 100;
		chronoDecimalsStartY = 50;

		chronoMinutesStartX = 55;
		chronoMinutesStartY = 100;

		secondsStartX = 100;
		secondsStartY = 150;

		mainStartX = 100;
		mainStartY = 100;

		mainBoardRadius = 97;
		smallBoardRadius = 28;

		//pointers lengths

		hourPointerLength = 55;
		minutePointerLength = 80;
		secondPointerLength = 20;

		chronoDecimalsPointerLength = 20;
		chronoMinutesPointerLength = 20;
		chronoSecondsPointerLength = 80;

		batteryStatePointerLength = 35;
		pressurePointerLength = 100;

		compassPointerLength = 20;

		//index lengths
		secondsIndexLength = 4;
		chronoMinutesIndexLength = 2;
		chronoDecimalsIndexLength = 4;
		mainIndexLength = 10;

		batteryStateIndexLength = 15;

		//pointer shifts
		batteryPointerShift = 20;
		pressurePointerShift = 85;

		//moon Phase
		moonPhaseX = 150;
		moonPhaseY = 50;
		moonPhaseRadius = 10;
	}

	else if (l == 5) { //meter

		showBarometer = 0;
		showBatteryState = 1;
		showChrono = 0;
		showNaviDigital = 0;
		showNaviAnalog = 0;
		showDate = 0;
		showHigrometer = 0;
		showSeconds = 0;
		showThermometer = 0;
		showDigitalInterface = 0;
		showMeter = 1;
		showMoonPhase = 0;
		LPMode = 0;

		meterX = 59;
		meterY = 20;

		//sensor readings positions

		temperatureX = 85;
		temperatureY = 30;

		humidityX = 130;
		humidityY = 75;

		pressureX = 17;
		pressureY = 50;

		//compass and altitude
		compassX = 30;
		compassY = 78;

		//date position
		dateX = 153;
		dateY = 95;

		batteryStateStartX = 135;
		batteryStateStartY = 135;

		pointerShadowShift = 2;

		chronoDecimalsStartX = 50;
		chronoDecimalsStartY = 100;

		chronoMinutesStartX = 100;
		chronoMinutesStartY = 150;

		secondsStartX = 100;
		secondsStartY = 150;

		mainStartX = 100;
		mainStartY = 100;

		mainBoardRadius = 97;
		smallBoardRadius = 28;

		//pointers lengths

		hourPointerLength = 55;
		minutePointerLength = 80;
		secondPointerLength = 20;

		chronoDecimalsPointerLength = 20;
		chronoMinutesPointerLength = 20;
		chronoSecondsPointerLength = 80;

		batteryStatePointerLength = 35;
		pressurePointerLength = 100;

		compassPointerLength = 20;

		//index lengths
		secondsIndexLength = 4;
		chronoMinutesIndexLength = 2;
		chronoDecimalsIndexLength = 4;
		mainIndexLength = 10;

		batteryStateIndexLength = 15;

		//pointer shifts
		batteryPointerShift = 20;
		pressurePointerShift = 85;
	}

}

void interfaceSelectColorScheme(uint8_t cs) {
	if (cs == COLOR_SCHEME_BLACK) {
		colorMain = BLACK;
		colorSecond = WHITE;
	} else if (cs == COLOR_SCHEME_WHITE) {
		colorMain = WHITE;
		colorSecond = BLACK;
	}
}

void interfaceInit() {

	//										COUNT INDEXES ANGLES

	for (uint8_t i = 0; i < 10; i++) {
		chronoDecimalsIndexAngle[i] = 2 * 3.14 / 10 * (i - 2.5);
	}
	for (uint8_t i = 0; i < 30; i++) {
		chronoMinutesIndexAngle[i] = 2 * 3.14 / 30 * (i - 7.5);
	}
	for (uint8_t i = 0; i < 12; i++) {
		secondsIndexAngle[i] = 2 * 3.14 / 12 * (i - 3);
	}
	for (uint8_t i = 0; i < 12; i++) {
		mainIndexAngle[i] = 2 * 3.14 / 12 * (i - 3);
	}
	for (uint8_t i = 0; i < 12; i++) {
		mainIndexAngle[i] = 2 * 3.14 / 12 * (i - 3);
	}

	//										DISPLAY INITIALISATION

	printf("EPD_1in54_V2_test Demo\r\n");
	DEV_Module_Init();

	printf("e-Paper Init and Clear...\r\n");
	EPD_1IN54_V2_Init();
	EPD_1IN54_V2_Clear();
	DEV_Delay_ms(500);

	//Create a new image cache
	/* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
	UWORD Imagesize = (
			(EPD_1IN54_V2_WIDTH % 8 == 0) ?
					(EPD_1IN54_V2_WIDTH / 8) : (EPD_1IN54_V2_WIDTH / 8 + 1))
			* EPD_1IN54_V2_HEIGHT;
	if ((BlackImage = (UBYTE*) malloc(Imagesize)) == NULL) {
		printf("Failed to apply for black memory...\r\n");
		// return -1;
	}
	printf("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, EPD_1IN54_V2_WIDTH, EPD_1IN54_V2_HEIGHT, 0,
			colorMain);

	//										INITIALISING AND TESTING MODES

	//initialise full update
//	EPD_1IN54_V2_Init();
//	Paint_SelectImage(BlackImage);
//
//	//draw splash
//	Paint_Clear(colorMain);
//	Paint_DrawString_EN(10, 80, "ORIANA", &Font20, colorMain, colorSecond);
//	Paint_DrawString_EN(10, 100, "designed by  Bart", &Font12, colorMain,
//			colorSecond);
//	//burn image
//	EPD_1IN54_V2_Display(BlackImage);
//	DEV_Delay_ms(200);
//
//	//initialise partial update
//	EPD_1IN54_V2_Init();
//	EPD_1IN54_V2_DisplayPartBaseImage(BlackImage);
//	Paint_SelectImage(BlackImage);
//	//draw point
//	for (uint8_t i = 90; i <= 110; i = i + 10) {
//		Paint_DrawPoint(i, 150, colorSecond, DOT_PIXEL_3X3, DOT_STYLE_DFT);
//		//burn image
//		EPD_1IN54_V2_DisplayPart(BlackImage);
//		DEV_Delay_ms(50);
//	}

}

void interfaceUpdate(uint8_t mode) {
	if (mode == INTERFACE_UPDATE_FULL) {

		EPD_1IN54_V2_Init();
		Paint_SelectImage(BlackImage);

		interfaceUpdateMode = INTERFACE_UPDATE_FULL;

	} else if (mode == INTERFACE_UPDATE_PARTIAL) {

		EPD_1IN54_V2_Init();
		EPD_1IN54_V2_DisplayPartBaseImage(BlackImage);
		Paint_SelectImage(BlackImage);

		interfaceUpdateMode = INTERFACE_UPDATE_PARTIAL;
	}

}

void interfaceWrite() {

	if (interfaceUpdateMode == INTERFACE_UPDATE_PARTIAL) {

		EPD_1IN54_V2_DisplayPart(BlackImage);

	} else if (interfaceUpdateMode == INTERFACE_UPDATE_FULL) {

		EPD_1IN54_V2_Display(BlackImage);

	}

}

void interfaceClear() {
	Paint_Clear(colorMain);
}

void interfaceDrawLayer(uint8_t layer) {

	if (layer == 1) { //boards
		//										MOON PHASE

		if (showMoonPhase == 1) {

			//		moonPhase = 51;

			Paint_DrawCircle(moonPhaseX, moonPhaseY, moonPhaseRadius,
					colorSecond, DOT_PIXEL_1X1, DRAW_FILL_FULL);

			float moonPhaseShift;

			if (moonPhase < 50) {

				moonPhaseShift = ((float) moonPhase / 25) * moonPhaseRadius;
				Paint_DrawCircle(moonPhaseX - (uint32_t) moonPhaseShift,
						moonPhaseY, moonPhaseRadius, colorMain, DOT_PIXEL_1X1,
						DRAW_FILL_FULL);

			} else if (moonPhase > 50) {
				moonPhase = 100 - moonPhase;

				moonPhaseShift = ((float) moonPhase / 25) * moonPhaseRadius;
				Paint_DrawCircle(moonPhaseX + (uint32_t) moonPhaseShift,
						moonPhaseY, moonPhaseRadius, colorMain, DOT_PIXEL_1X1,
						DRAW_FILL_FULL);

			}

		}

		//										METER

		if (showMeter == 1) {
			Paint_DrawRectangle(meterX, meterY, meterX + 82, meterY + 52,
					colorSecond, DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
		}

		//										DIGITAL INTERFACE FIELD

		if (showDigitalInterface == 1) {
			Paint_DrawRectangle(digitalX, digitalY, digitalX + 80,
					digitalY + 37, colorSecond, DOT_PIXEL_1X1, DRAW_FILL_FULL);

		}

		//										TEMPERATURE FIELD

		if (showThermometer == 1) {
			Paint_DrawRectangle(temperatureX - 7, temperatureY,
					temperatureX + 34, temperatureY + 12, colorSecond,
					DOT_PIXEL_2X2, DRAW_FILL_FULL); // date window
		}

		//										HUMIDITY BAR FIELD

		if (showHigrometer == 1) {
			Paint_DrawRectangle(humidityX, humidityY, humidityX + 5,
					humidityY + 50, colorSecond, DOT_PIXEL_1X1,
					DRAW_FILL_EMPTY);
		}

		//										COMPASS DIGITAL
		if (showNaviDigital == 1) {
			Paint_DrawRectangle(compassX, compassY, compassX + 48,
					compassY + 44, colorSecond, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
			Paint_DrawLine(compassX, compassY + 29, compassX + 48,
					compassY + 29, colorSecond, DOT_PIXEL_1X1,
					LINE_STYLE_SOLID);
		}

		//										COMPASS ANALOG

		if (showNaviAnalog == 1) {
			Paint_DrawCircle(compassX, compassY, compassBoardRadius,
					colorSecond, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
			Paint_DrawCircle(compassX, compassY, 2, colorSecond, DOT_PIXEL_1X1,
					DRAW_FILL_FULL);

		}

		//										MAIN BOARD

		Paint_DrawCircle(100, 100, mainBoardRadius, colorSecond, DOT_PIXEL_1X1,
				DRAW_FILL_EMPTY); //main

		//										CHRONO DECIMALS BOARD

		if (showChrono == 1) {
			Paint_DrawCircle(chronoDecimalsStartX, chronoDecimalsStartY,
					smallBoardRadius + 2, colorSecond, DOT_PIXEL_1X1,
					DRAW_FILL_EMPTY);
			Paint_DrawCircle(chronoDecimalsStartX, chronoDecimalsStartY,
					smallBoardRadius, colorSecond, DOT_PIXEL_1X1,
					DRAW_FILL_FULL); //chrono decimals

			//										CHRONO MINUTES BOARD

			Paint_DrawCircle(chronoMinutesStartX, chronoMinutesStartY,
					smallBoardRadius + 2, colorSecond, DOT_PIXEL_1X1,
					DRAW_FILL_EMPTY);
			Paint_DrawCircle(chronoMinutesStartX, chronoMinutesStartY,
					smallBoardRadius, colorSecond, DOT_PIXEL_1X1,
					DRAW_FILL_FULL); //chrono minutes
		}

		//										SECONDS BOARD

		if (showSeconds == 1) {
			Paint_DrawCircle(secondsStartX, secondsStartY, smallBoardRadius + 2,
					colorSecond, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
			Paint_DrawCircle(secondsStartX, secondsStartY, smallBoardRadius,
					colorSecond, DOT_PIXEL_1X1, DRAW_FILL_FULL); //seconds
		}

		//										DATE WINDOW
		if (showDate == 1) {
			Paint_DrawRectangle(dateX - 3, dateY - 3, dateX + 17, dateY + 14,
					colorSecond, DOT_PIXEL_2X2, DRAW_FILL_EMPTY); // date window
		}

		//										DOTS

		if (showChrono == 1) {
			Paint_DrawCircle(chronoDecimalsStartX, chronoDecimalsStartY, 2,
					colorMain, DOT_PIXEL_1X1, DRAW_FILL_FULL);
			Paint_DrawCircle(chronoMinutesStartX, chronoMinutesStartY, 2,
					colorMain, DOT_PIXEL_1X1, DRAW_FILL_FULL);
			Paint_DrawCircle(secondsStartX, secondsStartY, 2, colorMain,
					DOT_PIXEL_1X1, DRAW_FILL_FULL);
		}

		Paint_DrawString_EN(82, 7, "libra", &Font12, colorSecond, colorMain);
		//^logo
	}

	if (layer == 2) { //indexes
		//										METER INDEX

		if (showMeter == 1) {
			Paint_DrawString_EN(meterX + 65, meterY + 2, "V", &Font16,
					colorSecond, colorMain);
			Paint_DrawString_EN(meterX + 56, meterY + 18, "Vd", &Font16,
					colorSecond, colorMain);
			Paint_DrawString_EN(meterX + 56, meterY + 34, "kR", &Font16,
					colorSecond, colorMain);
		}

		//										DIGITAL INTERFACE INDEX

		if (showDigitalInterface == 1) {
			Paint_DrawString_EN(digitalX + 55, digitalY, "hPa", &Font12,
					colorMain, colorSecond);
			Paint_DrawString_EN(digitalX + 55, digitalY + 12, "%RH", &Font12,
					colorMain, colorSecond);
			Paint_DrawString_EN(digitalX + 42, digitalY + 24, "deg C", &Font12,
					colorMain, colorSecond);
		}

		//										BAROMETER INDEX

		if (showBarometer == 1) {
			Paint_DrawNum(177, 102, 975, &Font8, colorSecond, colorMain);
			Paint_DrawString_EN(177, 111, "hPa", &Font8, colorSecond,
					colorMain);
			Paint_DrawNum(102, 185, 1000, &Font8, colorSecond, colorMain);
			Paint_DrawNum(5, 102, 1025, &Font8, colorSecond, colorMain);
		}

		//										HUMIDITY INDEX

		if (showHigrometer == 1) {
			for (uint8_t i = 0; i <= 50; i = i + 5) {
				Paint_DrawLine(humidityX, humidityY + i, humidityX - 2,
						humidityY + i, colorSecond, DOT_PIXEL_1X1,
						LINE_STYLE_SOLID);
			}

			Paint_DrawString_EN(humidityX + 6, humidityY, "0%RH", &Font8,
					colorSecond, colorMain);
			Paint_DrawString_EN(humidityX + 6, humidityY + 43, "100", &Font8,
					colorSecond, colorMain);
		}



		if (showNaviAnalog) {

			//										ANALOG COMPASS ALTIMETER UNIT
			Paint_DrawChar(compassX -4, compassY + 3, 'm', &Font12,
								colorSecond, colorMain);



			//										ANALOG COMPASS INDEX
			//										BACKGROUD FOR COMPASS INDEX
			Paint_DrawRectangle(compassX-3, compassY-30, compassX-3+8, compassY-30+12,
					colorMain, DOT_PIXEL_1X1, DRAW_FILL_FULL);
			Paint_DrawRectangle(compassX-3, compassY+19, compassX-3+8, compassY+19+12,
								colorMain, DOT_PIXEL_1X1, DRAW_FILL_FULL);
			Paint_DrawRectangle(compassX-28, compassY-5, compassX-28+8, compassY-5+12,
								colorMain, DOT_PIXEL_1X1, DRAW_FILL_FULL);
			Paint_DrawRectangle(compassX+20, compassY-5, compassX+20+8, compassY-5+12,
								colorMain, DOT_PIXEL_1X1, DRAW_FILL_FULL);

			//										INDEX
			Paint_DrawChar(compassX - 3, compassY - 30, 'N', &Font12,
					colorSecond, colorMain);
			Paint_DrawChar(compassX - 3, compassY + 19, 'S', &Font12,
					colorSecond, colorMain);
			Paint_DrawChar(compassX - 28, compassY - 5, 'W', &Font12,
					colorSecond, colorMain);
			Paint_DrawChar(compassX + 20, compassY - 5, 'E', &Font12,
					colorSecond, colorMain);

		}

		//										DIGITAL ALTIMETER UNIT
		if (showNaviDigital == 1) {
			Paint_DrawChar(compassX + 38, compassY + 31, 'm', &Font12,
					colorSecond, colorMain);

			//										DIGITAL COMPASS INDEX

			Paint_DrawChar(compassX + 22, compassY + 1, 'N', &Font8,
					colorSecond, colorMain);
			Paint_DrawChar(compassX + 22, compassY + 20, 'S', &Font8,
					colorSecond, colorMain);
			Paint_DrawChar(compassX + 2, compassY + 11, 'W', &Font8,
					colorSecond, colorMain);
			Paint_DrawChar(compassX + 40, compassY + 11, 'E', &Font8,
					colorSecond, colorMain);

		}

		//										BATTERY STATE INDEX

		if (showBatteryState == 1) {
			Paint_DrawLine(batteryStateStartX + batteryPointerShift,
					batteryStateStartY,
					batteryStateStartX + batteryPointerShift
							+ batteryStateIndexLength, batteryStateStartY,
					colorSecond, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
			Paint_DrawLine(batteryStateStartX,
					batteryStateStartY + batteryPointerShift,
					batteryStateStartX,
					batteryStateStartY + batteryPointerShift
							+ batteryStateIndexLength, colorSecond,
					DOT_PIXEL_2X2, LINE_STYLE_SOLID);
		}

		//										TEMPERATURE UNIT

		if (showThermometer == 1) {
			Paint_DrawCircle(temperatureX + 21, temperatureY + 4, 2, colorMain,
					DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
			Paint_DrawString_EN(temperatureX + 24, temperatureY, "C", &Font12,
					colorMain, colorSecond);
		}

		//										CHRONO DECIMALS INDEX

		if (showChrono == 1) {
			for (uint8_t i = 0; i < 10; i++) {

				Paint_DrawLine(
						cos(chronoDecimalsIndexAngle[i])
								* (smallBoardRadius - chronoDecimalsIndexLength)
								+ chronoDecimalsStartX,
						sin(chronoDecimalsIndexAngle[i])
								* (smallBoardRadius - chronoDecimalsIndexLength)
								+ chronoDecimalsStartY,

						cos(chronoDecimalsIndexAngle[i]) * (smallBoardRadius)
								+ chronoDecimalsStartX,
						sin(chronoDecimalsIndexAngle[i]) * (smallBoardRadius)
								+ chronoDecimalsStartY, colorMain,
						DOT_PIXEL_1X1, LINE_STYLE_SOLID);

			}

			//										CHRONO DECIMALS DIGITS
			Paint_DrawString_EN(chronoDecimalsStartX - 4,
					chronoDecimalsStartY - 24, "0", &Font12, colorMain,
					colorSecond);
			Paint_DrawString_EN(chronoDecimalsStartX + 12,
					chronoDecimalsStartY - 12, "2", &Font12, colorMain,
					colorSecond);
			Paint_DrawString_EN(chronoDecimalsStartX + 6,
					chronoDecimalsStartY + 6, "4", &Font12, colorMain,
					colorSecond);
			Paint_DrawString_EN(chronoDecimalsStartX - 14,
					chronoDecimalsStartY + 6, "6", &Font12, colorMain,
					colorSecond);
			Paint_DrawString_EN(chronoDecimalsStartX - 18,
					chronoDecimalsStartY - 12, "8", &Font12, colorMain,
					colorSecond);

			//										CHRONO MINUTES INDEX
			for (uint8_t i = 0; i < 30; i++) {

				Paint_DrawLine(
						cos(chronoMinutesIndexAngle[i])
								* (smallBoardRadius - chronoMinutesIndexLength)
								+ chronoMinutesStartX,
						sin(chronoMinutesIndexAngle[i])
								* (smallBoardRadius - chronoMinutesIndexLength)
								+ chronoMinutesStartY,

						cos(chronoMinutesIndexAngle[i]) * (smallBoardRadius)
								+ chronoMinutesStartX,
						sin(chronoMinutesIndexAngle[i]) * (smallBoardRadius)
								+ chronoMinutesStartY, colorMain, DOT_PIXEL_1X1,
						LINE_STYLE_SOLID);

				if (i % 5 == 0) {
					Paint_DrawLine(
							cos(chronoMinutesIndexAngle[i])
									* (smallBoardRadius
											- (chronoMinutesIndexLength + 5))
									+ chronoMinutesStartX,
							sin(chronoMinutesIndexAngle[i])
									* (smallBoardRadius
											- (chronoMinutesIndexLength + 5))
									+ chronoMinutesStartY,

							cos(chronoMinutesIndexAngle[i]) * (smallBoardRadius)
									+ chronoMinutesStartX,
							sin(chronoMinutesIndexAngle[i]) * (smallBoardRadius)
									+ chronoMinutesStartY, colorMain,
							DOT_PIXEL_1X1, LINE_STYLE_SOLID);
				}
			}

			//										CHRONO MINUTES DIGITS

			Paint_DrawString_EN(chronoMinutesStartX - 8,
					chronoMinutesStartY - 20, "30", &Font12, colorMain,
					colorSecond);
			Paint_DrawString_EN(chronoMinutesStartX + 2,
					chronoMinutesStartY + 2, "10", &Font12, colorMain,
					colorSecond);
			Paint_DrawString_EN(chronoMinutesStartX - 18,
					chronoMinutesStartY + 2, "20", &Font12, colorMain,
					colorSecond);
		}

		//										SECONDS INDEX

		if (showSeconds == 1) {
			for (uint8_t i = 0; i < 12; i++) {

				Paint_DrawLine(
						cos(secondsIndexAngle[i])
								* (smallBoardRadius - secondsIndexLength)
								+ secondsStartX,
						sin(secondsIndexAngle[i])
								* (smallBoardRadius - secondsIndexLength)
								+ secondsStartY,

						cos(secondsIndexAngle[i]) * (smallBoardRadius)
								+ secondsStartX,
						sin(secondsIndexAngle[i]) * (smallBoardRadius)
								+ secondsStartY, colorMain, DOT_PIXEL_1X1,
						LINE_STYLE_SOLID);

				if (i % 3 == 0) {
					Paint_DrawLine(
							cos(secondsIndexAngle[i])
									* (smallBoardRadius
											- (secondsIndexLength + 5))
									+ secondsStartX,
							sin(secondsIndexAngle[i])
									* (smallBoardRadius
											- (secondsIndexLength + 5))
									+ secondsStartY,

							cos(secondsIndexAngle[i]) * (smallBoardRadius)
									+ secondsStartX,
							sin(secondsIndexAngle[i]) * (smallBoardRadius)
									+ secondsStartY, colorMain, DOT_PIXEL_1X1,
							LINE_STYLE_SOLID);
				}
			}

			//										SECONDS DIGITS

			Paint_DrawString_EN(secondsStartX - 8, secondsStartY - 20, "60",
					&Font12, colorMain, colorSecond);
			Paint_DrawString_EN(secondsStartX + 2, secondsStartY + 2, "20",
					&Font12, colorMain, colorSecond);
			Paint_DrawString_EN(secondsStartX - 18, secondsStartY + 2, "40",
					&Font12, colorMain, colorSecond);

		}

		//										MAIN INDEX

		for (uint8_t i = 1; i < 12; i++) {

			Paint_DrawLine(
					cos(mainIndexAngle[i]) * (mainBoardRadius - mainIndexLength)
							+ mainStartX,
					sin(mainIndexAngle[i]) * (mainBoardRadius - mainIndexLength)
							+ mainStartY,

					cos(mainIndexAngle[i]) * (mainBoardRadius) + mainStartX,
					sin(mainIndexAngle[i]) * (mainBoardRadius) + mainStartY,
					colorSecond, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

		}

	}

	if (layer == 3) {		//pointers

		//										METER

		if (showMeter == 1) {
			Paint_DrawString_EN(meterX + 2, meterY + 2, voltagePassive, &Font16,
					colorSecond, colorMain);

			Paint_DrawString_EN(meterX + 2, meterY + 18, voltageDrop, &Font16,
					colorSecond, colorMain);

			Paint_DrawString_EN(meterX + 2, meterY + 34, resistance, &Font16,
					colorSecond, colorMain);

		}

		//										DIGITAL INTERFACE

		if (showDigitalInterface == 1) {
			Paint_DrawNum(digitalX, digitalY, pressureValue, &Font12, colorMain,
					colorSecond);
			Paint_DrawNum(digitalX, digitalY + 12, humidityValue, &Font12,
					colorMain, colorSecond);

			if (temperatureValue < 0) {

				Paint_DrawChar(digitalX, digitalY + 24, '-', &Font12, colorMain,
						colorSecond);
				Paint_DrawNum(digitalX + 8, digitalY + 24,
						abs(temperatureValue), &Font12, colorMain, colorSecond);
			} else {
				Paint_DrawNum(digitalX, digitalY + 24, temperatureValue,
						&Font12, colorMain, colorSecond);
			}

		}

		//										TEMPERATURE READING

		if (showThermometer == 1) {
			if (temperatureValue < 0) {

				Paint_DrawChar(temperatureX - 8, temperatureY, '-', &Font12,
						colorMain, colorSecond);
				Paint_DrawNum(temperatureX, temperatureY, abs(temperatureValue),
						&Font12, colorMain, colorSecond);
			} else {
				Paint_DrawNum(temperatureX, temperatureY, temperatureValue,
						&Font12, colorMain, colorSecond);
			}
		}

		//										HUMIDITY READING

		if (showHigrometer == 1) {
			Paint_DrawRectangle(humidityX, humidityY, humidityX + 5,
					humidityY + (humidityValue / 2), colorSecond, DOT_PIXEL_1X1,
					DRAW_FILL_FULL);
		}

		//										ANALOG COMPASS

		if (showNaviAnalog == 1) {

			if (altitudeValue < 0) {
				Paint_DrawChar(compassX - 12, compassY - 14, '-', &Font12,
						colorSecond, colorMain);
				Paint_DrawNum(compassX - 12 + 8, compassY - 14,
						abs(altitudeValue), &Font12, colorSecond, colorMain);
			} else {
				Paint_DrawNum(compassX - 12, compassY - 14, altitudeValue,
						&Font12, colorSecond, colorMain);
			}

			compassAngle = atan2(magneticFieldY, magneticFieldX);

			Paint_DrawPointer(compassX, compassY, compassAngle,
					compassPointerLength, 0, colorSecond, DOT_PIXEL_2X2,
					LINE_STYLE_SOLID);
			Paint_DrawPointer(compassX, compassY, compassAngle + 3.14,
					compassPointerLength, 0, colorSecond, DOT_PIXEL_1X1,
					LINE_STYLE_SOLID);

		}

		//										DIGITAL COMPASS - ALT

		if (showNaviDigital == 1) {
			if (altitudeValue < 0) {
				Paint_DrawChar(compassX, compassY + 31, '-', &Font12,
						colorSecond, colorMain);
				Paint_DrawNum(compassX + 8, compassY + 31, abs(altitudeValue),
						&Font12, colorSecond, colorMain);
			} else {
				Paint_DrawNum(compassX, compassY + 31, altitudeValue, &Font12,
						colorSecond, colorMain);
			}

			//										DIGITAL COMPASS - COMPASS

			uint16_t compassCenterX = compassX + 24;
			uint16_t compassCenterY = compassY + 14;

			Paint_DrawPoint(compassCenterX + magneticFieldX,
					compassCenterY + magneticFieldY, colorSecond, DOT_PIXEL_3X3,
					DOT_STYLE_DFT);

			Paint_DrawLine(compassX, compassCenterY + magneticFieldY,
					compassX + 48, compassCenterY + magneticFieldY, colorSecond,
					DOT_PIXEL_1X1, LINE_STYLE_SOLID);

			Paint_DrawLine(compassCenterX + magneticFieldX, compassY,
					compassCenterX + magneticFieldX, compassY + 29, colorSecond,
					DOT_PIXEL_1X1, LINE_STYLE_SOLID);

		}

		//										PRESSURE POINTER

		if (showBarometer == 1) {

			pressureAngle = 2 * 3.14 / 100
					* ((int32_t) pressureValue - 950 - 25);

			Paint_DrawPointer(mainStartX, mainStartY, pressureAngle,
					pressurePointerLength, pressurePointerShift, colorSecond,
					DOT_PIXEL_2X2, LINE_STYLE_SOLID);

			Paint_DrawCircle(
					(cos(pressureAngle) * pressurePointerShift) + mainStartX,
					(sin(pressureAngle) * pressurePointerShift) + mainStartY, 4,
					colorSecond, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
			//^ pointer
		}

		//										BATTERY STATE POINTER

		batteryStateAngle = 2 * 3.14 / 28 * (batteryState);

		if (showBatteryState) {
			for (uint8_t i = batteryState; i <= 7; i++) {
				batteryStateAngle = 2 * 3.14 / 28 * (i);

				Paint_DrawPointer(batteryStateStartX, batteryStateStartY,
						batteryStateAngle, batteryStatePointerLength,
						batteryPointerShift, colorSecond, DOT_PIXEL_1X1,
						LINE_STYLE_SOLID);

			}

		}

		//										HOUR POINTER

		hourAngle = 2 * 3.14 / 60 * ((actual.hour * 5 + (actual.minute / 10)) - 15);

		Paint_DrawPointer(mainStartX + pointerShadowShift,
				mainStartY + pointerShadowShift, hourAngle, hourPointerLength,
				15, colorMain, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
		//^shadow

		Paint_DrawPointer(mainStartX, mainStartY, hourAngle, hourPointerLength,
				15, colorSecond, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
		//^ pointer

		//										MINUTE POINTER

		minuteAngle = 2 * 3.14 / 60 * (actual.minute - 15);

		Paint_DrawPointer(mainStartX + pointerShadowShift,
				mainStartY + pointerShadowShift, minuteAngle,
				minutePointerLength, 15, colorMain, DOT_PIXEL_2X2,
				LINE_STYLE_SOLID);
		//^shadow

		Paint_DrawPointer(mainStartX, mainStartY, minuteAngle,
				minutePointerLength, 15, colorSecond, DOT_PIXEL_2X2,
				LINE_STYLE_SOLID);
		//^ pointer

		//										CHRONO MINUTE POINTER

		if (showChrono == 1) {

			chronoMinutesAngle = 2 * 3.14 / 30 * (chrono.minute - 7.5);

			Paint_DrawPointer(chronoMinutesStartX, chronoMinutesStartY,
					chronoMinutesAngle, chronoMinutesPointerLength, 0,
					colorMain, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

			//										CHRONO HALF HOURS DOTS

			for (uint8_t halfHours = (chrono.hour * 2) + (chrono.minute / 30);
					halfHours > 0; halfHours--) {
				Paint_DrawPoint(
						chronoMinutesStartX - chronoMinutesPointerLength
								+ (halfHours * 4), chronoMinutesStartY - 5,
						colorMain, DOT_PIXEL_2X2, DOT_STYLE_DFT);
			};

		}

		//										SECONDS POINTER

		secondAngle = 2 * 3.14 / 60 * (actual.second - 15);

		if (showSeconds == 1) {
			Paint_DrawPointer(secondsStartX, secondsStartY, secondAngle,
					secondPointerLength, 0, colorMain, DOT_PIXEL_1X1,
					LINE_STYLE_SOLID);
			//^pointer
		}

		//										CHRONO SECOND POINTER

		if (showChrono == 1) {

			chronoSecondsAngle = 2 * 3.14 / 60 * (chrono.second - 15);

			Paint_DrawPointer(mainStartX, mainStartY, chronoSecondsAngle,
					chronoSecondsPointerLength, 15, colorSecond, DOT_PIXEL_1X1,
					LINE_STYLE_SOLID);
			//^ pointer

			Paint_DrawPointer(mainStartX + pointerShadowShift,
					mainStartY + pointerShadowShift, chronoSecondsAngle,
					chronoSecondsPointerLength, 15, colorMain, DOT_PIXEL_1X1,
					LINE_STYLE_SOLID);
			//^shadow
		}

		//										CHRONO DECIMAL POINTER

		if (showChrono == 1) {

			chronoDecimalsAngle = 2 * 3.14 / 10 * (chrono.decimal - 2.5);

			Paint_DrawPointer(chronoDecimalsStartX, chronoDecimalsStartY,
					chronoDecimalsAngle, chronoDecimalsPointerLength, 0,
					colorMain, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
		}

		//										DATE

		if (showDate == 1) {
			Paint_DrawNum(dateX, dateY, actual.day, &Font12, colorSecond, colorMain); //date
		}

		//										LOCK INDICATOR
		if (flagLocked == LOCKED) {
//			Paint_DrawCircle(mainStartX, mainStartY, 5, colorSecond,
//					DOT_PIXEL_2X2, DRAW_FILL_FULL);
//			Paint_DrawCircle(mainStartX, mainStartY, 14, colorSecond,
//								DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
		} else {
			Paint_DrawCircle(mainStartX, mainStartY, 14, colorSecond,
					DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
		}

	}

}

void interfaceDrawBatteryWarning() {
	interfaceClear();
	Paint_DrawString_EN(105, 90, "CHARGE", &Font16, colorSecond, colorMain);
	interfaceWrite();	//burn framebuffer
}

