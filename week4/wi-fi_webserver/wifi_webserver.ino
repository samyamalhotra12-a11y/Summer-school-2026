#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22      // Use DHT11 on real hardware

#define LEDPIN 2

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);
DHT dht(DHTPIN, DHTTYPE);
bool ledState = false;

void handleRoot() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  String html = "<!DOCTYPE html><html>";
  html += "<head>";
  html += "<meta http-equiv='refresh' content='10'>";
  html += "<title>ESP32 Weather Station</title>";
  html += "</head><body>";
  html += "<h1>Wi-Fi Temperature Monitor</h1>";
  html += "<h2>Temperature: ";
  html += String(temperature);
  html += " &deg;C</h2>"
  html += "<h2>Humidity: ";
  html += String(humidity);
  html += " %</h2>";
  html += "<h2>Uptime: ";
  html += String(millis()/1000);
  html += " seconds</h2>";
  html += "<p><a href='/toggle'><button style='font-size:20px;'>Toggle LED</button></a></p>";
  html += "</body></html>";
  server.send(200, "text/html", html);}

void toggleLED() {
  ledState = !ledState;
  digitalWrite(LEDPIN, ledState);
  server.sendHeader("Location","/");
  server.send(303);}

void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");}

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/toggle", toggleLED);
  server.begin();
  Serial.println("HTTP Server Started");}

void loop() {
  server.handleClient();}
