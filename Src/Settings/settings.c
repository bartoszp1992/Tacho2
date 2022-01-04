#include "../Settings/settings.h"
#include <stdlib.h>

//uint8_t firstLine = 70;
//uint8_t secondLine = 100;
//uint8_t thirdLine = 130;
//uint8_t fourthLine = 160;
//
//uint8_t firstColumn = 10;
//uint8_t secondColumn = 50;
//uint8_t thirdColumn = 90;
//uint8_t fourthColumn = 130;

uint8_t line[] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75,
		80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150,
		155, 160, 165, 170, 175, 180, 185, 190, 195 };
uint8_t column[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130,
		140, 150, 160, 170, 180, 190 };

void settingsDrawData(void) {

	//										SENSOR READINGS

	if (temperatureValue < 0) {

		Paint_DrawChar(column[COLUMN_TEMP] - 8, line[LINE_TEMP], '-', &Font12,
				colorSecond, colorMain);
		Paint_DrawNum(column[COLUMN_TEMP], line[LINE_TEMP],
				abs(temperatureValue), &Font12, colorSecond, colorMain);

	} else {
		Paint_DrawNum(column[COLUMN_TEMP], line[LINE_TEMP], temperatureValue,
				&Font12, colorSecond, colorMain);
	}

	Paint_DrawNum(column[COLUMN_HUM], line[LINE_HUM], humidityValue, &Font12,
			colorSecond, colorMain);
	Paint_DrawNum(column[COLUMN_PRESS], line[LINE_PRESS], pressureValue,
			&Font12, colorSecond, colorMain);

	if (altitudeValue < 0) {
		Paint_DrawChar(column[COLUMN_ALTITUDE], line[LINE_ALTITUDE], '-',
				&Font12, colorSecond, colorMain);
		Paint_DrawNum(column[COLUMN_ALTITUDE] + 8, line[LINE_ALTITUDE],
				abs(altitudeValue), &Font12, colorSecond, colorMain);
	} else {
		Paint_DrawNum(column[COLUMN_ALTITUDE], line[LINE_ALTITUDE],
				altitudeValue, &Font12, colorSecond, colorMain);
	}

	//										SENSOR READINGS UNITS
	Paint_DrawString_EN(column[COLUMN_TEMP + 2], line[LINE_TEMP], "C", &Font12,
			colorSecond, colorMain);
	Paint_DrawString_EN(column[COLUMN_HUM + 2], line[LINE_HUM], "%", &Font12,
			colorSecond, colorMain);
	Paint_DrawString_EN(column[COLUMN_PRESS + 4], line[LINE_PRESS], "hPa",
			&Font12, colorSecond, colorMain);
	Paint_DrawString_EN(column[COLUMN_ALTITUDE + 5], line[LINE_ALTITUDE],
			"m a.s.l.", &Font12, colorSecond, colorMain);

	//										STRINGS
	Paint_DrawString_EN(column[COLUMN_LAYOUT], line[LINE_LAYOUT], "Layout:",
			&Font12, colorSecond, colorMain);
	Paint_DrawString_EN(column[COLUMN_COLOR], line[LINE_COLOR], "Color:",
			&Font12, colorSecond, colorMain);
	Paint_DrawString_EN(column[COLUMN_TEMP_CMP], line[LINE_TEMP_CMP], "T.cmp:",
			&Font12, colorSecond, colorMain);
	Paint_DrawString_EN(column[COLUMN_PRESS_REF], line[LINE_PRESS_REF],
			"P.ref:", &Font12, colorSecond, colorMain);

	//										CLOCK
	Paint_DrawNum(column[COLUMN_HOUR], line[LINE_CLOCK], hours, &Font16,
			colorSecond, colorMain);
	Paint_DrawNum(column[COLUMN_MIN], line[LINE_CLOCK], minutes, &Font16,
			colorSecond, colorMain);
	Paint_DrawNum(column[COLUMN_SEC], line[LINE_CLOCK], seconds, &Font16,
			colorSecond, colorMain);

	//										DATE
	Paint_DrawNum(column[COLUMN_HOUR], line[LINE_DATE], day, &Font16,
			colorSecond, colorMain);
	Paint_DrawNum(column[COLUMN_MIN], line[LINE_DATE], month, &Font16,
			colorSecond, colorMain);
	Paint_DrawNum(column[COLUMN_SEC], line[LINE_DATE], year, &Font16,
			colorSecond, colorMain);

	//										LAYOUT
	Paint_DrawNum(column[COLUMN_LAYOUT + 6], line[LINE_LAYOUT], layout, &Font12,
			colorSecond, colorMain);

	//										COLOR
	if (colorScheme == COLOR_SCHEME_WHITE)
		Paint_DrawChar(column[COLUMN_COLOR + 5], line[LINE_COLOR], 'W', &Font12,
				colorSecond, colorMain);
	else if (colorScheme == COLOR_SCHEME_BLACK)
		Paint_DrawChar(column[COLUMN_COLOR + 5], line[LINE_COLOR], 'B', &Font12,
				colorSecond, colorMain);

	//										PRESSURE REFERENCE
	Paint_DrawNum(column[COLUMN_PRESS_REF + 5], line[LINE_PRESS_REF],
			pressureReference, &Font12, colorSecond, colorMain);

	//										TEMPERATURE COMPENSATION

	if (temperatureCompensation < 0) {

		Paint_DrawChar(column[COLUMN_TEMP_CMP + 5], line[LINE_TEMP_CMP], '-',
				&Font12, colorSecond, colorMain);
		Paint_DrawNum(column[COLUMN_TEMP_CMP + 5] + 8, line[LINE_TEMP_CMP],
				abs(temperatureCompensation), &Font12, colorSecond, colorMain);
	} else {
		Paint_DrawNum(column[COLUMN_TEMP_CMP + 5], line[LINE_TEMP_CMP],
				temperatureCompensation, &Font12, colorSecond, colorMain);
	}

//	Paint_DrawNum(column[COLUMN_COLOR+7], line[LINE_COLOR], colorScheme, &Font16, colorSecond,
//			colorMain);

}

void settingsDrawSubs(void) {

	Paint_DrawChar(160, 40, '+', &Font20, colorSecond, colorMain);
	Paint_DrawChar(160, 140, '>', &Font20, colorSecond, colorMain);
	Paint_DrawString_EN(132, 92, "libra", &Font16, colorSecond, colorMain);

	Paint_DrawLine(0, 75, 122, 75, colorSecond, DOT_PIXEL_1X1,
			LINE_STYLE_SOLID);
	Paint_DrawLine(0, 118, 122, 118, colorSecond, DOT_PIXEL_1X1,
			LINE_STYLE_SOLID);

	Paint_DrawCircle(200, 100, 80, colorSecond, DOT_PIXEL_2X2, DRAW_FILL_EMPTY);

}

void settingsDrawPointer(void) {
	if (settingsPointer == SETTINGS_HOURS) {

	}

	switch (settingsPointer) {
	case SETTINGS_HOURS:
		Paint_DrawLine(column[COLUMN_HOUR] + 3, line[LINE_CLOCK] + 15,
				column[COLUMN_HOUR] + 20, line[LINE_CLOCK] + 15, colorSecond,
				DOT_PIXEL_2X2, LINE_STYLE_SOLID); // hour
		break;

	case SETTINGS_MINUTES:
		Paint_DrawLine(column[COLUMN_MIN] + 3, line[LINE_CLOCK] + 15,
				column[COLUMN_MIN] + 20, line[LINE_CLOCK] + 15, colorSecond,
				DOT_PIXEL_2X2, LINE_STYLE_SOLID); // minute
		break;

	case SETTINGS_SECONDS:
		Paint_DrawLine(column[COLUMN_SEC] + 3, line[LINE_CLOCK] + 15,
				column[COLUMN_SEC] + 20, line[LINE_CLOCK] + 15, colorSecond,
				DOT_PIXEL_2X2, LINE_STYLE_SOLID); // second
		break;

	case SETTINGS_DAYS:
		Paint_DrawLine(column[COLUMN_HOUR] + 3, line[LINE_DATE] + 15,
				column[COLUMN_HOUR] + 20, line[LINE_DATE] + 15, colorSecond,
				DOT_PIXEL_2X2, LINE_STYLE_SOLID); // day
		break;

	case SETTINGS_MONTHS:
		Paint_DrawLine(column[COLUMN_MIN] + 3, line[LINE_DATE] + 15,
				column[COLUMN_MIN] + 20, line[LINE_DATE] + 15, colorSecond,
				DOT_PIXEL_2X2, LINE_STYLE_SOLID); // month
		break;

	case SETTINGS_YEARS:
		Paint_DrawLine(column[COLUMN_SEC] + 3, line[LINE_DATE] + 15,
				column[COLUMN_SEC] + 20, line[LINE_DATE] + 15, colorSecond,
				DOT_PIXEL_2X2, LINE_STYLE_SOLID); // year
		break;

	case SETTINGS_LAYOUT:
		Paint_DrawLine(column[COLUMN_LAYOUT + 6] + 3, line[LINE_LAYOUT] + 15,
				column[COLUMN_LAYOUT + 6] + 15, line[LINE_LAYOUT] + 15,
				colorSecond, DOT_PIXEL_2X2, LINE_STYLE_SOLID); // year
		break;

	case SETTINGS_COLOR:
		Paint_DrawLine(column[COLUMN_COLOR + 5] + 3, line[LINE_COLOR] + 15,
				column[COLUMN_COLOR + 5] + 15, line[LINE_COLOR] + 15,
				colorSecond, DOT_PIXEL_2X2, LINE_STYLE_SOLID); // year
		break;

	case SETTINGS_PRESS_REF:
		Paint_DrawLine(column[COLUMN_PRESS_REF + 5] + 3,
				line[LINE_PRESS_REF] + 15, column[COLUMN_PRESS_REF + 5] + 30,
				line[LINE_PRESS_REF] + 15, colorSecond, DOT_PIXEL_2X2,
				LINE_STYLE_SOLID); // year
		break;

	case SETTINGS_TEMP_CMP:
		Paint_DrawLine(column[COLUMN_TEMP_CMP + 5] + 3,
				line[LINE_TEMP_CMP] + 15, column[COLUMN_TEMP_CMP + 5] + 15,
				line[LINE_TEMP_CMP] + 15, colorSecond, DOT_PIXEL_2X2,
				LINE_STYLE_SOLID); // year
		break;

	}

}
