//Include required libraries
#include <PPMReader.h>
#include <Servo.h>

//Instantiate servo motor objects, names can be changed
//Servo servo_Name;
Servo backdoor;
Servo scoop_grey;
Servo scoop_black;

//Global Pins Assignment for motor pins, and motor enable pins
//IN1-IN4 pins can be connected to both digital and analog pins
//EN1-EN2 pins to be connected to D3, D5, D6, D9, D10, or D11
//const int pin_Name = pin_Number;
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

//Controller settings, do not change
byte interruptPin = 3;
byte channelAmount = 8;
PPMReader ppm(interruptPin, channelAmount);

//Initialize global variables
//These are used in the calculation for the robot's wheel speed
//when it is turning left/right
int turn_Speed = 0;
int L_Speed = 0;
int R_Speed = 0;
bool Dir = true; //Forward = true, Backward = false



void setup() {
  //Assign servo motors to pins, can be any digital pins
  //ServoName.attach(pin_Number);
  Scoop.attach(11);
  Backdoor.attach(10);

  //Setting the L298N pins as output pins
  //pinMode(pin_Name, OUTPUT);
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

  //Start serial comm for troubleshooting through serial monitor
  //Serial.begin(baud rate);
  Serial.begin(115200);
}



void loop() {
  //Read controller channel values
  //In this case, channel 1 and 2 are assigned to the right
  //stick and left stick respectively
  //int channel_Name = readChannel(channel_Number);
  int c1 = readChannel(1);
  int c2 = readChannel(2);
  int c3 = readChannel(3);
  int c4 = readChannel(4);
  int c5 = readChannel(5);

  //If the left stick is pushed down, wheels on both sides will
  //rotate forward. Speed of both sides will be calculated
  //with the "speed_Check" function.
  if (c2 >= 1000 and c2 < 1450) {
    backward();
    Dir = false;
    speed_Check(Dir, c2, c1, 1450, 1000);
  }
  //If the left stick is pushed up, wheels on both sides
  //will rotate backwards.
  else if (c2 <= 2000 and c2 > 1550) {
    forward();
    Dir = true;
    speed_Check(Dir, c2, c1, 1550, 2000);
  }
  //If the left stick is stationary (in the middle)
  else {
    //If the right stick is pushed left, left wheel will rotate
    //backwards, while the right wheel will rotate forward.
    //Rotation speed will be calculated using "rotate" function.
    if (c1 >= 1000 and c1 < 1450) {
      right();
      rotate(c1, 1450, 1000);
    }
    //If the right stick is pushed right,left wheel will rotate
    //forward, while the right wheel will rotate backwards.
    else if (c1 <= 2000 and c1 > 1550) {
      left();
      rotate(c1, 1550, 2000);
    }
    //If the right stick is stationary (in the middle),
    //stop the robot from moving
    else {
      stop_moving();
    }
  }

  //INSERT GRIPPER CODE HERE
  //if right stick push down backdoor move
  if (c4 >= 1000 and c4 < 1450) {
    arduinoSpeed(c4, 1450, 1000, backdoor);
  }
  //If the left stick is pushed up scoop go up
  else if (c4 <= 2000 and c4 > 1550) {
    arduinoSpeed(c4, 1550, 2000, scoop_grey);
    arduinoSpeed(c4, 1550, 2000, scoop_black);
  }
  //If the right stick is stationary (in the middle),
  //reset all scoops
  else {
    backdoor.write(90);
    scoop_grey.write(0);
    scoop_black.write(180);
   }


  //automation code

  if(c5 <=1100){
    //automation code go here
  }



  //incase mapping no work then we die
  //if(c3 <= 1100){
    //Backdoor.write(0);
  //}
  //else if(c3 > 1000){
    //Backdoor.write(84);
  //}
  //if(c4 <= 1100){
    //Scoop.write(0);
  //}
  //else if(c4 > 1000){
    //Scoop.write(120);
  //}

  delay(10);
}
