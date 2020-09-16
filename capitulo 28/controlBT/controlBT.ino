#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);   //Instancia la conexion al bluetooth - PIN 10 a TX y PIN 11 a RX

int LED_VERDE = 2;
int LED_ROJO = 3;
int LED_NARANJA = 4;
int LED_AZUL = 5;


long int LED_VERDE_ON = 1;
long int LED_VERDE_OFF = 2;
long int LED_ROJO_ON = 3;
long int LED_ROJO_OFF = 4;
long int LED_NARANJA_ON = 5;
long int LED_NARANJA_OFF = 6;
long int LED_AZUL_ON = 7;
long int LED_AZUL_OFF = 8;
 
void setup()
{
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_NARANJA, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_NARANJA, LOW);
  digitalWrite(LED_AZUL, LOW);
  
  Serial.begin(9600); //Inicia la comunicación en el monitor serial a 9600 Baudios
  miBT.begin(9600); // inicialmente la comunicacion serial a 9600 Baudios (velocidad de convencional)

  Serial.println("Módulo conectado");
}
 
void loop()
{
    if(miBT.available() > 0){

      long data;

      data = miBT.parseInt();

      //BEGIN LED_VERDE
      if(data == LED_VERDE_ON){
        digitalWrite(LED_VERDE, HIGH);
        delay(100);
      }
      if(data == LED_VERDE_OFF){
        digitalWrite(LED_VERDE, LOW);
        delay(100);
      }
      //END
      
      //BEGIN LED_ROJO
      if(data == LED_ROJO_ON){
        digitalWrite(LED_ROJO, HIGH);
        delay(100);
      }
      if(data == LED_ROJO_OFF){
        digitalWrite(LED_ROJO, LOW);
        delay(100);
      }
      //END LED_ROJO

      //BEGIN LED_NARANJA
      if(data == LED_NARANJA_ON){
        digitalWrite(LED_NARANJA, HIGH);
        delay(100);
      }
      if(data == LED_NARANJA_OFF){
        digitalWrite(LED_NARANJA, LOW);
        delay(100);
      }
      //END LED_NARANJA

      //BEGIN LED_AZUL
      if(data == LED_AZUL_ON){
        digitalWrite(LED_AZUL, HIGH);
        delay(100);
      }
      if(data == LED_AZUL_OFF){
        digitalWrite(LED_AZUL, LOW);
        delay(100);
      }
      //END LED_AZUL
    }
}
