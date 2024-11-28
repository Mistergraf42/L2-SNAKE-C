#ifndef __MENU_H__
#define __MENU_H__
#include "../heads/types.h"

int retour_click_menu_principale(int x,int y,boutons b);
void menu_principale(boutons *b, personalisation_couleur *couleurs, configuration *config);

int retour_click_menu_play(int x,int y,boutons b);
void menu_play(boutons b, personalisation_couleur *couleurs, configuration *config);

int retour_click_menu_nouvelle_partie(int x,int y,boutons b,configuration *config);
void menu_nouvelle_partie(boutons b, personalisation_couleur *couleurs, configuration *config);

int retour_click_menu_pause(int x,int y,boutons b);
int menu_pause(boutons b, configuration *config);

void menu_options(boutons b, personalisation_couleur *couleurs);

#endif