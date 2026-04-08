// Independent Multi-LED Blinker
// Red, green, and blue LEDs blink simultaneously at different rates
// using millis()-based timers — no delay() used.

int redPin = 13;
int greenPin = 7;
int bluePin = 2;

unsigned long dtr = 500;
unsigned long dtg = 1000;
unsigned long dtb = 1500;

unsigned long nowr, nowg, nowb;
unsigned long laterr, laterg, laterb;

bool togglestateRed = 1, togglestateGreen = 1, togglestateBlue = 1;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  nowr = millis(); nowg = millis(); nowb = millis();

  digitalWrite(redPin, togglestateRed);
  digitalWrite(greenPin, togglestateGreen);
  digitalWrite(bluePin, togglestateBlue);
}

void loop()
{
  laterr = millis(); laterg = millis(); laterb = millis();

  if(laterr - nowr >= dtr) {
    digitalWrite(redPin, togglestateRed = !togglestateRed);
    nowr = laterr;
  }

  if(laterg - nowg >= dtg) {
    togglestateGreen = !togglestateGreen;
    digitalWrite(greenPin, togglestateGreen);
    nowg = laterg;
  }

  if(laterb - nowb >= dtb) {
    togglestateBlue = !togglestateBlue;
    digitalWrite(bluePin, togglestateBlue);
    nowb = laterb;
  }
}
