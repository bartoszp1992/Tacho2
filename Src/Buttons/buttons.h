#include "main.h"
#include "../RTC/rtc.h"
#include "stm32g0xx_hal.h"
#include "../Settings/settings.h"
#include "../Interface/interface.h"
#include "../Timers/timers.h"

#ifndef BUTTONS_H
#define BUTTONS_H



volatile uint8_t flagDontSleep;//for fast refresh and avoid stack overflow/debouncing
volatile uint8_t modeBackup;

extern volatile uint8_t counterForce;

volatile uint8_t flagClockConfig;




#endif
