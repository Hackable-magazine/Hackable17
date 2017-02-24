#define CLOCK 2
#define DATA  8

// données cumulées
volatile int b_data;
// compteur d'horloge
volatile int cpt;
// drapeau prêt/ready
volatile int rdy;

// routine d'interruption
void clksig() {
  b_data|=digitalRead(DATA) << cpt ;
  cpt++;
  if(cpt > 10) {
    cpt=0;
    rdy=1;
  }
}

void setup() {
  Serial.begin(115200);
  while(!Serial){;}
  Serial.println("Go go go!");

  pinMode(CLOCK, INPUT_PULLUP);
  pinMode(DATA, INPUT_PULLUP);

  // installation de la routine
  attachInterrupt(digitalPinToInterrupt(CLOCK), clksig, RISING);
}

void loop() {
  // données prêtes ?
  if(rdy) {
    // horodatage
    Serial.print(millis());
    Serial.print(" : ");
    // bits collectés
    Serial.println(b_data,BIN);
    rdy=0;
    b_data=0;
  }
}
