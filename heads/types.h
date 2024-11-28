#ifndef __TYPES_H__
#define __TYPES_H__
#include <time.h>
#include "../heads/options.h"
#include "../heads/types.h"
typedef struct{
int x;
int y;
}coordonnees;

typedef struct{
    int r;
    int g;
    int b;
}rgb; 

typedef struct{
int secondes;
int minutes;
}temps;

typedef struct{
    int hauteur;
    int largeur;
}resolution;

typedef struct{
    temps duree;
    int pommes;
    int vitesse;
}score;

/*structure contenant les données relatives du plateau de jeu*/
typedef struct{
    short int plateau[TAILLE_MAX_PLATEAU][TAILLE_MAX_PLATEAU];
    coordonnees pomme[TAILLE_MAX_PLATEAU*TAILLE_MAX_PLATEAU];
    coordonnees murs_sup[TAILLE_MAX_PLATEAU*TAILLE_MAX_PLATEAU];
    int n;
}map;

/*structure contenant les données relatives  au serpent*/
typedef struct{
    coordonnees corp[TAILLE_MAX_PLATEAU*TAILLE_MAX_PLATEAU];   
    int taille; 
    char direction;
    char nom[10];
}serpent;


/*structure regroupement les données nécessaires au fonctionements de la partie*/
typedef struct{
    int vitesse;
    int mode_jeu;
    int taille_plateau;
    int boost_vitesse;
    int nb_pommes;
    int tic;
    int nb_joueurs;
    map map;
    serpent joueur[NB_MAX_JOUEUR];
    temps actuel;
    temps debut;
}partie;

/* classe les meilleurs scores*/
typedef struct{
score tab[10];
int nb;
}classement;

/*structure regroupement les données nécessaires au fonctionements du jeu*/
typedef struct{
    partie partie;
    resolution fenetre;
    classement classement; 
}configuration;

/*structure regroupement toutes les coordonnées des différents boutons des différents menus*/
typedef struct{

    /*MENU PRINCIPALE*/
    coordonnees play;
    coordonnees multi;
    coordonnees options;
    coordonnees quitter;

    /*MENU PLAY*/
    coordonnees nouvelle_partie;
    coordonnees options_partie;
    coordonnees save1;
    coordonnees save2;
    coordonnees save3;
    coordonnees save4;
    coordonnees leaderboard;
    coordonnees quitter_play;

    /***MENU NOUVELLE_PARTIE***/
    coordonnees taille_map;
    coordonnees mode_jeu;
    coordonnees lancer_partie;
    coordonnees retour;
    coordonnees vitesse;
    coordonnees input_box_pseudo;

    /**MENU PAUSE**/
    coordonnees reprendre;
    coordonnees quitter_la_partie;
    coordonnees sauvegarder_et_quitter;

    /**MENU SAUVEGARDE**/

    coordonnees sauvegarde1;
    coordonnees sauvegarde2;
    coordonnees sauvegarde3;
    coordonnees sauvegarde4;
    coordonnees annuler;
    coordonnees valider;

    int largeur_bouton; /*par convention, cette entier représentera la largeur d'un bouton de base en pixels.*/
    int hauteur_bouton; /*par convention, cette entier représentera la hauteur d'un bouton de base en pixels.*/



}boutons;

typedef struct{

/*Personalisation pommes:*/

rgb pomme_normal;
rgb pomme_vitesse;
rgb pomme_malus;
rgb snake_1;
rgb snake_1_tete;
rgb snake_2;
rgb snake_2_tete;
rgb plateau;
rgb murs;
rgb textes;

}personalisation_couleur;


/*nom des sauvegardes*/

typedef struct{
int num_save;
}sauvegarde;

#endif