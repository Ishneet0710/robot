
#include <Servo.h>

const int trigpin = 11;
const int echopin = 12;
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

  
}

void loop() {

  bool automated = 1; // change to 0 after 30 seconds (upon a press of a button?)


  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  

  //automated period
  while (automated){

     // if (button_pressed) {automated = 0; break;}
    duration = pulseIn(echopin, HIGH);
    distance = duration * 0.034 / 2;
  
    
    Serial.print("Distance: ");
    Serial.println(distance);
  
    if(distance >= 10 and distance <= 15){
      for (int i = 0; i < 11; ++i){ //scoop up ball
        scoop.write(i*10);
        delay(75);
      }
      delay(1500);
      scoop.write(0); // wait 1.5 second, then scoop back down
      continue; // back to start of while loop
    }
  }

  //manual period
  
}
