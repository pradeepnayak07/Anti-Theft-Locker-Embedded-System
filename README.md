# 🔐 Anti-Theft Locker System

An embedded systems-based electronic locker security system using Arduino UNO, keypad authentication, LCD display, servo-based locking, failed-attempt detection, buzzer alarm, and LED status indicators.

---

## 📌 Project Overview

The Anti-Theft Locker System is an embedded security project designed to provide password-based access control for an electronic locker.

The system uses an Arduino UNO as the main controller. A 4x4 matrix keypad is used to enter the password, while a 16x2 I2C LCD provides system feedback.

A servo motor controls the locker locking mechanism. The system also includes a buzzer and red/green LEDs for security alerts and status indication.

The complete system has been developed and tested using the Wokwi simulation environment.

---

## 🎯 Problem Statement

Traditional lockers generally depend on physical keys or basic mechanical locking mechanisms.

This project aims to develop an electronic locker security system that provides:

- Password-based authentication
- Automatic locking
- Failed-attempt detection
- Security alarm
- Visual status indication
- User-friendly LCD feedback

---

## ✨ Features

- 🔑 4x4 keypad password input
- 🔒 Password-based authentication
- ⭐ Masked password display
- 📺 16x2 I2C LCD
- ⚙️ Servo-based locker mechanism
- ⏱️ Automatic locking
- 🚨 Failed-attempt detection
- 🔔 Buzzer security alarm
- 🟢 Green LED for successful access
- 🔴 Red LED for failed access
- 🔐 Three-attempt security lockout
- 🖥️ Serial Monitor debugging
- 🧪 Complete Wokwi simulation

---

## 🧰 Components

| Component | Purpose |
|---|---|
| Arduino UNO | Main microcontroller |
| 4x4 Matrix Keypad | Password input |
| 16x2 I2C LCD | Display and user feedback |
| Servo Motor | Locker locking mechanism |
| Buzzer | Security alarm |
| Green LED | Access granted indication |
| Red LED | Access denied indication |
| Resistors | LED current limiting |

---

## 💻 Technologies and Tools

- Arduino C/C++
- Arduino IDE
- Arduino UNO
- Wokwi Simulator
- Visual Studio Code
- Git
- GitHub

### Libraries

- Keypad
- LiquidCrystal I2C
- Servo

---

## 🧠 Embedded Concepts Used

This project demonstrates:

- Digital Input/Output
- GPIO control
- Matrix keypad interfacing
- I2C communication
- LCD interfacing
- Servo motor control
- Timing and delays
- Conditional statements
- Password authentication
- Failed-attempt handling
- Alarm generation
- Hardware-software integration

---

## 🏗️ System Architecture

```text
                 ┌─────────────────┐
                 │   4x4 Keypad    │
                 └────────┬────────┘
                          │
                          ▼
                ┌───────────────────┐
                │    Arduino UNO    │
                │   Main Controller │
                └─────┬─────┬───────┘
                      │     │
          ┌───────────┘     └───────────┐
          ▼                             ▼
   ┌──────────────┐              ┌──────────────┐
   │ 16x2 I2C LCD │              │ Servo Motor  │
   └──────────────┘              └──────────────┘
          │
          ├───────────────┐
          ▼               ▼
   ┌────────────┐   ┌────────────┐
   │ Green LED  │   │  Red LED   │
   └────────────┘   └─────┬──────┘
                           │
                           ▼
                     ┌──────────┐
                     │  Buzzer  │
                     └──────────┘
                     
---

## 🔌 Circuit Connections

### 4x4 Keypad

| Keypad Pin | Arduino UNO Pin |
|---|---|
| R1 | D9 |
| R2 | D8 |
| R3 | D7 |
| R4 | D6 |
| C1 | D5 |
| C2 | D4 |
| C3 | D3 |
| C4 | D2 |

### 16x2 I2C LCD

| LCD Pin | Arduino UNO Pin |
|---|---|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

### Servo Motor

| Servo Pin | Arduino UNO Pin |
|---|---|
| Signal | D10 |
| VCC | 5V |
| GND | GND |

### Buzzer

| Buzzer Pin | Arduino UNO Pin |
|---|---|
| Positive (+) | D11 |
| Negative (-) | GND |

### LEDs

| Component | Arduino UNO Pin |
|---|---|
| Green LED | D12 through resistor |
| Red LED | D13 through resistor |

For complete wiring details, see:

[`Circuit_Connections.md`](circuit_diagram/Circuit_Connections.md)

---

## 🔐 Authentication Logic

### Correct Password

```text
Enter Password
      ↓
Password Verification
      ↓
Access Granted
      ↓
Green LED ON
      ↓
Servo Unlocks
      ↓
Auto-Lock Timer
      ↓
Servo Locks
```

### Wrong Password

```text
Wrong Password
      ↓
Access Denied
      ↓
Failed Attempt +1
      ↓
Red LED ON
```

### Three Wrong Attempts

```text
Third Wrong Attempt
        ↓
Security Lockout
        ↓
Locker Remains Locked
        ↓
Buzzer Alarm
        ↓
Red LED ON
```

---

## 📁 Project Structure

```text
Anti_Theft_Locker_Embedded_System/
│
├── src/
│   └── .gitkeep
│
├── arduino_code/
│   └── AntiTheftLocker/
│       └── AntiTheftLocker.ino
│
├── simulation/
│   └── README.md
│
├── circuit_diagram/
│   ├── Anti-Theft_Locker.png
│   └── Circuit_Connections.md
│
├── outputs/
│   └── .gitkeep
│
├── screenshots/
│   ├── S1_project_structure.png
│   ├── S2_keypad_working.png
│   ├── S3_password_correct.png
│   ├── S4_password_wrong.png
│   ├── S5_lcd_enter_password.png
│   ├── S6_first_failed_attempt.png
│   ├── S7_second_failed_attempt.png
│   ├── S8_third_failed_attempt.png
│   ├── S9_servo_locker_unlocked.png
│   ├── S10_auto_lock_locker_locked.png
│   ├── S11_buzzer_security_alarm.png
│   ├── S12_green_led_access_granted.png
│   ├── S13_red_led_access_denied.png
│   └── S14_complete_wokwi_circuit.png
│
├── reports/
│   └── TESTING.md
│
├── docs/
│   └── PROJECT_DOCUMENTATION.md
│
├── README.md
└── .gitignore
```

---

## 🧪 Testing

The system was tested using the Wokwi simulation environment.

| Test Case | Result |
|---|---|
| Correct Password | PASS |
| Wrong Password | PASS |
| Password Masking | PASS |
| Password Clear | PASS |
| Failed Attempt Counter | PASS |
| Three Failed Attempts | PASS |
| Security Lockout | PASS |
| Servo Unlock | PASS |
| Auto-Lock | PASS |
| Buzzer Alarm | PASS |
| Green LED | PASS |
| Red LED | PASS |
| LCD Messages | PASS |
| Complete Integration | PASS |

Detailed testing information is available in:

[`TESTING.md`](reports/TESTING.md)

---

## 🖥️ Wokwi Simulation

The project was implemented and tested using the Wokwi simulation environment.

### Simulated Components

- Arduino UNO
- 4x4 Matrix Keypad
- 16x2 I2C LCD
- Servo Motor
- Buzzer
- Green LED
- Red LED

The simulation verifies:

- Password authentication
- Wrong-password detection
- Failed-attempt counting
- Three-attempt security lockout
- Servo unlocking
- Automatic locking
- Buzzer alarm
- LED status indication
- LCD messages
- Complete system integration

More information:

[`simulation/README.md`](simulation/README.md)

---

## 📸 Screenshots

Project screenshots and simulation evidence are available in the [`screenshots`](screenshots/) directory.

The screenshots demonstrate:

- Project structure
- Keypad operation
- Correct password
- Wrong password
- LCD password entry
- Failed attempts
- Servo unlocking
- Automatic locking
- Buzzer security alarm
- Green LED
- Red LED
- Complete Wokwi circuit

---

## 📚 Documentation

Additional documentation:

- [Circuit Connections](circuit_diagram/Circuit_Connections.md)
- [Testing Report](reports/TESTING.md)
- [Project Documentation](docs/PROJECT_DOCUMENTATION.md)
- [Simulation Documentation](simulation/README.md)

---

## 🔮 Future Improvements

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

These features are considered future extensions and are not claimed as implemented features of the current Wokwi version.

---

## 🌍 Industry Relevance

Electronic access-control systems can be applied in:

- Smart lockers
- Offices
- Banks
- Hotels
- Educational institutions
- Warehouses
- Industrial security systems
- Smart homes

This project demonstrates practical embedded-system concepts related to electronic access control and security.

---

## 🎓 Learning Outcomes

This project helped develop practical knowledge of:

- Arduino programming
- Embedded C/C++
- Keypad interfacing
- I2C communication
- LCD interfacing
- Servo motor control
- Authentication logic
- Security-system design
- Debugging
- Wokwi simulation
- Git and GitHub

---

## 👨‍💻 Author

**Pradeep Nayak**

B.Tech - Computer Science and Engineering

---

## 📌 Project Status

**Completed and tested successfully in Wokwi simulation.**

The core Anti-Theft Locker System features have been implemented, integrated and tested successfully.