#include <EEPROM.h>
#include <FastLED.h>
FASTLED_USING_NAMESPACE

#include "Configuration.h"
#include "Page_Script.js.h"
#include "Pages_html.h"
#include "Animation.h"
#include "Page_Style.css.h"
#include "SetupWifi.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

uint8_t mBRIGHTNESS ;
uint8_t mSATURATION ;



void handleRoot() {
  server.send ( 200, "text/html", main_page );
  for ( uint8_t i = 0; i < server.args(); i++ ) {
    if (server.argName (i) == "couleur" ) {
      Couleur = server.arg(i);
    }
    if (server.argName (i) == "vitesse" ) {
      Vitesse = server.arg(i);
    }
    if (server.argName (i) == "Hue" ) {
      Hue = server.arg(i).toInt();
    }
    if (server.argName (i) == "Lumiere" ) {
      mBRIGHTNESS = server.argName (i).toInt();
    }
    if (server.argName (i) == "Saturation" ) {
      mSATURATION = server.argName (i).toInt();
    }
  }
  /*
    Couleur = server.arg("couleur");
    Vitesse = server.arg("vitesse");
    Hue = server.arg("Hue").toInt();
  */
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


void setup ( void ) {
  Serial.begin ( 115200 );
  pinMode(BlueLed, OUTPUT);
  digitalWrite(BlueLed, LOW); //Allumage de la LED Bleu du ESP pendant la phase d'init

  /*//////////////////////
            EEPROM
  *//////////////////////
  EEPROM.begin(512);
  delay(10);
  Serial.println();
  Serial.println();
  // read eeprom for ssid and pass
  Serial.println("Lecture EEPROM");
  String esid;
  for (int i = 0; i < 32; ++i)
  {
    esid += char(EEPROM.read(i));
  }
  Serial.print("SSID: ");
  Serial.println(esid);
  String epass = "";
  for (int i = 32; i < 96; ++i)
  {
    epass += char(EEPROM.read(i));
  }
  Serial.print("PASS: ");
  Serial.println(epass);

    uint8_t eNUM_LEDS = 0;
      NUM_LEDS = int(EEPROM.read(96));
      if (NUM_LEDS == 0) { NUM_LEDS = 1; }
  Serial.print("Nombre de LEDs: ");
  Serial.println(NUM_LEDS);
  
StartFastLED();

  /*======================================
              Debut Connection WIFI
    ======================================*/

  if ( esid.length() > 1 ) { //EEPROM NON VIDE
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    WiFi.begin(esid.c_str(), epass.c_str()); //TEST de la connection
    if (testWifi()) {   // SI la connection est bonne alors on lance le serveur
      launchWeb(0);
    } else {            // SINON creation d'un reseau wifi
      setupAP();
    }
  } else { //EEPROM VIDE
    setupAP();
  }

  /*======================================
              Fin Connection WIFI
    ======================================*/

  MDNSConnect();

  server.on ( "/", []() {
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Rainbow", []()  {
    Choix = "Rainbow";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Rain", []()  {
    Choix = "Rainbow";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/RainbowCycle", []()  {
    Choix = "RainbowCycle";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Neige", []()    {
    Choix = "Neige";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/TwinkleRandom", []()    {
    Choix = "TwinkleRandom";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Gyro", []()    {
    Choix = "Gyro";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Nuage", []()    {
    Choix = "Nuage";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Juggle", []()    {
    Choix = "Juggle";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Bpm", []()    {
    Choix = "Bpm";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Ripple", []()    {
    Choix = "Ripple";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Fire", []()    {
    Choix = "Fire";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Confetti", []()    {
    Choix = "Confetti";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/RainbowWithGlitter", []()    {
    Choix = "RainbowWithGlitter";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Sinelon", []()    {
    Choix = "Sinelon";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Blackout", []()    {
    Choix = "Blackout";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/color", []()    {
    Choix = "color";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/Config", []() {
//    Choix = "Config";
    digitalWrite(BlueLed, LOW);
    server.send ( 200, "text/html", config_page );
  } );
  server.on ( "/SendAll.js", []() {
    digitalWrite(BlueLed, LOW);
    server.send ( 200, "text/plain", PAGE_SendAll_js );
  } );
  server.on ( "/rangeslider.js", []() {
    digitalWrite(BlueLed, LOW);
    server.send ( 200, "text/plain", PAGE_rangeslider_js );
  } );
  server.on ( "/rangeslider.min.js", []() {
    digitalWrite(BlueLed, LOW);
    server.send ( 200, "text/plain", PAGE_rangeslider_min_js );
  } );
  server.on ( "/Style.css", []() {
    digitalWrite(BlueLed, LOW);
    server.send ( 200, "text/css", PAGE_Style_css );
  } );
  server.onNotFound ( handleNotFound );
  server.begin();
  httpUpdater.setup(&server);
  Serial.println ( "HTTP server started" );
  initLED();
  Serial.println ( "Init Finish" );
}


void loop ( void ) {

  mdns.update();
  server.handleClient();
  digitalWrite(BlueLed, HIGH);

  if (Choix == "Neige") {
    SnowSparkle(0x10, 0x10, 0x10, 100, random(200, 1000));
  } else if (Choix == "Rainbow") {
    Rainbow(FRAMES_PER_SECOND/2, &RainbowIndex);
  } else if (Choix == "RainbowWithGlitter") {
    RainbowWithGlitter(FRAMES_PER_SECOND);
  } else if (Choix == "RainbowCycle") {
    RainbowCycle(FRAMES_PER_SECOND/2, &RainbowCycleIndex);
  } else if (Choix == "Gyro") {
    LeftToRight(255, 0, 0, 300, 0, &SinelonIndex);
  } else if (Choix == "TwinkleRandom") {
    TwinkleRandom(false, SATURATION, BRIGHTNESS);
  } else if (Choix == "Confetti") {
    Confetti(&ConfettiIndex);
  } else if (Choix == "Sinelon") {
    Sinelon(&SinelonIndex);
  } else if (Choix == "Nuage") {
    Nuage();
  } else if (Choix == "Juggle") {
    Juggle();
  } else if (Choix == "Bpm") {
    Bpm(&BpmIndex);
  } else if (Choix == "Ripple") {
    Ripple();
  } else if (Choix == "Fire") {
    Fire(1, 1000, 100);
    //    Fire2012(false, 200, 80);
  } else if (Choix == "Blackout") {
    Blackout();
  } else if (Choix == "color") {
    if (Couleur != "") {
      Serial.println (Couleur);
      HexatoDec(Couleur);
      Couleur = "";
    } else if (Hue > 0) {
      Serial.println (Hue);
      setAllHue( Hue, SATURATION, BRIGHTNESS);
      Rgb = leds[1].r;
      rGb = leds[1].g;
      rgB = leds[1].b;
      Hue = 0;
    } else if ( Vitesse.toInt() > 0 ) {
      Strobe(Rgb, rGb, rgB, 1, Vitesse.toInt(), 0);
      Serial.println (Vitesse);
    } else
    setAll(Rgb, rGb, rgB);
    Serial.println (Rgb);
    Serial.println (rGb);
    Serial.println (rgB);
  }

  if (Choix != "") {
    //Serial.println (Choix);
  }
  if (Couleur != "") {
  }
  if (Hue > 0 ) {
    //Serial.println (Hue);
  }
}
