# Fi-DEL
Création de plusieurs Lampes LED connecté au wifi, à l'aide de Wemos D1-mini. Normalement compatible avec d'autre ESP.
![Fi-DEL](https://github.com/Miauto/Fi-DEL/blob/master/images/Fi-DEL.png?raw=true "Fi-DEL")

Le tout piloté par une seul interface Web.

![Web](https://github.com/Miauto/Fi-DEL/blob/master/images/Web.png?raw=true "Web")

## Objectifs
  - Des lampes d'ambiance de couleurs.
  - Pilotable depuis mon smartphone.
  - Piloté plusieurs à la fois.
  - Intégrer les différents scripts effect fastled et neopixel.
   
## Améliorations Futur
- [ ] Création de page Html indépendante au code (par fichier sépration).
- [ ] Séparation des Script d'effet lumières.
- [ ] Amélioration de l'interface par intégration JS. ![JS](http://www.jqueryrain.com/?vMUktPIX "JS")
- [ ] Utilisé la memoire eeprom pour redemarrer sur le dernier effet utilisé.
- [ ] Voir pour géré la Led Bleu du ESP
- [ ] Faire un version en prog dur, sans passer par arduino. Pas de mon niveau (pour le moment :p )


## Accessoires

* [Un Wemos D1-Mini](http://www.wemos.cc/Products/d1_mini.html "Un Wemos D1-Mini")
* Des LED [WS2812b](http://fr.aliexpress.com/item/10-1000pcs-4-Pin-WS2812B-WS2812-LED-Chip-Heatsink-5V-5050-RGB-WS2811-IC-Built-in/32634454437.html "WS2812b")
* Un powerpack tout simple sans intelligence
* Un petit cable Usb (5-10 cm)
* Boule chinoise en papier


## Réalisation

* Dans le script changé le SSID et MPD (possibilité de mettre 2 SSID)
* Les démarré puis scanné le résseaux avec fing (android), leur nom netbios devrais apparaitre.
* puis modifier les noms a la ligne 40 à 44 (mettre autant de ligne que de wemos)
* Recharger tous les wemos
* Raccordé l'ensemble
* Testé (cela marche avec Chrome 51.0.2704.103)
    Il ce peut certains ne repondent pas tout de suite. Insciter.

![Raccordement](https://github.com/Miauto/Fi-DEL/blob/master/images/Raccordement.png?raw=true "Raccordement")

* Soudure de 4 LED ou plus (adapter la variable NbLED) pour former un cercle, toute dos à dos.
* Soudure de trois fils entre le Wemos et les WS28xx
* Mettre le tout dans la boule et faire en sorte que les led reste en son centre. tendre un fil de haut en bas pour aider.
* Let's GO

## Bugs et gènes
- La Led bleu du wemos reste allumer.
- L'ordinateur ou la tablette ne voit pas tout les wemos de suite, insisté, cela vient rapidement.
- Wifi non reparametrable via le web.
