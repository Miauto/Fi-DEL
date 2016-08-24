#define BlueLed 2
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

#define BRIGHTNESS         255
#define SATURATION         200
#define FRAMES_PER_SECOND  30

String Choix = "Fire";
String Couleur = "";
String Vitesse = "";
uint8_t Hue;

/*========================================
 *        Les INDEX
 =========================================*/
byte RainbowIndex;
byte RainbowCycleIndex;
byte ConfettiIndex;
byte SinelonIndex;

/*=========================================
 *        Variables Nuage Rainbow
 *=========================================*/
static uint16_t Nuage_dist = random16(12345);         // A random number for our noise generator.
uint16_t Nuage_scale = 30;          // Wouldn't recommend changing this on the fly, or the animation will be really blocky.
uint8_t Nuage_maxChanges = 48;      // Value for blending between palettes.
CRGBPalette16 Nuage_currentPalette(CRGB::Black);
CRGBPalette16 Nuage_targetPalette(OceanColors_p);


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
