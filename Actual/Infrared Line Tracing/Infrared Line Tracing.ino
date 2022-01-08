int sensor1 = 12;
int sensor2 = 13; //front 2

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

void forward(int a) {
  leftFwd();
  rightBwd();
  delay(a);
}

void backward(int a) {
  leftBwd();
  rightFwd();
  delay(a);
}

void right(int a){
  leftBwd();
  rightBwd();
  delay(a);
}

void left(int a){
  leftFwd();
  rightFwd();
  delay(a);
}

void stopmove(){
  leftStop();
  rightStop();
}

void setup(){
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  
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

}

void loop(){
  int value_s1 = digitalRead(sensor1); //left
  int value_s2 = digitalRead(sensor2); //right
  Serial.print(value_s1);
  Serial.print("     ");
  Serial.println(value_s2);


  if(value_s1 == 1 and value_s2 == 1){
    forward(1000);
  }
  else if(value_s1 == 0 and value_s2 == 1){
    left(200); //change time later
  }

  else if(value_s1 == 1 and value_s2 == 0){
    right(200); //change time later
  }

  else if(value_s1 == 0 and value_s2 == 0){
    //right(825); //this one use either one, depending on which side we start
    //left(825);
  }
  
}
