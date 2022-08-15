#include <atmel_start.h>

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    atmel_start_init();


    pwm_set_parameters(&PWMi_1[0], 249, 249);
    pwm_set_parameters(&PWMi_1[1], 249, 10);
    pwm_set_parameters(&PWMi_1[2], 249, 10);
    pwm_set_parameters(&PWMi_1[3], 249, 10);
    pwm_enable(&PWM_1);


    pwm_set_parameters(&PWMi_2[0], 249, 249);
    pwm_set_parameters(&PWMi_2[1], 249, 249);
    pwm_enable(&PWM_2);

    pwm_set_parameters(&PWMi_3[0], 249, 249);
    pwm_set_parameters(&PWMi_3[1], 249, 10);
    pwm_enable(&PWM_3);

    /* pwm_set_parameters(&PWM_2, 249, 20);*/
    /* pwm_enable(&PWM_2);*/

    /* pwm_set_parameters(&PWM_3, 249, 20);*/
    /* pwm_enable(&PWM_3);*/

    /* Replace with your application code */
    while (1) {
    }
}
