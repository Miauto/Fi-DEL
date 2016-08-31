#define BlueLed 2
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

String Choix = "Fire";
String Couleur = "";
String Vitesse = "";
uint8_t Hue;
byte Rgb = 0;
byte rGb = 0;
byte rgB = 0;


uint8_t BRIGHTNESS         = 255;
uint8_t SATURATION         = 200;
uint8_t FRAMES_PER_SECOND  = 30;

/*========================================
 *        Les INDEX
 =========================================*/
byte RainbowIndex;
byte RainbowCycleIndex;
byte ConfettiIndex;
byte SinelonIndex;
byte BpmIndex;

/*=========================================
 *        Variables Nuage Rainbow
 *=========================================*/
static uint16_t Nuage_dist = random16(12345);         // A random number for our noise generator.
uint16_t Nuage_scale = 30;          // Wouldn't recommend changing this on the fly, or the animation will be really blocky.
uint8_t Nuage_maxChanges = 48;      // Value for blending between palettes.
CRGBPalette16 Nuage_currentPalette(CRGB::Black);
CRGBPalette16 Nuage_targetPalette(OceanColors_p);

/*=========================================
 *        Variables Ripples
 *=========================================*/
int Rip_color;
int Rip_center = 0;
int Rip_step = -1;
int Rip_maxSteps = 16;
float Rip_fadeRate = 0.8;
int Rip_diff;
//background color
uint32_t Rip_currentBg = random(256);
uint32_t Rip_nextBg = Rip_currentBg;



/*=========================================
 *        HTTP GET
 ========================================*/

 // Les serveur à interroger
const char *AdrServeur[] = {
  "perdu.com",
  ""
};

