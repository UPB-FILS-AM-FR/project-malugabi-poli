Maison intelligente

Ungureanu Maria-Gabriela

Description

Ce projet a pour objectif de créer un système de sécurité intelligent basé sur une carte ESP32. Le système permet de surveiller différents risques pouvant apparaître dans une maison, comme les incendies, les fuites de gaz ou encore les infiltrations d’eau.
Pour réaliser ce projet, plusieurs capteurs sont utilisés. Un capteur de flamme permet de détecter la présence de feu, tandis que le capteur MQ-6 est utilisé pour détecter la fumée ou les gaz inflammables. Un capteur d’eau est également intégré afin d’identifier les risques d’inondation ou de fuite.
Lorsque le système détecte un danger, une alarme sonore est activée grâce à un buzzer et une LED s’allume pour avertir l’utilisateur. Les informations et les alertes sont aussi affichées sur un écran LCD 16x2 afin de faciliter la surveillance du système.
La carte ESP32 joue un rôle central dans le projet, car elle assure le traitement des données reçues par les capteurs ainsi que le contrôle des différents composants électroniques.
Le schéma électronique du système a été conçu avec le logiciel KiCad.


Motivation

Depuis toujours, je suis curieuse de tout ce qui concerne la technologie, l’électronique et les systèmes intelligents. J’ai toujours aimé comprendre le fonctionnement des appareils électroniques et découvrir comment différents composants peuvent communiquer entre eux pour réaliser des tâches utiles.
Ce projet représente pour moi une excellente opportunité d’apprendre davantage sur les systèmes embarqués et sur l’utilisation des capteurs avec une carte ESP32. J’ai choisi ce sujet parce que la sécurité domestique est un domaine important et très intéressant, surtout avec le développement des technologies intelligentes.
La réalisation de ce projet m’a également permis de développer plusieurs compétences techniques, comme la programmation, la conception de schémas électroniques avec KiCad et la compréhension du fonctionnement des composants électroniques.


Architecture

L’architecture du système est basée sur une carte ESP32, qui représente l’unité centrale du projet. Tous les capteurs et composants électroniques sont connectés à cette carte afin de permettre la communication et le traitement des données.
Le système comprend trois capteurs principaux. Le capteur de flamme est utilisé pour détecter la présence de feu, le capteur MQ-6 permet de détecter la fumée ou les gaz inflammables, tandis que le capteur d’eau sert à identifier les fuites ou les infiltrations d’eau.
Les données envoyées par les capteurs sont analysées par l’ESP32. En fonction des informations reçues, la carte peut activer différents dispositifs de sortie. Une LED et un buzzer sont utilisés pour signaler rapidement un danger à l’utilisateur.
Le système possède également un écran LCD 16x2 qui affiche les différents messages d’état et les alertes en temps réel. Cela permet de surveiller facilement le fonctionnement du système.
L’architecture générale du projet est organisée autour de trois parties principales :
- les capteurs d’entrée ;
- l’unité de traitement ESP32 ;
- les dispositifs de sortie et d’alerte.
Cette organisation permet d’obtenir un système simple, clair et efficace pour la surveillance de la sécurité domestique.


Block diagram
<img width="1536" height="1024" alt="WhatsApp Image 2026-05-27 at 14 00 45" src="https://github.com/user-attachments/assets/28a91d75-ea4e-4b58-8dd0-d849124218ea" />


Schéma électronique du système
[SmartSystemSafety.pdf](https://github.com/user-attachments/files/28305759/SmartSystemSafety.pdf)


Component


| Device | Usage | Price |
|--------|--------|-------|
| Module d’interface I2C/IIC pour LCD1602 | facilite la connexion de l’écran LCD avec moins de fils | [9,99 RON] |
|Capteur de mesure du niveau d’eau compatible Arduino | détecte la présence ou le niveau d’eau | [2.99 RON] |
|Module capteur numérique IR, détecteur de flamme |détecte la présence d’une flamme ou d’un incendie | [3.65 RON] |
|Modul capteur de gaz MQ2 |détection de gaz, fumée et fuites dans l’air | [11.99 RON] |
|Écran LCD1602 HD44780 avec rétroéclairage bleu |affichage des informations et des messages du système | [13.99 RON]|
|Module buzzer actif, compatible Arduino.|émission de signaux sonores et d’alarmes. | [3.24 RON] |
|Ensemble de 200 LED de différentes couleurs, 3 mm/5 mm, Bitmi 10508.|indication lumineuse et signalisation visuelle| [30.24 RON] |
|Breadboard 830 points MB-102 |réalisation et test de circuits électroniques sans soudure.| [13.99 RON] |
|40 fils Dupont mâle-femelle de 20 cm.| connexion des composants électroniques et des modules Arduino.| [6.99 RON] |
|40 fils Dupont mâle-mâle de 20 cm.| connexion des composants électroniques et des modules Arduino.| [8.99 RON] |
|Ensemble de résistances, 20 valeurs, 400 pièces, 10Ω-10MΩ, 1/4W.| limitation du courant et protection des composants électroniques.| [19.99 RON] |
|Carte de développement Plusivo Wireless compatible avec ESP32 et BLE |développement de projets IoT et communication sans fil Bluetooth/Wi-Fi| [29.99 RON] |


### Libraries

| Library | Description | Usage |
|---|---|---|
| WiFi | Bibliothèque pour la connexion WiFi de l’ESP32 | Utilisée pour connecter la carte ESP32 au réseau WiFi |
| BlynkSimpleEsp32 | Bibliothèque pour connecter l’ESP32 à la plateforme Blynk | Utilisée pour envoyer des notifications et afficher l’état du système dans l’application |
| Wire | Bibliothèque pour la communication I2C | Utilisée pour la communication entre l’ESP32 et l’écran LCD |
| LiquidCrystal_I2C | Bibliothèque pour contrôler l’écran LCD 16x2 avec module I2C | Utilisée pour afficher les messages d’état et les alertes |

