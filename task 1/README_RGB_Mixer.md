# Potentiometer-Controlled RGB Mixer with Variable Blinker

An Arduino sketch that lets you mix red, green, and blue LED intensities using individual potentiometers, while a fourth yellow LED blinks at a rate controlled by a separate pot.

---

## Hardware Requirements

- Arduino UNO (or compatible)
- Red, Green, Blue, Yellow LEDs
- 4x Potentiometers
- 4x 220Ω resistors (for LEDs)
- Jumper wires

---

## Wiring

### LEDs (PWM pins)

| LED     | Arduino Pin | Resistor |
|---------|-------------|----------|
| Red     | D11 (PWM)   | 220Ω     |
| Green   | D5  (PWM)   | 220Ω     |
| Blue    | D9  (PWM)   | 220Ω     |
| Yellow  | D2          | 220Ω     |
| All (−) | GND         | —        |

> Red, Green, and Blue must be on PWM-capable pins for brightness control.

### Potentiometers

| Pot       | Arduino Pin | Controls              |
|-----------|-------------|-----------------------|
| Red Pot   | A5          | Red LED brightness    |
| Green Pot | A1          | Green LED brightness  |
| Blue Pot  | A3          | Blue LED brightness   |
| Time Pot  | A4          | Yellow LED blink rate |

---

## How It Works

- The **red, green, and blue pots** set the brightness of their respective LEDs by mapping the 0–1023 analog reading to a 0–255 PWM value.
- The **time pot** controls how fast the yellow LED blinks, with a range of **50ms to 10000ms**.
- When the time pot is turned all the way down to 0, the yellow LED turns **off completely** (no blinking).
- All readings update continuously in `loop()`, so changes to any pot take effect immediately.

---

## Usage

1. Wire up the components as shown above.
2. Upload the sketch to your Arduino.
3. Turn the red, green, and blue pots to mix LED colors and brightness.
4. Turn the time pot to set the yellow LED blink speed.
5. Open the **Serial Monitor at 9600 baud** to view live debug readings.

> **Note:** The Serial debug output is always active. Comment out the `Serial.print` lines at the bottom of `loop()` when not debugging to reduce overhead.

---

## Configuration

| Variable   | Default  | Description                     |
|------------|----------|---------------------------------|
| `minDt`    | 50 ms    | Fastest possible blink interval |
| `maxDt`    | 10000 ms | Slowest possible blink interval |
| `redPin`   | D11      | PWM pin for red LED             |
| `greenPin` | D5       | PWM pin for green LED           |
| `bluePin`  | D9       | PWM pin for blue LED            |
| `ylwPin`   | D2       | Pin for yellow LED              |

---

## Serial Output Example

```
red intensity: 128
blue intensity: 64
green intensity: 200
t1: (512
timeFactor: 512.00
dt (ms): 4926
```

---

## Notes

- The analog-to-PWM scaling uses `255 / 1023.0` as a float to avoid integer division truncation.
- The yellow LED blink uses a `millis()`-based timer — no `delay()` is used anywhere, so RGB brightness updates remain smooth and responsive even while the yellow LED is blinking.
- The yellow LED's initial state on startup is derived from the time pot reading — if the pot is above 0, it starts ON; if at 0, it starts OFF.
