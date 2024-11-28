#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "../heads/types.h"
#include "../heads/affichage_graphique.h"
#include "../heads/solo.h"
#include "../heads/saves.h"
#include "../heads/recup_click.h"
#include "../heads/menu_options.h"

int menu_sauvegardes(boutons b, configuration *config){

    int m,x,y;
    int exit=0; 
    int save=0;            /*default à chaque  fois */


    while(!exit){
        /*Affichage graphique du menu*/
        affichage_menu_sauvegardes(b,*config, save); 
        do{
            MLV_wait_mouse(&x,&y); /* recuperer les cordonnée du prochain click de l'utilisateur sur la fenêtre*/
        }while(!(m=retour_click_menu_sauvegarde(x,y,b))); /*tant qu'il ne correspondent pas aux coordonnées d'un bouton*/

        switch(m){

        case 1:

            save=1;
            break;

        case 2:

            save=2;
            break;

        case 3:

            save=3;
            break;

        case 4:
            save=4;
            break;

        case 5:

            if(save){
                sauvegarde_binaire(config->partie, save);
                return 1;
            }
            break;

        case 6:

            return 0;
            break;


        default: exit=1;
        }
    }
    return 0;
}

int menu_pause(boutons b, configuration *config){

    int m,x,y;
    int statut=0; 



    affichage_menu_pause(b); 

    do{
        MLV_wait_mouse(&x,&y); /* recuperer les cordonnée du prochain click de l'utilisateur sur la fenêtre*/
    }while(!(m=retour_click_menu_pause(x,y,b))); /*tant qu'il ne correspondent pas aux coordonnées d'un bouton*/

    switch(m){

    case 1:
        return 0;
        break;

    case 2:

        return 1;
        break;

    case 3:

        
        statut=menu_sauvegardes(b,config);

        return statut;
        break;

    default: fprintf(stderr,"Erreur 36, cf manuel\n");
    }
    return 0;
}

 int menu_nouvelle_partie(boutons b, personalisation_couleur *couleurs, configuration *config){

    int m,x,y;
    int exit=0;

    while(!exit){
        affichage_menu_nouvelle_partie(b,config);
        do{
            MLV_wait_mouse(&x,&y); /* recuperer les cordonnée du prochain click de l'utilisateur sur la fenêtre*/
        }while(!(m=retour_click_menu_nouvelle_partie(x,y,b))); /*tant qu'il ne correspondent pas aux coordonnées d'un bouton*/

        switch(m){

        case 1:
            config->partie.vitesse = (config->partie.vitesse+1)%3;
            break;

        case 2:
            config->partie.taille_plateau = (config->partie.taille_plateau+1)%3;
            break;

        case 3:
            config->partie.mode_jeu = (config->partie.mode_jeu+1)%3;
            break;

        case 4:
            return 1;
            initialisation_nouvelle_partie(config,1);
            nouvelle_partie_graphique(config,couleurs,b);
            exit=1;
            break;

        case 5:
            return 0;
            exit=1;
            break;

        default: exit=1;
        }
    }
    return 0;
}

void menu_play(boutons b, personalisation_couleur *couleurs, configuration *config){

    int m,x,y;
    int exit=0;

    config->partie.nb_joueurs=1;
    while(!exit){

        /*Affichage graphique du menu*/
        affichage_menu_play(b, *config); 

        do{
            MLV_wait_mouse(&x,&y); /* recuperer les cordonnée du prochain click de l'utilisateur sur la fenêtre*/
        }while(!(m=retour_click_menu_play(x,y,b))); /*tant qu'il ne correspondent pas aux coordonnées d'un bouton*/

        switch(m){

        case 1:
            if(menu_nouvelle_partie(b, couleurs, config)){
            initialisation_nouvelle_partie(config,1);
            nouvelle_partie_graphique(config,couleurs,b);
            }
            break;

        case 2:

            if(charger_sauvegarde_binaire(&config->partie,1))
            nouvelle_partie_graphique(config,couleurs,b);
            break;

        case 3:

            if(charger_sauvegarde_binaire(&config->partie,2))
            nouvelle_partie_graphique(config,couleurs,b);
            break;

        case 4:
            if(charger_sauvegarde_binaire(&config->partie,3))
            nouvelle_partie_graphique(config,couleurs,b);
            break;

        case 5:

            if(charger_sauvegarde_binaire(&config->partie,4))
            nouvelle_partie_graphique(config,couleurs,b);
            break;

        case 6:
            affiche_classement(*config);
            MLV_wait_seconds(3);
            printf("leaderboard");
            break;

        case 7:
            exit=1;
            break;

        default: exit=1;
        }
    }

}

void menu_principale(boutons *b, personalisation_couleur *couleurs, configuration *config){
    int m,x,y;
    int exit=0; 

    while(!exit){

        /*Affichage graphique du menu*/
        affichage_menu_principale(*b, *config); 
        do{
            MLV_wait_mouse(&x,&y); /* recuperer les cordonnée du prochain click de l'utilisateur sur la fenêtre*/
        }while(!(m=retour_click_menu_principale(x,y,*b))); /*tant qu'il ne correspondent pas aux coordonnées d'un bouton*/



        switch(m){

        case 1:
            menu_play(*b, couleurs, config);
            break;

        case 2:

            if(menu_nouvelle_partie(*b, couleurs, config)){
            initialisation_nouvelle_partie(config,2);
            nouvelle_partie_graphique(config,couleurs,*b);
        }
            break;

        case 3:
            menu_options(couleurs, config, b);
            break;

        case 4: 
            exit=1;
            break;

        default: exit=1;
        }

    }

}