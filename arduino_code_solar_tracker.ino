/* Solar Tracking System
   Home Page
*/

#include <Servo.h>  // Include the servo motor library

#define LDR1 A0     // Define LDR sensor pins
#define LDR2 A1
#define error 10    // Define error threshold

int Spoint = 90;   // Starting point of the servo motor
Servo servo;       // Create a servo motor object

void setup() {
  servo.attach(11);   // Attach servo to PWM pin 11
  servo.write(Spoint); // Set initial position of the servo
  delay(1000);         // Delay for stability
}

void loop() {
  int ldr1 = analogRead(LDR1);   // Read LDR sensor 1
  int ldr2 = analogRead(LDR2);   // Read LDR sensor 2

  int value1 = abs(ldr1 - ldr2); // Calculate difference between sensor readings
  int value2 = abs(ldr2 - ldr1);

  if (value1 > error && value2 > error) { // Check if difference exceeds error threshold
    if (ldr1 > ldr2) {
      Spoint--;   // Adjust servo position based on sensor comparison
    } else if (ldr1 < ldr2) {
      Spoint++;
    }
  }

  servo.write(Spoint);  // Set servo position
  delay(80);            // Small delay for servo movement
}