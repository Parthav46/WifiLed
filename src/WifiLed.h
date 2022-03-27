#include <Arduino.h>

// WifiLed control
class WifiLed {
    public:
        WifiLed(int pin);
        void on();
        void off();
    private:
        int _pin;
};
