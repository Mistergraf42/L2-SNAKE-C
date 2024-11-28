#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../heads/types.h"
#define DELIMITEUR '-'
#define EXTENSION_SAVE ".bin"

void sauvegarde_binaire(partie partie, int save){

FILE *sauvegarde;
char Nom_sauvegarde[40];


sprintf(Nom_sauvegarde,"%s%d%s","sauvegardes/sauvegarde",save,EXTENSION_SAVE);

sauvegarde = fopen(Nom_sauvegarde,"wb");

if(sauvegarde==NULL){
	fprintf(stderr, "La sauvegarde n'a pas pu être enregistrer");
	return ;
}

fwrite(&partie, sizeof(partie),1,sauvegarde);

fclose(sauvegarde);
}

int charger_sauvegarde_binaire(partie *partie,int num_save){

FILE *save;

char Nom_sauvegarde[40];

if(num_save){

}

sprintf(Nom_sauvegarde,"%s%d%s","sauvegardes/sauvegarde",num_save,EXTENSION_SAVE);

save = fopen(Nom_sauvegarde,"rb");

if(save==NULL){
	return 0;
}

if( (fread(partie,sizeof(*partie),1,save)!=sizeof(*partie)) != 1){
	fprintf(stderr,"Erreur 77");
}

fclose(save);
return 1;
}

void modifie_classement(classement classement){

FILE *classe;

classe = fopen("sauvegardes/classement.bin","wb");

if(classe==NULL){
	return ;
}

fwrite(&classement, sizeof(classement),1,classe);
fclose(classe);

}

void initialisation_classement(configuration *config){
FILE *classement;

classement = fopen("sauvegardes/classement.bin","rb");

if(classement==NULL){
	config->classement.nb=0;
	return ;
}

if( fread(&config->classement, sizeof(config->classement),1,classement)!=1){
		fprintf(stderr,"Erreur 78");
		return ;
}
fclose(classement);
}