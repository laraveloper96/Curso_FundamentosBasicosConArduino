/*
 * 
 * 
 * @Derecho de autor: Cristhian Lara 10/09/20
 * D2MAGICOS
 * 
 * Carrito controlado mediante aplicacion movil echa en android studio
 */

#include <SoftwareSerial.h>

SoftwareSerial miBT(2, 3);   //Instancia la conexion al bluetooth - PIN 2 a TX y PIN 3 a RX

int LED = 13;
//Variables para el sensor ultrasonico
int trigPin = 11;
int echoPin = 12;
int maxDist = 15;
int minDist = 2;

float distancia;

//Entrada de los motores
int motor1A = 5; // INPUT 1
int motor1B = 6; // INPUT 2
int motor2A = 10; // INPUT 3
int motor2B = 9; // INPUT 4

// Dato recibido atraves de la aplicacion movil
char data = 'S';

void setup()
{
  pinMode(echoPin, INPUT);    // echo como entrada
  pinMode(trigPin, OUTPUT);   // trigger como salida
  pinMode(LED, OUTPUT);    // LED como salida
  
  //Definimos las salidas del arduino
  pinMode(motor1A , OUTPUT);
  pinMode(motor1B , OUTPUT);  
  pinMode(motor2A , OUTPUT);  
  pinMode(motor2B , OUTPUT);
      
  Serial.begin(9600); //Inicia la comunicación en el monitor serial a 9600 Baudios
  miBT.begin(9600); // inicialmente la comunicacion serial a 9600 Baudios (velocidad de convencional)

  Serial.println("Módulo conectado");
}
 
void loop()
{
    //Esperamos hasta que haya un Stream de datos
    if(miBT.available() > 0){
      data = miBT.read();
      Serial.println(data);
    }
    
    switch (data) {
    case 'F':
      avanzar();        // Forward | AVANZAR
      break;
    case 'B':
      retroceder();     // Backward | RETROCEDER
      break;
    case 'L':
      izquierda();  //Left | IZQUIERDA
      break;
    case 'R':
      derecha();    //Right | DERECHA
      break;
    case 'S':
      detener();    //Stop | DETENER
      break;
    case 'A':
      automatico(); // Modo automatico depende del sensor ultrasonico 
      break;
    }
    delay(20);
}

void avanzar(){
  // Forward | AVANZAR
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
      
}

void retroceder(){
  // Backward | RETROCEDER
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH); 
}

void derecha(){
  //Right | DERECHA
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW); 
}

void izquierda(){
  //Left | IZQUIERDA
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void detener(){
  //Stop | DETENER
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW); 
}

void automatico(){
  
     distancia = calcularDistanciaCm(); // Calculamos la distancia de la pulso
     Serial.println(distancia);
     if (distancia <= maxDist && distancia >= minDist){    // si la distancia es menor de 15cm
        digitalWrite(LED,HIGH);      // Enciende LED
        
        detener(); //DETENEMOS LOS MOTORES 200 ms     
        delay (200);
        
        retroceder();          // RETROCEDE DURANTE 500 ms
        delay(500);           
        
        izquierda();     // Girar durante 600 milisegundos     
        delay(600);
        
        digitalWrite(LED,LOW);
     }
     else{                            
        avanzar(); //SI NO EXISTE OBSTACULO CONTINUA AVANZANDO
     }
}

float calcularDistanciaCm() {
  
  float duracion, distancia; // Variable para calcular el tiempo y distancia
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion * 0.0343) / 2;
  
  delay(10);
  
  return distancia;
}
