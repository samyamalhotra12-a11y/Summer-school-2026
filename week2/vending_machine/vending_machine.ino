/*
=========================================================
VENDING MACHINE STATE MACHINE

States:
1. IDLE
2. COIN_INSERTED
3. ITEM_SELECTED
4. DISPENSING

Buttons:
Insert Coin -> D2
Select Item -> D3
Cancel      -> D4

LEDs:
LED1 -> IDLE
LED2 -> COIN_INSERTED
LED3 -> ITEM_SELECTED / DISPENSING

---------------- State Transition Diagram ----------------

            Insert Coin
      +--------------------+
      |                    |
      v                    |
   +--------+          Cancel
   | IDLE   |<----------------------+
   +--------+                       |
       |                            |
       | Insert Coin                |
       v                            |
+----------------+                  |
| COIN_INSERTED |-------------------+
+----------------+
       |
       | Select Item
       v
+----------------+
| ITEM_SELECTED  |
+----------------+
       |
       | (Automatic)
       v
+----------------+
| DISPENSING     |
+----------------+
       |
       | Item Dispensed
       v
    +--------+
    | IDLE   |
    +--------+

=========================================================
*/

enum State
{
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

// Function Prototypes
void updateLEDs();
void changeState(State newState);

// Button Pins
const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

// LED Pins
const int idleLED = 8;
const int coinLED = 9;
const int stateLED = 10;

void setup()
{
  Serial.begin(9600);

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(idleLED, OUTPUT);
  pinMode(coinLED, OUTPUT);
  pinMode(stateLED, OUTPUT);

  updateLEDs();

  Serial.println("Vending Machine Started");
  Serial.println("Current State: IDLE");
}

void loop()
{
  bool coin = (digitalRead(coinBtn) == LOW);
  bool select = (digitalRead(selectBtn) == LOW);
  bool cancel = (digitalRead(cancelBtn) == LOW);

  switch (currentState)
  {
    case IDLE:

      if (coin)
      {
        changeState(COIN_INSERTED);
        delay(250);
      }

      break;

    case COIN_INSERTED:

      if (select)
      {
        changeState(ITEM_SELECTED);
        delay(250);
      }
      else if (cancel)
      {
        changeState(IDLE);
        delay(250);
      }

      break;

    case ITEM_SELECTED:

      Serial.println("Dispensing Item...");
      delay(1000);

      changeState(DISPENSING);

      delay(1500);

      Serial.println("Item Dispensed.");

      changeState(IDLE);

      break;

    case DISPENSING:
      // Automatic transition handled above
      break;
  }
}

void changeState(State newState)
{
  currentState = newState;

  updateLEDs();

  Serial.print("Current State -> ");

  switch (currentState)
  {
    case IDLE:
      Serial.println("IDLE");
      break;

    case COIN_INSERTED:
      Serial.println("COIN_INSERTED");
      break;

    case ITEM_SELECTED:
      Serial.println("ITEM_SELECTED");
      break;

    case DISPENSING:
      Serial.println("DISPENSING");
      break;
  }
}

void updateLEDs()
{
  digitalWrite(idleLED, LOW);
  digitalWrite(coinLED, LOW);
  digitalWrite(stateLED, LOW);

  switch (currentState)
  {
    case IDLE:
      digitalWrite(idleLED, HIGH);
      break;

    case COIN_INSERTED:
      digitalWrite(coinLED, HIGH);
      break;

    case ITEM_SELECTED:
      digitalWrite(stateLED, HIGH);
      break;

    case DISPENSING:
      digitalWrite(stateLED, HIGH);
      break;
  }
}
