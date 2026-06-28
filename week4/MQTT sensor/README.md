MQTT Sensor Publisher (ESP32)

Project Description

This project uses an ESP32 to read temperature and humidity from a DHT sensor and publish the readings to a public MQTT broker every 5 seconds in JSON format. The ESP32 also subscribes to an MQTT topic to remotely control an LED.

Hardware Required

ESP32 Development Board

DHT11 Sensor (DHT22 used for Wokwi simulation)

LED

220 Ω Resistor

Breadboard

Jumper Wires

Circuit Connections

DHT Sensor

DHT Pin	ESP32 Pin

VCC	3.3V

GND	GND

DATA	GPIO 4

LED

LED Pin	ESP32 Pin

Anode (+)	GPIO 2

Cathode (-)	GND (through 220 Ω resistor)

MQTT Broker

Broker: broker.hivemq.com

Port: 1883

MQTT Topics

Temperature

Humidity

LED Control

JSON Message Format

Temperature
{
  "value": 28.5,
  "unit": "C",
  "ts": 1234567890
}

Humidity
{
  "value": 65,
  "unit": "%",
  "ts": 1234567890
}

Features

Connects ESP32 to Wi-Fi

Connects to a public MQTT broker

Publishes temperature every 5 seconds

Publishes humidity every 5 seconds

Uses JSON-formatted messages

Subscribes to the LED control topic

Turns the LED ON/OFF based on MQTT messages

Libraries Used

WiFi

PubSubClient

ArduinoJson

DHT Sensor Library by Adafruit

Testing

The MQTT messages were verified using the HiveMQ WebSocket Client by subscribing to the project topics. Published temperature and humidity data were successfully 
received in JSON format.

Folder Structure
week4/
└── mqtt_sensor/
    ├── mqtt_sensor.ino
    ├── README.md
    └── screenshots/
        └── mqtt_messages.png

Simulation Note
This project was developed using Wokwi with a DHT22 sensor because DHT11 is unavailable in the simulator. MQTT communication was tested successfully using the HiveMQ public broker.

Author

Samya Malhotra
