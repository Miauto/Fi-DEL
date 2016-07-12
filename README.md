# Fi-DEL
Création de plusieurs Lampes LED connectées au wifi, à l'aide de Wemos D1-mini. Normalement compatibles avec d'autres ESP.
![Fi-DEL](https://github.com/Miauto/Fi-DEL/blob/master/images/Fi-DEL.png?raw=true "Fi-DEL")

Le tout piloté par une seule interface Web.

![Web](https://github.com/Miauto/Fi-DEL/blob/master/images/Web.png?raw=true "Web")

## Objectifs
  - Des lampes d'ambiance de couleurs.
  - Pilotables depuis mon smartphone.
  - En piloter plusieurs à la fois.
  - Intégrer les différents scripts effect fastled et neopixel.
   
## Améliorations Futures
- [ ] Création de page Html indépendante au code (par fichiers séparés).
- [ ] Séparation des Scripts d'effets lumières.
- [ ] Amélioration de l'interface par intégration JS. [Exemple](http://www.jqueryrain.com/?vMUktPIX "Exemple").
- [ ] Utilisation de la memoire eeprom pour redémarrer sur le dernier effet utilisé.
- [ ] Voir pour gérer la Led Bleu du ESP
- [ ] Faire une version en programmation dure, sans passer par arduino. Pas de mon niveau (pour le moment :p )


## Accessoires

* [Un Wemos D1-Mini](http://www.wemos.cc/Products/d1_mini.html "Un Wemos D1-Mini")
* Des LED [WS2812b](http://fr.aliexpress.com/item/10-1000pcs-4-Pin-WS2812B-WS2812-LED-Chip-Heatsink-5V-5050-RGB-WS2811-IC-Built-in/32634454437.html "WS2812b")
* Un powerpack tout simple sans intelligence
* Un petit cable Usb (5-10 cm)
* Boule chinoise en papier


## Réalisation

* Dans le script changer le SSID et MPD (possibilité de mettre 2 SSID)
* Les démarrer puis scanner le réseau avec fing (Android), leur nom netbios devrait apparaître.
* Modifier les noms de la ligne 40 à 44 (mettre autant de ligne que de wemos)
* Recharger tous les wemos
* Raccorder l'ensemble
* Tester (cela marche avec Chrome 51.0.2704.103)
    Il se peut que certains ne répondent pas tout de suite. Insister.

![Raccordement](https://github.com/Miauto/Fi-DEL/blob/master/images/Raccordement.png?raw=true "Raccordement")

* Souder 4 LED ou plus (adapter la variable NbLED) pour former un cercle, toutes dos à dos.
* Souder trois fils entre le Wemos et les WS28xx
* Mettre le tout dans la boule et faire en sorte que les led reste en son centre. Tendre un fil de haut en bas pour les guider.
* Let's GO

## Bugs et gènes
- La Led bleu du wemos reste allumée.
- L'ordinateur ou la tablette ne voit pas tous les wemos de suite, insister, cela vient rapidement.
- Wifi non reparamétrable via le web.
