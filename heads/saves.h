#ifndef __SAVES_H__
#define __SAVES_H__


void sauvegarde_binaire(partie partie,int save);
int charger_sauvegarde_binaire(partie *partie,int num_save);
void modifie_classement(classement classement);
void initialisation_classement(configuration *config);

#endif