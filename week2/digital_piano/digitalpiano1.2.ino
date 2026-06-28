const int mode = 7;
bool major = true;
bool prev = HIGH;

const int buzzer = 8;
const int dobtn = 3;
const int rebtn = 4;
const int mibtn = 5;
const int fabtn = 6;

void setup() {
  pinMode(dobtn, INPUT_PULLUP);
  pinMode(rebtn, INPUT_PULLUP);
  pinMode(mibtn, INPUT_PULLUP);
  pinMode(fabtn, INPUT_PULLUP);
  pinMode(mode, INPUT_PULLUP);}

void loop() {
  bool current = digitalRead(mode);
  if(prev==HIGH && current==LOW){
    major=!major;
    delay(200);}

  prev=current;

  bool d=digitalRead(dobtn)==LOW;
  bool r=digitalRead(rebtn)==LOW;
  bool m=digitalRead(mibtn)==LOW;
  bool f=digitalRead(fabtn)==LOW;

  int pressed=d+r+m+f;

  if(pressed>=2){
    tone(buzzer,392);}

  else if(d){
    tone(buzzer,262);}

  else if(r){
    tone(buzzer,294);}

  else if(m){
    if(major)
      tone(buzzer,330);
    else
      tone(buzzer,311);}

  else if(f){
    if(major)
      tone(buzzer,349);
    else
      tone(buzzer,330);}

  else{
      noTone(buzzer);}}
