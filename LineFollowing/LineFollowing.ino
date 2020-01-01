//
//  Author: Diana Avanesian
//  Sourses: Code modified from https://sbpengineering.weebly.com/uploads/6/5/5/8/6558719/lesson_5_line_tracking_car.pdf
//  Purpose: Line following mode in smart car
//

#define LT1 digitalRead(10)// Line following sensor 1
#define LT2 digitalRead(4) // Line following sensor 2
#define LT3 digitalRead(2) // Line following sensor 3

#define ENA 5
#define ENB 11
#define RW1 6  //front  right wheel
#define RW2 7  //rear right wheel
#define LW2 8  //rear left wheel
#define LW1 9  //front  left wheel

#define speeD 115

// Making car move straight by making two rear wheels move
void moveForward()
{
 analogWrite(ENA,speeD);
 analogWrite(ENB,speeD);
  digitalWrite(RW1,LOW);
  digitalWrite(RW2,HIGH);
  digitalWrite(LW2,HIGH);
  digitalWrite(LW1,LOW);
}

// Making car move back by making two front wheels move
void moveBack()
{
 analogWrite(ENA,speeD);
 analogWrite(ENB,speeD);
  digitalWrite(RW1,HIGH);
  digitalWrite(RW2,LOW);
  digitalWrite(LW2,LOW);
  digitalWrite(LW1,HIGH);
}

// Making car turn left by making front right wheel and rear left wheel move
void moveLeft()
{
 analogWrite(ENA,speeD);
 analogWrite(ENB,speeD);
  digitalWrite(RW1,HIGH);
  digitalWrite(RW2,LOW);
  digitalWrite(LW2,HIGH);
  digitalWrite(LW1,LOW); 
}

// Making car turn rigth by making rear right wheel and  front  left wheel move
void moveRight()
{
 analogWrite(ENA,speeD);
 analogWrite(ENB,speeD);
  digitalWrite(RW1,LOW);
  digitalWrite(RW2,HIGH);
  digitalWrite(LW2,LOW);
  digitalWrite(LW1,HIGH);
} 

void stop(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
} 

void setup(){
  Serial.begin(9600);
}

void loop() {
 //If middle sensor sensing black line go forward
  if(LT2){
    forward();
  }
 //If left sensor sensing black line turn left
  else if(LT1) {
    left();
    //Do that as long as sensor still sensing black line
    while(LT1);                             
  }   
 //If right sensor sensing black line turn right
  else if(LT3) {
    right();
    //Do that as long as sensor still sensing black line
    while(LT3);  
  }
}
