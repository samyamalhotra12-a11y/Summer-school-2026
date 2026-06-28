const int redled = 3;
const int yellowled = 4;
const int greenled = 5;
const int button = 7;
void setup() {
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  }
void showred() {
  digitalWrite(redled, HIGH);
  digitalWrite(yellowled, LOW);
  digitalWrite(greenled, LOW);
  Serial.print(millis());
  Serial.println(" ms : RED");
  }
void showyellow() {
  digitalWrite(redled, LOW);
  digitalWrite(yellowled, HIGH);
  digitalWrite(greenled, LOW);
  Serial.print(millis());
  Serial.println(" ms : YELLOW");
  }
void showgreen() {
  digitalWrite(redled, LOW);
  digitalWrite(yellowled, LOW);
  digitalWrite(greenled, HIGH);
  Serial.print(millis());
  Serial.println(" ms : GREEN");
  }
void pedestrian() {
  showred();
  Serial.print(millis());
  Serial.println(" ms : Pedestrian Button Pressed");
  delay(8000);}
void loop() {
  if (digitalRead(button) == LOW) {
    pedestrian();
    return;
    }
  showred();
  delay(5000);
  if (digitalRead(button) == LOW) {
    pedestrian();
    return;
    }
  showyellow();
  delay(2000);
  if (digitalRead(button) == LOW) {
    pedestrian();
    return;
    }
  showgreen();
  delay(4000);
  }