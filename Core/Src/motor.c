#include "main.h"

#include "motor.h"

TIM_HandleTypeDef htim1;
UART_HandleTypeDef huart4;



uint8_t motor_drive(uint8_t ex_state) {

  uint8_t state;

  state = (GPIOC -> IDR) & 7;
  // TIM1 CH 1  PWM 1 // PE9
  // TIM1 CH 1N PWM 2 // PA7
  // TIM1 CH 2  PWM 3 // PE11
  // TIM1 CH 2N PWM 4 // PB0
  // TIM1 CH 3  PWM 5 // PE13
  // TIM1 CH 3N PWM 6 // PB1

  if (state != ex_state) {

    switch (state) {

    case 5:
      /*
				Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
				NC        -         +          0        0        1
				CH1|CH1N||CH2|CH2N||CH3|CH3N
				OFF|OFF ||OFF| ON ||PWM1/2
			   */

      //CH1 and CH1N comple close
      HAL_TIM_PWM_Stop( & htim1, TIM_CHANNEL_1);
      HAL_TIMEx_PWMN_Stop( & htim1, TIM_CHANNEL_1);

      //CH2 forced to zero CH2N forced to one
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_2);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_2);
      TIM1 -> CCR2 = 0;

      //CH3 and CH3N PWM mode
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_3);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_3);
      TIM1 -> CCR3 = 399;

      break;
    case 3:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        +         NC        -          0        1        0
        CH1|CH1N||CH2|CH2N||CH3|CH3N
        PWM1/2  ||OFF|OFF ||OFF| ON
       */
      //CH1 and CH1N PWM mode
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_1);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_1);
      TIM1 -> CCR1 = 399;

      //CH2 CH2N closed
      HAL_TIM_PWM_Stop( & htim1, TIM_CHANNEL_2);
      HAL_TIMEx_PWMN_Stop( & htim1, TIM_CHANNEL_2);

      //CH3 forced to zero CH3N forced to one
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_3);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_3);
      TIM1 -> CCR3 = 0;

      break;
    case 1:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        +         -         NC         0        1        1
        CH1|CH1N||CH2|CH2N||CH3|CH3N
        PWM1/2  ||OFF| ON ||OFF|OFF
       */
      //CH1 and CH1N PWM mode
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_1);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_1);
      TIM1 -> CCR1 = 399;

      //CH3 CH3N closed
      HAL_TIM_PWM_Stop( & htim1, TIM_CHANNEL_3);
      HAL_TIMEx_PWMN_Stop( & htim1, TIM_CHANNEL_3);

      //CH2 forced to zero CH2N forced to one
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_2);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_2);
      TIM1 -> CCR2 = 0;

      break;
    case 6:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        -         +         NC         0        0        1
        CH1|CH1N||CH2|CH2N||CH3|CH3N
        OFF| ON ||PWM1/2  ||OFF|OFF
       */

      //CH1 forced to zero CH1N forced to one
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_1);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_1);
      TIM1 -> CCR1 = 0;

      //CH2 and CH2N PWM mode
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_2);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_2);
      TIM1 -> CCR2 = 399;

      //CH3 CH3N closed
      HAL_TIM_PWM_Stop( & htim1, TIM_CHANNEL_3);
      HAL_TIMEx_PWMN_Stop( & htim1, TIM_CHANNEL_3);

      break;
    case 4:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        -         NC        +          1        0        1
        CH1|CH1N||CH2|CH2N|CH3|CH3N
        OFF| ON ||OFF|OFF |PWM1/2
       */
      //CH1 forced to zero CH1N forced to one
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_1);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_1);
      TIM1 -> CCR1 = 0;

      //CH3 and CH3N PWM mode
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_3);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_3);
      TIM1 -> CCR3 = 399;

      //CH2 CH2N closed
      HAL_TIM_PWM_Stop( & htim1, TIM_CHANNEL_2);
      HAL_TIMEx_PWMN_Stop( & htim1, TIM_CHANNEL_2);
      break;
    case 2:
      /*
        Phase A | Phase B | Phase C || Hall C | Hall B | Hall A
        NC        +         -          0        1        1
        CH1|CH1N||CH2|CH2N|CH3|CH3N
        OFF|OFF ||PWM1/2  |OFF| ON
       */
      //CH1 CH1N closed
      HAL_TIM_PWM_Stop( & htim1, TIM_CHANNEL_1);
      HAL_TIMEx_PWMN_Stop( & htim1, TIM_CHANNEL_1);
      TIM1 -> CCR1 = 0;

      //CH2 CH2N Pwm mode
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_2);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_2);
      TIM1 -> CCR2 = 399;
      //CH3 forced to zero CH3N forced to one
      HAL_TIM_PWM_Start( & htim1, TIM_CHANNEL_3);
      HAL_TIMEx_PWMN_Start( & htim1, TIM_CHANNEL_3);
      TIM1 -> CCR3 = 0;
      break;
    default:
      break;
    }

  }
  if (state == 0)
    state = ex_state;
  return state;

}


