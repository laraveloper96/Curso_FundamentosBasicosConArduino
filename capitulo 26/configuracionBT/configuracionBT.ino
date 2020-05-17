#include<SoftwareSerial.h>

SoftwareSerial miBT(10, 11); //Instancia la conexion al bluetooth - PIN 10 a TX y PIN 11 a RX

char NOMBRE[21] = "D2Magicos"; // NOMBRE DE 20 CARACTERES MAXIMO
char BPS        = '4'; //1=1200, 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200 
char PASSWORD[5]   = "4444"; //PIN O CLAVE DE 4 CARACTERES      

void setup() {
  Serial.begin(9600); //Inicia la comunicacion en el monitor serial a 9600 baudios
  miBT.begin(9600); //Inicia la comunicacion en el modulo HC-06

  Serial.println("Todos OK");

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); //Encinde el LED 13
  delay(5000); //Se enciende por 5s

  digitalWrite(13, LOW);

  Serial.println("Enviando comandos AT"); //Imprime en el monitor serial

  miBT.print("AT"); //INICIALIZA COMANDO AT
  delay(1000); //esperamos 1 segundo

  miBT.print("AT+NAME"); //Configurando el nuevo nombre
  miBT.print(NOMBRE);
  delay(1000);

  miBT.print("AT+BAUD"); //Configurando la nueva velocidad
  miBT.print(BPS);
  delay(1000);

  miBT.print("AT+PIN"); //Configurando el nuevo PASSWORD
  miBT.print(PASSWORD);
  delay(1000);

  Serial.println("Fin de los comandos AT");
}

void loop() {
  digitalWrite(13, !digitalRead(13)); //Hacemos parpadear nuestro LED 13
  delay(500);
}
