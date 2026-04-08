# Arduino Morse Code Transmitter

An Arduino sketch that takes text input from the Serial Monitor and transmits it as Morse code via a buzzer, at 19 WPM.

---

## Hardware Requirements

- Arduino UNO (or compatible)
- Buzzer (active or passive)
- LED
- 220Ω resistor (for LED)
- Jumper wires

---

## Wiring

| Component    | Arduino Pin | Notes          |
|--------------|-------------|----------------|
| Buzzer (+)   | D6          | —              |
| Buzzer (−)   | GND         | —              |

---

## How It Works

1. The Arduino prompts you to enter text via the Serial Monitor.
2. You type a message and press **Enter**.
3. The sketch converts each character to Morse code and transmits it — the buzzer beeps.
4. Spaces between words are handled automatically.
5. Once done, `"Done!"` is printed to Serial and it prompts for the next message.

Morse timing follows the standard ITU rules:

| Element           | Duration         |
|-------------------|------------------|
| Dot (dit)         | 1 unit (63 ms)   |
| Dash (dah)        | 3 units (189 ms) |
| Intra-char space  | 1 unit (63 ms)   |
| Letter space      | 3 units total    |
| Word space        | 7 units total    |

---

## Usage

1. Wire up the components as shown above.
2. Upload the sketch to your Arduino.
3. Open the **Serial Monitor at 9600 baud**.
4. Type any text (letters, numbers, spaces) and press **Enter**.
5. Watch and listen as the message is transmitted in Morse code.
6. Repeat for the next message.

> Input is automatically converted to uppercase before transmission, so you can type in any case.

---

## Supported Characters

- **Letters:** A–Z
- **Numbers:** 0–9
- **Spaces:** Treated as word gaps
- Unknown characters are silently ignored.

---

## Configuration

| Variable | Default | Description                        |
|----------|---------|------------------------------------|
| `dt`     | 63 ms   | Dot duration (sets speed at 19 WPM)|
| `buzPin` | D6      | Buzzer output pin                  |

To change the transmission speed, adjust `dt`:
- Faster = smaller `dt`
- Slower = larger `dt`

Standard WPM reference (based on the word "PARIS"):

| WPM | dot duration (ms) |
|-----|-------------------|
| 5   | 240               |
| 10  | 120               |
| 19  | 63                |
| 20  | 60                |
| 25  | 48                |

---

## Notes

- The sketch uses `delay()` for timing, which blocks execution during transmission — this is intentional and appropriate for Morse code output.
- `Serial.readStringUntil('\n')` reads the full input line, so make sure your Serial Monitor is set to send a **newline** on Enter (default in the Arduino IDE).
