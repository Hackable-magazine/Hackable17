/*
  Ce croquis est destiné à l'ATmega16U2  de la carte UNO
*/

#include <Keyboard.h>

void setup() {
  // configuration des led et extinction
  pinMode(LED_BUILTIN_RX, OUTPUT);
  pinMode(LED_BUILTIN_TX, OUTPUT);
  digitalWrite(LED_BUILTIN_RX, HIGH);
  digitalWrite(LED_BUILTIN_TX, HIGH);

  // Liaison série vers l'ATmega328P à 2400 bps
  Serial1.begin(2400);

  // Mise en route du clavier USB HID
  Keyboard.begin();
}

void loop() {
  // A-t-on des données à lire ?
  if (Serial1.available() > 0) {
    // récupération d'un caracère
    char c = Serial1.read();
    // on envoi le caractère comme tapez au clavier
    Keyboard.print(c);
  }
}
