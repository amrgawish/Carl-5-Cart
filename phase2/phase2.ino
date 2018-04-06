#include <Time.h>
#include <stdlib.h>

const int trig = 2;
const int R = 11;
const int L = 12;
const int M = 3;
const int safeDist = 6;

void setup() {
   // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(trig, OUTPUT);
   pinMode(R, INPUT);
   pinMode(L, INPUT);
   pinMode(M, INPUT);
   digitalWrite(trig, LOW);
   delay(1000);
}

void loop() {
  int RS = getDistance (R);
  int MS = getDistance (M);
  int LS = getDistance (L);
  if (MS == 0){MS = 100;}
  if (RS == 0){RS = 100;}
  if (LS == 0){LS = 100;}
  Serial.print("  ");
  Serial.print(LS);
  Serial.print("  ");
  Serial.print(MS);
  Serial.print("  ");
  Serial.println (RS);
  
  if (MS <= safeDist){
    STOP();
  if (RS <= safeDist && LS <= safeDist){
        D180();
    }else if (RS < LS){
        SLeft();
      }else if (RS > LS){
        SRight();
      }else{
        STOP();
      }
    } 

  if (MS > safeDist){
    if (RS <= 4){
      Left();
      delay(100);
    }else if (LS <= 4 ){
      Right();
      delay(100);
    }
      Forward();
  }
}

int getDistance(int pin){
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  return pulseIn(pin, HIGH)*0.034/2;
}

void Forward() {
   analogWrite(5, LOW);
   analogWrite(6, 170);
   analogWrite(9, 140);
   analogWrite(10, LOW);
}

void Left() {
   analogWrite(5, LOW);
   analogWrite(6, 170);
   analogWrite(9, LOW);
   analogWrite(10, 140);
}

void Right() {
   analogWrite(5, 170);
   analogWrite(6, LOW);
   analogWrite(9, 140);
   analogWrite(10, LOW);
}

void SLeft() {
   analogWrite(5, LOW);
   analogWrite(6, 170);
   analogWrite(9, LOW);
   analogWrite(10, 140);
   delay(650);
}

void SRight() {
   analogWrite(5, 170);
   analogWrite(6, LOW);
   analogWrite(9, 140);
   analogWrite(10, LOW);
   delay(650);
}
void D180() {
   analogWrite(5, 170);
   analogWrite(6, LOW);
   analogWrite(9, 140);
   analogWrite(10, LOW);
   delay(1100);
}
void STOP() {
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
}
