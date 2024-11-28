#ifndef __SOLO_H__
#define __SOLO_H__
#include "../heads/types.h"

void nouvelle_partie_graphique(configuration *config, personalisation_couleur *couleurs, boutons b);
void initialisation_partie(configuration *config);
void initialisation_nouvelle_partie(configuration *config,int nb_joueurs);
#endif