# Reaction Time Tester

An Arduino-based reaction time measurement tool. A red LED lights up after a random delay, and the user must press a button as fast as possible. Their reaction time is reported over Serial.

---

## Hardware Requirements

- Arduino UNO (or compatible)
- Red LED
- Pushbutton
- 220Ω resistor (for LED)
- Jumper wires

## Wiring

| Component     | Arduino Pin |
|---------------|-------------|
| Button        | D4 (INPUT_PULLUP) |
| Red LED (+)   | D12 (via 220Ω resistor) |
| Red LED (-)   | GND |
| Button (other leg) | GND |

> The button uses the Arduino's internal pull-up resistor, so no external resistor is needed for it.

---

## How It Works

1. After upload, the Arduino waits a **random delay** between 500ms and 10000ms.
2. The **red LED turns on** — this is your cue.
3. **Press the button** as quickly as you can.
4. Your **reaction time in milliseconds** is printed to the Serial Monitor.
5. The cycle resets with a new random delay.

---

## Usage

1. Wire up the components as shown above.
2. Upload the sketch to your Arduino.
3. Open the **Serial Monitor** at **9600 baud**.
4. Wait for the LED to turn on, then press the button.
5. Your reaction time will appear in the Serial Monitor.

---

## Configuration

You can adjust these variables at the top of the sketch:

| Variable | Default | Description |
|----------|---------|-------------|
| `mindt`  | 500 ms  | Minimum delay before LED turns on |
| `maxdt`  | 10000 ms | Maximum delay before LED turns on |
| `dt2`    | 100 ms  | Button polling interval |
| `butPin` | 4       | Pin number for the button |
| `redPin` | 12      | Pin number for the LED |

---

## Serial Output Example

```
reaction time (ms): 342
reaction time (ms): 271
reaction time (ms): 489
```

---

## Notes

- Pressing the button **before** the LED turns on does nothing.
- Only a **falling edge** (button press) is detected, not a held button, thanks to edge detection using `currentReading` and `prevReading`.
- Reaction times below ~150ms are likely accidental presses (human reaction time floor is around 150–200ms).
