#ifndef ESP8266_MQTT_CLIENT_V1_H
#define ESP8266_MQTT_CLIENT_V1_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/* ===================== Configuration ===================== */
#define MQTT_PORT        1883
#define MQTT_MSG_SIZE    80
#define MQTT_PUBLISH_MS  5

/* ===================== API ===================== */
void MQTT_Init(const char* ssid,
               const char* password,
               const char* mqtt_server);

void MQTT_Update(void);

void MQTT_PublishData(float flowRate,
                      float pressure);

#endif
