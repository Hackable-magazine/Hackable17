#include <Keyboard.h>

int bouton[] = {A0,A1,A2,A3};
int led[]    = {11,10,9,6};

void raccourcis(int val) {
  // pour Win & Linux
  //Keyboard.press(KEY_LEFT_CTRL);
  // pour Mac
  Keyboard.press(KEY_LEFT_GUI);
  switch(val) {
    case 0:
      // "Annuler"
      // attention QWERTY w=z !
      Keyboard.press('w');
      break;
    case 1:
      // "Tout sélectionner"
      // attention QWERTY q=a !
      Keyboard.press('q');
      break;
    case 2:
      // "Copier"
      Keyboard.press('c');
      break;
    case 3:
      // "Coller"
      Keyboard.press('v');
  }
  delay(100);
  Keyboard.releaseAll();
}

// juste pour faire beau
void animation() {
  for(int i=0; i<4; i++) {
    digitalWrite(led[i], HIGH);
    delay(150);
  }
  for(int i=0; i<4; i++) {
    digitalWrite(led[i], LOW);
    delay(150);
  }
}

void setup() {
  // les leds en sorties
  for (int i=0; i<4; i++) {
    pinMode(led[i], OUTPUT);
  }

  // les bouton en entrées
  for (int i=0; i<4; i++) {
    pinMode(bouton[i], INPUT_PULLUP);
  }

  Keyboard.begin();

  animation();
}

void loop() {
  // on scanne les boutons
  for (int i=0; i<4; i++) {
    if(!digitalRead(bouton[i])) {
      // led allumée
      digitalWrite(led[i], HIGH);
      // envoi du raccourcis
      raccourcis(i);
      // on éteint doucement la led
      // tout en gérant les rebonds
      for(int j=250; j>=0; j=j-10) {
        analogWrite(led[i],j);
        delay(10);
      }
    }
  }
}
