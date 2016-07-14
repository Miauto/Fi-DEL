#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


#include "Page_Script.js.h"
#include "Pages_html.h"
#include "LedAnim.h"
//#include "Animation.h"
#include "Page_rangeslider.css.h"

#define colorSaturation 255
String Choix = "Fire";
String Couleur = "";
String Vitesse = "";

byte rainbowIndex;
byte theaterChaseRainbowIndex;
byte RainbowCycleIndex;

const int nbssid = 2;

const char *ssid[] = {
//  "ssid1",
//  "ssid2",
};
const char *password[] = {
//  "mdp1",
//  "mdp2",
};

int ErrComm = 0;

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
    //    out += i + ": ";
    //    out += server.argName (i) + "= ";
    //    out += server.arg(i) + "\n";
  }
  //  Couleur = server.arg(0);
  //  Vitesse = server.arg(1);
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

 
void setup ( void ) {
  Serial.begin ( 115200 );
  
  strip.begin();
  strip.show();

  int SSID_N = 0;
  Serial.println ( "" );
  Serial.println ( "Connection au SSID : " );
  Serial.print ( ssid[SSID_N] );
  WiFi.begin ( ssid[SSID_N], password[SSID_N] );
  Serial.println ( "" );
  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
    Serial.print ( ErrComm );
    ErrComm = ErrComm + 1;
    if (ErrComm > 15) {
      SSID_N++;
      if (SSID_N > nbssid) {
        SSID_N = 0;
      }
      ErrComm = 0;
      Serial.println ( "" );
      Serial.println ( "SSID non present" );
      Serial.println ( "Connection au SSID : " );
      Serial.print ( ssid[SSID_N] );
      Serial.println ( "" );
      WiFi.begin ( ssid[SSID_N], password[SSID_N] );
    }
  }
  Serial.println ( "" );
  Serial.print ( "Connecte a " );
  Serial.println ( ssid[SSID_N] );
  Serial.print ( "IP Adresse: " );
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
  server.on ( "/rain", []()  {
    Choix = "Rainbow";
    handleRoot();
  } );
    server.on ( "/RainbowCycle", []()  {
    Choix = "RainbowCycle";
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
  server.on ( "/TwinkleRandom", []()    {
    Choix = "TwinkleRandom";
    handleRoot();
  } );
  server.on ( "/Gyro", []()    {
    Choix = "Gyro";
    handleRoot();
  } );
  server.on ( "/Fire", []()    {
    Choix = "Fire";
    handleRoot();
  } );
  server.on ( "/color", []()    {
    Choix = "color";
    handleRoot();
  } );
    server.on ( "/config", []() {
    server.send ( 200, "text/plain", config_page );
  } );
  server.on ( "/SendAll.js", []() {
    server.send ( 200, "text/plain", PAGE_SendAll_js );
  } );
  server.on ( "/rangeslider.js", []() {
    server.send ( 200, "text/plain", PAGE_rangeslider_js );
  } );
  server.on ( "/rangeslider.min.js", []() {
    server.send ( 200, "text/plain", PAGE_rangeslider_min_js );
  } );
    server.on ( "/Picker.js", []() {
    server.send ( 200, "text/plain", PAGE_Picker_js );
  } );
  server.on ( "/rangeslider.css", []() {
    server.send ( 200, "text/css", PAGE_rangeslider_css );
  } );
  server.onNotFound ( handleNotFound );
  server.begin();
  Serial.println ( "HTTP server started" );
  initLED();
  
  digitalWrite(2, LOW); //extinction de la LED Bleu du ESP
  Serial.println ( "Init Finish" );
}


void loop ( void ) {
  
  mdns.update();
  server.handleClient();
  HexatoDec(Couleur);

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
//    Fire();          // V1
    Fire(1,1000,100); // V2
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
