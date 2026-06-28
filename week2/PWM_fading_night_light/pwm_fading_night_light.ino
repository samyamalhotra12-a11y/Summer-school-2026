const int ledPin = 9;
const int btnPin = 2;
int mode = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(btnPin) == LOW) {
    mode++;
    if (mode > 3) mode = 1;
    Serial.print("Current Mode: "); Serial.println(mode);
    delay(300); 
  }

  
  if (mode == 1) {
  
    for(int i=0; i<255; i++) { analogWrite(ledPin, i); delay(6); }
    for(int i=255; i>=0; i--) { analogWrite(ledPin, i); delay(6); }
  } 
  else if (mode == 2) {
    for(int i=0; i<255; i++) { analogWrite(ledPin, i); delay(1); }
    for(int i=255; i>=0; i--) { analogWrite(ledPin, i); delay(1); }
  } 
  else if (mode == 3) {
    for(int i=0; i<3; i++) { digitalWrite(ledPin, HIGH); delay(150); digitalWrite(ledPin, LOW); delay(150); }
    delay(500);
  }
}