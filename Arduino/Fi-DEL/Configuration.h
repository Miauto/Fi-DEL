
#define BlueLed 2

#define colorSaturation 255
String Choix = "Fire";
String Couleur = "";
String Vitesse = "";

/*========================================
 *        Les INDEX
 =========================================*/
byte rainbowIndex;
byte theaterChaseRainbowIndex;
byte RainbowCycleIndex;


/*=========================================
 *    PARAMETRE WIFI
 ==========================================*/
const int nbssid = 2; // Nombre SSID dans le tableau

// =========== ATTENTION AUX VIRGULES DU TABLEAU =========
const char *ssid[] = { 
  "SSID_1",
  "SSID_2"
};
const char *password[] = {
  "PASS_1",
  "PASS_2"
};

byte ErrComm        = 0;
byte WifiNotFound   = 0;

boolean ModeWifi_STA = true; // Active point accès Wifi si il ne trouve pas de WIFI
boolean EtatWifiSec = false;
#define ACCESS_POINT_NAME  "ESP"        
#define ACCESS_POINT_PASSWORD  "12345678" 
