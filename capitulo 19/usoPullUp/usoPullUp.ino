const int ledVerde = 8;
const int btnEncender = 12;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(btnEncender, INPUT_PULLUP);
}

void loop() {

  if(digitalRead(btnEncender) == LOW){
    digitalWrite(ledVerde, HIGH);
  }else{
    digitalWrite(ledVerde, LOW);
  }
  delay(5);
}
