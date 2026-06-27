int Led=9;
int LED1=10;

void setup(){
  pinMode(Led, OUTPUT);
  pinMode(LED1, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(Led, HIGH);
  delay(1000);
  Serial.println("blue");
  digitalWrite(Led, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  delay(1000);
  Serial.println("white");
  digitalWrite(LED1, LOW);
  delay(1000);
}