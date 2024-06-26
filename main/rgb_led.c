/*
 * rgb_led.c
 *
 *  Created on: 11 Jun 2024
 *      Author: apple
 */
#include <stdbool.h>
#include <stdint.h>

#include "driver/ledc.h"
#include "driver/timer_types_legacy.h"
#include "hal/ledc_types.h"
#include "rgb_led.h"

//handle for rgb led pwn init 
bool g_pwm_init_handle = false;


//RGB LED config initialisation
ledc_info_t ledc_ch[RGB_LED_CHANNEL_NUM];

/*
*Initialises the RGB LED settings per channel, 
*including gpio for each color, mode and timer configuration
*/
static void rgb_led_pwm_init(void)
{
	int rgb_ch;	
	//Red
	ledc_ch[0].channel = LEDC_CHANNEL_0;
	ledc_ch[0].gpio = RGB_LED_RED_GPIO;
	ledc_ch[0].mode = LEDC_HIGH_SPEED_MODE;
	ledc_ch[0].timer_index = LEDC_TIMER_0;
	
	//Green
	ledc_ch[1].channel = LEDC_CHANNEL_1;
	ledc_ch[1].gpio = RGB_LED_GREEN_GPIO;
	ledc_ch[1].mode = LEDC_HIGH_SPEED_MODE;
	ledc_ch[1].timer_index = LEDC_TIMER_0;
	
	//Red
	ledc_ch[2].channel = LEDC_CHANNEL_2;
	ledc_ch[2].gpio = RGB_LED_BLUE_GPIO;
	ledc_ch[2].mode = LEDC_HIGH_SPEED_MODE;
	ledc_ch[2].timer_index = LEDC_TIMER_0;
	
	//Configure timer 0
	ledc_timer_config_t ledc_timer = {
		.duty_resolution = LEDC_TIMER_8_BIT,
		.freq_hz         = 100,
		.speed_mode      = LEDC_HIGH_SPEED_MODE,
		.timer_num       = LEDC_TIMER_0
		
	};
	
	ledc_timer_config(&ledc_timer);
	
	//configure channels
	for(rgb_ch = 0; rgb_ch < RGB_LED_CHANNEL_NUM; rgb_ch++)
	{
		ledc_channel_config_t ledc_channel = 
		{
			.channel = ledc_ch[rgb_ch].channel,
			.duty = 0,
			.gpio_num = ledc_ch[rgb_ch].gpio,
			.hpoint = 0,
			.intr_type = LEDC_INTR_DISABLE,
			.speed_mode = ledc_ch[rgb_ch].mode,
			.timer_sel = ledc_ch[rgb_ch].timer_index,
		};
		ledc_channel_config(&ledc_channel);
	}
	
	g_pwm_init_handle = true;
}

/*
* Set the RGB color
*/
static void rgb_led_set_color(uint8_t red, uint8_t green, uint8_t blue)
{
	//Valur should be 0-255 for 8bit
	ledc_set_duty(ledc_ch[0].mode, ledc_ch[0].channel, red);
	ledc_update_duty(ledc_ch[0].mode, ledc_ch[0].channel);
	
	ledc_set_duty(ledc_ch[1].mode, ledc_ch[1].channel, green);
	ledc_update_duty(ledc_ch[1].mode, ledc_ch[1].channel);

	ledc_set_duty(ledc_ch[2].mode, ledc_ch[2].channel, blue);
	ledc_update_duty(ledc_ch[2].mode, ledc_ch[2].channel);
}

/**
* Color to indicate wifi application has started
*/
void rgb_led_wifi_app_started(void)
{   
	if(g_pwm_init_handle==false)
	{
		rgb_led_pwm_init();
	}
	
	rgb_led_set_color(255,0, 0);
}

/**
* Color to indicate HTTP Server has started
*/
void rgb_led_http_server_started(void)
{
	if(g_pwm_init_handle==false)
	{
		rgb_led_pwm_init();
	}
	
	rgb_led_set_color(0,255, 0);
}


/*
*  blink color to indicate esp32 is about to connect to wifi
*/
void rgb_led_connecting_to_wifi(void)
{
	//Configure timer 0
	ledc_timer_config_t ledc_timer = {
		.duty_resolution = LEDC_TIMER_8_BIT,
		.freq_hz         = 5,
		.speed_mode      = LEDC_HIGH_SPEED_MODE,
		.timer_num       = LEDC_TIMER_0
		
	};
	ledc_timer_config(&ledc_timer);
		
	rgb_led_set_color(0,0, 200);
	
}



/*
*  color to indicate esp32 is connected to access point
*/
void rgb_led_wifi_connected(void)
{
	if(g_pwm_init_handle==false)
	{
		rgb_led_pwm_init();
	}
	
	rgb_led_set_color(0,0, 255);
}

/*
*  color to indicate esp32 is on OTA
*/
void rgb_led_ota(void)
{
	//Configure timer 0
	ledc_timer_config_t ledc_timer = {
		.duty_resolution = LEDC_TIMER_8_BIT,
		.freq_hz         = 5,
		.speed_mode      = LEDC_HIGH_SPEED_MODE,
		.timer_num       = LEDC_TIMER_0
		
	};
	ledc_timer_config(&ledc_timer);
		
	rgb_led_set_color(0,200, 0);
	
}
































