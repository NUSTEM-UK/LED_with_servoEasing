// Very simple demo of simultaneous blinking LED and (interupt-driven) servo movement.

#include <Arduino.h>
#include <ServoEasing.h>

#define LED_PIN 5
#define SERVO_PIN 8

ServoEasing servo1;
bool servoToggle;

void checkServo() {
    Serial.println("Checking servo...");
    if (!servo1.isMoving()) {
        servoToggle = !servoToggle;
        servo1.startEaseTo(servoToggle ? 0 : 180);
        Serial.print("Servo moving to: ");
        Serial.println(servoToggle ? 0 : 180);
    }
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting...");
    pinMode(LED_PIN, OUTPUT);
    servo1.attach(SERVO_PIN);
    servo1.write(90);
    servo1.setSpeed(60);
    servo1.setEasingType(EASE_CUBIC_IN_OUT);
    servoToggle = true;
    delay(500);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    checkServo();
    delay(500);
    digitalWrite(LED_PIN, LOW);
    checkServo();
    delay(500);
}

