# Fi-DEL

![](https://img.shields.io/github/stars/Miauto/Fi-DEL.svg) ![](https://img.shields.io/github/forks/Miauto/Fi-DEL.svg) ![](https://img.shields.io/github/tag/Miauto/Fi-DEL.svg) ![](https://img.shields.io/github/release/Miauto/Fi-DEL.svg) ![](https://img.shields.io/github/issues/Miauto/Fi-DEL.svg) ![](https://img.shields.io/bower/v/Fi-DEL.svg)

Création de plusieurs Lampes LED connectées au wifi, à l'aide de Wemos D1-mini. Normalement compatibles avec d'autres ESP8622.

![Fi-DEL](/images/Fi-DEL.png?raw=true "Fi-DEL")

Le tout piloté par une seule interface Web.

![Web](/images/Web.png?raw=true "Web")

## Objectifs
  - Des lampes d'ambiance de couleurs.
  - Pilotables depuis mon smartphone.
  - En piloter plusieurs à la fois.
  - Intégrer les différents scripts effect fastled et neopixel.

## Améliorations Futures
- [x] Création de page Html indépendante au code (par fichiers séparés).
- [x] Séparation des Scripts d'effets lumières.
- [ ] Amélioration de l'interface par intégration de JS. [Exemple](http://www.jqueryrain.com/?vMUktPIX "Exemple").
- [ ] Utilisation de la memoire eeprom pour redémarrer sur le dernier effet utilisé.
- [x] Voir pour gérer la Led Bleu du ESP.
- Création d'un page de Configuration.
  - [x] Wifi
  - [ ] ...
- [ ] Faire une version en programmation dure, sans passer par arduino. Pas de mon niveau (pour le moment :p )
- [x] Mise a jour par interface Web via un fichier
- Augmenter la bibliotheque de d'effet.
  - Rainbow
  - Rainbow Cycle
  - Rainbow Glitter
  - Rainbow Nuage
  - TwinkleRandom, couleurs aléatoire à chaque diode
  - Confetti
  - Fire (Bougie)
  - Couleur au choix
  - Couleur au choix + Stobe


## Accessoires

* [Un Wemos D1-Mini](http://www.wemos.cc/Products/d1_mini.html "Un Wemos D1-Mini")
* Des LED [WS2812b](http://fr.aliexpress.com/item/10-1000pcs-4-Pin-WS2812B-WS2812-LED-Chip-Heatsink-5V-5050-RGB-WS2811-IC-Built-in/32634454437.html "WS2812b")
* Un powerpack tout simple sans intelligence
* Un petit cable Usb (5-10 cm)
* Boule chinoise en papier


## Réalisation

* Premier temps installer le logiciel [Arduino](https://www.arduino.cc/en/Main/Software)
* [Configurer](ConfigurerArduino.md).
* Télécharger la derniere version. [Latest release](https://github.com/Miauto/Fi-DEL/releases)
* Au premier demarrage il vas crée son propore WIFI
  * Fi-DEL avec mot de passe 12345678
  * IP/Config renseigner le SSID et MDP
* Scanner le réseau avec fing (Android), leur nom netbios devrait apparaître.
* Page_Script.js.h Ligne 4, Modifier les noms ou IP (mettre autant de ligne que de wemos)
* Recharger tous les wemos
* Raccorder l'ensemble
* Tester avec Chrome 51.0.2704.103 + Livebox
    Il se peut que certains ne répondent pas tout de suite. Insister.

![Raccordement](/images/Raccordement.png?raw=true "Raccordement")

* Souder 4 LED ou plus (adapter la variable NbLED) pour former un cercle, toutes dos à dos.
* Souder trois fils entre le Wemos et les WS28xx, évité la PIN D3.
* Mettre le tout dans la boule et faire en sorte que les led reste en son centre. Tendre un fil de haut en bas pour les guider.
* Let's GO

## Utilisation

Avec un navigateur on peut controler les LED mais on peut aussi avec des logiciels qui font des requettes http.
- Windows
  - ...
- Android
  - [HTTP Request Widget](https://play.google.com/store/apps/details?id=com.idlegandalf.httprequestwidget)
- OSX
  - ...
- Domotique
  - [Jeedom](https://www.jeedom.com/forum/viewtopic.php?f=84&t=18819)


## Bugs et gènes
- L'ordinateur ou la tablette ne voit pas tous les wemos de suite, insister, cela vient rapidement.

## Autres Exemples sur Projet Similaires
 [easydomoticz.com Lampe Informative RGB WIFI](http://easydomoticz.com/forum/viewtopic.php?f=24&t=1834)

 [jeedom.com Tuto réaliser une lampe Wifi](https://www.jeedom.com/forum/viewtopic.php?f=84&t=18819)
