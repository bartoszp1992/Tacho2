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

RTC_DateTypeDef sDate;
RTC_TimeTypeDef sTime;

volatile uint8_t mode;
volatile uint8_t flagSettings;


volatile int8_t hours;
volatile int8_t hours12;
volatile int16_t minutes;
volatile int8_t seconds;
volatile int32_t decimals;

volatile uint8_t day;
volatile uint8_t month;
volatile uint8_t year;

volatile uint32_t moonPhase;

volatile int8_t chronoStartYear;
volatile int8_t chronoStartMonth;
volatile int8_t chronoStartDay;
volatile int8_t chronoStartHours;
volatile int16_t chronoStartMinutes;
volatile int8_t chronoStartSeconds;
volatile int32_t chronoStartDecimals;

volatile int8_t chronoYear;
volatile int8_t chronoMonth;
volatile int8_t chronoDay;
volatile int8_t chronoHours;
volatile int32_t chronoDecimals;
volatile int16_t chronoMinutes;
volatile int8_t chronoSeconds;




extern volatile uint8_t interfaceFullUpdateFlag;





void rtcGetTime(void);
void rtcSetTime(void);
void rtcResetChrono(void);

void rtcInit();



#endif
