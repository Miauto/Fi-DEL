#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Adafruit_NeoPixel.h>


#define PIN   0 // GPIO.2 reservé a la led bleu du ESP
#define NbLED 4
#define colorSaturation 255
String Choix = "Rainbow";
String Couleur = "";
String Vitesse = "";
byte Rgb = 0;
byte rGb = 0;
byte rgB = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NbLED, PIN, NEO_GRB + NEO_KHZ800);

const char *ssid = "SSID_1";              // A modifier
const char *password = "SSID_MDP_1";      // A modifier
const char *ssid2 = "SSID_2";             // A modifier
const char *password2 = "SSID_MDP_2";     // A modifier

int ErrComm = 0;

MDNSResponder mdns;
ESP8266WebServer server ( 80 );


void handleRoot() {

    String out = "<html>\n"
    "<head>\n"
    "<meta charset='utf-8'>\n"
    "<title>Fi-DEL</title>\n"
    "<script>\n"
    "\n"
    "var nodes = [\n"
    "    'http://espe0c2f1',\n"      // A modifier > Nom des wemos sur le reseau
    "    'http://espe0bfad',\n"
    "    'http://esp001507',\n"
    "    'http://espe0c786',\n"
    "    'http://esp104d81',\n"
    "]\n"
    "\n"
    "function sendReq(path, params) {\n"
    "    var oReq = new XMLHttpRequest();\n"
    "\n"
    "    if(params) {\n"
    "        var query = objToWWWEncoded(params);\n"
    "        path += '?' + query;\n"
    "    }\n"
    "    \n"
    "    oReq.open('GET', path);\n"
    "    oReq.send();\n"
    "}\n"
    "\n"
    "function objToWWWEncoded(obj) {\n"
    "   var str = '';\n"
    "\n"
    "   for(prop in obj) {\n"
    "     if(str) {\n"
    "       str += '&';\n"
    "     }\n"
    "     str += prop + '=' + encodeURIComponent(obj[prop]);\n"
    "   }\n"
    "\n"
    "   return str;\n"
    "}\n"
    "\n"
    "function formToObj(form) {\n"
    "    var obj = {};\n"
    "    var inputs = form.getElementsByTagName('input');\n"
    "    \n"
    "    for(input of inputs) {\n"
    "       obj[input.name] = input.value;\n"
    "    }\n"
    "\n"
    "    return obj;\n"
    "}\n"
    "\n"
    "function submitForm(form) {\n"
    "   var obj = formToObj(form);\n"
    "   \n"
    "   for(node of nodes) {\n"
    "       sendReq(node + form.getAttribute('action'), obj);\n"
    "   }\n"
    "}\n"
    "\n"
    "function submitLink(a) {\n"
    "   for(node of nodes) {\n"
    "       sendReq(node + a.getAttribute('href'));\n"
    "   }\n"
    "}\n"
    "\n"
    "document.addEventListener('DOMContentLoaded', function(event) {\n"
    "    var forms = document.getElementsByTagName('form');\n"
    "    var as = document.getElementsByTagName('a');\n"
    "\n"
    "    for(element of forms) {\n"
    "        element.addEventListener('submit', function(e) {\n"
    "            e.preventDefault();\n"
    "            submitForm(e.currentTarget);\n"
    "        });\n"
    "    }\n"
    "\n"
    "    for(element of as) {\n"
    "        element.addEventListener('click', function(e) {\n"
    "            e.preventDefault();\n"
    "            submitLink(e.currentTarget);\n"
    "        });\n"
    "    }\n"
    "});\n"
    "\n"
    "</script>\n"
    "</head>\n"
    "<body style='background-color: rgb(12, 24, 36)'>\n"
    "<span style='display:block; width:100%; font-size:2em; font-family:Verdana; text-align:center; color:white'>Fi-Del</span>\n"
    "<br/>\n"
    "<a href='/color?couleur=%23000000&vitesse=0'><span style='display:block; float: left; background-color:Black; width:100%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:White'>BLACKOUT</span></a>\n"
    "<br>\n"
    "<a href='/neige'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Neige</span></a>\n"
    "<a href='/Gyro'><span style='display:block; float: left; background-color:red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Gyro</span></a>\n"
    "<a href='/rainbow'><span style='display:block; float: left; background-color:Orange; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Rainbow</span></a>\n"
    "<a href='/theatre'><span style='display:block; float: left; background-color:pink; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Rainbow Strobe</span></a>\n"
   "<br>\n"
    "<a href='/color?couleur=%23FFFFFF&vitesse=50'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>\n"
    "<a href='/color?couleur=%23FFFFFF&vitesse=75'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>\n"
    "<a href='/color?couleur=%23FFFFFF&vitesse=100'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>\n"
    "<a href='/color?couleur=%23FFFFFF&vitesse=0'><span style='display:block; float: left; background-color:white; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>BLANC</span></a>\n"
    
    "<a href='/color?couleur=%230000FF&vitesse=50'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>\n"
    "<a href='/color?couleur=%230000FF&vitesse=75'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>\n"
    "<a href='/color?couleur=%230000FF&vitesse=100'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>\n"
    "<a href='/color?couleur=%230000FF&vitesse=0'><span style='display:block; float: left; background-color:blue; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>BLEU</span></a>\n"
    
    "<a href='/color?couleur=%23FF0000&vitesse=50'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>\n"
    "<a href='/color?couleur=%23FF0000&vitesse=75'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>\n"
    "<a href='/color?couleur=%23FF0000&vitesse=100'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>\n"
    "<a href='/color?couleur=%23FF0000&vitesse=0'><span style='display:block; float: left; background-color:Red; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>ROUGE</span></a>\n"
    
    "<a href='/color?couleur=%2300FF00&vitesse=50'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 50ms</span></a>\n"
    "<a href='/color?couleur=%2300FF00&vitesse=75'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 75ms</span></a>\n"
    "<a href='/color?couleur=%2300FF00&vitesse=100'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>Strobe 100ms</span></a>\n"
    "<a href='/color?couleur=%2300FF00&vitesse=0'><span style='display:block; float: left; background-color:green; width:25%; height:5em;font-size:2em; font-family:Verdana; text-align:center; color:Black'>VERT</span></a>\n"
    
    "<br/>\n"
    "<center>\n"
    "<form action='/color' method='get'>\n"
    "<input type='color' style='width:50%;height:6em' name='couleur' value=#ffffff>\n"
    "<br>\n"
    "<br>\n"
    "<button>envoye</button>\n"
    "<h1 style='color:white'>Vitesse</h1>\n"
    "<br>\n"
    "<br>\n"
    "<input type='range' value='0' max='250' min='0' step='50' style='width:90%;height:6em' name='vitesse'>\n"
    "</form>\n"
    "</center>\n"
    "</body>\n"
    "</html>\n";

  
    for ( uint8_t i = 0; i < server.args(); i++ ) {
      if (server.argName (i) == "couleur" ) { Couleur = server.arg(i); }
      if (server.argName (i) == "vitesse" ) { Vitesse = server.arg(i); }
        out += i + ": ";
        out += server.argName (i) + "= ";
        out += server.arg(i) + "\n";
    }
    Couleur = server.arg(0);
    Vitesse = server.arg(1);
    server.send ( 200, "text/html", out );
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
  for(int i = 0; i < NbLED; i++ ) {
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
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
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

  *j = *j+1;
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+*j) & 255));
    }
    strip.show();
    delay(wait);
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait,  unsigned char* j) {
  *j = *j+1;     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+*j) % 255));    //turn every third pixel on
        }
        strip.show();

        delay(wait);

        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  
}

// effet neige
void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red,green,blue);
  
  int Pixel = random(NbLED);
  setPixel(Pixel,0xff,0xff,0xff);
  showStrip();
  delay(SparkleDelay);
  setPixel(Pixel,red,green,blue);
  showStrip();
  delay(SpeedDelay);
}

// Strobe
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
    setAll(red,green,blue);
    showStrip();
    delay(FlashDelay);
    setAll(0,0,0);
    showStrip();
    delay(FlashDelay);
  }
 
 delay(EndPause);
}


void LeftToRight(byte red, byte green, byte blue, int SpeedDelay, int ReturnDelay) {
  for(int i = 0; i < NbLED; i++) {
    setAll(red/100, green/100, blue/100);
    
    setPixel(i, red, green, blue);
    
    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}


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
    digitalWrite(2, LOW);
      
    strip.begin();
    strip.show();

    Serial.begin ( 115200 );
    WiFi.begin ( ssid, password );
    Serial.println ( "" );
    // Wait for connection
    while ( WiFi.status() != WL_CONNECTED ) {
        delay ( 500 );
        Serial.print ( "." );
        ErrComm = ErrComm + 1;
        if (ErrComm > 20) {
          ErrComm = 0;
          WiFi.begin ( ssid2, password2 );
        }
    }
    Serial.println ( "" );
    Serial.print ( "Connected to " );
    Serial.println ( ssid );
    Serial.print ( "IP address: " );
    Serial.println ( WiFi.localIP() );
    if ( mdns.begin ( "esp8266", WiFi.localIP() ) ) {
        Serial.println ( "MDNS responder started" );
    }
    server.on ( "/", []() {handleRoot();} );
    server.on ( "/rainbow", []()  {Choix = "Rainbow"; handleRoot(); } );
    server.on ( "/theatre", []()  {Choix = "theaterChaseRainbow"; handleRoot();} );
    server.on ( "/neige", []()    {Choix = "neige"; handleRoot();} );
    server.on ( "/Gyro", []()    {Choix = "Gyro"; handleRoot();} );
    server.on ( "/color", []()    {Choix = "color"; handleRoot();} );
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
      SnowSparkle(0x10, 0x10, 0x10, 20, random(100,1000));
    } else if (Choix == "theaterChaseRainbow") {
      theaterChaseRainbow(50, &theaterChaseRainbowIndex);
    } else if (Choix == "Rainbow") {
      rainbow(500, &rainbowIndex);
    } else if (Choix == "Gyro") {
      LeftToRight(255, 0, 0, 75, 0);
    } else if (Choix == "color") {
      
        if ( Vitesse.toInt() > 0 ) { Strobe(Rgb, rGb, rgB, 1, Vitesse.toInt(), 0);} else { setAll(Rgb, rGb, rgB);}
    }
    
    if (Choix == "") {} else { Serial.println (Choix); }
    if (Couleur == "") {} else { Serial.println (Couleur);}
                                    
}

