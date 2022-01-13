==============================================================
====                                                      ====
==   GogoDro par Loïc Drieu la rochelle et Yannis Sauzeau   ==
====                                                      ====
==============================================================


  ===================
  ==  Arborescence ==         
  ===================


.
├── Arbre_Syntaxique
│   └── graph.png
├── Exemple
│   ├── Image
│   │   ├── cube.bmp
│   │   ├── dessin.bmp
│   │   ├── quadrilatere.bmp
│   │   └── quadrillage.bmp
│   ├── cube
│   ├── erreur
│   ├── quadrilatere
│   ├── quadrillage
│   └── test
├── ReadMe.txt
└── Source
    ├── CImg.h
    ├── Makefile
    ├── affectation.cc
    ├── affectation.hh
    ├── code.cc
    ├── code.hh
    ├── color.cc
    ├── color.hh
    ├── declaration.cc
    ├── declaration.hh
    ├── entete.cc
    ├── entete.hh
    ├── expression.hh
    ├── instruction.hh
    ├── lexeur.ll
    ├── loop.cc
    ├── loop.hh
    ├── main.cc
    ├── operator.cc
    ├── operator.hh
    ├── parseur.yy
    ├── pen.cc
    ├── pen.hh
    ├── position.cc
    ├── position.hh
    ├── printer.cc
    ├── printer.hh
    ├── program.cc
    ├── program.hh
    ├── rectangle.cc
    ├── rectangle.hh
    ├── term.hh
    ├── travel.cc
    ├── travel.hh
    ├── value.cc
    ├── value.hh
    ├── var.cc
    ├── var.hh
    └── visitor.hh

Dans ce projet vous trouverez en plus de ce ReadMe les dossiers :

    - Arbre syntaxique => Contient une image de l'arbre syntaxique

    - Exemple => Contient des exemple de fichiers et le résultat
    qu'il produise dans le dossier Image

    - Source => Contient un makefile, un lexeur, un parseur, un main
    et des classes utilitaires.


  ===================
  ==  Utilisation  ==         
  ===================


Pour compiler mettez vous dans le dossier ./Source puis éxectuer la commande make.
Ensuite vous pouvez tester les exemples avec la commande make :
  
    * cube => Dessine un cube en 3D

    * erreur => Possède quatre erreurs qui sont commentées et qu'il faut 
    décommenter pour voir les messages d'erreurs

    * quadrilatere => Dessine un quadrilatere avec une croix bleu et rouge
    au centre.

    * quadrillage => Créer un quadrillage avec des boucles 

    * test => Sert de fichier test à notre syntaxe nous vous conseillons
    d'utiliser ce fichier pour tester notre langage

Si vous voulez créer votre propre fichier faites le dans le dossier ./Exemple et
respectez la syntaxe décrite dans la documentation ci-dessous. Ensuite vous pouvez
lancer le programme sur votre fichier avec la commande ./prog < ./Example/<nom_de_votre_fichier>


  =====================
  ==  Documentation  ==         
  =====================


La syntaxe de notre langage doit respecter les règles suivantes.

Avant votre code vous pouvez ajouter un header (optionnel) comme décrit ci-dessous :

taille (x, y);         // x un nombre pour la longueur et y pour la largeur
nom "nom_de_l_image";  // nom_de_l_image pour le nom de l'image que vous voulez sauvegarder
couleur #xxxxxx;       // xxxxx le code hexadécimal du fond de l'image 
affiche;               // Optionnel : Permet d'afficher l'image à la fin du programme

Ensuite le code est une suite d'instruction.

var x; // Déclare une variable x

x <- 1; // Affecte la valeur 1 à la varibale x

var y <- x; // Met la valeur de x, c'est-à-dire 1, dans la variable y

x <- 1.5 + 2.5; // Met la valeur de 4 dans x

x <- 3 - 1; // Met la valeur de 2 dans x

x <- 5 * 3; // Met la valeur de 15 dans x

x <- 5 / 2; // Met la valeur de 1.5 dans x

lever; // Lève le stylo

baisser; // Baisse le stylo

couleur #00FF00; // Change la couleur du stylo en vert

deplacer (100, 200); // Déplace le stylo au coordonnées 100 en longueur 
                     // et 200 en largeur, sachant que (0, 0) se situe 
                     // en haut à gauche. Si le stylo est levé alors 
                     // on se déplace sinon on écrit

ligne (12, 21) (121, 212); // Dessine une ligne de la position (12, 21)
                           // à la position (121, 212)

rectangle (10, 10) (100, 100); // Dessine un rectangle avec comme coin supérieur
                               // gauche à la coordonnée (10, 10) et comme coin
                               // inférieur droit à la coordonnée (100, 100)

boucle n 1 10;
    /* 
     * Code à éxecuter par la boucle
     */
fin boucle; // Boucle qui fait 10 fois le code qui est à l'intérieur d'elle
