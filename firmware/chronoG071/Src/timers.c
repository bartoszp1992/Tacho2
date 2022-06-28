#include "timers.h"

void timersInit(void) {
	HAL_TIM_Base_Start_IT(&htim3);
	counterForce = 0;
	counterMultiplePress = 0;
	flagLocked = UNLOCKED;
	counterSettings = 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM3) {
		if (counterForce < ON_TIME) {
			counterForce++;
		}

		counterMultiplePress = 0;

		if (flagSettings == FLAG_SETTINGS_ON) {
			counterSettings--;
			if (counterSettings <= 0) {
				flagSettings = FLAG_SETTINGS_OFF;
				flagDontSleep = 1;
				interfaceSelectColorScheme(colorScheme);
				interfaceSelectLayout(layout);
			}
		}

	}
}
