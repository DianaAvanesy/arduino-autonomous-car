//
//  Author: Diana Avanesian
//  Sourses: Code modified from https://sbpengineering.weebly.com/uploads/6/5/5/8/6558719/lesson_4_obstacle_avoidance_car.pdf
//  Purpose: Obticle avoiding mode in smart car
//  Algorithm: If the car facing object on the left side, its moving right. If car facing object on the right side its moving left. If car facing objects on the left and right sides its moving back;
//

#include <Servo.h> 
Servo myservo; 
int Echo = A4;  
int Trig = A5; 
int RW1 = 6;  //front  right wheel
int RW2 = 7;  //rear right wheel
int LW2= 8;  //rear left wheel
int LW1 = 9; //front  left wheel
int ENA = 5;
int ENB =11;
int speeD = 150;
int rightDistance = 0;
int leftDistance = 0;
int middleDistance = 0 ;

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
void Stop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
} 
 //Ultrasonic distance measurement function
int Distance_test()   
{
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance/58;       
  return (int)Fdistance;
}  

void setup() 
{ 
  myservo.attach(3);
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  Stop();
} 

void loop() 
{ 
    myservo.write(60);//setservo center position 
    delay(500); 
    middleDistance = Distance_test(); 
    #ifdef send
    Serial.print("middleDistance=");
    Serial.println(middleDistance);
    #endif

    if(middleDistance<=20)
    {     
      Stop();
      delay(500);     
      myservo.write(10);//10°-180°          
      delay(1000);      
      rightDistance = Distance_test();

      #ifdef send
      Serial.print("rightDistance=");
      Serial.println(rightDistance);
      #endif

      delay(500);
       myservo.write(60);              
      delay(1000);                                                  
      myservo.write(120);              
      delay(1000); 
      leftDistance = Distance_test();

      #ifdef send
      Serial.print("leftDistance=");
      Serial.println(leftDistance);
      #endif

      delay(500);
      myservo.write(60);              
      delay(1000);
      
      if(rightDistance>leftDistance)  
      {
        moveRight();
        delay(360);
       }
       else if(rightDistance<leftDistance)
       {
        moveLeft();
        delay(360);
       }
       else if((rightDistance<=20)||(leftDistance<=20))
       {
        moveBack();
       }
       else
       {
        moveBack();
       }
    }  
    else
        moveForward();
       
                         
}
