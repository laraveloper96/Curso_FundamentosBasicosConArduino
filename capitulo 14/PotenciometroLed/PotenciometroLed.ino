int ledVerde = 8; // Led indicador de resistencia variable
int potPin = A0; // Pin de lectura del potenciometro
int potValue = 0; // Obtiene la lectura del potenciometro

void setup() {
  // put your setup code here, to run once:
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  digitalWrite(ledVerde, HIGH);
  delay(potValue);
  digitalWrite(ledVerde, LOW);
  delay(potValue);
}
