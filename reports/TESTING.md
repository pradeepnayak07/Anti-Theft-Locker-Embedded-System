# Anti-Theft Locker System - Testing Report

## 1. Testing Overview

The Anti-Theft Locker System was tested using Wokwi simulation.

The testing focused on:
- Keypad input
- Password authentication
- LCD display
- Wrong-attempt detection
- Security lockout
- Servo lock/unlock
- Automatic locking
- Buzzer alarm
- Red and green LED indicators
- Complete system integration

---

## 2. Test Environment

### Simulation Platform
Wokwi

### Controller
Arduino UNO

### Input Device
4x4 Matrix Keypad

### Display
16x2 I2C LCD

### Locking Mechanism
Servo Motor

### Security Alert
Buzzer

### Status Indicators
- Green LED
- Red LED

---

## 3. Test Cases

| Test ID | Test Case | Input/Action | Expected Result | Status |
|---|---|---|---|---|
| TC01 | Correct Password | Enter `1234#` | Access Granted and locker unlocks | PASS |
| TC02 | Wrong Password | Enter incorrect password | Access Denied and failed attempt increases | PASS |
| TC03 | Second Wrong Attempt | Enter wrong password twice | Failed attempt counter reaches 2 | PASS |
| TC04 | Third Wrong Attempt | Enter wrong password three times | Locker remains locked and security alarm activates | PASS |
| TC05 | Password Clear | Press `*` | Entered password is cleared | PASS |
| TC06 | Password Masking | Enter password digits | LCD displays `*` instead of actual digits | PASS |
| TC07 | Servo Unlock | Enter correct password | Servo moves to unlock position | PASS |
| TC08 | Servo Lock | Auto-lock timer expires | Servo returns to locked position | PASS |
| TC09 | Auto-Lock | Keep locker unlocked | Locker automatically locks after configured time | PASS |
| TC10 | Buzzer Alarm | Three consecutive wrong passwords | Buzzer activates as security alert | PASS |
| TC11 | Green LED | Enter correct password | Green LED turns ON | PASS |
| TC12 | Red LED | Enter wrong password | Red LED turns ON | PASS |
| TC13 | LCD Authentication | Enter correct/incorrect password | LCD displays appropriate authentication message | PASS |
| TC14 | Complete Integration | Operate complete system | Keypad, LCD, authentication, LEDs, servo and buzzer work together | PASS |
| TC15 | System Restart | Restart simulation | System starts in locked state | PASS |

---

## 4. Unit Testing

Individual modules were tested separately during development.

### Keypad
The keypad was tested by pressing different keys and verifying that the correct key values appeared in the Serial Monitor.

**Result:** PASS

### Password Authentication
The stored password was tested with both correct and incorrect inputs.

**Result:** PASS

### LCD
The LCD was tested for password prompts, access messages and locker status.

**Result:** PASS

### Servo
The servo was tested for both locked and unlocked positions.

**Result:** PASS

### Buzzer
The buzzer was tested after three consecutive failed authentication attempts.

**Result:** PASS

### LEDs
The green and red LEDs were tested for successful and failed authentication states.

**Result:** PASS

---

## 5. Integration Testing

All major modules were combined and tested as a single system.

The following interactions were verified:

1. Keypad accepts password input.
2. Password input is masked on the LCD.
3. Correct password grants access.
4. Green LED indicates successful authentication.
5. Servo unlocks the locker.
6. Auto-lock timer starts.
7. Servo automatically returns to the locked position.
8. Wrong password increases the failed-attempt counter.
9. Red LED indicates failed authentication.
10. Three failed attempts activate the security lockout.
11. Buzzer activates during the security alarm.
12. LCD displays the appropriate system status.

**Integration Test Result: PASS**

---

## 6. System Testing

The complete Anti-Theft Locker System was tested in Wokwi as an end-to-end system.

### Successful Authentication Flow

```text
Enter Password
      ↓
Enter 1234#
      ↓
Access Granted
      ↓
Green LED ON
      ↓
Servo Unlocks
      ↓
Locker Open
      ↓
Auto-Lock Timer
      ↓
Servo Locks
      ↓
Locker Locked
---

## Failed Authentication Flow

```text
Enter Wrong Password
        ↓
Access Denied
        ↓
Failed Attempt +1
        ↓
Red LED ON
        ↓
Three Failed Attempts
        ↓
Security Lockout
        ↓
Buzzer Alarm
        ↓
Locker Remains Locked
```

**System Test Result: PASS**

---

## 7. User Acceptance Testing (UAT)

The system behavior was checked from a basic user perspective.

### User should be able to:

- Enter a password using the keypad.
- See masked password characters.
- Clear the entered password.
- Receive access after entering the correct password.
- See access denied after entering an incorrect password.
- Understand locker status through the LCD.
- Identify successful access using the green LED.
- Identify failed access using the red LED.
- Observe automatic locker locking.
- Receive an alarm after repeated incorrect attempts.

**UAT Result: PASS**

---

## 8. Error Handling and Debugging

During development, the system was debugged using the Wokwi Serial Monitor and LCD output.

The following issues were identified and resolved:

- Keypad library dependency
- LCD library dependency
- Servo library dependency
- Keypad input verification
- Password authentication logic
- Failed-attempt counter
- Servo lock/unlock behavior
- Auto-lock timing
- Buzzer alarm behavior
- LED status indication

Serial Monitor messages were used to verify internal system states during testing.

---

## 9. Security Testing

The security mechanism was tested using repeated incorrect passwords.

### Security Conditions

- Correct password → Access Granted
- Incorrect password → Access Denied
- Failed attempts are counted
- Three consecutive failed attempts → Security lockout
- Buzzer activates after the third failed attempt
- Locker remains locked during lockout
- Correct authentication resets the failed-attempt counter

**Security Test Result: PASS**

---

## 10. Performance Observations

| Metric | Observation |
|---|---|
| Keypad Response | Immediate |
| LCD Response | Immediate |
| Password Verification | Immediate |
| Servo Response | Immediate |
| Buzzer Activation | Triggered after third failed attempt |
| Auto-Lock | Activated after configured delay |
| System Stability | Stable during simulation |

---

## 11. Final Testing Result

The Anti-Theft Locker System successfully completed functional testing in the Wokwi simulation environment.

### Overall Result

**PROJECT TEST STATUS: PASS**

The major functional modules including keypad authentication, LCD display, failed-attempt detection, servo locking, automatic locking, buzzer alarm and LED indicators were successfully integrated and tested.