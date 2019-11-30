#ifndef __LED__
#define __LED__

/*
 * Classe che implementa il comportamento di un led
 */
class Led {

  public:
    Led(int pin);
    int getPin();
    void turnOn();
    void turnOff();
    int getState();
    void setState(int state);
    bool isOn();

  protected:
    int pin;
};

#endif
