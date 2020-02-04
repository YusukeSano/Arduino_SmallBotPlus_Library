#include <SmallBotPlus.h>
#include <I2CLiquidCrystal.h>
#include <Wire.h>

I2CLiquidCrystal lcd(40, false);
SmallBotPlus robot = SmallBotPlus();

void setup() {
  lcd.begin(16,2);
  lcd.print("light-threshold");
  robot.setup();
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print(robot.light());
  lcd.print("-");
  lcd.print(robot.slider());
  lcd.print("   ");
  robot.Linetrace(90, 120, robot.light());
}