#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22        // Change to DHT11 on real hardware
#define LED_PIN 2

// ---------------- WiFi ----------------

const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ---------------- MQTT ----------------

const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;

// Change your name if required
const char* tempTopic =
"iitjammu/summer26/samyamalhotra/temperature";

const char* humTopic =
"iitjammu/summer26/samyamalhotra/humidity";

const char* ledTopic =
"iitjammu/summer26/samyamalhotra/led_control";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);
unsigned long lastPublish = 0;

// ----------------------------------------------------

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];}
  Serial.print("Message received: ");
  Serial.println(message);
  if (String(topic) == ledTopic) 
    if (message == "ON") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");}

    else if (message == "OFF") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");}}}

// ----------------------------------------------------

void connectWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");}

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());}

// ----------------------------------------------------

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    String clientID = "ESP32-";
    clientID += String(random(1000,9999));
    if (client.connect(clientID.c_str())) {
      Serial.println("Connected");
      client.subscribe(ledTopic);
      Serial.print("Subscribed to: ");
      Serial.println(ledTopic);}

    else {
      Serial.print("Failed. Retry in 5 sec. Error: ");
      Serial.println(client.state());
      delay(5000);}}}

// ----------------------------------------------------

void publishSensorData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT");
    return;}

  StaticJsonDocument<128> tempDoc;
  tempDoc["value"] = temperature;
  tempDoc["unit"] = "C";
  tempDoc["ts"] = millis();
  char tempBuffer[128];
  
  serializeJson(tempDoc, tempBuffer);
  
  client.publish(tempTopic, tempBuffer);
  StaticJsonDocument<128> humDoc;
  humDoc["value"] = humidity;
  humDoc["unit"] = "%";
  humDoc["ts"] = millis();
  char humBuffer[128];
  
  serializeJson(humDoc, humBuffer);
  
  client.publish(humTopic, humBuffer);
  Serial.println("----------------------");
  Serial.print("Temperature: ");
  Serial.println(tempBuffer);
  Serial.print("Humidity: ");
  Serial.println(humBuffer);
  Serial.println("----------------------");}

// ----------------------------------------------------

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();
  connectWiFi();
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);}

// ----------------------------------------------------

void loop() {
  if (!client.connected()) {
    reconnectMQTT();}
  client.loop();
  if (millis() - lastPublish >= 5000) {
    lastPublish = millis();
    publishSensorData();}}
