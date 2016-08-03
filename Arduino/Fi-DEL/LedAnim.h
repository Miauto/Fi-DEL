#include <Adafruit_NeoPixel.h>

#define NbLED 24
#define PIN   0

byte Rgb = 0;
byte rGb = 0;
byte rgB = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NbLED, PIN, NEO_GRB + NEO_KHZ800);

void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NbLED; i++ ) {
    setPixel(i, red, green, blue);
  }
  strip.show();
}

////////////////////////// Blink START
void Blink(byte red, byte green, byte blue, int DelayOff, int DelayOn, int Nb) {
  for (int i=0; i<Nb; i++) {
    setAll(red,green,blue);
    delay(DelayOn);
    setAll(0,0,0);
    delay(DelayOff);
  }
}
////////////////////////// Blink END


////////////////////////// fade START ////////// jamais tester
void fade(int time, int i1, int i2) {
  if (i2 < i1) {
    for (int ii = i1; ii < i2; ++ii) {
      strip.setBrightness(255 - ii);
      strip.show();
      delay (time);
    }
  } else if (i2 > i1) {
    for (int ii = i1; ii > i2; --ii) {
      strip.setBrightness(255 + ii);
      strip.show();
      delay (time);
    }
  }
}
////////////////////////// fade END

////////////////////////// showStrip START
void showStrip() {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  FastLED.show();
#endif
}
////////////////////////// showStrip END

////////////////////////// setPixelHeatColor START
void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature/255.0)*191);

  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252

  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
    setPixel(Pixel, heatramp,  heatramp/5, 0);
//    Serial.print (heatramp);
//    Serial.println ("    Hot");
  } else if( t192 > 0x40 ) {             // middle
    setPixel(Pixel, heatramp, heatramp/4, 0);
//    Serial.print (heatramp);
//    Serial.println ("    Mid");
  } else {                               // coolest
    setPixel(Pixel, heatramp, heatramp/3, 0);
//    Serial.print (heatramp);
//    Serial.println ("    Cool");
  }
}
////////////////////////// END

////////////////////////// LeftToRight START
void LeftToRight(byte red, byte green, byte blue, int SpeedDelay, int ReturnDelay) {
  for (int i = 0; i < NbLED; i++) {
    setAll(red / 100, green / 100, blue / 100);

    setPixel(i, red, green, blue);

    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}
////////////////////////// LeftToRight END

////////////////////////// Convertie couleur Hexa en RGB
void HexatoDec(String Hexa) {
  // Get rid of '#' and convert it to integer
  int number = (int) strtol( &Hexa[1], NULL, 16);
  // Split them up into r, g, b values
  Rgb = number >> 16;
  rGb = number >> 8 & 0xFF;
  rgB = number & 0xFF;
}
//////////////////////////

////////////////////////// WHEEL Fonction
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
//////////////////////////

////////////////////////// Rainbow
void rainbow(uint8_t wait, byte* j) {
  int i;
  *j = *j + 1;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel((i + *j) & 255));
  }
  strip.show();
  delay(wait);
}
////////////////////////// END

////////////////////////// Rainbow Cycle
void RainbowCycle(byte* j) {
  int i;
  *j = *j + 1;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + *j) & 255));
  }
  strip.show();
  delay(20);
}
////////////////////////// END

//////////////////////////  Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait,  byte* j) {
  *j = *j + 1;   // cycle all 256 colors in the wheel
  for (int q = 0; q < 3; q++) {
    for (int i = 0; i < strip.numPixels(); i = i + 3) {
      strip.setPixelColor(i + q, Wheel( (i + *j) % 255)); //turn every third pixel on
    }
    strip.show();
    delay(wait);
    for (int i = 0; i < strip.numPixels(); i = i + 3) {
      strip.setPixelColor(i + q, 0);      //turn every third pixel off
    }
  }
}
////////////////////////// END

////////////////////////// effet neige START
void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red, green, blue);
  int Pixel = random(NbLED);
  setPixel(Pixel, 0xff, 0xff, 0xff);
  showStrip();
  delay(SparkleDelay);
  setPixel(Pixel, red, green, blue);
  showStrip();
  delay(SpeedDelay);
}
////////////////////////// END

////////////////////////// Strobe START
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause) {
  for (int j = 0; j < StrobeCount; j++) {
    setAll(red, green, blue);
    showStrip();
    delay(FlashDelay);
    setAll(0, 0, 0);
    showStrip();
    delay(FlashDelay);
  }
  delay(EndPause);
}
////////////////////////// END

////////////////////////// TwinkleRandom START
void TwinkleRandom(int SpeedDelay, boolean OnlyOne) {

  int x = random(0, 4);
  Serial.println ( x );
  if (x == 1) {
    setPixel(random(NbLED), random(0, 255), random(0, 255), 0);
  }
  if (x == 2) {
    setPixel(random(NbLED), random(0, 255), 0, random(0, 255));
  }
  if (x == 3) {
    setPixel(random(NbLED), 0, random(0, 255), random(0, 255));
  }
  if ((x == 0)) {
    setPixel(random(NbLED), random(0, 255), random(0, 255), random(0, 255));
  }
  if ((x > 3)) {
    setPixel(random(NbLED), random(0, 255), random(0, 255), random(0, 255));
  }
  showStrip();
  delay(SpeedDelay);
  if (OnlyOne) {
    setAll(0, 0, 0);
  }
}
////////////////////////// TwinkleRandom END

////////////////////////// Fire Start
void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[NbLED];
  int cooldown;

  // Step 1.  Cool down every cell a little
  for( int i = 0; i < NbLED; i++) {
    cooldown = random(0, ((Cooling * 10) / NbLED) + 2);
    if(cooldown>heat[i]) {
      heat[i]=0;
    } else {
      heat[i]=heat[i]-cooldown;
    }
  }
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= NbLED - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    //heat[y] = random(160,255);
  }
  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < NbLED; j++) {
    setPixelHeatColor(j, heat[j] );
  }
  showStrip();
  delay(random(SpeedDelay));
}
////////////////////////// FIRE END


////////////////////////// INIT START
void initLED()
{
  setAll(127, 0, 0);
  delay(500);
  setAll(0, 127, 0);
  delay(500);
  setAll(0, 0, 127);
  delay(500);
  setAll(127, 127, 127);
  delay(500);
}
////////////////////////// INIT END
