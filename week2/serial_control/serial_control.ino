const int ledPin = LED_BUILTIN;
int blinkCount = 0; // Tracks total blinks performed

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("System Ready. Enter command:");
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim(); // Remove any extra spaces or hidden characters

    if (cmd == "LED_ON") {
      digitalWrite(ledPin, HIGH);
      Serial.println("OK: LED is ON");
    } 
    else if (cmd == "LED_OFF") {
      digitalWrite(ledPin, LOW);
      Serial.println("OK: LED is OFF");
    } 
    else if (cmd.startsWith("BLINK_")) {
      // Get the character after 'BLINK_' (which is at index 6)
      char xChar = cmd.charAt(6); 
      
      // Validate that it is a digit between 1 and 9
      if (xChar >= '1' && xChar <= '9') {
        int x = xChar - '0'; // Convert char to integer
        for (int i = 0; i < x; i++) {
          digitalWrite(ledPin, HIGH); delay(500);
          digitalWrite(ledPin, LOW); delay(500);
        }
        blinkCount += x;
        Serial.print("OK: Blinked "); Serial.print(x); Serial.println(" times");
      } else {
        Serial.println("ERROR: Invalid number (1-9)");
      }
    } 
    else if (cmd == "STATUS") {
      Serial.print("LED State: ");
      Serial.println(digitalRead(ledPin) ? "ON" : "OFF");
      Serial.print("Total Blinks Performed: ");
      Serial.println(blinkCount);
    } 
    else if (cmd == "RESET") {
      blinkCount = 0;
      Serial.println("OK: Counter Reset");
    } 
    else {
      Serial.println("ERROR: Unknown command");
    }
  }
}
