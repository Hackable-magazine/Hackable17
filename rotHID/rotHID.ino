#include <HID.h>

#define PINA 3
#define PINB 2
#define CLIC 4

typedef struct {
  uint8_t modifiers = 0;
  uint8_t key = 0;
} KeyReportMini;

// dernier état de A
int derniereA = LOW;
// état actuel
int n = LOW;

int clic = HIGH;

/*
  http://eleccelerator.com/usbdescreqparser/
*/

static const uint8_t hidReportDescriptor[] PROGMEM = {
  0x05, 0x0C,        // Usage Page (Consumer)
  0x09, 0x01,        // Usage (Consumer Control)
  0xA1, 0x01,        // Collection (Application)
  0x85, 0x01,        //   Report ID (1)
  0x19, 0x00,        //   Usage Minimum (Unassigned)
  0x2A, 0xFF, 0x03,  //   Usage Maximum (0x03FF)
  0x15, 0x00,        //   Logical Minimum (0)
  0x26, 0xFF, 0x03,  //   Logical Maximum (1023)
  0x95, 0x01,        //   Report Count (1)
  0x75, 0x10,        //   Report Size (16)
  0x81, 0x00,        //   Input (Data,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
  0xC0,              // End Collection
  0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
  0x09, 0x80,        // Usage (Sys Control)
  0xA1, 0x01,        // Collection (Application)
  0x85, 0x02,        //   Report ID (2)
  0x19, 0x81,        //   Usage Minimum (Sys Power Down)
  0x29, 0x83,        //   Usage Maximum (Sys Wake Up)
  0x15, 0x00,        //   Logical Minimum (0)
  0x25, 0x01,        //   Logical Maximum (1)
  0x75, 0x01,        //   Report Size (1)
  0x95, 0x03,        //   Report Count (3)
  0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
  0x95, 0x05,        //   Report Count (5)
  0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
  0xC0,              // End Collection
};

void setup() {
  pinMode(PINA,INPUT);
  pinMode(PINB,INPUT);
  pinMode(CLIC,INPUT);
  
  static HIDSubDescriptor node(hidReportDescriptor, sizeof(hidReportDescriptor));
  HID().AppendDescriptor(&node);
  delay(5000);
}

void loop() {
  // données du rapport
  KeyReportMini report;

  // gestion du clic "muet"
  if((digitalRead(CLIC) == LOW)) {
    if(clic == HIGH) {
      clic = LOW;
      // on change la valeur du second octet du rapport
      report1.modifiers = 0xe2;
      // envoi du rapport
      HID().SendReport(1,&report,sizeof(KeyReportMini));
      // temps de pression sur la touche
      delay(20);
      // touche relâchée
      report1.modifiers = 0x00;
      // envoi du rapport
      HID().SendReport(1,&report,sizeof(KeyReportMini));
    }
  } else {
    clic = HIGH;
  }
  
  // lecture A
  n = digitalRead(PINA);
  if ((derniereA == LOW) && (n == HIGH)) {
    if (digitalRead(PINB) == LOW) {
      // on décrémente
      report1.modifiers = 0xea;
      HID().SendReport(1,&report,sizeof(KeyReportMini));
      delay(20);
      report1.modifiers = 0x00;
      HID().SendReport(1,&report,sizeof(KeyReportMini));
    } else {
      // on incrément
      report1.modifiers = 0xe9;
      HID().SendReport(1,&report,sizeof(KeyReportMini));
      delay(20);
      report1.modifiers = 0x00;
      HID().SendReport(1,&report,sizeof(KeyReportMini));
    }
  }
  // l'état actuelle devient l'état précédent
  derniereA = n;
}
