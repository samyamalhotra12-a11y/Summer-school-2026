int ldr=A0;
int led=9;
void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int ldrvalue=analogRead(ldr);
  if(ldrvalue<300){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  delay(1000);
}