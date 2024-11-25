#include <atmel_start.h>
#include "rtos_start.h"
#include "LXSAMD21DMX.h"

#define DOOR 7
#define PWM_PERIOD 249

bool updated = false;

LXSAMD21DMX SAMD21DMX(SERCOM0, DMX_USART_CONF_SAMPLE);

void SERCOM0_Handler(){
    SAMD21DMX.IrqHandler();
}

struct pwm_instance *LED[] = {
    &(PWMi_1[0]),
    &(PWMi_1[1]),
    &(PWMi_1[2]),
    &(PWMi_1[3]),

    &(PWMi_2[0]),
    &(PWMi_2[1]),

    &(PWMi_3[0]),
    &(PWMi_3[1]),
};


void vTaskWatchdog(void * pvParameters) {
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 1000 / portTICK_PERIOD_MS;

    xLastWakeTime = xTaskGetTickCount();

    for(;;) {
        vTaskDelayUntil( &xLastWakeTime, xFrequency);

        if(!updated){
            pwm_set_parameters(LED[0], PWM_PERIOD, 0);
            pwm_set_parameters(LED[1], PWM_PERIOD, 0);
            pwm_set_parameters(LED[2], PWM_PERIOD, 0);
            pwm_set_parameters(LED[3], PWM_PERIOD, 0);
            pwm_set_parameters(LED[4], PWM_PERIOD, 0);
            pwm_set_parameters(LED[5], PWM_PERIOD, 0);
            pwm_set_parameters(LED[6], PWM_PERIOD, 0);
            pwm_set_parameters(LED[7], PWM_PERIOD, 0);
        }
        updated = false;
    }
}


void dataRecv(int max){
    updated = true;
    #if DOOR == 1
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(1));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(2));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(3));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(4));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(5));
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(6));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(7));
    #elif DOOR == 2
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(8));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(9));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(10));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(11));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(12));
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(13));
    #elif DOOR == 3
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(14));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(15));
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(16));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(17));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(18));
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(19));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(20));
    #elif DOOR == 4 // TODO
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(21));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(22));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(23));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(24));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(25));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(26));
    #elif DOOR == 5
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(27));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(28));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(29));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(30));
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(31));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(32));
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(33));
    #elif DOOR == 6
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(34));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(35));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(36));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(37));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(38));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(39));
    #elif DOOR == 7
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(40));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(41));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(42));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(43));
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(44));
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(45));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(46));
    #elif DOOR == 8
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(47));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(48));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(49));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(50));
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(51));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(52));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(53));
    #elif DOOR == 9
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(54));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(55));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(56));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(57));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(58));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(59));
    #elif DOOR == 10
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(60));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(61));
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(62));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(63));
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(64));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(65));
    #elif DOOR == 11
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(66));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(67));
        pwm_set_parameters(LED[6], PWM_PERIOD, SAMD21DMX.getSlot(68));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(69));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(70));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(71));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(72));
    #elif DOOR == 12
        pwm_set_parameters(LED[7], PWM_PERIOD, SAMD21DMX.getSlot(73));
        pwm_set_parameters(LED[4], PWM_PERIOD, SAMD21DMX.getSlot(74));
        pwm_set_parameters(LED[5], PWM_PERIOD, SAMD21DMX.getSlot(75));
        pwm_set_parameters(LED[2], PWM_PERIOD, SAMD21DMX.getSlot(76));
        pwm_set_parameters(LED[1], PWM_PERIOD, SAMD21DMX.getSlot(77));
        pwm_set_parameters(LED[3], PWM_PERIOD, SAMD21DMX.getSlot(78));
        pwm_set_parameters(LED[0], PWM_PERIOD, SAMD21DMX.getSlot(79));
    #endif
};

int main(void){
    /* Initializes MCU, drivers and middleware */
    atmel_start_init();

    pwm_set_parameters(LED[0], PWM_PERIOD, 0);
    pwm_set_parameters(LED[1], PWM_PERIOD, 0);
    pwm_set_parameters(LED[2], PWM_PERIOD, 0);
    pwm_set_parameters(LED[3], PWM_PERIOD, 0);
    pwm_set_parameters(LED[4], PWM_PERIOD, 0);
    pwm_set_parameters(LED[5], PWM_PERIOD, 0);
    pwm_set_parameters(LED[6], PWM_PERIOD, 0);
    pwm_set_parameters(LED[7], PWM_PERIOD, 0);

    pwm_enable(&PWM_1);
    pwm_enable(&PWM_2);
    pwm_enable(&PWM_3);

    SAMD21DMX.startInput();
    SAMD21DMX.setDataReceivedCallback(dataRecv);

    xTaskCreate(vTaskWatchdog, "WatchDog", 64, NULL, 1, NULL);
    vTaskStartScheduler();
    for(;;);
}
