//
//  Author: Diana Avanesian
//  Sourses: Code modified from  https://sbpengineering.weebly.com/uploads/6/5/5/8/6558719/lesson_3_infrared_remote_control_car.pdf
//  Purpose: IR remote mode in smart car
//  Algorithm: If difined button on IR remote is pressed car make corresponding movement
//

#include <IRremote.h>
#define F 2239373790 // IR remoute button 
#define B 2239406430 // IR remoute button 
#define L 2239422750 // IR remoute button 
#define R 2239390110 // IR remoute button 
#define S 1671244567 // IR remoute button 

int RECV_PIN = 12;
int RW1 = 6;  //front  right wheel
int RW2 = 7;  //rear right wheel
int LW2= 8;  //rear left wheel
int LW1 = 9; //front  left wheel
int ENA=5;
int ENB=11;
int speeD=115;

IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long val;

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


void Stop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("STOP!");  
}

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
  irrecv.enableIRIn();  
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)){ 
    val = results.value;
    Serial.println(val);
    irrecv.resume();
    switch(val){
      case F:  moveForward(); //When the Forward button pressed
      break;
      case B:  moveBack();    //When the Back button pressed
      break;
      case L:  moveLeft();  //When the Left button pressed
      break;
      case R:  moveRight();  //When the Right button pressed
      break;
      case S:  Stop();      //When the Stop button pressed
      break;
      default:break;
    }
  }
} 
