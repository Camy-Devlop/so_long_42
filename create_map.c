#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100  // Taille du labyrinthe (500x500)
#define NB_COLLECTIBLES 50  // Nombre de collectibles 'C'

// Fonction pour initialiser le labyrinthe avec des murs ('1') partout
void initialiserLabyrinthe(char labyrinthe[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (i == 0 || i == TAILLE - 1 || j == 0 || j == TAILLE - 1) {
                labyrinthe[i][j] = '1';  // Bordures en murs
            } else {
                labyrinthe[i][j] = (rand() % 100 < 70) ? '0' : '1';  // 70% vide, 30% murs
            }
        }
    }
}

// Fonction pour placer un élément unique ('P', 'E', ou un 'C')
void placerElement(char labyrinthe[TAILLE][TAILLE], char element) {
    int x, y;
    do {
        x = rand() % (TAILLE - 2) + 1;  // Coordonnées aléatoires dans la zone intérieure
        y = rand() % (TAILLE - 2) + 1;
    } while (labyrinthe[x][y] != '0');  // Assurez-vous que la case est vide
    labyrinthe[x][y] = element;
}

// Fonction pour afficher le labyrinthe dans la console
void afficherLabyrinthe(char labyrinthe[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            putchar(labyrinthe[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));  // Initialisation de la graine aléatoire

    char labyrinthe[TAILLE][TAILLE];

    // Initialiser le labyrinthe avec des murs et des cases vides
    initialiserLabyrinthe(labyrinthe);

    // Placer le point de départ ('P') et le point d'arrivée ('E')
    placerElement(labyrinthe, 'P');
    placerElement(labyrinthe, 'E');

    // Placer les collectibles ('C')
    for (int i = 0; i < NB_COLLECTIBLES; i++) {
        placerElement(labyrinthe, 'C');
    }

    // Afficher le labyrinthe
    afficherLabyrinthe(labyrinthe);

    return 0;
}

