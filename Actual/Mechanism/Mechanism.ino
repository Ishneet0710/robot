#include <Servo.h>

//const int trigpin = 11;
//const int echopin = 12;
long duration;
int distance;

const int FL_FwdPin = A4;
const int FL_BwdPin = A5;
const int BL_FwdPin = 13;
const int BL_BwdPin = 12;
const int L_EN = 5;
const int FR_FwdPin = A3;
const int FR_BwdPin = A2;
const int BR_FwdPin = A1;
const int BR_BwdPin = A0;
const int R_EN = 6;

void leftFwd() {
  digitalWrite(FL_FwdPin, HIGH);
  digitalWrite(FL_BwdPin, LOW);
  digitalWrite(BL_FwdPin, HIGH);
  digitalWrite(BL_BwdPin, LOW);
}

void leftBwd() {
  digitalWrite(FL_FwdPin, LOW);
  digitalWrite(FL_BwdPin, HIGH);
  digitalWrite(BL_FwdPin, LOW);
  digitalWrite(BL_BwdPin, HIGH);
}

void leftStop() {
  digitalWrite(FL_FwdPin, LOW);
  digitalWrite(FL_BwdPin, LOW);
  digitalWrite(BL_FwdPin, LOW);
  digitalWrite(BL_BwdPin, LOW);
}


void rightFwd() {
  digitalWrite(FR_FwdPin, HIGH);
  digitalWrite(FR_BwdPin, LOW);
  digitalWrite(BR_FwdPin, HIGH);
  digitalWrite(BR_BwdPin, LOW);
}

void rightBwd() {
  digitalWrite(FR_FwdPin, LOW);
  digitalWrite(FR_BwdPin, HIGH);
  digitalWrite(BR_FwdPin, LOW);
  digitalWrite(BR_BwdPin, HIGH);
}

void rightStop() {
  digitalWrite(FR_FwdPin, LOW);
  digitalWrite(FR_BwdPin, LOW);
  digitalWrite(BR_FwdPin, LOW);
  digitalWrite(BR_BwdPin, LOW);
}


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
    delay(40+3*i);
  }
  delay(alfa);
  return;
}

void trigger_backdoor(int bita){
  backdoor.write(84);
  delay(bita);
  return;
}

void reset_backdoor(int gahma){
  backdoor.write(180);
  delay(gahma);
  return;
}

void forward(int a) {
  leftFwd();
  rightBwd();
  delay(a);
}

void backward(int b) {
  leftBwd();
  rightFwd();
  delay(b);
}

void right(int c){
  leftBwd();
  rightBwd();
  delay(c); //takes about 825ms to turn 90 degrees
}

void left(int d){
  leftFwd();
  rightFwd();
  delay(d); //takes about 825ms to turn 90 degrees
}

void please_stop_i_want_to_die(){
  leftStop();
  rightStop();
}


void setup() {
//  pinMode(trigpin, OUTPUT);
//  pinMode(echopin, INPUT);
  Serial.begin(9600);
  backdoor.attach(10);
  backdoor.write(180);
  scoop.attach(11);
  scoop.write(0);
  pinMode(FL_FwdPin, OUTPUT);
  pinMode(FL_BwdPin, OUTPUT);
  pinMode(BL_FwdPin, OUTPUT);
  pinMode(BL_BwdPin, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(FR_FwdPin, OUTPUT);
  pinMode(FR_BwdPin, OUTPUT);
  pinMode(BR_FwdPin, OUTPUT);
  pinMode(BR_BwdPin, OUTPUT);
  pinMode(R_EN, OUTPUT);
  //forward(1000);
  delay(5000);
  for (int i = 0; i < 3; ++i){
    forward(2000);
    please_stop_i_want_to_die();
    //delay(500);
    scoop_ball(2000);
    reset_scoop(1500);
    }
    trigger_backdoor(3000);
    reset_backdoor(500);
    forward(2000);
    please_stop_i_want_to_die();
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
  // what in the actual fuck
  
}
