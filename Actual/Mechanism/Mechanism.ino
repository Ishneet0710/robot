#include <Servo.h>

//const int trigpin = 11;
//const int echopin = 12;
long duration;
int distance;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int motor3pin1 = 6;
int motor3pin2 = 7;

int motor4pin1 = 8;
int motor4pin2 = 9;


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
  backdoor.write(84);
  delay(bita);
  return;
}

void reset_backdoor(int gahma){
  backdoor.write(180);
  delay(gahma);
  return;
}

void forward(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  //delay(1000);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  //delay(dulta);
}

void please_stop_i_want_to_die(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  //delay(1000);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
}


void setup() {
//  pinMode(trigpin, OUTPUT);
//  pinMode(echopin, INPUT);
  Serial.begin(9600);
  backdoor.attach(12);
  backdoor.write(180);
  scoop.attach(11);
  scoop.write(0);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  //forward(1000);
  delay(2000);
  for (int i = 0; i < 2; ++i){//change to 3 later
    forward();
    delay(2000);
    please_stop_i_want_to_die();
    //delay(500);
    scoop_ball(2000);
    reset_scoop(1500);
    }
    trigger_backdoor(3000);
    reset_backdoor(500);
    forward();
    delay(2000);
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
