// C++ code
//
#include <Servo.h>

int _E0_B8_B5ultrasonic = 0;

int Ultrasonic = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_2;

Servo servo_3;

void setup()
{
  servo_2.attach(2, 500, 2500);
  servo_3.attach(3, 500, 2500);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Ultrasonic = 0.01723 * readUltrasonicDistance(7, 6);
  if (Ultrasonic >= 50) {
    servo_2.write(0);
    servo_3.write(180);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  } else {
    if (Ultrasonic <= 50) {
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      servo_2.write(80);
      servo_3.write(80);
      digitalWrite(8, HIGH);
    }
  }
  Serial.println(Ultrasonic);
  delay(10); // Delay a little bit to improve simulation performance
}
