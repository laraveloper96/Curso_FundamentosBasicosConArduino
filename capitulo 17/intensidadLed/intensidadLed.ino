int ledVerde = 3;
int ledAzul = 5;
int ledNaranja = 6;

int potPin = A0;
int potValue = 0;
int brightValue = 0;

void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  brightValue = map(potValue, 0, 1024, 0, 255);
  analogWrite(ledVerde, brightValue);
  analogWrite(ledAzul, brightValue);
  analogWrite(ledNaranja, brightValue);
  delay(20);  
}
