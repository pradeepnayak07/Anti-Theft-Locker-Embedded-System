# Anti-Theft Locker System - Circuit Connections

## 1. Controller

Arduino UNO is used as the main microcontroller for the Anti-Theft Locker System.

---

## 2. 4x4 Matrix Keypad

| Keypad Pin | Arduino UNO Pin | Purpose |
|---|---|---|
| R1 | D9 | Row 1 |
| R2 | D8 | Row 2 |
| R3 | D7 | Row 3 |
| R4 | D6 | Row 4 |
| C1 | D5 | Column 1 |
| C2 | D4 | Column 2 |
| C3 | D3 | Column 3 |
| C4 | D2 | Column 4 |

The keypad is used for entering the locker password.

---

## 3. 16x2 I2C LCD

| LCD Pin | Arduino UNO Pin | Purpose |
|---|---|---|
| GND | GND | Ground |
| VCC | 5V | Power |
| SDA | A4 | I2C Data |
| SCL | A5 | I2C Clock |

The LCD displays password prompts, authentication results and locker status.

---

## 4. Servo Motor

| Servo Pin | Arduino UNO Pin | Purpose |
|---|---|---|
| Signal | D10 | Servo Control |
| VCC | 5V | Power |
| GND | GND | Ground |

Servo position:

- 0° → Locker Locked
- 90° → Locker Unlocked

The servo automatically returns to the locked position after the configured auto-lock time.

---

## 5. Buzzer

| Buzzer Pin | Arduino UNO Pin | Purpose |
|---|---|---|
| Positive (+) | D11 | Alarm Signal |
| Negative (-) | GND | Ground |

The buzzer is activated after three consecutive incorrect password attempts.

---

## 6. Green LED

| LED Pin | Arduino UNO Pin | Purpose |
|---|---|---|
| Positive (+) | D12 through resistor | Access Granted |
| Negative (-) | GND | Ground |

The green LED indicates successful authentication.

---

## 7. Red LED

| LED Pin | Arduino UNO Pin | Purpose |
|---|---|---|
| Positive (+) | D13 through resistor | Access Denied |
| Negative (-) | GND | Ground |

The red LED indicates an incorrect password or security lockout.

---

## 8. Complete Pin Summary

| Component | Arduino UNO Pin |
|---|---|
| Keypad R1 | D9 |
| Keypad R2 | D8 |
| Keypad R3 | D7 |
| Keypad R4 | D6 |
| Keypad C1 | D5 |
| Keypad C2 | D4 |
| Keypad C3 | D3 |
| Keypad C4 | D2 |
| Servo Signal | D10 |
| Buzzer | D11 |
| Green LED | D12 |
| Red LED | D13 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| LCD VCC | 5V |
| LCD GND | GND |

---

## 9. System Operation

1. The user enters the password using the 4x4 keypad.
2. The password is displayed as masked `*` characters on the LCD.
3. The system verifies the entered password.
4. If the password is correct:
   - Access is granted.
   - Green LED turns ON.
   - Servo unlocks the locker.
   - Auto-lock timer starts.
5. If the password is incorrect:
   - Access is denied.
   - Red LED turns ON.
   - Failed-attempt counter increases.
6. After three consecutive incorrect attempts:
   - Locker remains locked.
   - Buzzer alarm activates.
   - Security lockout is triggered.
7. After the configured unlock period, the servo automatically returns to the locked position.

---

## 10. Simulation Platform

The complete circuit is implemented and tested using the Wokwi Arduino simulation environment.

The Wokwi simulation provides virtual hardware for the Arduino UNO, keypad, LCD, servo motor, buzzer and LEDs.