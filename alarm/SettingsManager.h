#ifndef __SETTINGS__
#define __SETTINGS__

#include "Arduino.h"

/**
 * Classe di gestione delle preferenze dell'applicazione, come l'UUID del sistema.
 */
class SettingsManager {
  public:
    void clearEEPROM(); // Pulisce la memoria permanente di Arduino scrivendo in ogni cella il byte 0
    void saveUUID(String uuid);
    String loadUUID();
    boolean needUUID(); // Indica se il sistema non ha ancora un UUID assegnato
};

String generateUUID();

#endif
