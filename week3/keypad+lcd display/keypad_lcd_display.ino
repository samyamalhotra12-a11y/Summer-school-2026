#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD Pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// LEDs & Buzzer
const int greenLED = 12;
const int redLED = 13;
const int buzzer = 11;

// Correct PIN
String correctPIN = "1234";
String enteredPIN = "";

int attempts = 0;

// ---------------- Keypad ----------------

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};

byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {A4, A5, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ----------------------------------------

void setup() {
  lcd.begin(16,2);
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.print("ENTER PIN:");
  lcd.setCursor(0,1);}

void loop() {
  char key = keypad.getKey();
  if(key){
    if(key>='0' && key<='9'){
      enteredPIN += key;
      lcd.print("*");}

    if(enteredPIN.length()==4){
      checkPIN();}}}

void checkPIN(){
  lcd.clear();
  if(enteredPIN==correctPIN){
    lcd.print("ACCESS");
    lcd.setCursor(0,1);
    lcd.print("GRANTED");
    digitalWrite(greenLED,HIGH);
    tone(buzzer,1000,200);
    delay(3000);
    digitalWrite(greenLED,LOW);
    attempts=0;}

  else{
    lcd.print("ACCESS");
    lcd.setCursor(0,1);
    lcd.print("DENIED");
    digitalWrite(redLED,HIGH);
    tone(buzzer,500);
    delay(1000);
    noTone(buzzer);
    digitalWrite(redLED,LOW);

    attempts++;

    if(attempts>=3){
      lcd.clear();
      lcd.print("SYSTEM LOCKED");
      lcd.setCursor(0,1);
      lcd.print("10 SECONDS");
      delay(10000);
      attempts=0;}}

  enteredPIN="";
  lcd.clear();
  lcd.print("ENTER PIN:");
  lcd.setCursor(0,1);}
