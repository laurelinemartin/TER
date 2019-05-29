README

TER - Algorithmes d'optimisation pour un bureau des temps
=========================================================

_Par : Maxime GONTHIER, Benjamin GUILLOT et Laureline MARTIN_

*********
Commandes
---------
*********
Depuis le dossier TER/TER
- Lancement de l'application : make
- Compilation de l'application : make compile
- Suppression des fichiers *.o et de l'exécutable : make clean


**********************
Fichier des paramètres
----------------------
**********************
Le fichier params.txt permet de renseigner les différents paramètres variables.
Liste des champs :
Ligne 1 : Probalilité qu'au moins un élève soit dans 2 cours
Ligne 2 : Nombre de cours
Ligne 3 : Nombre de salles
Ligne 4 : Nombre de bus
Ligne 5 ; Nombre d'itérations pour les algorithmes tabou dur et tabou roulette


******************
Fichiers de sortie
------------------
******************
Le fichier resultats.txt : Le meilleur planification pour chaque algorithme.

Le fichier congestion_bus.txt : Le nombre d'élève dans chaque bus pour chaque planification
- Vert = bus agréable (peu de monde)
- Orange = bus peu confortable (assez rempli)
- Rouge = bus inconfortable (beaucoup de monde)

*******
Rapport
-------
*******
Le fichier rapport.pdf
