int led = 13;
int pot = A0;
int blink = 0;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  }
void loop() {
  int sensor = analogRead(pot);
  int delaytime = map(sensor, 0, 1023, 100, 1000);
  digitalWrite(led, HIGH);
  delay(delaytime);
  digitalWrite(led, LOW);
  delay(delaytime);
  blink++;
  Serial.print("Blink count: ");
  Serial.println(blink);
  }
