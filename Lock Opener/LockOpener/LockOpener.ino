#include <PWMServo.h>
#include <LiquidCrystal.h>

// Setup the servo objects
PWMServo servoLatch;

const int servoPin = 9;
const int servoLockPosition = 15;
const int servoUnlockPosition = 120;

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  lcd.begin(16, 2);
  
  servoLatch.attach(SERVO_PIN_A);
  servoLatch.write(servoUnlockPosition);
}

void loop() {
  // put your main code here, to run repeatedly:
  servoLatch.write(servoLockPosition);
  printLcd("Locked");
  delay(2000);
  
  servoLatch.write(servoUnlockPosition);
  printLcd("Unlocked");
  delay(2000);
}

void printLcd(String message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
}

