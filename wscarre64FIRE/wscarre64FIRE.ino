#include <FastLED.h>

// nombre de leds
#define NBRPIX 64

// matrice pour calculer l'image
uint8_t firematrice[8][8];

// tableau de leds
CRGB leds[NBRPIX];
// palette
CRGBPalette16 gPal;

void setup() {
  // initialisation du PRNG
  randomSeed(analogRead(0));

  // configuration des leds
  FastLED.addLeds<WS2812B, 6, GRB>(leds, NBRPIX);
  // ajustement luminosité
  FastLED.setBrightness(155);
  // initialisation palette personnalisée
  gPal = CRGBPalette16(CRGB::Black, CRGB::Red, CRGB::Red, CRGB::Yellow,
                       CRGB::Yellow, CRGB::Yellow, CRGB::Yellow, CRGB::White,
                       CRGB::White, CRGB::White, CRGB::White, CRGB::White,
                       CRGB::White, CRGB::White, CRGB::White, CRGB::White);
}

void loop() {
  // On ajoute peut-être un pixel chaud en bas
  // 2 chances sur 3
  if(random(0,3)) {
    firematrice[0][random(0,8)] = random(160,256);
  }

  // On lisse la desnière ligne en faisant la moyenne
  for (int x=0; x<8; x++) {
    firematrice[0][x]=
      (firematrice[0][(x-1>0) ? x-1 : 7]+
      firematrice[0][x]+
      firematrice[0][(x+1<7) ? x+1 : 0])/4;
  }

  // Pour chaque pixel on fait une moyen des pixels plus bas
  // et on divise pour "refroidir" le tout
  for (int y=1; y<8; y++) {
    for(int x=0; x<8; x++) {
      firematrice[y][x]=
        (firematrice[y-1][(x-1>0) ? x-1 : 7]+
        firematrice[y-1][x]+
        firematrice[y-1][(x+1<7) ? x+1 : 0])/4;
    }

    // Après chaque ligne traitée, on rafraichi l'affichage
    for(int i=0; i<8; i++) {
      for(int j=0; j<8; j++) {
        // on applique la palette aux leds
        CRGB color = ColorFromPalette(gPal, firematrice[i][j]);
        leds[(j*8)+i]=color;
      }
    }
    // affichage
    FastLED.show();
    delay(10);
  }
}

