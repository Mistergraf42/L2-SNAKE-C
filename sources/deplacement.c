#include <stdio.h>
#include "../heads/types.h"
#include "../heads/map.h"

int next_mouve(int x_t,int y_t,int x_q,int y_q,int diff_x_t,int diff_y_t,int num_joueur,configuration *config){
   int i; 

switch(config->partie.map.plateau[x_t+diff_x_t][y_t+diff_y_t]){

case '.':

        /* remplace la queu du serpent par une case vide. */
        config->partie.map.plateau[x_q][y_q]='.';

        /* dernière case du tableau corp prend les cordonnée de l'avant dernière ... jusqu'à la deuxième case (corp[1]). */
        for(i=config->partie.joueur[num_joueur].taille-1;i>0;i--){
            config->partie.joueur[num_joueur].corp[i].x = config->partie.joueur[num_joueur].corp[i-1].x;
            config->partie.joueur[num_joueur].corp[i].y = config->partie.joueur[num_joueur].corp[i-1].y;
        }

        /* et la tête (corp[0]) prend la nouvelle valeur en fonction de la touche pressée. */
        config->partie.joueur[num_joueur].corp[0].x+=diff_x_t;
        config->partie.joueur[num_joueur].corp[0].y+=diff_y_t;
        return 1;

case '$':/*si on avance sur une pomme*/

    reset_pomme(config,config->partie.nb_pommes);

    for(i=config->partie.joueur[num_joueur].taille-1;i>0;i--){
        config->partie.joueur[num_joueur].corp[i].x = config->partie.joueur[num_joueur].corp[i-1].x;
        config->partie.joueur[num_joueur].corp[i].y = config->partie.joueur[num_joueur].corp[i-1].y;
    }


    /* On remplace les cordonée de la pomme par les cordonnée de la tete du serpent dans la tableau. */
    config->partie.joueur[num_joueur].corp[0].x+=diff_x_t;
    config->partie.joueur[num_joueur].corp[0].y+=diff_y_t;

    /*On ajoute dans le tableau corp un nouveau "bout de serpent" à aux cordonnées de l'ancienne queue.*/
    config->partie.joueur[num_joueur].corp[config->partie.joueur[num_joueur].taille].x=x_q;
    config->partie.joueur[num_joueur].corp[config->partie.joueur[num_joueur].taille].y=y_q;
    /* On incrémente la taille du serpent */
    config->partie.joueur[num_joueur].taille +=1;

    /*On regenere les elements du jeu*/
    generation_pomme(config);
    return 1;
    break;

case '@':/*MALUS TAILLE -1*/

        if(config->partie.joueur[num_joueur].taille ==1){
            return 0;
        }

        reset_pomme(config,config->partie.nb_pommes);


        /* dernière case du tableau corp prend les cordonnée de l'avant dernière ... jusqu'à la deuxième case (corp[1]). */
        for(i=config->partie.joueur[num_joueur].taille-1;i>0;i--){
            config->partie.joueur[num_joueur].corp[i].x = config->partie.joueur[num_joueur].corp[i-1].x;
            config->partie.joueur[num_joueur].corp[i].y = config->partie.joueur[num_joueur].corp[i-1].y;
        }

        /* remplace la queu du serpent par une case vide. */
        config->partie.map.plateau[x_q][y_q]='.';

        /* remplace la queu du serpent par une case vide. */
        config->partie.map.plateau[config->partie.joueur[num_joueur].corp[config->partie.joueur[num_joueur].taille-1].x][config->partie.joueur[num_joueur].corp[config->partie.joueur[num_joueur].taille-1].y]='.';

        /* On decrémente la taille du serpent */
        config->partie.joueur[num_joueur].taille -=1;


        config->partie.joueur[num_joueur].corp[0].x+=diff_x_t;
        config->partie.joueur[num_joueur].corp[0].y+=diff_y_t;

        generation_pomme(config);
                return 1;

case 'v':

        reset_pomme(config,config->partie.nb_pommes);

        /* remplace la queu du serpent par une case vide. */
        config->partie.map.plateau[x_q][y_q]='.';

        /* dernière case du tableau corp prend les cordonnée de l'avant dernière ... jusqu'à la deuxième case (corp[1]). */
        for(i=config->partie.joueur[num_joueur].taille-1;i>0;i--){
            config->partie.joueur[num_joueur].corp[i].x = config->partie.joueur[num_joueur].corp[i-1].x;
            config->partie.joueur[num_joueur].corp[i].y = config->partie.joueur[num_joueur].corp[i-1].y;
        }

        /* et la tête (corp[0]) prend la nouvelle valeur en fonction de la touche pressée. */
        config->partie.joueur[num_joueur].corp[0].x+=diff_x_t;
        config->partie.joueur[num_joueur].corp[0].y+=diff_y_t;

        /*on rajoute du boost au boost vitesse*/
        if(( config->partie.tic - (config->partie.boost_vitesse + 10 )) > 0){
        config->partie.boost_vitesse+=10;
    }
        generation_pomme(config);

        return 1;

case 's':

        return 0;

case '*':

        return 0;

default: fprintf(stderr,"Une erreur est survenue2 \n");
}
return 0;
}

int mouvement(configuration *config,char direction, int num_joueur ){
        
    int statut=0;
    int x_t,y_t,x_q,y_q;

    /* Prend les cordonnées x et y de la tête du serpent. */
    x_t=config->partie.joueur[num_joueur].corp[0].x;
    y_t=config->partie.joueur[num_joueur].corp[0].y;
    /* Prend les cordonnées x et y de la queue du serpent. */
    x_q = config->partie.joueur[num_joueur].corp[config->partie.joueur[num_joueur].taille-1].x;
    y_q = config->partie.joueur[num_joueur].corp[config->partie.joueur[num_joueur].taille-1].y;
    
    switch(direction){

    case 'h': /* valeur ASCII 'h'*/
      
        statut=next_mouve(x_t,y_t,x_q,y_q,-1,0,num_joueur,config);
        break;


    case 'g': 
   
        statut=next_mouve(x_t,y_t,x_q,y_q,0,-1,num_joueur,config);
        break;

    case 'd': 

        statut=next_mouve(x_t,y_t,x_q,y_q,0,1,num_joueur,config);
        break;

    case 'b': 

        statut=next_mouve(x_t,y_t,x_q,y_q,1,0,num_joueur,config);
        break;

    default: fprintf(stderr,"Une erreur est survenue \n");

    }

return statut;
}