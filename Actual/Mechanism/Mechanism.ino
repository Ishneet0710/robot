
#include <Servo.h>

const int trigpin = 11;
const int echopin = 12;
long duration;
int distance;


Servo scoop;  
Servo backdoor;  

void reset_scoop(int sugma){
  scoop.write(0);
  delay(sugma);
  return;
}

void scoop_ball(int alfa){
  for (int i = 0; i < 11; ++i){
    scoop.write(i*10);
    delay(47+3*i);
  }
  delay(alfa);
  return;
}

void trigger_backdoor(int bita){
  backdoor.write(90);
  delay(bita);
  return;
}

void reset_backdoor(int gahma){
  backdoor.write(180);
  delay(gahma);
  return;
}


//void cock{bool balls}{ // balls is 0 if turn left & 1 if turn right
//  if (balls) {
//    turn right
//  }
//  else {
//    turn left
//  }
//}

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
  backdoor.attach(9);
  backdoor.write(180);
  scoop.attach(8);
  scoop.write(0);
  delay(3000);
    for (int i = 0; i < 2; ++i){
    scoop_ball(2000);
    reset_scoop(5000);}
    trigger_backdoor(3000);
    reset_backdoor(1000);
}


void loop() {

//  bool automated = 1; // change to 0 after 30 seconds (upon a press of a button?)


//  
//  digitalWrite(trigpin, LOW);
//  delayMicroseconds(2);
//
//  digitalWrite(trigpin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigpin, LOW);


  

//  //automated period
//  while (automated){
//
//     // if (button_pressed) {automated = 0; break;}
//    duration = pulseIn(echopin, HIGH);
//    distance = duration * 0.034 / 2;
//  
//    
//    Serial.print("Distance: ");
//    Serial.println(distance);
//  
//    if(distance >= 10 and distance <= 15){
//      
//  }

  //manual period
  
}
