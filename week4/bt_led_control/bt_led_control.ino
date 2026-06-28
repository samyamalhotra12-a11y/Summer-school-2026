#include <SoftwareSerial.h>

// HC-05 Bluetooth
SoftwareSerial BT(2, 3);   // RX, TX

const int redLED = 8;
const int greenLED = 9;
const int blueLED = 10;

void setup() {

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Bluetooth LED Controller Ready");}

void loop() {
  if (BT.available()) {
    char command = BT.read();
    Serial.print("Received: ");
    Serial.println(command);
    switch (command) {
      case 'R':
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        BT.println("Red LED ON");
        break;
      case 'G':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, LOW);
        BT.println("Green LED ON");
        break;
      case 'B':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, HIGH);
        BT.println("Blue LED ON");
        break;
      case 'X':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        BT.println("All LEDs OFF");
        break;
      case 'F':
        for (int i = 0; i < 5; i++) {
          digitalWrite(redLED, HIGH);
          digitalWrite(greenLED, HIGH);
          digitalWrite(blueLED, HIGH);
          delay(250);

          digitalWrite(redLED, LOW);
          digitalWrite(greenLED, LOW);
          digitalWrite(blueLED, LOW);
          delay(250);}

        BT.println("Flashed 5 Times");
        break;
      default:
        BT.println("Unknown Command");
        break;}}}