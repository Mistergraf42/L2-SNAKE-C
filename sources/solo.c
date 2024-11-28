#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include "../heads/affichage_graphique.h"
#include "../heads/solo.h"
#include "../heads/deplacement.h"
#include "../heads/map.h"
#include "../heads/types.h"
#include "../heads/menu.h"
#include "../heads/saves.h"

void timer(configuration *config){
    int temps_sec;

    temps_sec = config->partie.actuel.secondes = (time(NULL) - config->partie.debut.secondes);
    config->partie.actuel.minutes = temps_sec/60;
    config->partie.actuel.secondes = temps_sec%60;

}

score calcul_score(configuration config){
    score tmp;

    tmp.duree.secondes = config.partie.actuel.secondes;
    tmp.pommes = config.partie.joueur[0].taille - 1;
    tmp.vitesse = config.partie.vitesse + 1;

    return tmp;
}

void est_classement(configuration *config, score game){

    int i;
    score tmp;

    for(i=0; i < 10 ; i++){
        
        if( i >= config->classement.nb ){
        config->classement.tab[i].pommes = game.pommes;
        config->classement.tab[i].vitesse = game.vitesse;
        config->classement.tab[i].duree.secondes = game.duree.secondes;
        config->classement.tab[i].duree.minutes = game.duree.minutes;
        config->classement.nb++;
        modifie_classement(config->classement);
           return ;
        }

        if( config->classement.tab[i].pommes < game.pommes ){

            tmp = config->classement.tab[i];
            config->classement.tab[i] = game;
            est_classement(config,tmp);
            modifie_classement(config->classement);
            return ;
        }

    }
}

int gagnant(configuration *config){

    int joueur1_res, joueur2_res;
    joueur1_res=mouvement(config, config->partie.joueur[0].direction,0);

    switch(joueur1_res){

case 1:
        return 1;
case 0:
        joueur2_res=mouvement(config, config->partie.joueur[1].direction,1);
        if(joueur2_res){
            return 2;
        }
        return 0;

default: return 0;
    }
}

void initialisation_nouvelle_partie(configuration *config,int nb_joueurs){

    /*NB DE JOUERS*/
    config->partie.nb_joueurs=nb_joueurs;
    
    /*TAILLE*/
    config->partie.joueur[0].taille=0;

    /*MAP*/
    config->partie.map.n= 15*(config->partie.taille_plateau + 1);
    initialisation_table_de_jeu(config);

    /*Initialise le tic de jeu*/
    config->partie.tic= 150 - config->partie.vitesse*50;

    /*Initialisation config->config.nb_pommes*/  
    config->partie.nb_pommes=3;

    /*Initialise le temps*/
    config->partie.debut.secondes = time(NULL);
    config->partie.actuel.secondes=0;
    config->partie.actuel.minutes=0;

    /*Initialisation boost vitesse */
    config->partie.boost_vitesse=0;

    switch(config->partie.nb_joueurs){

    case 1:

        config->partie.joueur[0].corp[0].x = config->partie.map.n / 2;
        config->partie.joueur[0].corp[0].y = config->partie.map.n / 2;
        config->partie.joueur[0].taille = 1;
        config->partie.joueur[0].direction = 'h';
        break;

    case 2:

        config->partie.joueur[0].corp[0].x = config->partie.map.n / 2;
        config->partie.joueur[0].corp[0].y = 1;
        config->partie.joueur[0].taille = 1;
        config->partie.joueur[0].direction = 'h';

        config->partie.joueur[1].corp[0].x = config->partie.map.n / 2;
        config->partie.joueur[1].corp[0].y = (config->partie.map.n)/2+1;
        config->partie.joueur[1].taille = 1;
        config->partie.joueur[1].direction = 'b';

        break;   
}
    /*Generation snake pour eviter les conflit avec la pomme*/
    generation_snake(config);
    /*Generation de LA POMME*/
    generation_pomme(config);
    if(config->partie.mode_jeu==2){
        generation_mur(config,(5*(config->partie.taille_plateau + 1)) +10*(config->partie.taille_plateau));
}
}

void direction_oposer(char direction, char *ancienne_direction, int num_joueur){

switch(direction){

case 'h':
    ancienne_direction[num_joueur-1] = 'h';
    break;

case 'b':
    ancienne_direction[num_joueur-1] = 'b';
    break;

case 'g':
    ancienne_direction[num_joueur-1] = 'g';
    break;

case 'd':
    ancienne_direction[num_joueur-1] = 'd';
    break;

default: fprintf(stderr,"Erreur 48");
}
}

int est_valide(configuration *config, char *ancienne_direction){
   
    switch(config->partie.nb_joueurs){
    case 1:

    if(mouvement(config, config->partie.joueur[0].direction,0)){
        direction_oposer(config->partie.joueur[0].direction,ancienne_direction,1);
        return 1;
    }
    return 0;

    break;
        
    case 2:

        if(mouvement(config, config->partie.joueur[0].direction,0) && mouvement(config,config->partie.joueur[1].direction,1)){
            direction_oposer(config->partie.joueur[0].direction,ancienne_direction,1);
            direction_oposer(config->partie.joueur[1].direction,ancienne_direction,2);
            return 1;
        }
        else{
            return 0;
        }

    default: printf("erreur 36"); 
    }
    return -1;
}

void initialisation_partie(configuration *config){

    /*MAP*/
    config->partie.map.n= 15*(config->partie.taille_plateau + 1);

    /*Initialise le tic de jeu*/
    config->partie.tic= 150 - config->partie.vitesse*50;

    /*Initialisation config->partie.nb_pommes*/  
    config->partie.nb_pommes=1;


}

/*cela nous permet de gerer les déplacements de nos snake et de gerer les cas évitant que le snake puissent tourner à 180 degret*/
int verif_coup(configuration *config,char key, char *derniere_direction){
switch(key){

case UP_JOUEUR1:

        if(config->partie.joueur[0].direction != 'b' && derniere_direction[0] != 'b') {
        config->partie.joueur[0].direction = 'h';
        }break;

case RIGTH_JOUEUR1:

         if(config->partie.joueur[0].direction != 'g' && derniere_direction[0] != 'g'){
            config->partie.joueur[0].direction = 'd';
        }break;

case LEFT_JOUEUR1:

        if (config->partie.joueur[0].direction != 'd' && derniere_direction[0] != 'd'){
            config->partie.joueur[0].direction = 'g';
        }break;


case DOWN_JOUEUR1: 

        if (config->partie.joueur[0].direction != 'h' && derniere_direction[0] != 'h'){
        config->partie.joueur[0].direction = 'b';
        }break;
case UP_JOUEUR2:

        if (config->partie.joueur[1].direction != 'b' && derniere_direction[1] != 'b') {
        config->partie.joueur[1].direction = 'h';
        }break;

case RIGTH_JOUEUR2:

         if(config->partie.joueur[1].direction != 'g' && derniere_direction[1] != 'g'){
            config->partie.joueur[1].direction = 'd';
        }break;

case LEFT_JOUEUR2:

        if (config->partie.joueur[1].direction != 'd' && derniere_direction[1] != 'd'){
            config->partie.joueur[1].direction = 'g';
        }break;


case DOWN_JOUEUR2: 

        if (config->partie.joueur[1].direction != 'h' && derniere_direction[1] != 'h'){
        config->partie.joueur[1].direction = 'b';
        }break;
        
default: return 1;
}
return 1;
}

void nouvelle_partie_graphique(configuration *config, personalisation_couleur *couleurs, boutons b){
    int compteur;
    char touche;
    char dernier_coup[3];
    int exit=0;
    MLV_Keyboard_button sym;
    MLV_Event event = MLV_NONE;

    do{

        compteur = 0;
        timer(config);

        generation_snake(config);
        affichage_graphique(config,couleurs);
        affichage_snake_pomme(config,couleurs);
        MLV_actualise_window();

        if(config->partie.boost_vitesse > 0){
            config->partie.boost_vitesse-=1; 
        }
        
        while (compteur != (config->partie.tic - config->partie.boost_vitesse)){

            event = MLV_get_event(&sym, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

            switch (event){

            case MLV_NONE:
                break;

            case MLV_KEY:

                touche = sym;

                if(touche==PAUSE){
                exit = menu_pause(b,config);
                break;     
                }

                if(verif_coup(config,touche, dernier_coup) && (MLV_get_keyboard_state (UP_JOUEUR1 || UP_JOUEUR2 || LEFT_JOUEUR1 || LEFT_JOUEUR2 || RIGTH_JOUEUR1 || RIGTH_JOUEUR2 || DOWN_JOUEUR1 || DOWN_JOUEUR2) == MLV_PRESSED)){
                 ;
                }
                break;

            default: fprintf(stderr, "Erreur : la valeur de l'évènement récupéré est impossible.");
            }

            MLV_wait_milliseconds(1);
            compteur += 1;
        }

    }while(est_valide(config, dernier_coup) && !exit);

    if(config->partie.nb_joueurs==1)
    est_classement(config,calcul_score(*config));
    else{
        /* Si partie multijoueur affiche le gagnant */
        affichage_gagnant(*config, gagnant(config), *couleurs);
    }
}

