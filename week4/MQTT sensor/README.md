MQTT Sensor Publisher
Use ESP32 to publish DHT11 readings to a free MQTT broker (broker.hivemq.com or test.mosquitto.org):
Topic: iitjammu/summer26/[yourname]/temperature
Topic: iitjammu/summer26/[yourname]/humidity
Publish every 5 seconds in JSON format: {"value": 28.5, "unit": "C", "ts": 1234567890}
Subscribe to iitjammu/summer26/[yourname]/led_control and toggle LED based on message
Test using MQTT Explorer or MQTT.fx. Submit a screenshot showing messages received.
