#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ldrPin = A1;
int Moisture_signal = A0;
int LM335_pin = A2;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(Moisture_signal,INPUT);
  pinMode(LM335_pin,INPUT);
  }

void loop() {
  lcd.setCursor(0, 0);
  
  
  int ldrStatus = analogRead(ldrPin);
   /* if (ldrStatus <= 600) 
      {
       Serial.println(ldrStatus);
       Serial.println("Light is not enough!");
       }
    else
    {
      Serial.println(ldrStatus);
      Serial.println("Light is enough:)");
      }*/
    lcd.print("LDR:");
    lcd.print(ldrStatus);
    int Moisture = analogRead(Moisture_signal);
    lcd.print("Moist:");
    lcd.print(Moisture);
   /* if (Moisture >= 500) 
      {
       Serial.print("Soil Moisture Level: ");
       Serial.println(Moisture);
       Serial.println("Moisture is not enough!");
       }
    else
    {
      Serial.print("Soil Moisture Level: ");
      Serial.println(Moisture);
      Serial.println("Moisture is enough!");
      }*/

    int Kelvin = analogRead(LM335_pin) * 0.489;      // Read analog voltage and convert it to Kelvin (0.489 = 500/1023)
    int Celsius = Kelvin - 273; 
    Serial.print("Tempreture in Celsius: ");
    Serial.println(Celsius);
    lcd.setCursor(0, 1);
    lcd.print("Temperature:");
    lcd.print(Celsius);
    delay(1000);
    
}
