int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;

int relay1 = 8;
int relay2 = 9;
int relay3 = 10;
int relay4 = 11;

bool state1 = false;
bool state2 = false;
bool state3 = false;
bool state4 = false;

bool lastButton1 = HIGH;
bool lastButton2 = HIGH;
bool lastButton3 = HIGH;
bool lastButton4 = HIGH;

char data;

void setup()
{
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
}

void loop()
{
  // BUTTON 1
  bool currentButton1 = digitalRead(button1);
  if (currentButton1 == LOW && lastButton1 == HIGH) {
    delay(50); // debounce
    state1 = !state1;
    digitalWrite(relay1, state1);
  }
  lastButton1 = currentButton1;

  // BUTTON 2
  bool currentButton2 = digitalRead(button2);
  if (currentButton2 == LOW && lastButton2 == HIGH) {
    delay(50);
    state2 = !state2;
    digitalWrite(relay2, state2);
  }
  lastButton2 = currentButton2;

  // BUTTON 3
  bool currentButton3 = digitalRead(button3);
  if (currentButton3 == LOW && lastButton3 == HIGH) {
    delay(50);
    state3 = !state3;
    digitalWrite(relay3, state3);
  }
  lastButton3 = currentButton3;

  // BUTTON 4
  bool currentButton4 = digitalRead(button4);
  if (currentButton4 == LOW && lastButton4 == HIGH) {
    delay(50);
    state4 = !state4;
    digitalWrite(relay4, state4);
  }
  lastButton4 = currentButton4;

  // BLUETOOTH
  if (Serial.available()) {
    data = Serial.read();
    if (data == 'A') { state1 = !state1; digitalWrite(relay1, state1); }
    if (data == 'B') { state2 = !state2; digitalWrite(relay2, state2); }
    if (data == 'C') { state3 = !state3; digitalWrite(relay3, state3); }
    if (data == 'D') { state4 = !state4; digitalWrite(relay4, state4); }
  }
}
