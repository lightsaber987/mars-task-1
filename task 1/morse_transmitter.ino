// Arduino Morse Code Transmitter
// Enter text via Serial Monitor (9600 baud) and it will be
// transmitted as Morse code via buzzer and LED at 19 WPM.

int buzPin = 6;
int ledPin = 2;

// Dot duration in ms for 19 WPM
int dt = 63;

void dit() {
  digitalWrite(buzPin, 1);
  digitalWrite(ledPin, 1);
  delay(dt);            // dot duration
  digitalWrite(buzPin, 0);
  digitalWrite(ledPin, 0);
  delay(dt);            // intra-character space
}

void dah() {
  digitalWrite(buzPin, 1);
  digitalWrite(ledPin, 1);
  delay(3 * dt);        // dash duration
  digitalWrite(buzPin, 0);
  digitalWrite(ledPin, 0);
  delay(dt);            // intra-character space
}

// Space between letters
void letterSpace() {
  delay(2 * dt);        // already waited 1 dt after last dit/dah, add 2 more = total 3 dt
}

// Space between words
void wordSpace() {
  delay(7 * dt);        // 7 dt total
}

void sendMorse(char c) {
  switch(c) {
    case 'A': dit(); dah(); break;
    case 'B': dah(); dit(); dit(); dit(); break;
    case 'C': dah(); dit(); dah(); dit(); break;
    case 'D': dah(); dit(); dit(); break;
    case 'E': dit(); break;
    case 'F': dit(); dit(); dah(); dit(); break;
    case 'G': dah(); dah(); dit(); break;
    case 'H': dit(); dit(); dit(); dit(); break;
    case 'I': dit(); dit(); break;
    case 'J': dit(); dah(); dah(); dah(); break;
    case 'K': dah(); dit(); dah(); break;
    case 'L': dit(); dah(); dit(); dit(); break;
    case 'M': dah(); dah(); break;
    case 'N': dah(); dit(); break;
    case 'O': dah(); dah(); dah(); break;
    case 'P': dit(); dah(); dah(); dit(); break;
    case 'Q': dah(); dah(); dit(); dah(); break;
    case 'R': dit(); dah(); dit(); break;
    case 'S': dit(); dit(); dit(); break;
    case 'T': dah(); break;
    case 'U': dit(); dit(); dah(); break;
    case 'V': dit(); dit(); dit(); dah(); break;
    case 'W': dit(); dah(); dah(); break;
    case 'X': dah(); dit(); dit(); dah(); break;
    case 'Y': dah(); dit(); dah(); dah(); break;
    case 'Z': dah(); dah(); dit(); dit(); break;
    case '0': dah(); dah(); dah(); dah(); dah(); break;
    case '1': dit(); dah(); dah(); dah(); dah(); break;
    case '2': dit(); dit(); dah(); dah(); dah(); break;
    case '3': dit(); dit(); dit(); dah(); dah(); break;
    case '4': dit(); dit(); dit(); dit(); dah(); break;
    case '5': dit(); dit(); dit(); dit(); dit(); break;
    case '6': dah(); dit(); dit(); dit(); dit(); break;
    case '7': dah(); dah(); dit(); dit(); dit(); break;
    case '8': dah(); dah(); dah(); dit(); dit(); break;
    case '9': dah(); dah(); dah(); dah(); dit(); break;
    default: break; // ignore unknown characters
  }
}

void setup() {
  pinMode(buzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter text:");
  while(Serial.available() == 0) {}
  String name = Serial.readStringUntil('\n');
  name.toUpperCase();

  for(int i = 0; i < name.length(); i++) {
    char c = name[i];
    if(c == ' ') {
      wordSpace();
    } else {
      sendMorse(c);
      letterSpace();
    }
  }

  Serial.println("Done!");
}
