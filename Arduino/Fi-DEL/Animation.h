#define DATA_PIN    0         // Borne Data
#define MAX_NUM_LEDS    99         // Nombre de Leds
int NUM_LEDS;

#define COLOR_ORDER GRB       // Ordre des couleurs
#define LED_TYPE    WS2812B   // Types des Leds


CRGB leds[MAX_NUM_LEDS];          // Tableau de leds
CRGBSet ledSet(leds, NUM_LEDS);    //Setup FastLED


void StartFastLED(){
FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
FastLED.setBrightness(BRIGHTNESS);
}


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
    leds[i].setRGB( red, green, blue);
  }
  FastLED.show();
}

void setAllHue(uint8_t gHue, uint8_t Sat, uint8_t Bri) {
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( gHue, Sat, Bri);
  }
  FastLED.show();
}

void Blackout (){
  fadeToBlackBy( leds, NUM_LEDS, 50);
  FastLED.show();
}

////////////////////////// Blink START
void Blink(byte red, byte green, byte blue, int DelayOff, int DelayOn, int Nb) {
  for (int i = 0; i < Nb; i++) {
    setAll(red, green, blue);
    FastLED.delay(DelayOn);
    setAll(0, 0, 0);
    FastLED.delay(DelayOff);
  }
}
////////////////////////// Blink END


////////////////////////// setPixelHeatColor START
void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);

  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252

  // figure out which third of the spectrum we're in:
  if ( t192 > 0x80) {                    // hottest
    setPixel(Pixel, heatramp,  heatramp / 5, 0);
    //    Serial.print (heatramp);
    //    Serial.println ("    Hot");
  } else if ( t192 > 0x40 ) {            // middle
    setPixel(Pixel, heatramp, heatramp / 4, 0);
    //    Serial.print (heatramp);
    //    Serial.println ("    Mid");
  } else {                               // coolest
    setPixel(Pixel, heatramp, heatramp / 3, 0);
    //    Serial.print (heatramp);
    //    Serial.println ("    Cool");
  }
}
////////////////////////// END

////////////////////////// LeftToRight START
void LeftToRight(byte red, byte green, byte blue, int SpeedDelay, int ReturnDelay, byte* gHue) {
  for (int i = 0; i < NUM_LEDS; i++) {
    setAll(0, 0, 0);

    setPixel(i, red, green, blue);
    FastLED.show();
    FastLED.delay(SpeedDelay / NUM_LEDS);
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


////////////////////////// Rainbow
void Rainbow(uint16_t wait, byte* j) {
  *j += 1;
  fill_rainbow( leds, NUM_LEDS, *j, 0);
  FastLED.show();
  FastLED.delay(1000 / wait);
}
////////////////////////// END

////////////////////////// Rainbow Cycle
void RainbowCycle(uint16_t wait, byte* j) {
  *j += 1;
  fill_rainbow( leds, NUM_LEDS, *j, NUM_LEDS / 2 );
  FastLED.show();
  FastLED.delay(1000 / wait);
}
////////////////////////// END


////////////////////////// effet neige START
void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red, green, blue);
  int Pixel = random(NUM_LEDS);
  setPixel(Pixel, 0xff, 0xff, 0xff);
  FastLED.show();
  FastLED.delay(SparkleDelay);
  setPixel(Pixel, red, green, blue);
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
////////////////////////// END

////////////////////////// Strobe START
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause) {
  for (int j = 0; j < StrobeCount; j++) {
    setAll(red, green, blue);
    FastLED.show();
    FastLED.delay(FlashDelay);
    setAll(0, 0, 0);
    FastLED.show();
    FastLED.delay(FlashDelay);
  }
  delay(EndPause);
}
////////////////////////// END

////////////////////////// TwinkleRandom START
void TwinkleRandom(boolean OnlyOne, uint8_t Sat, uint8_t Bri) {
  if (OnlyOne) {
    setAll(0, 0, 0);
  }
  leds[random(NUM_LEDS)] = CHSV( random(254), Sat, Bri);
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
////////////////////////// TwinkleRandom END

////////////////////////// Fire Start
void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[MAX_NUM_LEDS];
  int cooldown;

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < NUM_LEDS; i++) {
    cooldown = random(0, ((Cooling * 10) / NUM_LEDS) + 2);
    if (cooldown > heat[i]) {
      heat[i] = 0;
    } else {
      heat[i] = heat[i] - cooldown;
    }
  }
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if ( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160, 255);
    //heat[y] = random(160,255);
  }
  // Step 4.  Convert heat to LED colors
  for ( int j = 0; j < NUM_LEDS; j++) {
    setPixelHeatColor(j, heat[j] );
  }
  FastLED.show();
  FastLED.delay(random(SpeedDelay));
}
////////////////////////// FIRE END


////////////////////////// INIT START
void initLED()
{
  setAll(127, 0, 0);
  FastLED.delay(500);
  setAll(0, 127, 0);
  FastLED.delay(500);
  setAll(0, 0, 127);
  FastLED.delay(500);
  setAll(127, 127, 127);
  FastLED.delay(500);
}
////////////////////////// INIT END

/*///////////////////////////////////
              GLITTER
  ////////////////////////////////////*/
void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
  FastLED.show();
}
/*****************************************
              FIN GLITTER
*******************************************/


/*///////////////////////////////////
            RAINBOW GLITTER
  ////////////////////////////////////*/
void RainbowWithGlitter(uint16_t wait)
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  Rainbow(wait/2, &RainbowIndex);
  addGlitter(80);
  FastLED.delay(wait/2);
}
/*****************************************
           FIN  RAINBOW GLITTER
*******************************************/

/*///////////////////////////////////
             CONFETTI
  ////////////////////////////////////*/
void Confetti(byte* gHue)
{
  *gHue += 1;
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( *gHue + random8(64), 200, 255);
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
/*****************************************
              END CONFETTI
*******************************************/

void Sinelon(byte* gHue)
{
  *gHue += 1;
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS);
  leds[pos] += CHSV( *gHue, 255, 192);
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}

void Bpm(byte* gHue)
{
  *gHue += 1;
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for ( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, *gHue + (i * 2), beat - *gHue + (i * 10));
  }
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}

void Juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for ( int i = 0; i < 8; i++) {
    leds[beatsin16(i + 7, 0, NUM_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}

/*////////////////////////////
          FIRE 2012
*////////////////////////////
void Fire2012(bool gReverseDirection, int COOLING /* 55 */, byte SPARKING /* 120 */) {

  // Array of temperature readings at each simulation cell
  static byte heat[MAX_NUM_LEDS];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < NUM_LEDS; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < NUM_LEDS; j++) {
    CRGB color = HeatColor( heat[j]);
    int pixelnumber;
    if ( gReverseDirection ) {
      pixelnumber = (NUM_LEDS - 1) - j;
    } else {
      pixelnumber = j;
    }
    leds[pixelnumber] = color;
  }
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}

/*////////////////////////////////
            Nuage
*////////////////////////////////
void fillnoise8() {
  for (int i = 0; i < NUM_LEDS; i++) {                                     // Just ONE loop to fill up the LED array as all of the pixels change.
    uint8_t index = inoise8(i * Nuage_scale, Nuage_dist + i * Nuage_scale) % 255;            // Get a value from the noise function. I'm using both x and y axis.
    leds[i] = ColorFromPalette(Nuage_currentPalette, index, 255, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.
  }
  Nuage_dist += beatsin8(10, 1, 4);                                              // Moving along the distance (that random number we started out with). Vary it a bit with a sine wave.
  // In some sketches, I've used millis() instead of an incremented counter. Works a treat.
}

void Nuage() {
  EVERY_N_MILLISECONDS(10) {
    nblendPaletteTowardPalette(Nuage_currentPalette, Nuage_targetPalette, Nuage_maxChanges);  // Blend towards the target palette
    fillnoise8();                                                           // Update the LED array with noise at the new location
  }

  EVERY_N_SECONDS(5) {             // Change the target palette to a random one every 5 seconds.
    Nuage_targetPalette = CRGBPalette16(CHSV(random8(), 255, random8(128, 255)), CHSV(random8(), 255, random8(128, 255)), CHSV(random8(), 192, random8(128, 255)), CHSV(random8(), 255, random8(128, 255)));
  }

  FastLED.show();                    // Display the LED's at every loop cycle.
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}

/*////////////////////////////////
            Ripples
*////////////////////////////////
int Rip_wrap(int Rip_step) {
  if(Rip_step < 0) return NUM_LEDS + Rip_step;
  if(Rip_step > NUM_LEDS - 1) return Rip_step - NUM_LEDS;
  return Rip_step;
}

void one_color_allHSV(int ahue, int abright) {                // SET ALL LEDS TO ONE COLOR (HSV)
  for (int i = 0 ; i < NUM_LEDS; i++ ) {
    leds[i] = CHSV(ahue, 255, abright);
  }
}

void Ripple() {
 
    if (Rip_currentBg == Rip_nextBg) {
      Rip_nextBg = random(256);
    }
    else if (Rip_nextBg > Rip_currentBg) {
      Rip_currentBg++;
    } else {
      Rip_currentBg--;
    }
    for(uint16_t l = 0; l < NUM_LEDS; l++) {
      leds[l] = CHSV(Rip_currentBg, 255, 50);
    }
  if (Rip_step == -1) {
    Rip_center = random(NUM_LEDS);
    Rip_color = random(256);
    Rip_step = 0;
  }
  if (Rip_step == 0) {
    leds[Rip_center] = CHSV(Rip_color, 255, 255);
    Rip_step ++;
  }
  else {
    if (Rip_step < Rip_maxSteps) {
      Serial.println(pow(Rip_fadeRate,Rip_step));
 
      leds[Rip_wrap(Rip_center + Rip_step)] = CHSV(Rip_color, 255, pow(Rip_fadeRate, Rip_step)*255);
      leds[Rip_wrap(Rip_center - Rip_step)] = CHSV(Rip_color, 255, pow(Rip_fadeRate, Rip_step)*255);
      if (Rip_step > 3) {
        leds[Rip_wrap(Rip_center + Rip_step - 3)] = CHSV(Rip_color, 255, pow(Rip_fadeRate, Rip_step - 2)*255);
        leds[Rip_wrap(Rip_center - Rip_step + 3)] = CHSV(Rip_color, 255, pow(Rip_fadeRate, Rip_step - 2)*255);
      }
      Rip_step ++;
    }
    else {
      Rip_step = -1;
    }
  }
 
  FastLED.show();                    // Display the LED's at every loop cycle.
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}
