void setup() {
  // port en sortie
  pinMode(LED_BUILTIN_RX, OUTPUT);
  pinMode(LED_BUILTIN_TX, OUTPUT);
}

void loop() {
  // Attention c'est la cathode de la led qui est connectée au port et l'anode au +5V
  // La logique est donc inversée LOW = led active et HIGH = éteinte
  digitalWrite(LED_BUILTIN_RX, LOW);
  digitalWrite(LED_BUILTIN_TX, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN_RX, HIGH);
  digitalWrite(LED_BUILTIN_TX, HIGH);
  delay(1000);
}
