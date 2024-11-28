#include <stdio.h>
#include <stdlib.h>
#include "../heads/types.h"

/*Cette fonction permet une création de table de jeu*/
void initialisation_table_de_jeu(configuration *config){
    int i,j;

    for(i=0;i<config->partie.map.n;i++){
        for(j=0;j<config->partie.map.n;j++){

            if(i==0||i==config->partie.map.n-1){
                config->partie.map.plateau[i][j]='*';
            }
            else{
                if(j==0||j==config->partie.map.n-1){
                    config->partie.map.plateau[i][j]='*';
                }

            
                else{
                    config->partie.map.plateau[i][j]='.';
                }
            
            }
        }
    }
}
/*Cette fonction permet d'afficher notre table de jeu*/
void afficher_table(configuration *config){

    int i,j;

    for(i=0;i<config->partie.map.n;i++){
        for(j=0;j<config->partie.map.n;j++){
            printf("%c",config->partie.map.plateau[i][j]);
        }
        printf("\n");  
    }
}

/*cela permet de remettre la map sans pomme, il n'aura un plateau vide de pommes*/
void reset_pomme(configuration *config,int nb){
    int i;
    for(i=0;i<nb;i++){
    config->partie.map.plateau[config->partie.map.pomme[i].x][config->partie.map.pomme[i].y]='.';
    }
}
/*Cette fonction permet de générer un snake ayant pour corps le caratère s */
void generation_snake(configuration *config){
    int i,j;
    for(j=0;j<config->partie.nb_joueurs;j++){
    for(i=0;i<config->partie.joueur[j].taille;i++){
        config->partie.map.plateau[config->partie.joueur[j].corp[i].x][config->partie.joueur[j].corp[i].y]='s';
    }
}
}  
/*cette fonctions permet selon les cas de générer des pommes selon les modes de jeux*/
void generation_pomme(configuration *config){
    int r1,r2,i;
    char nouvelle_pomme;    
    char * types_pommes="$$$$$$$$$$";                    /*pour le mode classique*/

    if(config->partie.mode_jeu==1){

      if(config->partie.nb_joueurs==1)                          /*pomme normal, vitesse et moins 1 taille pour le mode solo*/
      types_pommes="$$$$$@@vvv";

      else
      types_pommes="$$$$$@@@@@";                         /*pomme normal, moins 1 taille pour le mode multi*/
        
    }

    for(i=0;i<config->partie.nb_pommes;i++){
    nouvelle_pomme=types_pommes[rand()%10];

    do{
        r2=rand()%(config->partie.map.n-2)+1;                   /*gération faite avec le +1 pour éviter de faire pop une pomme dans les murs*/
        r1=rand()%(config->partie.map.n-2)+1;
    }while(config->partie.map.plateau[r1][r2]!='.');            /*la pomme apparaitra seulement sur le plateau sur un lieu vide où il y aura pas de pommes*/

    config->partie.map.plateau[r1][r2]=nouvelle_pomme; 
    config->partie.map.pomme[i].x=r1;
    config->partie.map.pomme[i].y=r2;      
    }
}

void generation_mur(configuration *config, int nb){     /*cette fonction permet de générer de générer nos mur aléatoirement*/
int i,r1,r2;

for(i=0;i<nb;i++){

do{
    r2=rand()%(config->partie.map.n-2)+1;                      /*cela permet de crée des murs dans la zone du plateau de jeu*/
    r1=rand()%(config->partie.map.n-2)+1;
}while(config->partie.map.plateau[r1][r2]!='.');               /*un mur ne pourra pas apparaitre sur un mur existant*/

    config->partie.map.plateau[r1][r2]='*'; 
    config->partie.map.murs_sup[i].x=r1;
    config->partie.map.murs_sup[i].y=r2;    
}

}