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

void setup() {
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


void loop() {
  analogWrite(L_EN, 255);
  analogWrite(R_EN, 255);
  leftFwd();
  rightBwd();
}
