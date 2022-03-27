#include "WifiLed.h"

WifiLed led;

void setup()
{
    led = WifiLed(LED_BUILTIN);
}

void loop()
{
    led.on();
    delay(1000);
    led.off();
    delay(1000);
}