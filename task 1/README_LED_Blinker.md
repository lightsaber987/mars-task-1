# Independent Multi-LED Blinker

An Arduino sketch that blinks three LEDs (red, green, blue) simultaneously at different frequencies — each on its own independent timer, without using `delay()`.

---

## Hardware Requirements

- Arduino UNO (or compatible)
- Red LED
- Green LED
- Blue LED
- 3x 220Ω resistors
- Jumper wires

## Wiring

| Component      | Arduino Pin | Resistor |
|----------------|-------------|----------|
| Red LED (+)    | D13         | 220Ω     |
| Green LED (+)  | D7          | 220Ω     |
| Blue LED (+)   | D2          | 220Ω     |
| All LED (-)    | GND         | —        |

---

## How It Works

Each LED blinks independently using `millis()`-based timers instead of `delay()`. This means all three LEDs toggle at their own pace simultaneously without blocking each other.

| LED   | Blink Interval |
|-------|---------------|
| Red   | 500 ms        |
| Green | 1000 ms       |
| Blue  | 1500 ms       |

On startup, all three LEDs turn on. Each one then toggles on its own schedule.

---

## Usage

1. Wire up the components as shown above.
2. Upload the sketch to your Arduino.
3. All three LEDs will begin blinking immediately at their respective rates.

---

## Configuration

Adjust the blink intervals at the top of the sketch:

| Variable | Default  | Description              |
|----------|----------|--------------------------|
| `dtr`    | 500 ms   | Red LED toggle interval  |
| `dtg`    | 1000 ms  | Green LED toggle interval|
| `dtb`    | 1500 ms  | Blue LED toggle interval |
| `redPin`   | 13     | Pin for red LED          |
| `greenPin` | 7      | Pin for green LED        |
| `bluePin`  | 2      | Pin for blue LED         |

---

## Notes

- Uses `millis()` instead of `delay()` so all LEDs run truly in parallel — no LED has to wait for another.
- All LEDs start in the **ON** state (`togglestate` initialized to `1`).
- The red LED toggle uses an inline assignment (`togglestateRed = !togglestateRed`) inside `digitalWrite()` — this is functionally identical to the two-line approach used for green and blue.
