#include <FastLED.h>

#define NUM_LEDS 15
#define DATA_PIN D0
#define RGB_ORDER GRB

CRGB leds[NUM_LEDS];

void setup()
{
    FastLED.addLeds<WS2812B, DATA_PIN, RGB_ORDER>(leds, NUM_LEDS);
    Serial.begin(115200);
    int8_t Brightness = 10;
    delay(1000);

    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::White;
    }
    FastLED.setBrightness(Brightness);
    FastLED.show();
    delay(1000);
    Serial.println("Reading brightness now:");
}

void loop()
{
    if (Serial.available()) {
        uint8_t Brightness = Serial.readStringUntil('\n').toInt();
        Serial.println(Brightness);
        FastLED.setBrightness(Brightness);
        FastLED.show();
    }
}