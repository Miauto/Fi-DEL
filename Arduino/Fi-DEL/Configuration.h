#define BlueLed 2

#define BRIGHTNESS         255
#define FRAMES_PER_SECOND  120

String Choix = "Fire";
String Couleur = "";
String Vitesse = "";

/*========================================
 *        Les INDEX
 =========================================*/
 byte RainbowIndex;
 byte RainbowCycleIndex;
 byte ConfettiIndex;


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
#define ACCESS_POINT_NAME  "Fi-Del"
#define ACCESS_POINT_PASSWORD  "12345678"
