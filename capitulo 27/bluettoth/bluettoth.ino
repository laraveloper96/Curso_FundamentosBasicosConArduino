#include <SoftwareSerial.h>

/* 
  Código echo por Cristhian Lara 20/01/2019
  Módulo bluetooth HC-06: 
  NOMBRE  (Nombre de 20 caracteres como máximo)
  PIN     (Contraseña de cuatro numeros)
  BPS     (Velocidad de comunicación serial en baudios(9600 velocidad convencional))

  CONEXIONES:
  5V        VCC
  GND       GND
  PIN 2     TX
  PIN 3     RX
  
 */

SoftwareSerial miBT(10, 11);   //Instancia la conexion al bluetooth - PIN 10 a TX y PIN 11 a RX

char NOMBRE[21]  = "HC-06"; // Nombre de 20 caracteres maximo
char BPS         = '4';     // 1=1200 , 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
char PASS[5]    = "1234";   // PIN O CLAVE de 4 caracteres numericos     
 
void setup()
{
    Serial.begin(9600); //Inicia la comunicación en el monitor serial a 9600 Baudios
    miBT.begin(9600); // inicialmente la comunicacion serial a 9600 Baudios (velocidad de convencional)

    Serial.println("Todos Ok");
    
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH); // Enciende el LED 13 durante 5s antes de configurar el módulo Bluetooth
    delay(5000);
    
    digitalWrite(13,LOW); // Apaga el LED 13 nos iniciar que iniciara la programacion

    Serial.println("Enviando comandos AT"); //Imprime mensaje en el monitor serial
    
    miBT.print("AT"); // Inicializa comando AT
    delay(1000); // espera 1 segundo
 
    miBT.print("AT+NAME"); // Configura el nuevo nombre 
    miBT.print(NOMBRE);
    delay(1000);                  
 
    miBT.print("AT+BAUD"); // Configura la nueva velocidad 
    miBT.print(BPS); 
    delay(1000);
 
    miBT.print("AT+PIN"); // Configura el nuevo PIN
    miBT.print(PASS);
    delay(1000);    
    Serial.println("Fin de los comandos AT"); //Imprime mensaje en el monitor serial
}
 
void loop()
{
    digitalWrite(13, !digitalRead(13)); //Finalizada la configuracion del bluetooth queda el LED 13 parpadeando
    delay(500);
}
