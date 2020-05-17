#include<Servo.h>

int pinServo = 9;

Servo servo;
int pulsoMin = 1500;
int pulsoMax = 2500;
int angulo = 0;

void setup() {
 servo.attach(pinServo, pulsoMin, pulsoMax);
}

void loop() {

  for(angulo = 0; angulo < 180; angulo++){
    servo.write(angulo);
    delay(30);
  }

  for(angulo = 180; angulo > 0; angulo--){
    servo.write(angulo);
    delay(30);
  }
}
