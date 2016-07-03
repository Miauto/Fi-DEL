#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Adafruit_NeoPixel.h>

#include "Page_Script.js.h"
#include "html_pages.h"
#include "LedAnim.h"

#define PIN   2
#define NbLED 4
#define colorSaturation 255
String Choix = "Rainbow"; // demarre sur l'effet Rainbow
String Couleur = "";
String Vitesse = "";
byte Rgb = 0;
byte rGb = 0;
byte rgB = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NbLED, PIN, NEO_GRB + NEO_KHZ800);

const char *ssid[] = {"SSID1", "SSID2", "SSID3", "SSID4"};
const char *password[] = {"PASS1", "PASS2", "PASS3", "PASS4"};


int ErrComm = 0;


MDNSResponder mdns;
ESP8266WebServer server ( 80 );


void handleRoot() {
  server.send ( 200, "text/html", main_page );
//  for ( uint8_t i = 0; i < server.args(); i++ ) {
//    if (server.argName (i) == "couleur" ) {
//      Couleur = server.arg(i);
//    }
//    if (server.argName (i) == "vitesse" ) {
//      Vitesse = server.arg(i);
//    }
//    out += i + ": ";
//    out += server.argName (i) + "= ";
//    out += server.arg(i) + "\n";
//  }
  Couleur = server.arg(0);
  Vitesse = server.arg(1);
//  server.send ( 200, "text/html", out );
}
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }

  server.send ( 404, "text/plain", message );
}

///////////////////////
// Les fonctions LED //
///////////////////////

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

void HexatoDec(String Hexa) {
  // Get rid of '#' and convert it to integer
  int number = (int) strtol( &Hexa[1], NULL, 16);

  // Split them up into r, g, b values
  Rgb = number >> 16;
  rGb = number >> 8 & 0xFF;
  rgB = number & 0xFF;
}

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

// Rainbow
void rainbow(uint8_t wait, unsigned char* j) {
  int i;

  *j = *j + 1;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel((i + *j) & 255));
  }
  strip.show();
  delay(wait);
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait,  unsigned char* j) {
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

// effet neige
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

// Strobe
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

/*
void LeftToRight(byte red, byte green, byte blue, int SpeedDelay, int ReturnDelay) {
  for (int i = 0; i < NbLED; i++) {
    setAll(red / 100, green / 100, blue / 100);

    setPixel(i, red, green, blue);

    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}
*/

void initLED()
{
  setAll(127, 0, 0);
  delay(500);
  setAll(0, 127, 0);
  delay(500);
  setAll(0, 0, 127);
  delay(500);
  setAll(127, 127, 127);
  delay(1000);
  setAll(0, 0, 0);
}



void setup ( void ) {
  Serial.begin ( 115200 );

  strip.begin();
  strip.show();

  int i = 1;
    WiFi.begin ( ssid[i], password[i] );
    Serial.println ( "" );
    // Wait for connection
    while ( WiFi.status() != WL_CONNECTED ) {
        delay ( 500 );
        Serial.print ( "." );
        ErrComm = ErrComm + 1;
        if (ErrComm > 10) {
          i++;
          ErrComm = 0;
          WiFi.begin ( ssid[i], password[i] );
        }
    }
    Serial.println ( "" );
    Serial.print ( "Connected to " );
    Serial.println ( ssid[i] );
    Serial.print ( "IP address: " );
    Serial.println ( WiFi.localIP() );
    
  if ( mdns.begin ( "esp8266", WiFi.localIP() ) ) {
    Serial.println ( "MDNS responder started" );
  }
  server.on ( "/", []() {
    handleRoot();
  } );
  server.on ( "/rainbow", []()  {
    Choix = "Rainbow";
    handleRoot();
  } );
  server.on ( "/theatre", []()  {
    Choix = "theaterChaseRainbow";
    handleRoot();
  } );
  server.on ( "/neige", []()    {
    Choix = "neige";
    handleRoot();
  } );
  server.on ( "/Gyro", []()    {
    Choix = "Gyro";
    handleRoot();
  } );
  server.on ( "/color", []()    {
    Choix = "color";
    handleRoot();
  } );
  server.on ( "/SendAll.js", []() { Serial.println("SendAll.js"); server.send ( 200, "text/plain", PAGE_SendAll_js );  } );
  server.onNotFound ( handleNotFound );
  server.begin();
  Serial.println ( "HTTP server started" );
  initLED();
  Serial.println ( "Init Finish" );
}


void loop ( void ) {
  unsigned char rainbowIndex;
  unsigned char theaterChaseRainbowIndex;

  mdns.update();
  server.handleClient();
  HexatoDec(Couleur);

  if (Choix == "neige") {
    SnowSparkle(0x10, 0x10, 0x10, 20, random(100, 1000));
  } else if (Choix == "theaterChaseRainbow") {
    theaterChaseRainbow(50, &theaterChaseRainbowIndex);
  } else if (Choix == "Rainbow") {
    rainbow(500, &rainbowIndex);
  } else if (Choix == "Gyro") {
    LeftToRight(255, 0, 0, 75, 0);
  } else if (Choix == "color") {

    if ( Vitesse.toInt() > 0 ) {
      Strobe(Rgb, rGb, rgB, 1, Vitesse.toInt(), 0);
    } else {
      setAll(Rgb, rGb, rgB);
    }
  }

  if (Choix == "") {} else {
    Serial.println (Choix);
  }
  if (Couleur == "") {} else {
    Serial.println (Couleur);
  }

}
