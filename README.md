Sources et fichiers pour le magazine Hackable #17
=================================================

Ce dépôt contient les croquis, sources et fichiers présents dans le 17ème numéro de [Hackable](http://www.hackable.fr/) :

* `usbmacro` : croquis Arduino permettant d'envoyer des raccourcis clavier de copier/coller via USB HID (Arduino Leonardo ou Micro nécessaire)
* `rotHID` : croquis Arduino du contrôleur de volume USB HID compatible GNU/Linux, macOS, Windows, Android... (Arduino Leonardo ou Micro nécessaire)
* `clavier_XT/xt0pre` : croquis Arduino pour tester les réponses binaires et le protocole du clavier XT.
* `clavier_XT/xt0` : croquis Arduino pour récupérer les codes de touches du clavier XT.
* `clavier_XT/xt_usb` : croquis Arduino d'interface pour transformer le clavier XT en clavier USB HID (Arduino Leonardo ou Micro nécessaire)
* `Hood/hoodBlink` : premier croquis Arduino permettant de tester l'installation de HoodLoader2.
* `Hood/hood_IO` : croquis Arduino de test destiné à l'ATmega328p d'une carte UNO.
* `Hood/hood_USB` : croquis Arduino de test destiné à l'ATmega16u2 d'une carte UNO.
* `Pi_classLED/mesleds.dts` : Fichier source de l'overlay Device Tree permettant d'utiliser des leds supplémentaires connectées aux GPIOs de la Raspberry Pi via `/sys/class/leds`.
* `Rolling/rolling` : croquis Arduino du récepteur/vérificateur de codes tournants.
* `Rolling/rollingLCD` : croquis Arduino de l'émeteur/générateur de codes tournants
* `wscarre64FIRE` : croquis Arduino du simulateur d'effet de feu sur matrice de 8x8 leds WS2812B.

Les bibliothèques et modules utilisés dans les codes et croquis de ce numéro sont :

* [Hoodloader2](https://github.com/NicoHood/HoodLoader2)
* [HID-Project](https://github.com/NicoHood/HID)
* [FastLED](https://github.com/FastLED/FastLED)

