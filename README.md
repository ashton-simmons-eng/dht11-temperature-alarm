# DHT11 Temperature-Alarm System

Arduino project using a DHT11 sensor to monitor temperature and trigger a visual/audible alarm above a set threshold, built up over three iterations from a bare LED indicator to a full LCD + pulsing-buzzer alarm.

## What it does

Reads temperature from a DHT11 sensor every 2 seconds and compares it against a 30°C threshold. When exceeded, the system alerts via LED and buzzer, with a live temperature readout on an LCD in the final version.

**Demo videos:** [Google Drive folder](https://drive.google.com/drive/folders/1bVleKtZUGjAFgvKDz1jduumxYswvouvm?usp=drive_link) — see `stage1-led-only.mp4`, `stage2-led-buzzer-continuous.mp4`, and `stage3-lcd-pulsing-buzzer.mp4`.

## Build stages

**Stage 1 — LED only**
Basic proof of concept: read temperature from the DHT11, light an LED when it exceeds 30°C. No buzzer, no display — just confirming the sensor and threshold logic worked. The reading loop was originally much faster, but the temperature values updated too quickly to actually read — the delay between readings was increased to 2 seconds to fix this.

**Stage 2 — Added buzzer (continuous)**
Added a buzzer alongside the LED so the alarm had an audible component. Both triggered together above threshold. In testing, the buzzer's continuous tone turned out to be genuinely jarring — a problem worth fixing before calling it finished, not just noise to put up with.

**Stage 3 — LCD display + pulsing buzzer** (`DHT_2.ino` / `DHT_3.ino`)
Two improvements made together: added a 16x2 LCD showing live temperature (with a proper °C symbol), and changed the buzzer from continuous to a 300ms on/off pulse specifically to fix the harshness identified in Stage 2. `DHT_3.ino` is the same logic as `DHT_2.ino` with full comments added — this is the version to read if you want the code explained inline.

## Files

| File | Description |
|---|---|
| `DHT_1.ino` | LED + buzzer, continuous alarm, no display (Stages 1–2) |
| `DHT_2.ino` | Adds LCD display + pulsing buzzer (Stage 3) |
| `DHT_3.ino` | Same as above, fully commented — final version |

## Hardware

- Arduino Uno
- DHT11 temperature sensor
- 16x2 LCD (parallel, non-I2C)
- LED + buzzer
- Breadboard and jumper wires

## What I learned / next steps

Testing surfaced usability problems that weren't obvious from the code alone — only became clear once it was physically running. The reading rate was too fast to actually read on the display/serial monitor, so the delay was slowed to 2 seconds; the buzzer's continuous tone was jarring in practice, so it was changed to pulse instead of removed. Both fixes mattered more in practice than getting the logic "technically working" on the first pass. A natural next step would be making the threshold and pulse timing configurable (e.g. via serial input or a potentiometer) rather than hardcoded.
