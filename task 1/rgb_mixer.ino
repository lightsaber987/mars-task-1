// Potentiometer-Controlled RGB Mixer with Variable Blinker
// Three pots control red, green, blue LED brightness via PWM.
// A fourth pot controls the blink rate of a yellow LED.

int redPot = A5;
int bluePot = A3;
int greenPot = A1;
int timePot1 = A4;

int redPin = 11;
int bluePin = 9;
int greenPin = 5;
int ylwPin = 2;

unsigned long dt;
bool togglestateYlw;

int inputPins[3] = {redPot, greenPot, bluePot};
int outputPins[4] = {redPin, greenPin, bluePin, ylwPin};

unsigned long now;
unsigned long later;

void setup(){
  int i;
  for(i = 0; i < 3; i++) pinMode(inputPins[i], INPUT);
  for(i = 0; i < 4; i++) pinMode(outputPins[i], OUTPUT);
  Serial.begin(9600);
  now = millis();
  togglestateYlw = (analogRead(timePot1)) ? 1 : 0;
}

void loop(){
  later = millis();

  int redReading = analogRead(redPot);
  int blueReading = analogRead(bluePot);
  int greenReading = analogRead(greenPot);

  float scalingFactor = 255 / 1023.;
  int red   = redReading   * scalingFactor;
  int blue  = scalingFactor * blueReading;
  int green = scalingFactor * greenReading;

  int t1 = analogRead(timePot1);
  float minDt = 50;
  float maxDt = 10000;
  float timeFactor = (float)t1;
  dt = minDt + ((maxDt - minDt) / 1023.) * timeFactor;

  analogWrite(redPin,   red);
  analogWrite(bluePin,  blue);
  analogWrite(greenPin, green);

  if (timeFactor == 0) {
    digitalWrite(ylwPin, 0);
    now = later;
  } else {
    if (later - now >= dt) {
      digitalWrite(ylwPin, togglestateYlw = !togglestateYlw);
      now = later;
    }
  }

  // Uncomment during testing / debugging
  // Serial.print("red intensity: ");  Serial.println(red);
  // Serial.print("blue intensity: "); Serial.println(blue);
  // Serial.print("green intensity: ");Serial.println(green);
  // Serial.print("t1: ");             Serial.println(t1);
  // Serial.print("timeFactor: ");     Serial.println(timeFactor);
  // Serial.print("dt (ms): ");        Serial.println(dt);
}
