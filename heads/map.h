#ifndef __MAP_H__
#define __MAP_H__
#include "../heads/types.h"

void initialisation_table_de_jeu(configuration *config);
void generation_pomme(configuration *config);
void generation_snake(configuration *config);
void reset_pomme(configuration *config,int nb);
void generation_mur(configuration *config, int nb);

#endif