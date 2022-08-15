/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

/*! The buffer size for USART */
#define USART_0_BUFFER_SIZE 16

struct usart_async_descriptor USART_0;

static uint8_t USART_0_buffer[USART_0_BUFFER_SIZE];

struct pwm_descriptor PWM_1;


struct pwm_descriptor PWM_2;

struct pwm_descriptor PWM_3;

struct pwm_instance PWMi_1[] = {
    {.descr = &PWM_1, .ccx = 1},
    {.descr = &PWM_1, .ccx = 0},
    {.descr = &PWM_1, .ccx = 3},
    {.descr = &PWM_1, .ccx = 2}
};

struct pwm_instance PWMi_2[] = {
    {.descr = &PWM_2, .ccx = 0},
    {.descr = &PWM_2, .ccx = 1}
};

struct pwm_instance PWMi_3[] = {
    {.descr = &PWM_3, .ccx = 0},
    {.descr = &PWM_3, .ccx = 1}
};

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_0_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);
	_gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_0_PORT_init()
{

	gpio_set_pin_function(PA10, PINMUX_PA10C_SERCOM0_PAD2);

	gpio_set_pin_function(PA11, PINMUX_PA11C_SERCOM0_PAD3);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_async_init(&USART_0, SERCOM0, USART_0_buffer, USART_0_BUFFER_SIZE, (void *)NULL);
	USART_0_PORT_init();
}

void PWM_1_PORT_init(void)
{

	gpio_set_pin_function(PA04, PINMUX_PA04E_TCC0_WO0);

	gpio_set_pin_function(PA05, PINMUX_PA05E_TCC0_WO1);

	gpio_set_pin_function(PA18, PINMUX_PA18F_TCC0_WO2);

	gpio_set_pin_function(PA19, PINMUX_PA19F_TCC0_WO3);
}

void PWM_1_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TCC0);
	_gclk_enable_channel(TCC0_GCLK_ID, CONF_GCLK_TCC0_SRC);
}

void PWM_1_init(void)
{
	PWM_1_CLOCK_init();
	PWM_1_PORT_init();
	pwm_init(&PWM_1,   TCC0, _tcc_get_pwm());
}

void PWM_2_PORT_init(void)
{

	gpio_set_pin_function(PA06, PINMUX_PA06E_TCC1_WO0);

	gpio_set_pin_function(PA07, PINMUX_PA07E_TCC1_WO1);
}

void PWM_2_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TCC1);
	_gclk_enable_channel(TCC1_GCLK_ID, CONF_GCLK_TCC1_SRC);
}

void PWM_2_init(void)
{
	PWM_2_CLOCK_init();
	PWM_2_PORT_init();
	pwm_init(&PWM_2, TCC1, _tcc_get_pwm());
}

void PWM_3_PORT_init(void)
{

	gpio_set_pin_function(PA16, PINMUX_PA16E_TCC2_WO0);

	gpio_set_pin_function(PA17, PINMUX_PA17E_TCC2_WO1);
}

void PWM_3_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TCC2);
	_gclk_enable_channel(TCC2_GCLK_ID, CONF_GCLK_TCC2_SRC);
}

void PWM_3_init(void)
{
	PWM_3_CLOCK_init();
	PWM_3_PORT_init();
	pwm_init(&PWM_3, TCC2, _tcc_get_pwm());
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA02

	gpio_set_pin_level(PA02,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA02, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA02, GPIO_PIN_FUNCTION_OFF);

	USART_0_init();

	PWM_1_init();

	PWM_2_init();

	PWM_3_init();
}
