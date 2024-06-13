/*
 * rgb_led.h
 *
 *  Created on: 11 Jun 2024
 *      Author: apple
 */

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

//RGB LED GPIOS
#define RGB_LED_RED_GPIO     15
#define RGB_LED_GREEN_GPIO   2
#define RGB_LED_BLUE_GPIO    4

//RGB LED color mix channels
#define RGB_LED_CHANNEL_NUM  3

//RGB LED config
typedef struct 
{
	int channel;
	int gpio;
	int mode;
	int timer_index;	
} ledc_info_t;


/**
* Color to indicate wifi application has started
*/
void rgb_led_wifi_app_started(void);

/**
* Color to indicate HTTP Server has started
*/
void rgb_led_http_server_started(void);

/*
*  color to indicate esp32 is connectd to access point
*/
void rgb_led_wifi_connected(void);


#endif /* MAIN_RGB_LED_H_ */
