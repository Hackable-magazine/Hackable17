#define TAILLE_BUF 10

unsigned int buf[TAILLE_BUF];

int cherchecode(unsigned int code) {
  for(int i=0; i < TAILLE_BUF; i++) {
    if(buf[i] == code)
      return i;
  }
  return -1;
}

void majcode(int pos) {
  for(int i=0; i < TAILLE_BUF; i++) {
    if(i < TAILLE_BUF-pos-1)
      buf[i] = buf[i+pos+1];
    else
      buf[i] = random(1,65536);
  }
}

void printbuffer() {
  for(int i=0; i < TAILLE_BUF; i++) {
    Serial.print(buf[i]);
    Serial.print("  ");
  }
  Serial.println("");
}

void setup() {
  Serial.begin(115200);
  while(!Serial){;}
  
  randomSeed(42424242);

  Serial.println("Go go go");

  for(int i=0; i < TAILLE_BUF; i++) {
    buf[i] = random(1,65536);
  }

  printbuffer();

  /*
  int ret = cherchecode(41616);
  if(ret >= 0) {
    Serial.print("Trouve en position ");
    Serial.println(ret);
    majcode(ret);
    printbuffer();
  } else {
    Serial.println("Code non trouve");
  }
  */

}

void loop() {
  while (Serial.available() > 0) {
    unsigned int valeur = Serial.parseInt();

    if(!valeur)
      return;
    
    Serial.print("recu: ");
    Serial.println(valeur);
    
    int ret = cherchecode(valeur);
    if(ret >= 0) {
      Serial.print("Trouve en position ");
      Serial.println(ret);
      majcode(ret);
      //printbuffer();
    } else {
      Serial.println("Code non trouve");
    }    
  }
}
