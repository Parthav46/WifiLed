#include "WifiLed.h"

WifiLed::WifiLed(int pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
}

void WifiLed::on() {
    digitalWrite(_pin, HIGH);
}

void WifiLed::off() {
    digitalWrite(_pin, LOW);
}