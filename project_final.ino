#include <Wire.h>
#include <MMA_7455.h>

char xVal, yVal, zVal;
int score=0;
int maxCountDown = 10000;
int countDown = -1;

int led1 = 5;
int led2 = 6;
int led3 = 7;

int Tap=2;
volatile bool bascule=false;

int Accoustique = A2;
int sensorValue = 0;

int Tap3 = 3;
volatile bool bascule2=false;
int val;

MMA_7455 Tap2 = MMA_7455();

void setup() {
  // put your setup code here, to run once:
pinMode (led1, OUTPUT) ;
pinMode (led2, OUTPUT) ;
pinMode (led3, OUTPUT) ;

pinMode (Tap, INPUT) ;
digitalWrite(Tap,HIGH);

pinMode (Tap3, INPUT) ;

Tap2.initSensitivity(2);
interruption();
interruption2();
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(Accoustique);
Serial.println(sensorValue);

if (sensorValue>800)
{
  Serial.println("Sound detected");
    countDown = maxCountDown;
    digitalWrite (led1,HIGH);
}
if (sensorValue>1000)
{
  Serial.println("Sound detected");
    countDown = maxCountDown;
    digitalWrite (led2,HIGH);
}
xVal = Tap2.readAxis('x'); //Read out the 'x' Axis
if (sensorValue>600)
{
  Serial.println("Sound detected");
    countDown = maxCountDown;
    digitalWrite (led3,HIGH);
    if (xVal>10)
    {
      score=score+10;
      digitalWrite (led3,LOW);
    }
}
Serial.println("score: ");
Serial.print(score);
  xVal = Tap2.readAxis('x'); //Read out the 'x' Axis
  yVal = Tap2.readAxis('y'); //Read out the 'y' Axis
  zVal = Tap2.readAxis('z'); //Read out the 'z' Axis
  Serial.print("X = ");
  Serial.print(xVal, DEC);
  Serial.print("   Y = ");
  Serial.print(yVal, DEC);
  Serial.print("   Z = ");
  Serial.println(zVal, DEC);
  delay(10);

}


void interruption()
{
  attachInterrupt(digitalPinToInterrupt(Tap),basculer,RISING);
}
void basculer()
{
  bascule=!bascule;
  if(bascule){
    score=score+10;
   digitalWrite (led1,LOW); 
  }
}
void interruption2()
{
  attachInterrupt(digitalPinToInterrupt(Tap3),basculer2,RISING);
}
void basculer2()
{
  bascule2=!bascule2;
  if(bascule2){
    score=score+50;
   digitalWrite (led2,LOW); 
  }
}
