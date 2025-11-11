#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String command = "";

void setup() {
  lcd.begin(16, 2);             
  lcd.print("Ready for cmd");   
  Serial.begin(9600);           
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n'); 
    command.trim(); 

    lcd.clear(); 

    if (command.equalsIgnoreCase("HELLO")) {
      lcd.print("HELLO WORLD!");
    } 
    else if (command.equalsIgnoreCase("WELCOME")) {
      lcd.print("WELCOME USER!");
    } 
    else if (command.equalsIgnoreCase("CLEAR")) {
      lcd.clear();
      lcd.print("Display Cleared");
    }
    else {
      lcd.print("Invalid Command");
    }

    delay(1500);
    lcd.clear();
    lcd.print("Ready for cmd");
  }
}
