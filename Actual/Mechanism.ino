
#include <Servo.h>

const int trigpin = 9;
const int echopin = 10;
long duration;
int distance;


Servo scoop;  
Servo backdoor;  

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
  backdoor.attach(9);
  backdoor.write(180);
  scoop.attach(8);
  scoop.write(0);
  delay(3000);

  if(distance > 10 && distance < 15){
    for (int i = 0; i < 11; ++i){
      scoop.write(i*10);
      delay(75);
    }
    
      //  scoop.write(80);
      //  delay(1000);
      //  scoop.write(120);
    
    delay(3000);
    backdoor.write(90);
  }
  
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;

}
