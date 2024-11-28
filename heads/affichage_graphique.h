#ifndef __AFFICHAGE_GRAPHIQUE_H__
#define __AFFICHAGE_GRAPHIQUE_H__
#include "../heads/types.h"

void affichage_menu_principale(boutons b,configuration config);
void affichage_menu_play(boutons b,configuration config);
void affichage_menu_nouvelle_partie(boutons b,configuration *config);
int find_reso(configuration *config);
void affichage_graphique(configuration *config, personalisation_couleur *couleurs);
void affichage_snake_pomme(configuration *config, personalisation_couleur *couleurs);
void initialisation_coordonnees(boutons *boutons,configuration config);
void affichage_menu_pause(boutons b);
void affichage_menu_sauvegardes(boutons b,configuration config,int selection);
void initialisation_couleur_jeu(personalisation_couleur *objets);
void affiche_classement(configuration config);
void affichage_gagnant(configuration config, int gagnant, personalisation_couleur couleurs);
#endif