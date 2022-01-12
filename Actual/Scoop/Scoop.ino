
#include <Servo.h>

Servo grey; //left
Servo black; //right

void setup() {
  grey.attach(9);
  black.attach(11);
  black.write(80);
  grey.write(90);

  delay(2000);

  black.write(180);
  grey.write(0);
  
}

void loop() {

}
