/*
  Ce croquis est destiné à l'ATmega328P de la carte UNO
*/

void setup() {
  // led L en sortie
  pinMode(LED_BUILTIN, OUTPUT);
  // Liaison série vers l'ATmega16U2 à 2400 bps
  Serial.begin(2400);
  // Petite pause pour laisser le temps de démarrer
  delay(5000);
}

void loop() {
  // Ecriture de texte sur le port série
  Serial.print("Coucou ");

  // Clignotement de la led à chaque envoi
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
