#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>

#include "Configuration.h"
#include "Page_Script.js.h"
#include "Pages_html.h"
#include "LedAnim.h"
//#include "Animation.h"
#include "Page_Style.css.h"




MDNSResponder mdns;
ESP8266WebServer server ( 80 );


void handleRoot() {
  server.send ( 200, "text/html", main_page );
  for ( uint8_t i = 0; i < server.args(); i++ ) {
    if (server.argName (i) == "couleur" ) {
      Couleur = server.arg(i);
    }
    if (server.argName (i) == "vitesse" ) {
      Vitesse = server.arg(i);
    }
  }
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
  strip.begin();
  strip.show();

  /*======================================
              Debut Connection WIFI
    ======================================*/

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  int SSID_N = 0;
  Serial.println ( "" );
  Serial.println ( "Connection au SSID : " );
  Serial.print ( ssid[SSID_N] );
  WiFi.begin ( ssid[SSID_N], password[SSID_N] );
  Serial.println ( "" );
  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED && WifiNotFound <= 3) {
    delay ( 500 );
    Serial.print ( "." );
    Serial.print ( ErrComm );
    ErrComm = ErrComm + 1;
    if (ErrComm > 15) {
      Serial.println ( "" );
      Serial.println ( "SSID non present" );
      SSID_N++;
      if (SSID_N > (nbssid - 1) ) {
        SSID_N = 0;
        Blink(255, 0, 0, 100, 100, 3);
        Blink(0, 0, 255, 100, 100, 1); // clignotte 3 fois rouge et 1 bleu pour erreur wifi
        WifiNotFound = WifiNotFound + 1;
      }
      ErrComm = 0;
      Serial.println ( "" );
      Serial.println ( "Connection au SSID : " );
      Serial.print ( ssid[SSID_N] );
      Serial.println ( "" );
      WiFi.begin ( ssid[SSID_N], password[SSID_N] );
    }
  }
  if ( WiFi.status() == WL_CONNECTED ) {
    Serial.println ( "" );
    Serial.print ( "Connecte a " );
    Serial.println ( ssid[SSID_N] );
    Serial.print ( "IP Adresse: " );
    Serial.println ( WiFi.localIP() );
  }

  if ( WifiNotFound > 3 && ModeWifi_STA == true) {
    Serial.println ( "" );
    Serial.println ( "Creation de point Wifi " );
    WiFi.mode(WIFI_AP);
    WiFi.softAP( ACCESS_POINT_NAME , ACCESS_POINT_PASSWORD);
    Serial.println ( "" );
    Serial.print ( "SSID : " );
    Serial.println ( ACCESS_POINT_NAME );
    Serial.print ( "PASSWORD : " );
    Serial.println ( ACCESS_POINT_PASSWORD );
    Serial.print ( "IP Adresse: " );
    Serial.println ( WiFi.localIP() );
  }



  /*======================================
              Fin Connection WIFI
    ======================================*/

  if ( mdns.begin ( "esp8266", WiFi.localIP() ) ) {
    Serial.println ( "MDNS responder started" );
  }
  server.on ( "/", []() {
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/rainbow", []()  {
    Choix = "Rainbow";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/rain", []()  {
    Choix = "Rainbow";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/RainbowCycle", []()  {
    Choix = "RainbowCycle";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/theatre", []()  {
    Choix = "theaterChaseRainbow";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/neige", []()    {
    Choix = "neige";
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
  server.on ( "/Fire", []()    {
    Choix = "Fire";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/color", []()    {
    Choix = "color";
    digitalWrite(BlueLed, LOW);
    handleRoot();
  } );
  server.on ( "/config", []() {
    Choix = "config";
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
  server.on ( "/Picker.js", []() {
    digitalWrite(BlueLed, LOW);
    server.send ( 200, "text/plain", PAGE_Picker_js );
  } );
  server.on ( "/Style.css", []() {
    digitalWrite(BlueLed, LOW);
    server.send ( 200, "text/css", PAGE_Style_css );
  } );
  server.onNotFound ( handleNotFound );
  server.begin();
  Serial.println ( "HTTP server started" );
  initLED();
  Serial.println ( "Init Finish" );
}


void loop ( void ) {

  mdns.update();
  server.handleClient();
  HexatoDec(Couleur);
  //  pinMode(BlueLed, OUTPUT);
  digitalWrite(BlueLed, HIGH);

  if (Choix == "neige") {
    SnowSparkle(0x10, 0x10, 0x10, 100, random(200, 1000));
  } else if (Choix == "theaterChaseRainbow") {
    theaterChaseRainbow(50, &theaterChaseRainbowIndex);
  } else if (Choix == "Rainbow") {
    rainbow(500, &rainbowIndex);
  } else if (Choix == "RainbowCycle") {
    RainbowCycle(&RainbowCycleIndex);
  } else if (Choix == "Gyro") {
    LeftToRight(255, 0, 0, 75, 0);
  } else if (Choix == "TwinkleRandom") {
    TwinkleRandom(500, false);
  } else if (Choix == "Fire") {
    Fire(1, 1000, 100);
  } else if (Choix == "color") {

    if ( Vitesse.toInt() > 0 ) {
      Strobe(Rgb, rGb, rgB, 1, Vitesse.toInt(), 0);
    } else {
      setAll(Rgb, rGb, rgB);
    }
  }

  if (Choix != "") {
    //    Serial.println (Choix);
  }
  if (Couleur != "") {
    //    Serial.println (Couleur);
  }

}

