#include <NewPing.h>
#include<Servo.h>
int X=99;
int Y=99;
int motor_l_pos=9; 
int motor_l_neg=12;
int motor_l_pwm=11;
int motor_r_pos=8;
int motor_r_neg=7; 
int motor_r_pwm=6;
int motor_val;
int serv=3;
int serv_val;
Servo servo;
int L_R=4;
int L_L=2;

#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 200 
#define MAX_SPEED 190 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo myservo;  
boolean goesForward=false;
int distance = 100;
int speedSet = 0;

 
void setup() {

Serial.begin(9600);
pinMode(motor_l_pos,OUTPUT);
pinMode(motor_l_neg,OUTPUT);
pinMode(motor_r_pos,OUTPUT);
pinMode(motor_r_neg,OUTPUT);
pinMode(motor_l_pwm,OUTPUT);
pinMode(motor_r_pwm,OUTPUT);
pinMode(L_R,OUTPUT);
pinMode(L_L,OUTPUT);
servo.attach(serv);


 myservo.attach(10);  
  myservo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  
if (Serial.available()>= 1){
 Y=Serial.read();
Serial.println(Y);
}
 if (Y==1 ){
  //forward
  servo.write(90);
digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
   analogWrite(motor_l_pwm,255);
  analogWrite(motor_r_pwm,255);
  
 }
 else if (Y==11){
   //forward
  servo.write(90);
digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
   analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
 }
 else if (Y==2){
  //backward
  servo.write(90);
 digitalWrite(motor_l_pos,HIGH);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,HIGH);
  digitalWrite(motor_r_neg,LOW);
   analogWrite(motor_l_pwm,255);
  analogWrite(motor_r_pwm,255);
 }
 else if (Y==12){
  //backward
  servo.write(90);
 digitalWrite(motor_l_pos,HIGH);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,HIGH);
  digitalWrite(motor_r_neg,LOW);
   analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
 }
 else if(Y==4 ){
  //right
  servo.write(0);
 digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
  analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
 }
 else if (Y==3){
  // left
servo.write(180);
  digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
   analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
 }
 else if (Y==0){
  // stop

  digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,LOW);
   analogWrite(motor_l_pwm,0);
  analogWrite(motor_r_pwm,0);
 }
else if (Y==5){
  // UL
 servo.write(180);
digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
   analogWrite(motor_l_pwm,255);
  analogWrite(motor_r_pwm,255);
 }
 else if (Y==6){
  // UR

  servo.write(0);
digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
   analogWrite(motor_l_pwm,255);
  analogWrite(motor_r_pwm,255);
 }
 else if (Y==7){
  // DL

 servo.write(180);
 digitalWrite(motor_l_pos,HIGH);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,HIGH);
  digitalWrite(motor_r_neg,LOW);
   analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
 }
 else if (Y==8){
  // DR

servo.write(0);
 digitalWrite(motor_l_pos,HIGH);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,HIGH);
  digitalWrite(motor_r_neg,LOW);
   analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
 }
 else if (Y==9){
  // C
int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=17)
 {
 digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,LOW);
   analogWrite(motor_l_pwm,0);
  analogWrite(motor_r_pwm,0);
  delay(1000);
 servo.write(90);
  digitalWrite(motor_l_pos,HIGH);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,HIGH);
  digitalWrite(motor_r_neg,LOW); 
  analogWrite(motor_l_pwm,150);
  analogWrite(motor_r_pwm,150);
  delay(500);
  digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,LOW);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,LOW);
   analogWrite(motor_l_pwm,0);
  analogWrite(motor_r_pwm,0);
  delay(1000);
  distanceR = lookRight();
  delay(500);
  distanceL = lookLeft();
  delay(500);

  if(distanceR>=distanceL)
  {
    servo.write(0);
 digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
  analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
  delay(1500);
 servo.write(90);
  digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
   
       
  analogWrite(motor_l_pwm,120);
  analogWrite(motor_r_pwm,120);
  

  }
  else {
    servo.write(180);
 digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
  analogWrite(motor_l_pwm,80);
  analogWrite(motor_r_pwm,80);
  delay(1500);
   servo.write(90);
  digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
  analogWrite(motor_l_pwm,120);
  analogWrite(motor_r_pwm,120);

 
  }
 }else
 {
  if(!goesForward)
  {
    goesForward=true;
   servo.write(90);
  digitalWrite(motor_l_pos,LOW);
  digitalWrite(motor_l_neg,HIGH);
  digitalWrite(motor_r_pos,LOW);
  digitalWrite(motor_r_neg,HIGH);
   
       
  analogWrite(motor_l_pwm,120);
  analogWrite(motor_r_pwm,120);
  }
 }
 distance = readPing();
 }
}
 
///////////////////////////////

int lookRight()
{
    myservo.write(40); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(180); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}


  
