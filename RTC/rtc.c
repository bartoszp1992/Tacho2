#include "main.h"
#include "../RTC/rtc.h"
#include <stdint.h>

void rtcInit(void) {
	HAL_RTC_Init(&hrtc);
	mode = MODE_NORMAL
	;

}


void rtcGetTime() {

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	hours = sTime.Hours;

	if (hours >= 12) {
		hours12 = hours - 12;
	} else {
		hours12 = hours;
	}

	minutes = sTime.Minutes;
	seconds = sTime.Seconds;

	decimals = (((255 - sTime.SubSeconds) * 100) / 255) / 10; //^ subsecond from RTC is 1/255 of second(becouse of RTC sync predivider)

	day = sDate.Date;
	month = sDate.Month;
	year = sDate.Year;

	//							MOON PHASE COUNT

	float X = (month + 9) / 12;
	uint32_t A = 4716 + (year+2000) + (uint32_t) X;
	float Y = 275 * month / 9;
	float V = 7 * A / 4;
	float B = 1729279.5 + 367 * (year+2000) + (uint32_t) Y - (uint32_t) V + day;
	float Q = (A + 83) / 100;
	uint32_t C = (uint32_t) Q;
	float W = 3 * (C + 1) / 4;
	uint32_t E = (uint32_t) W;
	float JD = B + 38 - E; //julian day
	float MS = 29.5305902778; //average value of synodic month
	float phasePrimary = ((JD / MS) - 0.3033);
	uint32_t phaseInteger = (uint32_t) phasePrimary;
	float phaseFinal = (phasePrimary - (float) phaseInteger) * 100;
	moonPhase = (uint32_t) phaseFinal;

	// 0 - new moon, 25- I, 50- II(full moon), 75- III

	if (mode == MODE_NORMAL) {
		chronoMinutes = 0;
		chronoSeconds = 0;
		chronoDecimals = 0;
		chronoHours = 0;
		chronoDay = 0;
		chronoMonth = 0;
		chronoYear = 0;
	}
	if (mode == MODE_CHRONO) {

		chronoDecimals = 0;
		chronoSeconds = seconds - chronoStartSeconds;
		chronoMinutes = minutes - chronoStartMinutes;
		chronoHours = hours - chronoStartHours;
		chronoDay = day - chronoStartDay;
		chronoMonth = month - chronoStartMonth;

		if (chronoDecimals < 0) {
			chronoSeconds--;
			chronoDecimals = chronoDecimals + 10;
		}

		if (chronoSeconds < 0) {
			chronoMinutes--;
			chronoSeconds = chronoSeconds + 60;
		}

		if (chronoMinutes < 0) {
			chronoHours--;
			chronoMinutes = chronoMinutes + 60;
		}

		if (chronoHours < 0) {
			chronoDay--;
			chronoHours = chronoHours + 24;
		}

		if (chronoDay < 0) {
			chronoMonth--;
			chronoDay = chronoDay + 30;
		}

		if (chronoMonth < 0) {
			chronoYear--;
			chronoMonth = chronoMonth + 12;
		}

		//max chrono count
		if(chronoHours >= 5){
			mode = MODE_STOP;
		}
	}

}

void rtcSetTime() {

	sTime.Hours = hours;
	sTime.Minutes = minutes;
	sTime.Seconds = seconds;
	sDate.Date = day;
	sDate.Month = month;
	sDate.Year = year;
	HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

//	HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0);

}

void rtcResetChrono(void) {

	chronoDecimals = 0;
	chronoMinutes = 0;
	chronoSeconds = 0;
	chronoHours = 0;

	chronoStartSeconds = 0;
	chronoStartMinutes = 0;
	chronoStartDecimals = 0;
	chronoStartHours = 0;

}
