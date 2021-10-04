#include "main.h"
#include "motor.h"
TIM_HandleTypeDef htim1;
uint8_t motor_drive(uint8_t ex_state){

	uint8_t state;

	state = (GPIOC->IDR) & 7;
	// TIM1 CH 1  PWM 1 // PE9
	// TIM1 CH 1N PWM 2 // PA7
	// TIM1 CH 2  PWM 3 // PE11
	// TIM1 CH 2N PWM 4 // PB0
	// TIM1 CH 3  PWM 5 // PE13
	// TIM1 CH 3N PWM 6 // PB1
	if(state != ex_state){

		switch(state){

			case 1:
				//PWM 1 VE PWM 6 AÇILCAK GERİSİ KAPALI
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); // PWM1
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1); // PWM2
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2); // PWM3
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2); // PWM4
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3); //PWM5
				HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3); //PWM6
				break;
			case 5:
				//PWM 1 VE PWM 4 AÇILCAK GERİSİ KAPALI
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); // PWM1
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1); // PWM2
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2); // PWM3
				HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2); // PWM4
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3); //PWM5
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3); //PWM6
				break;
			case 4:
				//PWM 4 VE PWM 5 AÇILCAK GERİSİ KAPALI
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1); // PWM1
				HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1); // PWM2
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2); // PWM3
				HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2); // PWM4
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3); //PWM5
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3); //PWM6
				break;
			case 6:
				//PWM 2 VE PWM 5 AÇILCAK GERİSİ KAPALI
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1); // PWM1
				HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1); // PWM2
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2); // PWM3
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2); // PWM4
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3); //PWM5
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3); //PWM6
				break;
			case 2:
				//PWM 2 VE PWM 3 AÇILCAK GERİSİ KAPALI
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1); // PWM1
				HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1); // PWM2
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); // PWM3
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2); // PWM4
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3); //PWM5
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3); //PWM6
				break;
			case 3:
				//PWM 3 VE PWM 6 AÇILCAK GERİSİ KAPALI
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1); // PWM1
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1); // PWM2
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); // PWM3
				HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2); // PWM4
				HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3); //PWM5
				HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3); //PWM6
				break;
			default:
				break;
				}

	}
		return state;

	}
