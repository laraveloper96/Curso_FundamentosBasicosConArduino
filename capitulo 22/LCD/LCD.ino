#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11 , 5 , 4, 3, 2);

const int sensorTemp = A0;
int tempC;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2); //Inicializamos nuestro LCD
}
 
void loop() {
  // put your main code here, to run repeatedly:
  tempC = analogRead(sensorTemp);
  tempC = tempC*0.48828125;
  Serial.println(tempC);
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  delay(1000);
}
