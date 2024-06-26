/*
 * wifi_app.h
 *
 *  Created on: 12 Jun 2024
 *      Author: apple
 */

#ifndef WIFI_APP_H_
#define WIFI_APP_H_

#include "esp_netif.h"
#include "esp_netif_types.h"
#include "esp_wifi_types.h"
#include "freertos/portmacro.h"

//wifi application settings
#define WIFI_AP_SSID                "ESP32_APP"      //AP name     
#define WIFI_AP_PASSWORD            "password"       //AP Password
#define WIFI_AP_CHANNEL             1                //AP channel 
#define WIFI_AP_SSID_HIDDEN         0                //AP visibility
#define WIFI_AP_MAX_CONNECTIONS     5                //AP Max clients
#define WIFI_AP_BEACON_INTERVAL     100              //Beacon interval 
#define WIFI_AP_IP                  "192.168.0.1"    //AP Default IP
#define WIFI_AP_GATEWAY             "192.168.0.1"    //AP default Gateway
#define WIFI_AP_NETMASK             "255.255.255.0"  //AP netmask
#define WIFI_AP_BANDWIDTH           WIFI_BW_HT20     //AP bandwidth - 40 as an option
#define WIFI_STA_POWER_SAVE         WIFI_PS_NONE     //Not using power save 
#define MAX_SSID_LENGTH             32               //MAX IEEE standard
#define MAX_PASSWORD_LENGTH         64               //MAX IEEE standard
#define MAX_CONNECTION_RETRIES      5                //retry number of disconnect


//network interface objects
extern esp_netif_t* esp_netif_sta;
extern esp_netif_t* esp_netif_ap;

/*
* Message IDs for wifi application task
* @note Expand this based on your application requirements
*/
typedef enum wifi_app_message
{
	WIFI_APP_MSG_START_HTTP_SERVER = 0,
	WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
	WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
	WIFI_APP_MSG_USER_REQUESTED_STA_DISCONNECT,
	WIFI_APP_MSG_LOAD_SAVED_CREDENTIALS,	
	WIFI_APP_MSG_STA_DISCONNECTED,
} wifi_app_message_e;

/*
* Structure for message queue
* @note expand based on your app
*/
typedef struct wifi_app_queue_message
{
	wifi_app_message_e msgID;
} wifi_app_queue_message_t;

/*
* Send message to the queue
* @param msgID message ID from the wifi_app_message_e enum
* @return pdTRUE if item is successfully sent to the queue, else pdFALSE
* @note expand based on your app
*/
BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

/*
* Starts the wifi RTOS task
*/
void wifi_app_start(void);


/**
 * Gets the wifi configuration
 */
wifi_config_t* wifi_app_get_wifi_config(void);






#endif /* WIFI_APP_H_ */
