#ifndef __PIRSENSOR__
#define __PIRSENSOR__

/*
 * Classe che implementa il comportamento di un sensore pir. 
 * Se il pir è collegato ad un pin abilitato per le interrupt è possibile attivarlo in modo che generi eventi di tipo PirDetectionEvent quando viene generato un interrupt
 */
class PirSensor {
  public:
    PirSensor(int pin);
    bool isDetecting();
    void setEnabled(bool on);
    
  private:
    int pin;
};

void motionDetected();

#endif
