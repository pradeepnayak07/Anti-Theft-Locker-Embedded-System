# Anti-Theft Locker System - Project Documentation

## 1. Project Overview

The Anti-Theft Locker System is an embedded security system designed to protect a locker using password-based authentication.

The system uses an Arduino UNO as the main controller. A 4x4 keypad is used to enter the password, while a 16x2 I2C LCD displays system messages. A servo motor controls the locker mechanism.

Security features include failed-attempt detection, a buzzer alarm, red and green status LEDs, and automatic locking.

---

## 2. Problem Statement

Traditional lockers may rely only on physical keys or basic mechanical locks.

The objective of this project is to develop an electronic locker security system that provides:

- Password-based access
- Automatic locking
- Failed-attempt detection
- Security alarm
- Visual status indication
- User-friendly display

---

## 3. System Architecture

```text
              ┌──────────────────┐
              │    4x4 Keypad    │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │    Arduino UNO   │
              │  Main Controller │
              └────┬─────┬───────┘
                   │     │
          ┌────────┘     └─────────┐
          ▼                        ▼
   ┌─────────────┐          ┌─────────────┐
   │ 16x2 I2C LCD│          │ Servo Motor  │
   └─────────────┘          └─────────────┘
          │
          ├──────────────┐
          ▼              ▼
   ┌───────────┐   ┌───────────┐
   │ Green LED │   │  Red LED   │
   └───────────┘   └───────────┘
                          │
                          ▼
                     ┌─────────┐
                     │ Buzzer  │
                     └─────────┘
---

## 4. Main Components

### Arduino UNO

Acts as the main microcontroller and controls the complete locker system.

### 4x4 Matrix Keypad

Used for entering the locker password.

### 16x2 I2C LCD

Displays password prompts, authentication results and locker status.

### Servo Motor

Acts as the electronic locking mechanism.

### Buzzer

Provides a security alarm after repeated incorrect password attempts.

### Green LED

Indicates successful authentication and access granted.

### Red LED

Indicates an incorrect password or security lockout.

---

## 5. Authentication Logic

The system uses a stored password for authentication.

### Correct Password

When the entered password matches the stored password:

1. Access is granted.
2. Green LED turns ON.
3. Servo moves to the unlock position.
4. Failed-attempt counter is reset.
5. Auto-lock timer starts.
6. Locker automatically locks after the configured delay.

### Incorrect Password

When the entered password does not match:

1. Access is denied.
2. Red LED turns ON.
3. Failed-attempt counter increases.
4. Locker remains locked.

### Three Failed Attempts

After three consecutive incorrect attempts:

1. Security lockout is activated.
2. Locker remains locked.
3. Buzzer alarm is activated.
4. Red LED indicates the security condition.

---

## 6. Embedded Concepts Used

The project demonstrates:

- Digital Input/Output
- GPIO control
- Matrix keypad interfacing
- I2C communication
- LCD interfacing
- Servo motor control
- Timing and delays
- Conditional logic
- Password authentication
- Failed-attempt handling
- Alarm generation
- Hardware-software integration

---

## 7. Software and Libraries

### Development Tools

- Arduino IDE
- Wokwi Simulator
- Visual Studio Code
- Git
- GitHub

### Libraries

- Keypad
- LiquidCrystal I2C
- Servo

---

## 8. Security Features

The implemented system provides:

- Password authentication
- Masked password entry
- Failed-attempt counter
- Three-attempt security lockout
- Buzzer alarm
- Red LED security indication
- Green LED successful-access indication
- Automatic locking

For the beginner-level simulation, the password is stored in the Arduino program.

For a real-world implementation, credential storage can be improved using secure storage mechanisms.

---

## 9. Circuit and Pin Configuration

The complete circuit connections are documented in:

`circuit_diagram/Circuit_Connections.md`

The main pin configuration is:

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

---

## 10. Simulation

The complete system was implemented and tested using the Wokwi simulation environment.

The simulated system contains:

- Arduino UNO
- 4x4 Matrix Keypad
- 16x2 I2C LCD
- Servo Motor
- Buzzer
- Green LED
- Red LED

The simulation was used to verify the major functional and security features of the system.

---

## 11. Testing

Testing was performed using the Wokwi simulation environment.

The following functions were tested:

- Correct password
- Wrong password
- Password masking
- Password clearing
- Failed-attempt counter
- Three consecutive failed attempts
- Security lockout
- Servo unlocking
- Automatic locking
- Buzzer alarm
- Green LED indication
- Red LED indication
- LCD messages
- Complete system integration

Detailed test results are available in:

`reports/TESTING.md`

**Overall Test Result: PASS**

---

## 12. Error Handling and Debugging

The Wokwi Serial Monitor and LCD output were used during development and debugging.

The following areas were verified:

- Keypad input
- Password authentication
- LCD messages
- Failed-attempt counter
- Servo lock/unlock behavior
- Auto-lock timing
- Buzzer alarm
- LED status indication

---

## 13. Performance Observations

The system was observed to provide:

- Immediate keypad response
- Immediate LCD feedback
- Immediate password verification
- Immediate servo response
- Buzzer activation after the third failed attempt
- Automatic locking after the configured delay
- Stable operation during simulation

---

## 14. Future Improvements

Possible future improvements include:

- RFID authentication
- Fingerprint authentication
- Vibration/tamper detection
- GSM-based security alerts
- Wi-Fi connectivity
- Secure credential storage
- Access logging
- Database integration
- Mobile application
- Remote locker monitoring

These are future extensions and are not claimed as implemented features of the current Wokwi version.

---

## 15. Project Outcome

The Anti-Theft Locker System successfully demonstrates how an Arduino-based embedded controller can be used to create an electronic locker security system.

The project integrates:

- User input
- Password authentication
- LCD feedback
- Servo-based locking
- Failed-attempt detection
- Alarm generation
- LED status indication
- Automatic locking

The complete core system was integrated and successfully tested in the Wokwi simulation environment.