#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Hackable 17");
  
  randomSeed(42424242);
}

void loop() {
  if (analogRead(0) < 50) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Code tournant:");
    lcd.setCursor(0,1);
    lcd.print(random(1,65536));
    delay(500);
  }
}


