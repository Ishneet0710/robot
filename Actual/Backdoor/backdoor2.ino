
#include <Servo.h>

Servo myservo;  

void setup() {
  myservo.attach(10);
  myservo.write(90);
}

void loop() {
}
