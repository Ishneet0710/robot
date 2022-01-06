int sensor1 = 1;
int sensor2 = 2; //front 2

void setup(){
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  
  
}

void loop(){
  int value_s1 = digitalRead(sensor1); //left
  int value_s2 = digitalRead(sensor2); //right
  Serial.print(value_s1);
  Serial.print("     ");
  Serial.println(value_s2);

  if(value_s1 == 1 and value_s2 == 1){
    //niuu forwards or backwards
  }
  if(value_s1 == 0 and value_s2 == 1){
    //turn left
  }

  else if(value_s1 == 1 and value_s2 == 0){
    //turn right
  }

  

  
  
}
