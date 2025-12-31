#include "ESP8266_MQTT_Client_V1.h"

/* ===================== WiFi & MQTT ===================== */
static WiFiClient espClient;
static PubSubClient client(espClient);

/* ===================== Credentials ===================== */
static const char* WIFI_SSID;
static const char* WIFI_PASS;
static const char* MQTT_SERVER;

/* ===================== Timing ===================== */
static unsigned long lastPublish = 0;

/* ===================== Buffers ===================== */
static char msg[MQTT_MSG_SIZE];

/* ======================================================== */

static void mqttCallback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  for (unsigned int i = 0; i < length; i++)
    Serial.print((char)payload[i]);

  Serial.println();
}

/* ======================================================== */

static void setupWiFi(void)
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

/* ======================================================== */

static void mqttReconnect(void)
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
      client.publish("outTopic", "hello world");
      client.subscribe("inTopic");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retry in 5s");
      delay(5000);
    }
  }
}

/* ======================================================== */

void MQTT_Init(const char* ssid,
               const char* password,
               const char* mqtt_server)
{
  WIFI_SSID   = ssid;
  WIFI_PASS   = password;
  MQTT_SERVER = mqtt_server;

  setupWiFi();
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(mqttCallback);
}

/* ======================================================== */

void MQTT_Update(void)
{
  if (!client.connected())
    mqttReconnect();

  client.loop();
}

/* ======================================================== */

void MQTT_PublishData(float flowRate,
                      float pressure)
{
  unsigned long now = millis();

  if (now - lastPublish >= MQTT_PUBLISH_MS)
  {
    lastPublish = now;

    snprintf(msg,
             MQTT_MSG_SIZE,
             "flowrate:%0.2f pressure:%0.2f time:%lu",
             flowRate,
             pressure,
             now);

    client.publish("EEV20/SNO.1", msg);

    Serial.print("MQTT >> ");
    Serial.println(msg);
  }
}
