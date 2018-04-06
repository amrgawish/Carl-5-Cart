#include <Time.h>
#include <stdlib.h>

int searchCount = millis();
void setup() {
   // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(2, INPUT);
   pinMode(3, INPUT);
   pinMode(12, INPUT);
   delay(1000);
}

int turn = 0;
void loop() {
  int RS = digitalRead(2);
  int MS = digitalRead(3);
  int LS = digitalRead(12);
  
  
  if (!RS && MS && !LS) { // if it is on the line from start
      Forward();
   }
  if (RS && !MS && !LS){
      Right();
   }
   if (!RS && !MS && LS){
      Left();
   }
   if (RS && MS && LS){
      Turn();
   }
   if (RS && MS && !LS){
      Turn();
   }
   if (!RS && MS && LS){
      Turn();
   }
}

void Forward() {
   analogWrite(5, LOW);
   analogWrite(6, 170);
   analogWrite(9, 170);
   analogWrite(10, LOW);
}

void Backward() {
   analogWrite(5, 170);
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   analogWrite(10, 170);
}

void Right() {
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   analogWrite(9, 170);
   digitalWrite(10, LOW);
   while (!digitalRead(3)){}
}

void Left() {
   digitalWrite(5, LOW);
   analogWrite(6, 170);
   digitalWrite(9, HIGH);
   digitalWrite(10, HIGH);
   while (!digitalRead(3)){}
}


void SRight() {
  Serial.println("SRIGHT");
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   analogWrite(9, 170);
   digitalWrite(10, LOW);
   delay(500);
   while (!digitalRead(3)){
    }
}

void SLeft() {
  Serial.println("SLEFT");
   digitalWrite(5, LOW);
   analogWrite(6, 170);
   digitalWrite(9, HIGH);
   digitalWrite(10, HIGH);
   delay(500);
   while (!digitalRead(3)){
   }
}
void STOP() {
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(9, HIGH);
   digitalWrite(10, HIGH);
}

void Turn(){
  Serial.println(turn);
  if (turn == 0){
    SLeft();
  }else if (turn == 1){
    SRight();
  }else if (turn == 2){
    SRight();
  }else if (turn == 3){
    SLeft();
  }else if (turn == 4){
    SRight();
  }else if (turn == 5){
    SRight();
  }else if (turn == 6){
    SRight();
  }else if (turn == 7){
    SLeft();
  }else if (turn == 8){
    SLeft();
  }else if (turn == 9){
    SRight();
  }else if (turn == 10){
    SLeft();
  }
  turn++;
}

