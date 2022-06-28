#include "Display_EPD/EPD_1in54_V2.h"
#include "Display_Config/DEV_Config.h"
#include "Display_GUI/GUI_Paint.h"
#include "interface.h"
#include "sensing.h"
#include "rtc.h"

#ifndef SETTINGS_H
#define SETTINGS_H

#define SETTINGS_HOURS 1
#define SETTINGS_MINUTES 2
#define SETTINGS_SECONDS 3
#define SETTINGS_DAYS 4
#define SETTINGS_MONTHS 5
#define SETTINGS_YEARS 6
#define SETTINGS_LAYOUT 7
#define SETTINGS_COLOR 8
#define SETTINGS_PRESS_REF 9
#define SETTINGS_TEMP_CMP 10

#define LINE_TEMP 2
#define LINE_HUM 5
#define LINE_PRESS 8
#define LINE_ALTITUDE 11
#define LINE_CLOCK 16
#define LINE_DATE 20
#define LINE_LAYOUT 24
#define LINE_COLOR 28
#define LINE_PRESS_REF 32
#define LINE_TEMP_CMP 36


#define COLUMN_TEMP 6
#define COLUMN_HUM 4
#define COLUMN_PRESS 3
#define COLUMN_ALTITUDE 2
#define COLUMN_HOUR 0
#define COLUMN_MIN 3
#define COLUMN_SEC 6
#define COLUMN_LAYOUT 1
#define COLUMN_COLOR 2
#define COLUMN_PRESS_REF 4
#define COLUMN_TEMP_CMP 7




volatile uint8_t settingsPointer; //variable for store actually choosed element to set




void settingsDrawPointer(void);
void settingsDrawData(void);
void settingsDrawSubs(void);

#endif
