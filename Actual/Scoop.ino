
#include <Servo.h>

Servo myservo;  

void setup() {
  myservo.attach(8);
  myservo.write(0);
  delay(2000);
  myservo.write(120);

}

void loop() {
}
