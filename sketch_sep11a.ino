#include <Servo.h>

Servo myServo;

const int ldrNorth = A0;
const int ldrSouth = A1;
const int ldrEast = A2;
const int ldrWest = A3;

const int motorPin1 = 6;
const int motorPin2 = 7;
const int enablePin = 5;  // Connect ENA of L298N to pin 7

const int servoPin = 9;  // Define the servo pin

void setup() {
  myServo.attach(servoPin);
  myServo.write(80);   // Set initial angle of servo to 130 degrees (within the limit)
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  // Start with the motor disabled
  digitalWrite(enablePin, LOW);
  
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int northValue = analogRead(ldrNorth);
  int southValue = analogRead(ldrSouth);
  int eastValue = analogRead(ldrEast);
  int westValue = analogRead(ldrWest);
  
  // Print LDR readings to Serial Monitor
  Serial.print("North: ");
  Serial.print(northValue);
  Serial.print(" | South: ");
  Serial.print(southValue);
  Serial.print(" | East: ");
  Serial.print(eastValue);
  Serial.print(" | West: ");
  Serial.println(westValue);

  int verticalDifference = northValue - southValue;
  int horizontalDifference = eastValue - westValue;

  // Vertical adjustment using Servo (for tilt)
  if (abs(verticalDifference) > 50) {
    int tiltAngle = map(verticalDifference, -1023, 1023, 0, 110);  // Limit servo angle between 75 and 130 degrees
    tiltAngle = constrain(tiltAngle, 0, 180);  // Ensure servo angle is within range
    myServo.write(tiltAngle);
  }

  // Horizontal adjustment using DC motor (for rotation)
  if (abs(horizontalDifference) > 150) {
    digitalWrite(enablePin, HIGH);  // Enable the motor driver
    
    if (horizontalDifference > 0) {
      digitalWrite(motorPin1, HIGH);  // Rotate clockwise
      digitalWrite(motorPin2, LOW);
    } else {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);  // Rotate counterclockwise
    }
  } else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(enablePin, LOW);    // Disable the motor driver
  }
  
  delay(1000);  // Adjust the delay to suit your needs
}
