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
		interfaceFullUpdateFlag = 1;
	}

	//lock watch when underwater
	if (HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) == 0
			&& HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 0
			&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin) == 0) {
		flagLocked = LOCKED;
		flagSettings = FLAG_SETTINGS_OFF;

		if ((mode == MODE_CHRONO || mode == MODE_STOP) && chronoYear == 0
				&& chronoMonth == 0 && chronoDay == 0 && chronoHours == 0
				&& chronoMinutes == 0 && chronoSeconds < 5) {
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

						HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, WAKE_UP_SHORT,
								RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

						HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
						HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

						chronoStartSeconds = sTime.Seconds;
						chronoStartMinutes = sTime.Minutes;
						chronoStartDecimals = (((255 - sTime.SubSeconds) * 100)
								/ 255) / 10;
						chronoStartHours = sTime.Hours;
						chronoStartDay = sDate.Date;
						chronoStartMonth = sDate.Month;
						chronoStartYear = sDate.Year;

						mode = MODE_CHRONO;
					}

					else if (mode == MODE_CHRONO) { //stop chrono if chrono is working

						HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, WAKE_UP_SHORT,
						RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

						HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
						HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

						minutes = sTime.Minutes;
						seconds = sTime.Seconds;
						decimals = (((255 - sTime.SubSeconds) * 100) / 255)
								/ 10;
						hours = sTime.Hours;
						day = sDate.Date;
						month = sDate.Month;
						year = sDate.Year;

						chronoDecimals = decimals - chronoStartDecimals;
						chronoSeconds = seconds - chronoStartSeconds;
						chronoMinutes = minutes - chronoStartMinutes;
						chronoHours = hours - chronoStartHours;
						chronoDay = day - chronoStartDay;
						chronoMonth = month - chronoStartMonth;
						chronoYear = year - chronoStartYear;

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
							hours++;
							if (hours > 23)
								hours = 0;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							hours--;
							if (hours < 0)
								hours = 23;

						}

						break;

					case SETTINGS_MINUTES:

						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							minutes++;
							if (minutes > 59)
								minutes = 0;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							minutes--;
							if (minutes < 0)
								minutes = 59;
						}
						break;

					case SETTINGS_SECONDS:
						seconds = 0;
						sTime.SubSeconds = 0;
						break;

					case SETTINGS_DAYS:
						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							day++;
							if (day > 31)
								day = 1;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							day--;
							if (day < 1)
								day = 31;
						}

						break;

					case SETTINGS_MONTHS:
						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							month++;
							if (month > 12)
								month = 1;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							month--;
							if (month < 1)
								month = 12;
						}

						break;

					case SETTINGS_YEARS:
						if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 1) {
							year++;
							if (year > 99)
								year = 1;
						} else if (HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin)
								== 0) {
							year--;
							if (year < 1)
								year = 99;
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

					HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, WAKE_UP_LONG,
					RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
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

					HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, WAKE_UP_SHORT,
							RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
//					modeBackup = mode;// legacy, fot keep chrono
					flagSettings = FLAG_SETTINGS_ON;
					counterSettings = SETTINGS_TIME;
					settingsPointer = 7;

				} else if (flagSettings == FLAG_SETTINGS_ON
						&& HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin) == 1) {
					HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, WAKE_UP_LONG,
							RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
//					mode = modeBackup; /legacy, for keep chrono
					flagSettings = FLAG_SETTINGS_OFF;
					counterSettings = 0;
					interfaceSelectColorScheme(colorScheme);
					interfaceSelectLayout(layout);
				}

			}
		}
	}
}

