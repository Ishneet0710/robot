
#include <Servo.h>

Servo myservo;  
int pos = 0;

void setup() {
  myservo.attach(9);
  myservo.write(180);
  delay(2000);
  myservo.write(90);
}

void loop() {
}
