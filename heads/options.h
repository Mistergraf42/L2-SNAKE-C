#ifndef __OPTIONS_H__
#define __OPTIONS_H__

/*****OPTIONS GRAPHIQUE****/ 

/*resolution*/

#define RESOLUTION_H 900
#define RESOLUTION_L 900

/*Couleur par défault à la compilation*/

#define POMME_NORMAL_R 255
#define POMME_NORMAL_G 0
#define POMME_NORMAL_B 0

#define POMME_MALUS_R 102
#define POMME_MALUS_G 102
#define POMME_MALUS_B 0

#define POMME_VITESSE_R 204
#define POMME_VITESSE_G 255
#define POMME_VITESSE_B 255

#define SNAKE_1_R 0;
#define SNAKE_1_G 155;
#define SNAKE_1_B 0;

#define SNAKE_1_T_R 0;
#define SNAKE_1_T_G 55;
#define SNAKE_1_T_B 0;


#define SNAKE_2_R 255;
#define SNAKE_2_G 204;
#define SNAKE_2_B 229;

#define SNAKE_2_T_R 204;
#define SNAKE_2_T_G 0;
#define SNAKE_2_T_B 102;

#define PLATEAU_R 0;
#define PLATEAU_G 128;
#define PLATEAU_B 255;

#define MUR_R 160;
#define MUR_G 160;
#define MUR_B 160;

#define TEXTE_R 255;
#define TEXTE_G 255;
#define TEXTE_B 255;

/***************************/

/*****OPTIONS DE PARTIE*****/

#define TAILLE_MAX_PLATEAU 256
#define NB_MAX_JOUEUR 3

#define TAILLE_MAP 15
#define TIC_DEFAULT 150

/***************************/

/*****OPTIONS DES CONTROLES*****/

/*TOUCHES DIRECTIONELLES*/

#define UP_JOUEUR1 'z'
#define LEFT_JOUEUR1 'q'
#define RIGTH_JOUEUR1 'd'
#define DOWN_JOUEUR1 's'

#define UP_JOUEUR2 'o'
#define LEFT_JOUEUR2 'k'
#define RIGTH_JOUEUR2 'm'
#define DOWN_JOUEUR2 'l'

#define PAUSE 27 /*Code ascii echap*/
#endif