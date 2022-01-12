
#include <Servo.h>

Servo myservo;  

void setup() {
  myservo.attach(10);
  myservo.write(90);
  delay(2000);
  myservo.write(17);
}

void loop() {
}
