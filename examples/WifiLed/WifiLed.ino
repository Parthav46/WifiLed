#include <FastLED.h>

#define NUM_LEDS 15
#define DATA_PIN D0
#define RGB_ORDER GRB
#define BRIGHTNESS 32

CRGB leds[NUM_LEDS];
uint8_t o = 0;

void setup()
{
    FastLED.addLeds<WS2812B, DATA_PIN, RGB_ORDER>(leds, NUM_LEDS);
    delay(1000);    
}

void loop()
{
    SetColorFromPalette(RainbowColors_p, o);
    o = (o + 1) % 256;
    delay(50);
}

void SetColorFromPalette(CRGBPalette16 pallet, uint8_t offset)
{
    uint16_t i;
    for (i = 0; i < NUM_LEDS; i++)
    {
        uint8_t index = ((i * 8) + offset) % 256;
        leds[i] = ColorFromPalette(pallet, index, BRIGHTNESS, LINEARBLEND);
    }
    FastLED.show();
}