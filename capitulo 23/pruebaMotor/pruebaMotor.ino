int motor1A = 5; // INPUT 1
int motor1B = 6; // INPUT 2
int velocidad = 0; // Velocidad del motor

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
}

void loop() {

  //Velocidad maxima
  velocidad = 255;
  analogWrite(motor1A, 0);
  delay(500);
  analogWrite(motor1B, velocidad); //Giro Horario
  delay(2000); // esperamos 2 segundos
  analogWrite(motor1B, 0); //Apagamos el motor
  
  //Velocidad intermedia

  velocidad = 140;
  analogWrite(motor1B, 0);
  delay(500);
  analogWrite(motor1A, velocidad); //Giro AntiHorario
  delay(2000); // esperamos 2 segundos
  analogWrite(motor1A, 0); //Apagamos el motor
  
  //Velocidad baja

  velocidad = 50;
  analogWrite(motor1A, 0);
  delay(500);
  analogWrite(motor1B, velocidad); //Giro Horario
  delay(2000); // esperamos 2 segundos
  analogWrite(motor1B, 0); //Apagamos el motor
}
