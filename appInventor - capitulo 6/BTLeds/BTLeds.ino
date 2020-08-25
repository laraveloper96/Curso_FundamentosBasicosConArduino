#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);   //Instancia la conexion al bluetooth - PIN 10 a TX y PIN 11 a RX

int LED_ROJO = 2;
int LED_AMARILLO = 3;
int LED_AZUL = 4;
int LED_VERDE = 5;

//CARACTERES RECUPERADOS POR EL BT
char LED_ROJO_ON = '1';
char LED_ROJO_OFF = '2';
char LED_AMARILLO_ON = '3';
char LED_AMARILLO_OFF = '4';
char LED_AZUL_ON = '5';
char LED_AZUL_OFF = '6';
char LED_VERDE_ON = '7';
char LED_VERDE_OFF = '8';
 
void setup()
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, LOW);
  
  Serial.begin(9600); //Inicia la comunicación en el monitor serial a 9600 Baudios
  miBT.begin(9600); // inicialmente la comunicacion serial a 9600 Baudios (velocidad de convencional)

  Serial.println("Módulo conectado");
}
 
void loop()
{
    if(miBT.available() > 0){

      char data;

      data = miBT.read();
      Serial.println(data);

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

      //BEGIN LED_AMARILLO
      if(data == LED_AMARILLO_ON){
        digitalWrite(LED_AMARILLO, HIGH);
        delay(100);
      }
      if(data == LED_AMARILLO_OFF){
        digitalWrite(LED_AMARILLO, LOW);
        delay(100);
      }
      //END LED_AMARILLO
      
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

      //BEGIN LED_VERDE
      if(data == LED_VERDE_ON){
        digitalWrite(LED_VERDE, HIGH);
        delay(100);
      }
      if(data == LED_VERDE_OFF){
        digitalWrite(LED_VERDE, LOW);
        delay(100);
      }
      //END LED_VERDE
    }
}
