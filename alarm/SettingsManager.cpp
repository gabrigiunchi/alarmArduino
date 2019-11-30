#include "SettingsManager.h"
#include "EEPROM.h"
#include "TrueRandom.h"
#include "Arduino.h"

boolean SettingsManager :: needUUID() {
  /*
   * Se la memoria non è mai stata usata allora ogni cella contiene il valore 255. 
   * Se ciò viene verificato attraverso questo ciclo allora assumo che in memoria non è presente l'UUID del sistema.
   * Nel caso la memoria sia stata utilizzata per altri scopi oltre a quello di salvare l'UUID del sistema potrebbero verificarsi malfunzionamenti,
   * è bene quindi accertarsi che la memoria sia inizializzata come nuova scrivendo su ogni cella il valore 255
   */
  for(int address = 0; address < EEPROM.length(); address++) {
    if(EEPROM.read(address) != 255) {
      return false;
    }
  }

  return true;
}

void SettingsManager :: clearEEPROM() {
  for(int address = 0; address < EEPROM.length(); address++) {
    EEPROM.write(address, 0);
  }
}

void SettingsManager :: saveUUID(String uuid) {
  int address;
  for(address = 0; address < uuid.length(); address++) {
    byte b = uuid.charAt(address);
    EEPROM.write(address, b);
  }

  EEPROM.write(address, 0);
}

String SettingsManager :: loadUUID() {
  String uuid = "";
  byte b = 1;
  int address = 0;

  while(b != 0 && address < EEPROM.length()) {
    b = EEPROM.read(address);
    if(b != 0) {
      uuid += char(b);
    }
    address++;
  }

  return uuid;
}

String generateUUID() {
  byte b[16];
  TrueRandom.uuid(b);

  String uuid = "";
  
  for(int i = 0; i < 16; i++) {
    if(i == 4 || i == 6 || i == 8 || i == 10) {
      uuid += "-";
    }
    uuid += String(b[i], HEX);
  }

  return uuid;
}
