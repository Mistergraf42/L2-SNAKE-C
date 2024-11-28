#include <MLV/MLV_all.h>
#include "../heads/types.h"
#include "../heads/options.h"
#include "../heads/affichage_graphique.h"



int traitement_click(int x,int y,rgb *objet,configuration *config){

int x_b_seclect;
int largeur_b_seclect;

/* Largeur en pixels de la barre de selection divisé par 256*/
largeur_b_seclect = ((config->fenetre.largeur*2)/3)/256;

x_b_seclect = (config->fenetre.largeur - largeur_b_seclect*256)/2;

/******** Regarde si les cordonnée coresponde à une des trois barres de selection ******/


/* Barre rouge */
    if(x>= x_b_seclect && x<= largeur_b_seclect*255 + x_b_seclect){ 
        if(y>= config->fenetre.hauteur/10 + config->fenetre.hauteur/50 && y<= config->fenetre.hauteur/10 - largeur_b_seclect + config->fenetre.hauteur/10 + config->fenetre.hauteur/50){
        	objet->r = (x - x_b_seclect)/largeur_b_seclect;
        	return 0;
        }        
    }

/* Barre verte */
    if(x>= x_b_seclect && x<= largeur_b_seclect*255 + x_b_seclect){ 
        if(y>= config->fenetre.hauteur/10 + config->fenetre.hauteur/50*2 + config->fenetre.hauteur/10 && y<= config->fenetre.hauteur/10 - largeur_b_seclect + config->fenetre.hauteur/10 + config->fenetre.hauteur/50*2 + config->fenetre.hauteur/10 ){
        	objet->g = (x - x_b_seclect)/largeur_b_seclect;
        	return 0;
        }        
    }

/* Barre bleu */
    if(x>= x_b_seclect && x<= largeur_b_seclect*255 + x_b_seclect){ 
        if(y>= config->fenetre.hauteur/10 + config->fenetre.hauteur/50*3 + config->fenetre.hauteur*2/10 && y<= config->fenetre.hauteur/10 + config->fenetre.hauteur/10 + config->fenetre.hauteur/50*3 + config->fenetre.hauteur*2/10){
        	objet->b = (x - x_b_seclect)/largeur_b_seclect;
        	return 0;
        }        
    }


/* Valider */
    if(x>= x_b_seclect && x<= (255*largeur_b_seclect)/2 -10 + x_b_seclect){ 
        if(y>= config->fenetre.hauteur*9/10 && y<= config->fenetre.hauteur*9/10 +  (config->fenetre.hauteur/10)/2){
        	return 1;
        }        
    }

/* Annuler */
    if(x>= x_b_seclect + (255*largeur_b_seclect)/2 + 15 && x<= (255*largeur_b_seclect)/2 -10 + x_b_seclect + (255*largeur_b_seclect)/2 + 15 ){ 
        if(y>= config->fenetre.hauteur*9/10 && y<= config->fenetre.hauteur*9/10 +  (config->fenetre.hauteur/10)/2){
        	return 2;
        }        
    }
    return 0;

}

void affichage_menu_nouvelle_couleur(rgb objet, configuration *config){

MLV_Image *fond_menu;
MLV_Image *bouton_valider;
MLV_Image *bouton_annuler;
int r,v,b;
int largeur_parfaite;
int diff_largeur;

coordonnees rectangle_rouge;
coordonnees rectangle_vert;
coordonnees rectangle_bleu;

coordonnees rectangle_resultat;

MLV_clear_window(MLV_COLOR_BLACK);

largeur_parfaite = ((config->fenetre.largeur*2)/3)/256;
diff_largeur = (config->fenetre.largeur - largeur_parfaite*256)/2;

rectangle_rouge.x=diff_largeur;
rectangle_rouge.y=config->fenetre.hauteur/10 + config->fenetre.hauteur/50;


rectangle_vert.x=diff_largeur;
rectangle_vert.y=config->fenetre.hauteur/10 + config->fenetre.hauteur/50*2 + config->fenetre.hauteur/10;

rectangle_bleu.x=diff_largeur;
rectangle_bleu.y=config->fenetre.hauteur/10 + config->fenetre.hauteur/50*3 + config->fenetre.hauteur*2/10;

rectangle_resultat.x=diff_largeur;
rectangle_resultat.y=config->fenetre.hauteur/10 + config->fenetre.hauteur/50*4 + config->fenetre.hauteur*3/10;


/****** FOND MENU *****/

fond_menu = MLV_load_image("images/menu-options/nv-couleur-bg_couleurs.jpg");
MLV_resize_image_with_proportions(fond_menu,config->fenetre.largeur,config->fenetre.hauteur);
MLV_draw_image(fond_menu,0, 0 );

bouton_valider = MLV_load_image("images/menu-options/nouvel-couleur-bouton_valider.jpg");
MLV_resize_image_with_proportions(bouton_valider,(255*largeur_parfaite)/2 -10,(config->fenetre.hauteur/10)/2);
MLV_draw_image(bouton_valider, diff_largeur -5, config->fenetre.hauteur*9/10);

bouton_annuler = MLV_load_image("images/menu-options/nouvel-couleur-bouton_annuler.jpg");
MLV_resize_image_with_proportions(bouton_annuler,(255*largeur_parfaite)/2 -10,(config->fenetre.hauteur/10)/2);
MLV_draw_image(bouton_annuler, diff_largeur + (255*largeur_parfaite)/2 + 15, config->fenetre.hauteur*9/10);

/******* BARRES DE SELECTIONS*******/

/*Selection rouge*/
MLV_draw_rectangle( rectangle_rouge.x-1, rectangle_rouge.y, largeur_parfaite*256 + largeur_parfaite, config->fenetre.hauteur/10, MLV_COLOR_WHITE_SMOKE);


for(r=0;r<=255;r++){

MLV_draw_filled_rectangle(rectangle_rouge.x + (r*largeur_parfaite), rectangle_rouge.y + 1, largeur_parfaite,config->fenetre.hauteur/10 - largeur_parfaite, MLV_convert_rgba_to_color(r,0,0,255));
}

/*Selection verte*/
MLV_draw_rectangle( rectangle_vert.x-1, rectangle_vert.y, largeur_parfaite*256 + largeur_parfaite, config->fenetre.hauteur/10, MLV_COLOR_WHITE_SMOKE);


for(v=0;v<=255;v++){

MLV_draw_filled_rectangle(rectangle_vert.x + (v*largeur_parfaite), rectangle_vert.y + 1, largeur_parfaite,config->fenetre.hauteur/10 - largeur_parfaite, MLV_convert_rgba_to_color(0,v,0,255));
}

/*Selection bleu*/
MLV_draw_rectangle( rectangle_bleu.x-1, rectangle_bleu.y, largeur_parfaite*256 + largeur_parfaite, config->fenetre.hauteur/10, MLV_COLOR_WHITE_SMOKE);


for(b=0;b<=255;b++){

MLV_draw_filled_rectangle(rectangle_bleu.x + (b*largeur_parfaite), rectangle_bleu.y + 1, largeur_parfaite,config->fenetre.hauteur/10 - largeur_parfaite, MLV_convert_rgba_to_color(0,0,b,255));
}

/********************************************/

/*** Ligne de selection***/
MLV_draw_filled_rectangle(rectangle_bleu.x + (objet.r*largeur_parfaite), rectangle_rouge.y + 1, largeur_parfaite,config->fenetre.hauteur/10 - largeur_parfaite,MLV_COLOR_BLACK);
MLV_draw_filled_rectangle(rectangle_bleu.x + (objet.g*largeur_parfaite), rectangle_vert.y + 1, largeur_parfaite,config->fenetre.hauteur/10 - largeur_parfaite,MLV_COLOR_BLACK);
MLV_draw_filled_rectangle(rectangle_bleu.x + (objet.b*largeur_parfaite), rectangle_bleu.y + 1, largeur_parfaite,config->fenetre.hauteur/10 - largeur_parfaite,MLV_COLOR_BLACK);

/*************Carré du résultat*************/
MLV_draw_rectangle(rectangle_resultat.x -1,rectangle_resultat.y +config->fenetre.hauteur/50 - 1, largeur_parfaite*256 + 2,config->fenetre.hauteur*4/10 - config->fenetre.hauteur/50 + 2,  MLV_COLOR_WHITE_SMOKE);
MLV_draw_filled_rectangle(rectangle_resultat.x,rectangle_resultat.y +config->fenetre.hauteur/50 , largeur_parfaite*256 ,config->fenetre.hauteur*4/10 - config->fenetre.hauteur/50 , MLV_convert_rgba_to_color(objet.r,objet.g,objet.b,255));
/*******************************************/

 MLV_free_image(fond_menu);
 MLV_free_image(bouton_valider);
 MLV_free_image(bouton_annuler);

}
/*******Permet de changer d'options de personnalisations quand on aura cliquer*********/
rgb *int_to_choix_rgb(int choix,personalisation_couleur *couleurs){
switch(choix){

case 0:
    return 0;
    break;

case 1:
    return &couleurs->snake_1_tete;
    break;

case 2:
    return &couleurs->snake_2_tete;
    break;

case 3:
    return &couleurs->snake_1;
    break;

case 4:
    return &couleurs->snake_2;
    break;

case 5:
    return &couleurs->pomme_normal;
    break;

case 6:
    return &couleurs->pomme_vitesse;
    break;

case 7:
    return &couleurs->pomme_malus;
    break;

case 8:
    return &couleurs->murs;
    break;

case 9:
    return &couleurs->plateau;
    break;

case 10:
    return &couleurs->textes;
    break;

default: fprintf(stderr,"Erreur 45\n");
}
return NULL;
}



int traitement_click_menu_options(int x,int y,int *selection, configuration *config, int *reso){

    if(x>= config->fenetre.largeur/6 && x<= config->fenetre.largeur/3 - 10  + config->fenetre.largeur/6){ 
        if(y>= config->fenetre.hauteur*9/10 && y<= config->fenetre.hauteur/20 + config->fenetre.hauteur*9/10){
            return 1;
        }
    }

    if(x>= config->fenetre.largeur/6 + config->fenetre.largeur/3 + 10 && x<= config->fenetre.largeur/3 + config->fenetre.largeur/6 + config->fenetre.largeur/3){ 
        if(y>= config->fenetre.hauteur*9/10 && y<= config->fenetre.hauteur/20 + config->fenetre.hauteur*9/10){
            return 2;
        }
    }

    if(x>= config->fenetre.largeur/6 && x<= config->fenetre.largeur*2/3 + config->fenetre.largeur/6 ){ 
        if(y>= config->fenetre.hauteur*8/10 - 10 && y<= config->fenetre.hauteur/10 + config->fenetre.hauteur*8/10 -20){
        	*selection= (*selection + 1)%11;
            return 0;
        }
    }

        if(x>= config->fenetre.largeur/6 && x<= config->fenetre.largeur/6 + config->fenetre.largeur*2/3){ 
        if(y>= config->fenetre.hauteur*8/10 - config->fenetre.hauteur/10 - 20 && y<= config->fenetre.hauteur*8/10 - config->fenetre.hauteur/10 - 20 + config->fenetre.hauteur/10){
            *reso = (*reso + 1)%2;
            return 3;
        }
    }
    return -1;
}



void affichage_menu_options(int choix,int reso, configuration *config){

MLV_Image *fond_menu_options;
MLV_Image *bouton_retour;
MLV_Image *bouton_personaliser;
MLV_Image *bouton_selection;
MLV_Image *bouton_reso=NULL;

fond_menu_options = MLV_load_image("images/menu-options/nv-couleur-bg_options.jpg");
MLV_resize_image_with_proportions(fond_menu_options,config->fenetre.largeur,config->fenetre.hauteur);
MLV_draw_image(fond_menu_options,0, 0 );

bouton_personaliser = MLV_load_image("images/menu-options/bouton_valider.jpg");
MLV_resize_image_with_proportions(bouton_personaliser,config->fenetre.largeur/3 - 10, config->fenetre.hauteur/20);
MLV_draw_image(bouton_personaliser,config->fenetre.largeur/6,config->fenetre.hauteur*9/10);

bouton_retour = MLV_load_image("images/menu-options/bouton_retour.jpg");
MLV_resize_image_with_proportions(bouton_retour,config->fenetre.largeur/3 - 10, config->fenetre.hauteur/20);
MLV_draw_image(bouton_retour,config->fenetre.largeur/6 + config->fenetre.largeur/3 + 10 ,config->fenetre.hauteur*9/10);

switch(reso){

case 0:
bouton_reso = MLV_load_image("images/menu-options/bouton_reso/bouton_900_900.jpg");
break;

case 1:
bouton_reso = MLV_load_image("images/menu-options/bouton_reso/bouton_600_600.jpg");
break;
 
default :
printf ("ERREUR dans affichage_menu_options: reso %d \n", reso);
break;
}

MLV_resize_image_with_proportions(bouton_reso,config->fenetre.largeur*2/3, config->fenetre.hauteur/10);
MLV_draw_image(bouton_reso,config->fenetre.largeur/6 ,config->fenetre.hauteur*8/10 - config->fenetre.hauteur/10 - 20);


switch(choix){

case 0:
	bouton_selection = MLV_load_image("images/menu-options/boutons_selections/reset.jpg");
	break;

case 1:
    bouton_selection = MLV_load_image("images/menu-options/boutons_selections/tete_1.jpg");
    break;

case 2:
    bouton_selection= MLV_load_image("images/menu-options/boutons_selections/tete_2.jpg");
    break;

case 3:
    bouton_selection = MLV_load_image("images/menu-options/boutons_selections/corp1.jpg");
    break;

case 4:
    bouton_selection= MLV_load_image("images/menu-options/boutons_selections/corp2.jpg");
    break;

case 5:
    bouton_selection = MLV_load_image("images/menu-options/boutons_selections/pomme.jpg");
    break;

case 6:
    bouton_selection= MLV_load_image("images/menu-options/boutons_selections/pomme_vit.jpg");
    break;

case 7:
    bouton_selection = MLV_load_image("images/menu-options/boutons_selections/pomme_piege.jpg");
    break;

case 8:
    bouton_selection= MLV_load_image("images/menu-options/boutons_selections/mur.jpg");
    break;

case 9:
    bouton_selection= MLV_load_image("images/menu-options/boutons_selections/plateau.jpg");
    break;

case 10:
    bouton_selection= MLV_load_image("images/menu-options/boutons_selections/couleur_txt.jpg");
    break;

default:  bouton_selection= MLV_load_image("images/menu-options/boutons_selections/404.jpg");   		
}

MLV_resize_image_with_proportions(bouton_selection,config->fenetre.largeur*2/3, config->fenetre.hauteur/10);
MLV_draw_image(bouton_selection,config->fenetre.largeur/6,config->fenetre.hauteur*8/10 - 10);

MLV_actualise_window();
MLV_free_image(fond_menu_options);
MLV_free_image(bouton_retour);
MLV_free_image(bouton_personaliser);
MLV_free_image(bouton_selection);

if(bouton_reso != NULL)
MLV_free_image(bouton_reso);
}


void nv_couleur(rgb *objet,configuration *config){



int x,y;
int retour;
rgb resultat;

resultat.r=objet->r;
resultat.g=objet->g;
resultat.b=objet->b;

do{
	affichage_menu_nouvelle_couleur(resultat, config);
	MLV_actualise_window();
	MLV_wait_mouse(&x,&y);

}while(!(retour=traitement_click(x,y,&resultat,config)));

if(retour == 1){
objet->r = resultat.r;
objet->g = resultat.g;
objet->b = resultat.b;
}
}

void menu_options(personalisation_couleur *objets,configuration *config, boutons *b){
int x,y;	
int retour=0;
int selection=0;
int reso;

switch(config->fenetre.hauteur){

case 900:
        reso = 0;
        break;

case 600:
        reso = 1;
        break ;

default: return ;
}


while(retour!=2){

do{
	affichage_menu_options(selection, reso, config);
	MLV_wait_mouse(&x,&y);
	if( (retour=traitement_click_menu_options(x,y,&selection, config, &reso)) ){
 /* permet de faire une resolution en temps réel en fonction du choix fait*/
 if(retour==3){
switch(reso){

    case 0:
    config->fenetre.hauteur = 900; 
    config->fenetre.largeur= 900;
    break;

    case 1:
    config->fenetre.hauteur = 600;
    config->fenetre.largeur= 600;
    break;
    
    
    default :
    config->fenetre.hauteur = 900;       
    config->fenetre.largeur= 900;
    break;

}
    MLV_change_window_size(config->fenetre.hauteur,config->fenetre.largeur);
    initialisation_coordonnees(b, *config);
 }
    }
}while(!retour || retour == 3);


if(retour==1){

    if(selection!=0){
	nv_couleur(int_to_choix_rgb(selection,objets), config);
    }
    else{
        initialisation_couleur_jeu(objets);
        MLV_draw_text(config->fenetre.largeur*2/5,config->fenetre.hauteur/5,"Les couleurs ont bien été reset !",MLV_COLOR_RED);
        MLV_actualise_window();
        MLV_wait_seconds(1);
    }
}
}
}