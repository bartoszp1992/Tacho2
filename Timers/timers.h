#include "main.h"
#include "../RTC/rtc.h"



#ifndef TIMERS_H
#define TIMERS_H
#define ON_TIME 20
#define MULTIPLE_PRESS 3
#define LOCKED 1
#define UNLOCKED 0
#define SETTINGS_TIME 5;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim6;

void timersInit(void);

volatile uint8_t counterForce;
volatile uint8_t counterMultiplePress;
volatile uint8_t flagLocked;
volatile uint8_t counterSettings;
extern volatile uint8_t flagDontSleep;

extern volatile uint8_t layout;
extern volatile uint8_t colorScheme;

extern void interfaceSelectLayout(uint8_t l);
extern void interfaceSelectColorScheme(uint8_t cs);



#endif
