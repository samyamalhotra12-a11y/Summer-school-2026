const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 9;
// Adjust according to your LDR
const int ldrThreshold = 500;

bool nightMode = false;
bool motionActive = false;

unsigned long motionTimer = 0;
const unsigned long motionDuration = 30000; //30 sec

// Time counter
unsigned long previousSecond = 0;
unsigned long totalSeconds = 0;

void printTime(){
    int hh = totalSeconds / 3600;
    int mm = (totalSeconds % 3600) / 60;
    int ss = totalSeconds % 60;

    Serial.print("[");

    if(hh < 10) Serial.print("0");
    Serial.print(hh);
    Serial.print(":");

    if(mm < 10) Serial.print("0");
    Serial.print(mm);
    Serial.print(":");

    if(ss < 10) Serial.print("0");
    Serial.print(ss);

    Serial.print("] ");}

void logEvent(String msg){
    printTime();
    Serial.print("EVENT: ");
    Serial.println(msg);}

void setup(){
    pinMode(pirPin, INPUT);
    pinMode(ledPin, OUTPUT);

    Serial.begin(9600);

    analogWrite(ledPin,0);}

void loop(){
    // Simple software clock
    if(millis() - previousSecond >= 1000){
        previousSecond += 1000;
        totalSeconds++;}

    int ldrValue = analogRead(ldrPin);
    int pirState = digitalRead(pirPin);

    // ---------------- DAY MODE ----------------
    if(ldrValue > ldrThreshold){
        if(nightMode){
            logEvent("Day Mode Enabled");}

        nightMode = false;
        motionActive = false;
        analogWrite(ledPin,0);
        return;}

    // ---------------- NIGHT MODE ----------------
    if(!nightMode){
        nightMode = true;
        analogWrite(ledPin,51);     //20%
        logEvent("Night Mode Enabled");}

    // Motion detected
    if(pirState == HIGH){
        analogWrite(ledPin,255);
        if(!motionActive){
            logEvent("Motion Detected");}

        motionActive = true;
        motionTimer = millis();}

    // Check timeout
    if(motionActive){
        if(millis() - motionTimer >= motionDuration){
            analogWrite(ledPin,51);   //20%
            motionActive = false;
            logEvent("No Motion - LED Dimmed");}}}