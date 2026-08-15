# Wokwi Simulation

## Simulation Platform

The Anti-Theft Locker System was developed and tested using the Wokwi online Arduino simulator.

## Controller

Arduino UNO

## Simulated Components

- 4x4 Matrix Keypad
- 16x2 I2C LCD
- Servo Motor
- Buzzer
- Green LED
- Red LED

## Simulation Features Tested

The following features were tested successfully:

1. Keypad password input
2. Password masking using `*`
3. Correct password authentication
4. Incorrect password detection
5. Failed-attempt counter
6. Three-attempt security lockout
7. LCD status messages
8. Servo-based locker unlocking
9. Automatic locker locking
10. Buzzer security alarm
11. Green LED access indication
12. Red LED access-denied indication
13. Complete system integration

## Authentication Flow

```text
User enters password
        ↓
Password verification
        ↓
   ┌────┴────┐
   ↓         ↓
Correct     Wrong
   ↓         ↓
Access      Attempt
Granted     Counter +1
   ↓         ↓
Servo       Red LED
Unlock      ON
   ↓         ↓
Green LED   3 Attempts?
ON          ↓
   ↓        YES
Auto-Lock   ↓
   ↓       Alarm
Locker     + Lockout
Locked