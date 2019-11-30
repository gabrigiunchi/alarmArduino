#include "EEPROM.h"

void setup() {
  Serial.begin(9600);
  Serial.print("Clearing memory..");
  for(int address = 0; address < EEPROM.length(); address++) {
    EEPROM.write(address, 255);
    if((address % 250) == 0) {
      Serial.print('.');
    }
  }
  Serial.println();
  Serial.println("Memory cleared");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() { }
