#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "../heads/menu.h"
#include "../heads/types.h"
#include "../heads/options.h"
#include "../heads/affichage_graphique.h"
#include "../heads/saves.h"


int main(){

    /*Par convention b est notre variable stockant toutes nos coordonnees de boutons*/
    boutons b;

    personalisation_couleur game_couleurs;

    configuration game;

    /*initialisation de la taille de la fenêtre*/
    game.fenetre.largeur = RESOLUTION_L;
    game.fenetre.hauteur = RESOLUTION_H;

    /*creation de la fenetre du jeu*/
    MLV_create_window("Snake", "snake",game.fenetre.largeur,game.fenetre.hauteur);

    /*calculs coordonnees des boutons*/
    initialisation_coordonnees(&b, game);

    /*Initilisation couleurs du jeu*/
    initialisation_couleur_jeu(&game_couleurs);

    /*initialisation de la seed de rand*/
    srand(time(NULL));

    /*Initialisation du classement*/
    initialisation_classement(&game);

    /*Ouverture du menu principale jusqu'à que l'utilisateur click sur quitter*/
    menu_principale(&b, &game_couleurs, &game);
    
    /*fermeture propre de la fenetre du jeu ainsi que du programme*/
    MLV_free_window();
    return 1;

}