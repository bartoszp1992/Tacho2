#include "buttons.h"

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin) {

	flagClockConfig = 1;

	//reset settings counter
	if (flagSettings == FLAG_SETTINGS_ON) {
		counterSettings = SETTINGS_TIME;
	}

	//set full update flag, when both reset and set pin was pressed

	if (HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) == 0
			&& HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 0
			&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin) == 1
			&& flagLocked == UNLOCKED) {
		flagInterfaceFullUpdate = 1;
		flashWriteFlag = 1;
	}

	//lock watch when underwater
	if (HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) == 0
			&& HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 0
			&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin) == 0) {
		flagLocked = LOCKED;
		flagSettings = FLAG_SETTINGS_OFF;

		if ((mode == MODE_CHRONO || mode == MODE_STOP) && chrono.year == 0
				&& chrono.month == 0 && chrono.day == 0 && chrono.hour == 0
				&& chrono.minute == 0 && chrono.second < 5) {
			mode = MODE_NORMAL;
			rtcResetChrono();

		}

	} else {

		flagDontSleep = 1;

		//										START BUTTON
		if (GPIO_Pin == START_Pin
				&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin)
						== GPIO_PIN_RESET
				&& HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin)
						== GPIO_PIN_SET) {

			if (flagLocked == UNLOCKED) {

				if (flagSettings == FLAG_SETTINGS_OFF) {

					if (mode == MODE_NORMAL) { // start chrono if mode is set as normal

						HAL_RTC_GetTime(&hrtc, &Time, RTC_FORMAT_BIN);
						HAL_RTC_GetDate(&hrtc, &Date, RTC_FORMAT_BIN);

						chronoStart.second = Time.Seconds;
						chronoStart.minute = Time.Minutes;
						chronoStart.decimal = (((255 - Time.SubSeconds) * 100)
								/ 255) / 10;
						chronoStart.hour = Time.Hours;
						chronoStart.day = Date.Date;
						chronoStart.month = Date.Month;
						chronoStart.year = Date.Year;

						mode = MODE_CHRONO;
					}

					else if (mode == MODE_CHRONO) { //stop chrono if chrono is working

						HAL_RTC_GetTime(&hrtc, &Time, RTC_FORMAT_BIN);
						HAL_RTC_GetDate(&hrtc, &Date, RTC_FORMAT_BIN);

						actual.minute = Time.Minutes;
						actual.second = Time.Seconds;
						actual.decimal = (((255 - Time.SubSeconds) * 100) / 255)
								/ 10;
						actual.hour = Time.Hours;
						actual.day = Date.Date;
						actual.month = Date.Month;
						actual.year = Date.Year;

						chrono.decimal = actual.decimal - chronoStart.decimal;
						chrono.second = actual.second - chronoStart.second;
						chrono.minute = actual.minute - chronoStart.minute;
						chrono.hour = actual.hour - chronoStart.hour;
						chrono.day = actual.day - chronoStart.day;
						chrono.month = actual.month - chronoStart.month;
						chrono.year = actual.year - chronoStart.year;

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

						mode = MODE_STOP;

					}

					else if (mode == MODE_STOP) { //start chrono if was stopped

						mode = MODE_CHRONO;

					}

				}

				else if (flagSettings == FLAG_SETTINGS_ON) {
					// if start was pressed in settings, add value
					switch (settingsPointer) {
					case SETTINGS_HOURS:

						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							actual.hour++;
							if (actual.hour > 23)
								actual.hour = 0;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							actual.hour--;
							if (actual.hour < 0)
								actual.hour = 23;

						}

						break;

					case SETTINGS_MINUTES:

						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							actual.minute++;
							if (actual.minute > 59)
								actual.minute = 0;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							actual.minute--;
							if (actual.minute < 0)
								actual.minute = 59;
						}
						break;

					case SETTINGS_SECONDS:
						actual.second = 0;
						Time.SubSeconds = 0;
						break;

					case SETTINGS_DAYS:
						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							actual.day++;
							if (actual.day > 31)
								actual.day = 1;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							actual.day--;
							if (actual.day < 1)
								actual.day = 31;
						}

						break;

					case SETTINGS_MONTHS:
						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							actual.month++;
							if (actual.month > 12)
								actual.month = 1;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							actual.month--;
							if (actual.month < 1)
								actual.month = 12;
						}

						break;

					case SETTINGS_YEARS:
						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							actual.year++;
							if (actual.year > 99)
								actual.year = 1;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							actual.year--;
							if (actual.year < 1)
								actual.year = 99;
						}

						break;

					case SETTINGS_LAYOUT:
						if (layout < layoutsCounter)
							layout++;
						else if (layout >= layoutsCounter)
							layout = 1;
						break;

					case SETTINGS_COLOR:
						if (colorScheme < 2)
							colorScheme++;
						else if (colorScheme >= 2)
							colorScheme = 1;
						break;

					case SETTINGS_PRESS_REF:

						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							pressureReference++;
							if (pressureReference > 1300)
								pressureReference = 700;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							pressureReference--;
							if (pressureReference < 700)
								pressureReference = 1300;
						}
						break;

					case SETTINGS_TEMP_CMP:

						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							temperatureCompensation++;
							if (temperatureCompensation > 20)
								temperatureCompensation = -20;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							temperatureCompensation--;
							if (temperatureCompensation < -20)
								temperatureCompensation = 20;
						}

						break;

					}

					rtcSetTime();

				}
			}
			//										RESET BUTTON

		} else if (GPIO_Pin == RESET_Pin
				&& HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin)
						== GPIO_PIN_RESET
				&& HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == GPIO_PIN_SET
				&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin)
						== GPIO_PIN_SET) {

			counterForce = 0;
			counterMultiplePress++;

			if (flagSettings == FLAG_SETTINGS_OFF) {
				if (counterMultiplePress >= MULTIPLE_PRESS) {
					if (flagLocked == LOCKED) {
						flagLocked = UNLOCKED;
					} else {
						flagLocked = LOCKED;
					}
				}
			}

			if (flagLocked == UNLOCKED) {

				if (mode == MODE_NORMAL && flagSettings == FLAG_SETTINGS_OFF) {
//			interfaceFullUpdateFlag = 1; //legacy
				}

				else if (mode == MODE_STOP && flagSettings == FLAG_SETTINGS_OFF) {

					mode = MODE_NORMAL;
					rtcResetChrono();

				}

				else if (flagSettings == FLAG_SETTINGS_ON) {

					if (settingsPointer < 10) {
						settingsPointer++; // if reset was pressed in settings, forward pointer
					} else if (settingsPointer >= 10) {
						settingsPointer = 1;
					}

				}
			}
			//										SET BUTTON

		} else if (GPIO_Pin == SET_Pin
				&& HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == GPIO_PIN_RESET
				&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin) == GPIO_PIN_SET
				&& HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin)
						== GPIO_PIN_SET) {

			if (flagLocked == UNLOCKED) {

				if (flagSettings == FLAG_SETTINGS_OFF
						&& HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) == 1) { //go to settings only when Reset button is released

					flagSettings = FLAG_SETTINGS_ON;
					counterSettings = SETTINGS_TIME;
					settingsPointer = 7;

				} else if (flagSettings == FLAG_SETTINGS_ON
						&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin) == 1) {

					flagSettings = FLAG_SETTINGS_OFF;
					counterSettings = 0;
					interfaceSelectColorScheme(colorScheme);
					interfaceSelectLayout(layout);
				}

			}
		}
	}
}

