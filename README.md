# Éditeur SVG en C

## Description du Projet

Ce projet est un **éditeur basique de graphiques vectoriels scalables (SVG)** développé en langage **C**.

L'objectif principal était de créer une application console permettant à l'utilisateur de générer interactivement des fichiers SVG en définissant une zone de visualisation (viewport) et en y ajoutant diverses formes géométriques.

---

## Fonctionnement

L'application s'exécute intéractivement et suit les étapes suivantes :

### 1. Configuration de la Zone de Dessin (Viewport)

L'utilisateur est d'abord invité à définir les limites de la **viewport SVG** en fournissant **quatre coordonnées** :
* Position de départ X et position de fin X.
* Position de départ Y et position de fin Y.

### 2. Ajout de Formes

Le programme demande ensuite si l'utilisateur souhaite ajouter une forme :
* **Réponse "oui" :** L'application passe à la sélection de la forme.
* **Réponse "non" :** L'application arrête le processus et génère le fichier SVG.
* **Autre réponse :** Le programme invite l'utilisateur à répondre par "oui" ou "non".

### 3. Sélection et Paramétrage des Formes

L'utilisateur peut choisir parmi les formes suivantes : **cercle**, **ellipse**, **carré**, **rectangle**, **ligne**, **polyligne** et **polygone**.

| Forme | Paramètres Demandés |
| :--- | :--- |
| **Cercle** | Position X/Y du centre, Rayon, **Couleur de remplissage** (en anglais) |
| **Ellipse** | Position X/Y du centre, Rayon X, Rayon Y, **Couleur de remplissage** (en anglais) |
| **Carré** | Position X/Y du coin supérieur gauche, Taille du côté, **Couleur de remplissage** (en anglais) |
| **Rectangle** | Position X/Y du coin supérieur gauche, Largeur, Longueur, **Couleur de remplissage** (en anglais) |
| **Ligne** | Position X/Y du premier point, Position X/Y du deuxième point, **Couleur du tracé** (en anglais) |
| **Polyligne** | Nombre de points, puis position X/Y pour chaque point consécutif, **Couleur du tracé** (en anglais) |
| **Polygone** | Nombre de points, puis position X/Y pour chaque point consécutif, **Couleur de remplissage** (en anglais) |

> **Note :** Toutes les couleurs doivent être spécifiées en anglais (ex: "red", "blue", "green").

Une fois que l'utilisateur a fini d'ajouter des formes, un fichiers "file.svg" est créé avec ses formes

---

## Compilation et Exécution

*Ce projet utilise un `Makefile` pour la compilation.*

1.  **Compiler le projet :**
    ```bash
    make
    ```
2.  **Exécuter le programme :**
    ```bash
    ./prog.exe
    ```