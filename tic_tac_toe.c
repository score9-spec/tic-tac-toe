#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Structure pour représenter le plateau de jeu
 */
typedef struct s_plateau {
    char grille[3][3];
} t_plateau;

/**
 * Fonction pour initialiser le plateau de jeu
 *
 * @param plateau Le plateau à initialiser
 */
void init_plateau(t_plateau *plateau)
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            plateau->grille[i][j] = ' ';
}

/**
 * Fonction pour afficher le plateau de jeu
 *
 * @param plateau Le plateau à afficher
 */
void print_plateau(t_plateau *plateau)
{
    printf(" %c | %c | %c \n", plateau->grille[0][0], plateau->grille[0][1], plateau->grille[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", plateau->grille[1][0], plateau->grille[1][1], plateau->grille[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", plateau->grille[2][0], plateau->grille[2][1], plateau->grille[2][2]);
}

/**
 * Fonction pour vérifier si un joueur a gagné
 *
 * @param plateau Le plateau de jeu
 * @param joueur Le joueur à vérifier
 * @return 1 si le joueur a gagné, 0 sinon
 */
int check_win(t_plateau *plateau, char joueur)
{
    int i;

    /* Vérifier les lignes */
    for (i = 0; i < 3; i++)
        if (plateau->grille[i][0] == joueur && plateau->grille[i][1] == joueur && plateau->grille[i][2] == joueur)
            return (1);

    /* Vérifier les colonnes */
    for (i = 0; i < 3; i++)
        if (plateau->grille[0][i] == joueur && plateau->grille[1][i] == joueur && plateau->grille[2][i] == joueur)
            return (1);

    /* Vérifier les diagonales */
    if ((plateau->grille[0][0] == joueur && plateau->grille[1][1] == joueur && plateau->grille[2][2] == joueur) ||
        (plateau->grille[0][2] == joueur && plateau->grille[1][1] == joueur && plateau->grille[2][0] == joueur))
        return (1);

    return (0);
}

/**
 * Fonction pour jouer contre l'ordinateur
 *
 * @param plateau Le plateau de jeu
 */
void play_against_computer(t_plateau *plateau)
{
    srand(time(NULL));
    int ligne, colonne;

    do {
        ligne = rand() % 3;
        colonne = rand() % 3;
    } while (plateau->grille[ligne][colonne] != ' ');

    plateau->grille[ligne][colonne] = 'O';
}

/**
 * Fonction pour jouer à deux joueurs
 *
 * @param plateau Le plateau de jeu
 */
void play_two_players(t_plateau *plateau)
{
    int ligne, colonne;
    char joueur = 'X';

    while (1) {
        print_plateau(plateau);
        printf("Joueur %c, entrez votre coup (ligne colonne) : ", joueur);
        scanf("%d %d", &ligne, &colonne);

        if (ligne < 1 || ligne > 3 || colonne < 1 || colonne > 3) {
            printf("Coup invalide, réessayez.\n");
            continue;
        }

        ligne--;
        colonne--;

        if (plateau->grille[ligne][colonne] != ' ') {
            printf("Case déjà occupée, réessayez.\n");
            continue;
        }

        plateau->grille[ligne][colonne] = joueur;

        if (check_win(plateau, joueur)) {
            print_plateau(plateau);
            printf("Joueur %c gagne !\n", joueur);
            break;
        }

        joueur = (joueur == 'X') ? 'O' : 'X';
    }
}

/**
 * Fonction pour jouer contre l'ordinateur
 *
 * @param plateau Le plateau de jeu
 */
void play_against_ordi(t_plateau *plateau)
{
    int ligne, colonne;
    char joueur = 'X';

    while (1) {
        print_plateau(plateau);
        printf("Entrez votre coup (ligne colonne) : ");
        scanf("%d %d", &ligne, &colonne);

        if (ligne < 1 || ligne > 3 || colonne < 1 || colonne > 3) {
            printf("Coup invalide, réessayez.\n");
            continue;
        }

        ligne--;
        colonne--;

if (plateau->grille[ligne][colonne] != ' ') {
printf("Case déjà occupée, réessayez.\n");
continue;
}

plateau->grille[ligne][colonne] = 'X';

if (check_win(plateau, 'X')) {
print_plateau(plateau);
printf("Vous gagnez !\n");
break;
}

play_against_computer(plateau);

if (check_win(plateau, 'O')) {
print_plateau(plateau);
printf("L'ordinateur gagne !\n");
break;
}
}
}

/**
* Fonction principale
*
* @return 0 en cas de succès
*/
int main(void)
{
t_plateau plateau;

init_plateau(&plateau);

printf("1. Jouer à deux\n");
printf("2. Jouer contre l'ordinateur\n");

int choix;
scanf("%d", &choix);

if (choix == 1)
play_two_players(&plateau);
else if (choix == 2)
play_against_ordi(&plateau);

return (0);
}
