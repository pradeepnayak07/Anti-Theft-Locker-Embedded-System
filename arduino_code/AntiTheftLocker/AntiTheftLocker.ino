#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// ================= KEYPAD =================

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);

// ================= LCD =================

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ================= SERVO LOCK =================

Servo lockServo;

const int SERVO_PIN = 10;

const int LOCK_POSITION = 0;
const int UNLOCK_POSITION = 90;

// ================= BUZZER =================

const int BUZZER_PIN = 11;

// ================= LEDs =================

const int GREEN_LED_PIN = 12;
const int RED_LED_PIN = 13;

// ================= AUTO LOCK =================

const unsigned long AUTO_LOCK_TIME = 5000;

unsigned long unlockTime = 0;

bool lockerOpen = false;

// ================= PASSWORD =================

const String correctPassword = "";

String enteredPassword = "";

// ================= SECURITY =================

const int MAX_ATTEMPTS = 3;

int failedAttempts = 0;

bool lockerLocked = false;

// ================= DISPLAY =================

void showEnterPassword() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  lcd.setCursor(0, 1);
}

// ================= BUZZER ALARM =================

void activateAlarm() {

  Serial.println("BUZZER ALARM ACTIVATED");

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("SECURITY ALERT");

  lcd.setCursor(0, 1);
  lcd.print("ALARM ACTIVE");

  // Red LED ON during alarm
  digitalWrite(RED_LED_PIN, HIGH);

  // Green LED OFF
  digitalWrite(GREEN_LED_PIN, LOW);

  // Buzzer ON
  tone(BUZZER_PIN, 1000);

  delay(3000);

  // Buzzer OFF
  noTone(BUZZER_PIN);

  Serial.println("BUZZER ALARM STOPPED");
}

// ================= SETUP =================

void setup() {

  Serial.begin(9600);

  // ================= SERVO =================

  lockServo.attach(SERVO_PIN);

  lockServo.write(LOCK_POSITION);

  lockerOpen = false;

  // ================= BUZZER =================

  pinMode(BUZZER_PIN, OUTPUT);

  noTone(BUZZER_PIN);

  // ================= LEDs =================

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Both LEDs OFF initially
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  // ================= LCD =================

  lcd.init();
  lcd.backlight();

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Anti-Theft");

  lcd.setCursor(0, 1);
  lcd.print("Locker System");

  delay(2000);

  showEnterPassword();

  Serial.println("Anti-Theft Locker System");
  Serial.println("System Initializing...");
  Serial.println("Locker Locked");
  Serial.println("Enter Password:");
}

// ================= MAIN LOOP =================

void loop() {

  // ================= AUTO LOCK CHECK =================

  if (lockerOpen &&
      (millis() - unlockTime >= AUTO_LOCK_TIME)) {

    // Lock the locker
    lockServo.write(LOCK_POSITION);

    lockerOpen = false;

    // Green LED OFF
    digitalWrite(GREEN_LED_PIN, LOW);

    // Red LED OFF
    digitalWrite(RED_LED_PIN, LOW);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Locker Locked");

    Serial.println("AUTO LOCK ACTIVATED");
    Serial.println("Servo Position: 0");
    Serial.println("Locker Locked");

    delay(1500);

    showEnterPassword();
  }

  // ================= GET KEYPAD INPUT =================

  char key = keypad.getKey();

  if (!key) {
    return;
  }

  // ================= TOO MANY ATTEMPTS =================

  if (lockerLocked) {

    // Red LED remains ON
    digitalWrite(RED_LED_PIN, HIGH);

    // Green LED OFF
    digitalWrite(GREEN_LED_PIN, LOW);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Too Many");

    lcd.setCursor(0, 1);
    lcd.print("Attempts!");

    Serial.println("LOCKER LOCKED");
    Serial.println("Too Many Attempts");

    delay(1000);

    return;
  }

  // ================= PASSWORD INPUT =================

  if (key != '#' && key != '*') {

    enteredPassword += key;

    lcd.setCursor(enteredPassword.length() - 1, 1);
    lcd.print("*");

    Serial.print("*");
  }

  // ================= SUBMIT PASSWORD =================

  else if (key == '#') {

    Serial.println();

    lcd.clear();

    // ================= CORRECT PASSWORD =================

    if (enteredPassword == correctPassword) {

      failedAttempts = 0;

      // Green LED ON
      digitalWrite(GREEN_LED_PIN, HIGH);

      // Red LED OFF
      digitalWrite(RED_LED_PIN, LOW);

      // Make sure buzzer is OFF
      noTone(BUZZER_PIN);

      lcd.setCursor(0, 0);
      lcd.print("Access Granted");

      lcd.setCursor(0, 1);
      lcd.print("Locker Open");

      Serial.println("ACCESS GRANTED");
      Serial.println("Locker Unlocked");
      Serial.println("Green LED: ON");
      Serial.println("Red LED: OFF");
      Serial.println("Failed attempts reset to 0");

      // Unlock locker
      lockServo.write(UNLOCK_POSITION);

      lockerOpen = true;

      unlockTime = millis();

      Serial.println("Servo Position: 90");
      Serial.println("Locker is OPEN");
      Serial.println("Auto-lock timer started");

      delay(2000);
    }

    // ================= WRONG PASSWORD =================

    else {

      failedAttempts++;

      // Green LED OFF
      digitalWrite(GREEN_LED_PIN, LOW);

      // Red LED ON
      digitalWrite(RED_LED_PIN, HIGH);

      lcd.setCursor(0, 0);
      lcd.print("Access Denied");

      lcd.setCursor(0, 1);
      lcd.print("Attempt: ");
      lcd.print(failedAttempts);

      Serial.println("ACCESS DENIED");

      Serial.print("Failed Attempt: ");
      Serial.println(failedAttempts);

      Serial.println("Red LED: ON");

      delay(2000);

      // ================= MAXIMUM ATTEMPTS =================

      if (failedAttempts >= MAX_ATTEMPTS) {

        lockerLocked = true;

        // Keep locker locked
        lockServo.write(LOCK_POSITION);

        lockerOpen = false;

        // Red LED remains ON
        digitalWrite(RED_LED_PIN, HIGH);

        // Green LED OFF
        digitalWrite(GREEN_LED_PIN, LOW);

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Too Many");

        lcd.setCursor(0, 1);
        lcd.print("Attempts!");

        Serial.println("************************");
        Serial.println("TOO MANY ATTEMPTS");
        Serial.println("LOCKER LOCKED");
        Serial.println("Servo Position: 0");
        Serial.println("Red LED: ON");
        Serial.println("************************");

        delay(1000);

        // Activate buzzer alarm
        activateAlarm();
      }
      else {

        // After first/second wrong attempt,
        // turn red LED OFF after showing warning
        delay(500);

        digitalWrite(RED_LED_PIN, LOW);
      }
    }

    enteredPassword = "";

    if (!lockerLocked) {
      showEnterPassword();
    }
  }

  // ================= CLEAR PASSWORD =================

  else if (key == '*') {

    enteredPassword = "";

    // Keep LEDs in normal state
    if (!lockerOpen) {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
    }

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Password");

    lcd.setCursor(0, 1);
    lcd.print("Cleared");

    Serial.println();
    Serial.println("Password Cleared");

    delay(1000);

    if (!lockerLocked) {
      showEnterPassword();
    }
  }
}