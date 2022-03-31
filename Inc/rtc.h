#include "main.h"
#include <stdint.h>

#ifndef RTC_H
#define RTC_H

#define MODE_NORMAL 0
#define MODE_CHRONO 1
#define MODE_STOP 2

#define FLAG_SETTINGS_ON 1
#define FLAG_SETTINGS_OFF 0


#define WAKE_UP_ULTRA_LONG 60

extern RTC_HandleTypeDef hrtc;

RTC_DateTypeDef Date;
RTC_TimeTypeDef Time;

struct ChronographTypeDef{
	int8_t year;
	int8_t month;
	int8_t day;
	int8_t hour;
	int8_t minute;
	int8_t second;
	int8_t decimal;
} actual, chronoStart, chrono;



volatile uint8_t mode;
volatile uint8_t flagSettings;


volatile uint32_t moonPhase;


extern volatile uint8_t flagInterfaceFullUpdate;


uint8_t flashWriteFlag;



void rtcGetTime();
void rtcSetTime(void);
void rtcResetChrono(void);

void rtcInit();



#endif
