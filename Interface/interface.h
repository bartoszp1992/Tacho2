#include "main.h"
#include "math.h"

#include "../Display/e-Paper/EPD_1in54_V2.h"
#include "../Display/Config/DEV_Config.h"
#include "../Display/GUI/GUI_Paint.h"
#include "../Sensing/sensing.h"
#include "../RTC/rtc.h"
#include "../Timers/timers.h"


#ifndef INTERFACE_H
#define INTERFACE_H

#define INTERFACE_UPDATE_FULL 0
#define INTERFACE_UPDATE_PARTIAL 1

#define COLOR_MAIN WHITE
#define COLOR_SECOND BLACK

//#define LAYOUT_BREITLING 1
//#define LAYOUT_TIMEX 2

#define COLOR_SCHEME_WHITE 1
#define COLOR_SCHEME_BLACK 2



//extern int32_t temperatureValue;
//extern uint32_t pressureValue;
//extern uint32_t humidityValue;
//
////extern uint8_t Data[256];
//
//extern volatile int8_t hours;
//extern volatile int8_t hours12;
//extern volatile int16_t minutes;
//extern volatile int8_t seconds;
//extern volatile int32_t decimals;
//
//
//extern volatile uint8_t day;
//extern volatile uint8_t month;
//extern volatile uint8_t year;
//
//extern volatile int32_t chronoDecimals;
//extern volatile int16_t chronoMinutes;
//extern volatile int8_t chronoSeconds;
//extern volatile int8_t chronoHours;
//
//extern uint32_t voltage;
//extern uint8_t batteryState;

//full update
volatile uint8_t interfaceFullUpdateFlag;
volatile uint8_t interfaceUpdateMode; //stores actual interface update mode


uint8_t layoutsCounter;
volatile uint8_t layout;
volatile uint8_t colorScheme;

volatile uint8_t colorMain;
volatile uint8_t colorSecond;

//low power mode
uint8_t LPMode;

//sensor reading positions

uint8_t temperatureX;
uint8_t temperatureY;

uint8_t humidityX;
uint8_t humidityY;

uint8_t pressureX;
uint8_t pressureY;

uint8_t compassX;
uint8_t compassY;

//digital interface positions
uint8_t digitalX;
uint8_t digitalY;

//meter position
uint8_t meterX;
uint8_t meterY;

//date position
uint8_t dateX;
uint8_t dateY;

//boards positions

uint8_t batteryStateStartX;
uint8_t batteryStateStartY;


uint8_t chronoMinutesStartX;
uint8_t chronoMinutesStartY;

uint8_t secondsStartX;
uint8_t secondsStartY;

uint8_t chronoDecimalsStartX;
uint8_t chronoDecimalsStartY;

uint8_t mainStartX;
uint8_t mainStartY;

uint8_t mainBoardRadius;
uint8_t smallBoardRadius;
//uint8_t sheathRadius;

//pointers lengths
uint8_t hourPointerLength;
uint8_t minutePointerLength;
uint8_t secondPointerLength;

uint8_t chronoDecimalsPointerLength;
uint8_t chronoMinutesPointerLength;
uint8_t chronoSecondsPointerLength;

uint8_t batteryStatePointerLength;
uint8_t pressurePointerLength;

uint8_t sensorsFieldStartX;
uint8_t sensorsFieldStartY;
uint8_t sensorsFieldEndX;
uint8_t sensorsFieldEndY;

//elements displayFlags

uint8_t showThermometer;
uint8_t showBarometer;
uint8_t showHigrometer;
uint8_t showBatteryState;
uint8_t showSeconds;
uint8_t showChrono;
uint8_t showDate;
uint8_t showNavi;
uint8_t showDigitalInterface;
uint8_t showMeter;


//pointers angles(in rad)
float hourAngle;
float minuteAngle;
float secondAngle;

float chronoMinutesAngle;
float chronoSecondsAngle;
float chronoDecimalsAngle;

float batteryStateAngle;
float pressureAngle;

//index lengths
uint8_t secondsIndexLength;
uint8_t chronoMinutesIndexLength;
uint8_t chronoDecimalsIndexLength;
uint8_t mainIndexLength;

uint8_t batteryStateIndexLength;

//pointer shifts
uint8_t batteryPointerShift;
uint8_t pressurePointerShift;

//index angles
float chronoDecimalsIndexAngle[10];
float chronoMinutesIndexAngle[30];
float secondsIndexAngle[12];
float mainIndexAngle[12];

//shadow
uint8_t pointerShadowShift; //pointers shadow shift



//framebuffer
UBYTE *BlackImage;

void interfaceInit(void);

void interfaceUpdate(uint8_t mode);

void interfaceDrawPointers(void);

void interfaceDrawBatteryWarning(void);

void interfaceDrawBoards(void);

void interfaceStart(void);

void interfaceWrite(void);

void interfaceClear(void);

void interfaceSelectLayout(uint8_t l);

void interfaceSelectColorScheme(uint8_t cs);

void interfaceDrawIndex(void);

#endif
