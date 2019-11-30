#ifndef __TIMER__
#define __TIMER__

/*
 * Classe che implementa il comportamento di un timer e che utilizza il timer1 di Arduino.
 * Il timer viene inizializzato con una frequenza (espressa in microsecondi) e genera un evento di tipo TimerEvent 
 * in base a tale frequenza. E' possibile fermare e far ripartire il timer dinamicamente 
 * Questa classe utilizza la libreria Timer1
 */
class Timer {

  public: 
    Timer(long period); // Inizializza il timer con la frequenza data. Di default il timer è spento quando è inizializzato
    void setPeriod(long period); // Re-inizializza il timer con la nuova frequenza
    void start(); // Fa ripartire il timer se era stato in precedenza stoppato
    void stop(); // Ferma il timer
};

void timerInterrupt();

#endif
