#include<Servo.h>
//Configuracion servomotor
Servo servo;
int pulsoMin = 1500; //pulso maximo
int pulsoMax = 2500; //pulso minimo
int angulo = 0; //angulo de giro
int pinServo = 9; // pin del servomotor
//Configuracion potenciometro
int potPin = A0; //pin analogico A0
int potValue = 0; // Guardar el valor del potenciometro

void setup() {
 servo.attach(pinServo, pulsoMin, pulsoMax); //Inicializando servomotor
}

void loop() {

  potValue = analogRead(potPin);
  angulo = map(potValue, 0, 700, 0, 180);
  servo.write(angulo);
  delay(30);
}
