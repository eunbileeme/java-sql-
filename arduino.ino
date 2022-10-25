#include "pitches.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define PIEZO 5 

int song[ ] = { NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4, 0, 
NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, 0, 
NOTE_A4, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_B4, 0, 
NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_C5, 0 }; 

//첫 소절 연주 시간
int time[ ] = { 250, 250, 250, 250, 750, 250, 
250, 250, 250, 250, 750, 250,
250, 250, 250, 250, 750, 250,
250, 250, 250, 250, 500, 250, 250 };
LiquidCrystal_I2C lcd(0x27,30,2);

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(PIEZO, OUTPUT);
  delay(3000); 
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Merry Christmas!");
  lcd.setCursor(0,1);
  lcd.print("Everyone:)");
}

void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(6, HIGH);
  
  int i;
  for (i=0; i<25; i++) {  
   tone(PIEZO, song[i], time[i]); 
   delay(time[i]);
  }
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  digitalWrite(9, LOW);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(6, LOW);
}