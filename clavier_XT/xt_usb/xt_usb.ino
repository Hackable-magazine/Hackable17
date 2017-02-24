#include <HID-Project.h>

#include "xtmap.h"

#define CLOCK 2
#define DATA  8

// données cumulées
volatile byte touche;
// compteur d'horloge
volatile int cpt;
// drapeau prêt/ready
volatile int rdy;

// routine d'interruption
void clksig() {
  // on saut le bit de start
  if(cpt > 0)
    // stockage
    touche |= digitalRead(DATA) << cpt-1 ;
  cpt++;
  // on ignore le bit de stop
  if(cpt > 9) {
    cpt=0;
    rdy=1;
  }
}

void setup() {
  Serial.begin(115200);

  // bloquant si aucune connexion série
  //while(!Serial){;}
  delay(2000);
  Serial.println("Go go go!");

  Keyboard.begin();

  pinMode(CLOCK, INPUT_PULLUP);
  pinMode(DATA, INPUT_PULLUP);

  delay(2000);
  
  // installation de la routine
  attachInterrupt(digitalPinToInterrupt(CLOCK), clksig, RISING);
}

void loop() {
  // données prêtes et touche valide ?
  if(rdy && touche > 0 && touche < 83) {
    // scancode
    Serial.print("0x");
    Serial.print(touche,HEX);
    Serial.print(": touche [");
    // KeyboardKeycode
    Serial.print(xtmap[touche & 127]);
    Serial.print("]");
    if(touche & 128) {
      // si bit 7 alors relachement
      Serial.println(" relacher");
      Keyboard.release(KeyboardKeycode(xtmap[touche & 127]));
    } else {
      // sinon pression
      Serial.println(" presser");
      Keyboard.press(KeyboardKeycode(xtmap[touche & 127]));
    }
    rdy=0;
    touche=0;
  }
}

