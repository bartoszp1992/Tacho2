#include "main.h"
#include "rtc.h"
#include <stdint.h>

void rtcInit(void) {
	HAL_RTC_Init(&hrtc);
	mode = MODE_NORMAL
	;

	HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, WAKE_UP_ULTRA_LONG,
		RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

}


void rtcGetTime() {

	HAL_RTC_GetTime(&hrtc, &Time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &Date, RTC_FORMAT_BIN);

	actual.hour = Time.Hours;



	actual.minute = Time.Minutes;
	actual.second = Time.Seconds;

	actual.decimal = (((255 - Time.SubSeconds) * 100) / 255) / 10; //^ subsecond from RTC is 1/255 of second(becouse of RTC sync predivider)

	actual.day = Date.Date;
	actual.month = Date.Month;
	actual.year = Date.Year;

	//							MOON PHASE COUNT

	float X = (actual.month + 9) / 12;
	uint32_t A = 4716 + (actual.year+2000) + (uint32_t) X;
	float Y = 275 * actual.month / 9;
	float V = 7 * A / 4;
	float B = 1729279.5 + 367 * (actual.year+2000) + (uint32_t) Y - (uint32_t) V + actual.day;
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
		chrono.minute = 0;
		chrono.second = 0;
		chrono.decimal = 0;
		chrono.hour = 0;
		chrono.day = 0;
		chrono.month = 0;
		chrono.year = 0;
	}
	if (mode == MODE_CHRONO) {

		chrono.decimal = 0;
		chrono.second = actual.second - chronoStart.second;
		chrono.minute = actual.minute - chronoStart.minute;
		chrono.hour = actual.hour - chronoStart.hour;
		chrono.day = actual.day - chronoStart.day;
		chrono.month = actual.month - chronoStart.month;

		if (chrono.decimal < 0) {
			chrono.second--;
			chrono.decimal = chrono.decimal + 10;
		}

		if (chrono.second < 0) {
			chrono.minute--;
			chrono.second = chrono.second + 60;
		}

		if (chrono.minute < 0) {
			chrono.hour--;
			chrono.minute = chrono.minute + 60;
		}

		if (chrono.hour < 0) {
			chrono.day--;
			chrono.hour = chrono.hour + 24;
		}

		if (chrono.day < 0) {
			chrono.month--;
			chrono.day = chrono.day + 30;
		}

		if (chrono.month < 0) {
			chrono.year--;
			chrono.month = chrono.month + 12;
		}

		//max chrono count
		if(chrono.hour >= 5){
			mode = MODE_STOP;
		}
	}

}

void rtcSetTime() {

	Time.Hours = actual.hour;
	Time.Minutes = actual.minute;
	Time.Seconds = actual.second;
	Date.Date = actual.day;
	Date.Month = actual.month;
	Date.Year = actual.year;
	HAL_RTC_SetTime(&hrtc, &Time, RTC_FORMAT_BIN);
	HAL_RTC_SetDate(&hrtc, &Date, RTC_FORMAT_BIN);

//	HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0);

}

void rtcResetChrono(void) {

	chrono.decimal = 0;
	chrono.minute = 0;
	chrono.second = 0;
	chrono.hour = 0;

	chronoStart.second = 0;
	chronoStart.minute = 0;
	chronoStart.decimal = 0;
	chronoStart.hour = 0;

}
