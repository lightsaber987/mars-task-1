// Reaction Time Tester
// Press the button as fast as you can when the red LED turns on.
// Reaction time is printed to Serial Monitor at 9600 baud.

int butPin = 4;
int redPin = 12;
unsigned long maxdt = 10000;
unsigned long mindt = 500;
unsigned long dt1 = random(mindt,maxdt);
unsigned long now1, later1;
unsigned long dt2 = 100;
unsigned long now2, later2;
int currentReading, prevReading;
bool ledOn = 0;
unsigned long ledOnTime, buttonPressTime;

void setup(){
  pinMode(butPin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  now1 = millis();
  now2 = millis();
  prevReading = digitalRead(butPin);
}

void loop(){
  later1 = millis();
  later2 = millis();
  currentReading = digitalRead(butPin);

  if (!ledOn && later1 - now1 >= dt1){
    digitalWrite(redPin, 1);
    ledOn = 1;
    ledOnTime = millis();
  }

  if (later2 - now2 >= dt2){
    if (currentReading == 0 && prevReading == 1){
      buttonPressTime = millis();
      digitalWrite(redPin, 0);
      if (ledOn){ Serial.print("reaction time (ms): "); Serial.println(buttonPressTime - ledOnTime); }
      ledOn = 0;
      now1 = later1;
      now2 = later2;
      dt1 = random(mindt, maxdt);
    }
    else now2 = later2;
  }

  prevReading = currentReading;
}
