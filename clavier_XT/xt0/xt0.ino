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
  // on saut le bit de start
  if(cpt > 0)
    // stockage
    b_data|=digitalRead(DATA) << cpt-1 ;
  cpt++;
  // on ignore le bit de stop
  if(cpt > 9) {
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
    // en hexa
    Serial.print(b_data,HEX);
    Serial.print(" : ");
    // en décimal
    Serial.print(b_data,DEC);
    Serial.print(" : ");
    // en binaire
    Serial.println(b_data,BIN);
    rdy=0;
    b_data=0;
  }
}
