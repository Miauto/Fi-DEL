#define DATA_PIN    0         // Borne Data
#define NUM_LEDS    10         // Nombre de Leds

#define COLOR_ORDER GRB       // Ordre des couleurs
#define LED_TYPE    WS2812B   // Types des Leds

CRGB leds[NUM_LEDS];          // Tableau de leds
CRGBSet ledSet(leds, NUM_LEDS);    //Setup FastLED

byte Rgb = 0;
byte rGb = 0;
byte rgB = 0;

/*/////////////////////////
*        Variable Nuage
*//////////////////////////
static uint16_t Nuage_dist = random16(12345);         // A random number for our noise generator.
uint16_t Nuage_scale = 30;          // Wouldn't recommend changing this on the fly, or the animation will be really blocky.
uint8_t Nuage_maxChanges = 48;      // Value for blending between palettes.
CRGBPalette16 Nuage_currentPalette(CRGB::Black);
CRGBPalette16 Nuage_targetPalette(OceanColors_p);




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

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
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
  for (int i = 0; i < NUM_LEDS; i++) {
    setAll(red / 100, green / 100, blue / 100);

    setPixel(i, red, green, blue);

    showStrip();
    FastLED.delay(SpeedDelay/NUM_LEDS);
  }
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
byte * Wheel(byte WheelPos) {
  static byte c[3];

  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }
}
//////////////////////////

////////////////////////// Rainbow
void Rainbow(uint16_t wait, byte* j) {
    *j = *j + 1;
  fill_rainbow( leds, NUM_LEDS, *j, 0);
  FastLED.show();
  delay(wait);
  if (*j == 255) { *j = 0;}
}
////////////////////////// END

////////////////////////// Rainbow Cycle
void RainbowCycle(uint16_t wait, byte* j) {
    *j = *j + 1;
  fill_rainbow( leds, NUM_LEDS, *j, 11);
  FastLED.show();
  delay(wait);
  if (*j == 255) { *j = 0;}

}
////////////////////////// END


////////////////////////// effet neige START
void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red, green, blue);
  int Pixel = random(NUM_LEDS);
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
  if (OnlyOne) {
    setAll(0, 0, 0);
  }
  if (x == 1) {
    setPixel(random(NUM_LEDS), random(0, 255), random(0, 255), 0);
  }
  if (x == 2) {
    setPixel(random(NUM_LEDS), random(0, 255), 0, random(0, 255));
  }
  if (x == 3) {
    setPixel(random(NUM_LEDS), 0, random(0, 255), random(0, 255));
  }
  if ((x == 0)) {
    setPixel(random(NUM_LEDS), random(0, 255), random(0, 255), random(0, 255));
  }
  if ((x > 3)) {
    setPixel(random(NUM_LEDS), random(0, 255), random(0, 255), random(0, 255));
  }
  showStrip();
  delay(SpeedDelay);
}
////////////////////////// TwinkleRandom END

////////////////////////// Fire Start
void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[NUM_LEDS];
  int cooldown;

  // Step 1.  Cool down every cell a little
  for( int i = 0; i < NUM_LEDS; i++) {
    cooldown = random(0, ((Cooling * 10) / NUM_LEDS) + 2);
    if(cooldown>heat[i]) {
      heat[i]=0;
    } else {
      heat[i]=heat[i]-cooldown;
    }
  }
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    //heat[y] = random(160,255);
  }
  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < NUM_LEDS; j++) {
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

/*///////////////////////////////////
 *            GLITTER
 ////////////////////////////////////*/
void addGlitter( fract8 chanceOfGlitter)
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
  FastLED.show();
}
/*****************************************
 *            FIN GLITTER
*******************************************/


/*///////////////////////////////////
 *          RAINBOW GLITTER
 ////////////////////////////////////*/
 void RainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  Rainbow(500, &RainbowIndex);
  addGlitter(80);
}
/*****************************************
 *         FIN  RAINBOW GLITTER
*******************************************/

 /*///////////////////////////////////
 *            CONFETTI
 ////////////////////////////////////*/
void Confetti(byte* gHue)
{
  *gHue++;
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( *gHue + random8(64), 200, 255);
  FastLED.show();
}
/*****************************************
 *            END CONFETTI
*******************************************/

void sinelon(byte* gHue)
{
  *gHue++;
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13,0,NUM_LEDS);
  leds[pos] += CHSV( *gHue, 255, 192);
  FastLED.show();
}

void bpm(byte* gHue)
{
  *gHue++;
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, *gHue+(i*2), beat-*gHue+(i*10));
  }
  FastLED.show();
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16(i+7,0,NUM_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
  FastLED.show();
}

/*////////////////////////////
 *        FIRE 2012
 *////////////////////////////
void Fire2012(bool gReverseDirection, int COOLING /* 55 */, byte SPARKING /* 120 */) {

// Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
    for( int i = 0; i < NUM_LEDS; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= NUM_LEDS - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < SPARKING ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < NUM_LEDS; j++) {
      CRGB color = HeatColor( heat[j]);
      int pixelnumber;
      if( gReverseDirection ) {
        pixelnumber = (NUM_LEDS-1) - j;
      } else {
        pixelnumber = j;
      }
      leds[pixelnumber] = color;
    }
  FastLED.show();
}

/*////////////////////////////////
 *          Nuage
 *////////////////////////////////
 void fillnoise8() {
  for(int i = 0; i < NUM_LEDS; i++) {                                      // Just ONE loop to fill up the LED array as all of the pixels change.
    uint8_t index = inoise8(i*Nuage_scale, Nuage_dist+i*Nuage_scale) % 255;                  // Get a value from the noise function. I'm using both x and y axis.
    leds[i] = ColorFromPalette(Nuage_currentPalette, index, 255, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.
  }
  Nuage_dist += beatsin8(10,1, 4);                                               // Moving along the distance (that random number we started out with). Vary it a bit with a sine wave.
                                                                           // In some sketches, I've used millis() instead of an incremented counter. Works a treat.
}

 void Nuage(){
 EVERY_N_MILLISECONDS(10) {
    nblendPaletteTowardPalette(Nuage_currentPalette, Nuage_targetPalette, Nuage_maxChanges);  // Blend towards the target palette
    fillnoise8();                                                           // Update the LED array with noise at the new location
  }

  EVERY_N_SECONDS(5) {             // Change the target palette to a random one every 5 seconds.
    Nuage_targetPalette = CRGBPalette16(CHSV(random8(), 255, random8(128,255)), CHSV(random8(), 255, random8(128,255)), CHSV(random8(), 192, random8(128,255)), CHSV(random8(), 255, random8(128,255)));
  }

  LEDS.show();                    // Display the LED's at every loop cycle.
 }
