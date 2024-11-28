#include <MLV/MLV_all.h>
#include "../heads/types.h"
#include "../heads/options.h"

MLV_Color type_rgb_to_color(rgb objet){ /*Prend en entré une variable de type rgv et renvoi sa couleur pour MLV*/

MLV_Color couleur = MLV_convert_rgba_to_color(objet.r,objet.g,objet.b,255);
return couleur; 
}

int find_reso(configuration *config){

    return config->fenetre.largeur / config->partie.map.n;
}

void initialisation_couleur_jeu(personalisation_couleur *objets){

objets->pomme_normal.r= POMME_NORMAL_R;
objets->pomme_normal.g= POMME_NORMAL_G;
objets->pomme_normal.b= POMME_NORMAL_B;

objets->pomme_malus.r= POMME_MALUS_R;
objets->pomme_malus.g= POMME_MALUS_G;
objets->pomme_malus.b= POMME_MALUS_B;

objets->pomme_vitesse.r= POMME_VITESSE_R;
objets->pomme_vitesse.g= POMME_VITESSE_G;
objets->pomme_vitesse.b= POMME_VITESSE_B;

objets->snake_1.r= SNAKE_1_R;
objets->snake_1.g= SNAKE_1_G;
objets->snake_1.b= SNAKE_1_B;
objets->snake_2.r= SNAKE_2_R;
objets->snake_2.g= SNAKE_2_G;
objets->snake_2.b= SNAKE_2_B;

objets->plateau.r= PLATEAU_R;
objets->plateau.g= PLATEAU_G;
objets->plateau.b= PLATEAU_B;

objets->murs.r= MUR_R;
objets->murs.g= MUR_G;
objets->murs.b= MUR_B;

objets->snake_1_tete.r= SNAKE_1_T_R;
objets->snake_1_tete.g= SNAKE_1_T_G;
objets->snake_1_tete.b= SNAKE_1_T_B;

objets->snake_2_tete.r= SNAKE_1_T_R;
objets->snake_2_tete.g= SNAKE_1_T_G;
objets->snake_2_tete.b= SNAKE_1_T_B;

objets->textes.r= TEXTE_R;
objets->textes.g= TEXTE_G;
objets->textes.b= TEXTE_B;

}

void affiche_classement(configuration config){
int i;
char ligne[100];
MLV_Image *fond_menu_leaderboard;

MLV_clear_window(MLV_COLOR_WHITE);

fond_menu_leaderboard = MLV_load_image("images/menu-play/fond_menu_leaderboard.jpg");
MLV_resize_image_with_proportions(fond_menu_leaderboard , config.fenetre.largeur, config.fenetre.hauteur);
MLV_draw_image(fond_menu_leaderboard , 0, 0 );

for(i=0;i<config.classement.nb;i++){
     sprintf(ligne,"%d. a manger %d pomme(s) en %d minutes et %d secondes en vitesse %d",i+1, config.classement.tab[i].pommes,config.classement.tab[i].duree.minutes,config.classement.tab[i].duree.secondes,config.classement.tab[i].vitesse);

    MLV_draw_text(5,config.fenetre.hauteur/7  + i*config.fenetre.hauteur/11 ,ligne,MLV_COLOR_BLACK);
}
MLV_actualise_window();
}

void affichage_gagnant(configuration config, int gagnant,  personalisation_couleur couleurs){
char message[100];
if(gagnant){
sprintf(message,"GG Joueur %d, tu es le gagnant !", gagnant);
}
else{
sprintf(message,"Egalité !");
}
MLV_draw_text(config.fenetre.largeur/2 - config.fenetre.largeur/10, config.fenetre.hauteur/3, message, type_rgb_to_color(couleurs.textes));
MLV_actualise_window();
MLV_wait_seconds(3);
}

void affichage_menu_principale(boutons b,configuration config){
    
    MLV_Image *fond_menu_principale;
    MLV_Image *fond_bouton_jouer;
    MLV_Image *fond_bouton_quitter;
    MLV_Image *fond_bouton_multi;
    MLV_Image *fond_bouton_options;

    MLV_clear_window(MLV_COLOR_GREEN);

    /* fond menu principales */
    fond_menu_principale = MLV_load_image("images/menu-principale/fond_menu_principale.jpg" );
    MLV_resize_image_with_proportions( fond_menu_principale, config.fenetre.largeur, config.fenetre.hauteur);
    MLV_draw_image( fond_menu_principale, 0, 0 );

    /* Bouton jouer */
    fond_bouton_jouer = MLV_load_image("images/menu-principale/play.jpg");
    MLV_resize_image_with_proportions(fond_bouton_jouer, b.largeur_bouton, b.hauteur_bouton);
    MLV_draw_image( fond_bouton_jouer,b.play.x, b.play.y );

    /* Bouton multiplayer */
    fond_bouton_multi = MLV_load_image("images/menu-principale/multi.jpg");
    MLV_resize_image_with_proportions(fond_bouton_multi,b.largeur_bouton,b.hauteur_bouton);
    MLV_draw_image(fond_bouton_multi,b.multi.x, b.multi.y );

    /* Bouton options */
    fond_bouton_options = MLV_load_image("images/menu-principale/options.jpg");
    MLV_resize_image_with_proportions(fond_bouton_options,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_options,b.options.x, b.options.y );

    /* Bouton quitter; */
    fond_bouton_quitter = MLV_load_image("images/menu-principale/quitter.jpg");
    MLV_resize_image_with_proportions(fond_bouton_quitter,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_quitter,b.quitter.x, b.quitter.y );
   
    /*Recharge la nouvelle fenetre, puis libere la memoire*/
    MLV_actualise_window(); 
    MLV_free_image(fond_menu_principale);
    MLV_free_image(fond_bouton_jouer);
    MLV_free_image(fond_bouton_multi);
    MLV_free_image(fond_bouton_options);
    MLV_free_image(fond_bouton_quitter);
}

void affichage_menu_play(boutons b,configuration config){
    
    MLV_Image *fond_menu_play;
    MLV_Image *fond_bouton_nouvelle_partie;

    MLV_Image *fond_bouton_save1;
    MLV_Image *fond_bouton_save2;
    MLV_Image *fond_bouton_save3;
    MLV_Image *fond_bouton_save4;

    MLV_Image *fond_bouton_leaderboard;
    MLV_Image *fond_bouton_quitter_play;

    MLV_clear_window(MLV_COLOR_GREEN);
    

    /* fond menu play */
    fond_menu_play = MLV_load_image( "images/menu-play/fond_menu_play.jpg" );
    MLV_resize_image_with_proportions( fond_menu_play, config.fenetre.largeur, config.fenetre.hauteur);
    MLV_draw_image( fond_menu_play, 0, 0 );

    /* Bouton mode de jeu */
    fond_bouton_nouvelle_partie = MLV_load_image( "images/menu-play/bouton_nouvelle_partie.jpg");
    MLV_resize_image_with_proportions(fond_bouton_nouvelle_partie, b.largeur_bouton, b.hauteur_bouton);
    MLV_draw_image( fond_bouton_nouvelle_partie,b.nouvelle_partie.x, b.nouvelle_partie.y );

    /* Bouton save1 */
    fond_bouton_save1 = MLV_load_image("images/menu-play/save_1.jpg");
    MLV_resize_image_with_proportions(fond_bouton_save1,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_save1,b.save1.x, b.save1.y );

    /* Bouton save2 */
    fond_bouton_save2 = MLV_load_image("images/menu-play/save_2.jpg");
    MLV_resize_image_with_proportions(fond_bouton_save2,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_save2,b.save2.x, b.save2.y );

    /* Bouton save3 */
    fond_bouton_save3 = MLV_load_image("images/menu-play/save_3.jpg");
    MLV_resize_image_with_proportions(fond_bouton_save3,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_save3,b.save3.x, b.save3.y );

    /* Bouton save4 */
    fond_bouton_save4 = MLV_load_image("images/menu-play/save_4.jpg");
    MLV_resize_image_with_proportions(fond_bouton_save4,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_save4,b.save4.x, b.save4.y );

    /* Bouton leaderboard */
    fond_bouton_leaderboard = MLV_load_image("images/menu-play/leaderboard.jpg");
    MLV_resize_image_with_proportions(fond_bouton_leaderboard,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_leaderboard,b.leaderboard.x, b.leaderboard.y );

    /* Bouton retour */
    fond_bouton_quitter_play = MLV_load_image("images/menu-play/retour.jpg");
    MLV_resize_image_with_proportions(fond_bouton_quitter_play,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_quitter_play, b.quitter_play.x, b.quitter_play.y );

    MLV_actualise_window(); 
    MLV_free_image(fond_menu_play);
    MLV_free_image(fond_bouton_nouvelle_partie);
    MLV_free_image(fond_bouton_save1);
    MLV_free_image(fond_bouton_save2);
    MLV_free_image(fond_bouton_save3);
    MLV_free_image(fond_bouton_save4);
    MLV_free_image(fond_bouton_leaderboard);
    MLV_free_image(fond_bouton_quitter_play);
}

void affichage_menu_nouvelle_partie(boutons b,configuration *config){
    
    MLV_Image *fond_menu_nouvelle_partie;
    MLV_Image *fond_bouton_taille_map;
    MLV_Image *fond_bouton_mode;
    MLV_Image *fond_bouton_lancer;
    MLV_Image *fond_bouton_retour;
    MLV_Image *fond_bouton_vitesse;

    MLV_clear_window(MLV_COLOR_GREEN);

    /* fond menu principales */
    fond_menu_nouvelle_partie = MLV_load_image("images/menu-nouvelle_partie/fond_menu_nouvelle_partie.jpg" );
    MLV_resize_image_with_proportions( fond_menu_nouvelle_partie, config->fenetre.largeur, config->fenetre.hauteur);
    MLV_draw_image( fond_menu_nouvelle_partie, 0, 0 );

    /* Bouton vitesse */
    switch(config->partie.vitesse){
    case 0:
        fond_bouton_vitesse = MLV_load_image("images/menu-nouvelle_partie/vitesse_lent.jpg");
        break;

    case 1:
        fond_bouton_vitesse = MLV_load_image("images/menu-nouvelle_partie/vitesse_normal.jpg");
        break;

    case 2:    
        fond_bouton_vitesse = MLV_load_image("images/menu-nouvelle_partie/vitesse_rapide.jpg");
        break;

    default: fond_bouton_vitesse = MLV_load_image("images/menu-nouvelle_partie/vitesse_normal.jpg");    
}
    MLV_resize_image_with_proportions(fond_bouton_vitesse, b.largeur_bouton, b.hauteur_bouton);
    MLV_draw_image( fond_bouton_vitesse,b.vitesse.x, b.vitesse.y);

    /* Bouton taille map */
    switch(config->partie.taille_plateau){

    case 0:
    fond_bouton_taille_map = MLV_load_image("images/menu-nouvelle_partie/taille_petite.jpg");
    break;

    case 1:
    fond_bouton_taille_map = MLV_load_image("images/menu-nouvelle_partie/taille_normal.jpg"); 
    break;

    case 2:
    fond_bouton_taille_map = MLV_load_image("images/menu-nouvelle_partie/taille_grande.jpg");
    break;

    default: fond_bouton_taille_map = MLV_load_image("images/menu-nouvelle_partie/taille_normal.jpg");
}
    MLV_resize_image_with_proportions(fond_bouton_taille_map, b.largeur_bouton, b.hauteur_bouton);
    MLV_draw_image( fond_bouton_taille_map,b.taille_map.x, b.taille_map.y);

    /* Bouton mode de jeu */
    switch(config->partie.mode_jeu){

    case 0:    
    fond_bouton_mode = MLV_load_image("images/menu-nouvelle_partie/mode_classique.jpg");
    break;

    case 1:
    fond_bouton_mode = MLV_load_image("images/menu-nouvelle_partie/mode_piege.jpg"); 
    break;

    case 2:
    fond_bouton_mode = MLV_load_image("images/menu-nouvelle_partie/mur_suplementaire.jpg"); 
    break;

    default: fond_bouton_mode = MLV_load_image("images/menu-nouvelle_partie/mode_classique.jpg");
}
    MLV_resize_image_with_proportions(fond_bouton_mode,b.largeur_bouton,b.hauteur_bouton);
    MLV_draw_image(fond_bouton_mode,b.mode_jeu.x, b.mode_jeu.y );

    /* Bouton options */
    fond_bouton_lancer = MLV_load_image("images/menu-nouvelle_partie/lancer.jpg");
    MLV_resize_image_with_proportions(fond_bouton_lancer,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_lancer,b.lancer_partie.x, b.lancer_partie.y );

    /* Bouton quitter; */
    fond_bouton_retour = MLV_load_image("images/menu-nouvelle_partie/retour.jpg");
    MLV_resize_image_with_proportions(fond_bouton_retour,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_retour,b.retour.x, b.retour.y );
   
    /*Recharge la nouvelle fenetre, puis libere la memoire*/
    MLV_actualise_window(); 
    MLV_free_image(fond_menu_nouvelle_partie);
    MLV_free_image(fond_bouton_vitesse);
    MLV_free_image(fond_bouton_taille_map);
    MLV_free_image(fond_bouton_mode);
    MLV_free_image(fond_bouton_lancer);
    MLV_free_image(fond_bouton_retour);
}

void initialisation_coordonnees(boutons *boutons,configuration config){





    /***MENU PRINCIPALE***/
    boutons->largeur_bouton = config.fenetre.largeur/3 * 2;
    boutons->hauteur_bouton = ((config.fenetre.largeur/3 * 2 )/3)/2;

    boutons->play.x=(config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->play.y=config.fenetre.hauteur/3 *2 - 20;

    boutons->multi.x= (config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->multi.y= (config.fenetre.hauteur/3 *2)+ boutons->hauteur_bouton -10;

    boutons->options.x= (config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->options.y= (config.fenetre.hauteur/3 *2) + boutons->hauteur_bouton*2;

    boutons->quitter.x= (config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->quitter.y= (config.fenetre.hauteur/3 *2) + boutons->hauteur_bouton*2;


    /***MENU PLAY***/
    boutons->nouvelle_partie.x=(config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->nouvelle_partie.y=config.fenetre.hauteur/3 *2 - 6;

    boutons->save1.x= (config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->save1.y= (config.fenetre.hauteur/3 *2)+ - 3 + boutons->hauteur_bouton;

    boutons->save2.x= (config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->save2.y= (config.fenetre.hauteur/3 *2)+ - 3 + boutons->hauteur_bouton;

    boutons->save3.x= (config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->save3.y= (config.fenetre.hauteur/3 *2)+ boutons->hauteur_bouton + (boutons->hauteur_bouton)/3 *2;

    boutons->save4.x= (config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->save4.y= (config.fenetre.hauteur/3 *2)+ boutons->hauteur_bouton + (boutons->hauteur_bouton)/3 *2;

    boutons->leaderboard.x= (config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->leaderboard.y= (config.fenetre.hauteur/3 *2)+ boutons->hauteur_bouton +3 + ((boutons->hauteur_bouton)/3 *2)*2;

    boutons->quitter_play.x= (config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->quitter_play.y= (config.fenetre.hauteur/3 *2)+ boutons->hauteur_bouton +3 + ((boutons->hauteur_bouton)/3 *2)*2;


    /***MENU NOUVELLE_PARTIE***/

    boutons->vitesse.x=(config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->vitesse.y=config.fenetre.hauteur/3 *2 - 30 - boutons->hauteur_bouton;

    boutons->taille_map.x=(config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->taille_map.y=config.fenetre.hauteur/3 *2 - 20;

    boutons->mode_jeu.x= (config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->mode_jeu.y= (config.fenetre.hauteur/3 *2)+ boutons->hauteur_bouton -10;

    boutons->lancer_partie.x= (config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->lancer_partie.y= (config.fenetre.hauteur/3 *2) + boutons->hauteur_bouton*2;

    boutons->retour.x= (config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->retour.y= (config.fenetre.hauteur/3 *2) + boutons->hauteur_bouton*2;

    boutons->input_box_pseudo.x=(config.fenetre.largeur-boutons->largeur_bouton)/2 + boutons->largeur_bouton/4;
    boutons->input_box_pseudo.y= config.fenetre.hauteur/3 *2 - 40 - boutons->hauteur_bouton*2;

    /***MENU PAUSE***/

    boutons->reprendre.x=config.fenetre.largeur/6 +5;
    boutons->reprendre.y=config.fenetre.hauteur/3;

    boutons->quitter_la_partie.x=config.fenetre.largeur/6+ +5;
    boutons->quitter_la_partie.y=config.fenetre.hauteur/3 + boutons->hauteur_bouton + 5;

    boutons->sauvegarder_et_quitter.x=config.fenetre.largeur/6 +5;
    boutons->sauvegarder_et_quitter.y=(config.fenetre.hauteur/(3*2))*2 + (boutons->hauteur_bouton + 5)*2;

    /***MENU SAUVEGARDES*/

    boutons->sauvegarde1.x=(config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->sauvegarde1.y=config.fenetre.hauteur/3;

    boutons->sauvegarde2.x=(config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->sauvegarde2.y=config.fenetre.hauteur/3;

    boutons->sauvegarde3.x=(config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->sauvegarde3.y=config.fenetre.hauteur/3 + boutons->hauteur_bouton + 5;

    boutons->sauvegarde4.x=(config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->sauvegarde4.y=config.fenetre.hauteur/3 + boutons->hauteur_bouton + 5;

    boutons->annuler.x=(config.fenetre.largeur-boutons->largeur_bouton)/2 + (boutons->largeur_bouton)/2 + 5;
    boutons->annuler.y=(config.fenetre.hauteur/(3*2))*2 + (boutons->hauteur_bouton + 5)*2;

    boutons->valider.x=(config.fenetre.largeur-boutons->largeur_bouton)/2;
    boutons->valider.y=(config.fenetre.hauteur/(3*2))*2 + (boutons->hauteur_bouton + 5)*2;

}

void affichage_graphique(configuration *config, personalisation_couleur *couleurs){

    int i;
    int diff_h; /* calcul les pixels en trop entre la hauteur de la fenêtre et la taille du plateau de jeu */
    int diff_l; /* calcul les pixels en trop entre la largeur de la fenêtre et la taille du plateau de jeu */
    int opti;   /*recup la taille opti pour les carré du plateau*/
    int TAILLE_PLATEAU;
    char etat[40];
    char temps[15];

    opti = find_reso(config);
    
    TAILLE_PLATEAU = config->partie.map.n*opti ; /*en pixel*/

    diff_h= config->fenetre.hauteur - TAILLE_PLATEAU; /* calcul les pixels en trop entre la hauteur de la fenêtre et la taille du plateau de jeu */
    diff_l= config->fenetre.largeur - TAILLE_PLATEAU; /* calcul les pixels en trop entre la hauteur de la fenêtre et la taille du plateau de jeu */

    MLV_clear_window(type_rgb_to_color(couleurs->plateau));

  
    /* BORDURE HAUTE */
    MLV_draw_filled_rectangle( 0, 0, config->fenetre.largeur,diff_h/2 +1,MLV_COLOR_SKY_BLUE); 

    /* BORDURE BASSE */
    MLV_draw_filled_rectangle( 0, TAILLE_PLATEAU + diff_h/2 +1, config->fenetre.largeur, diff_h/2 +1,MLV_COLOR_SKY_BLUE);

    /* BORDURE GAUCHE */
    MLV_draw_filled_rectangle( 0, diff_h/2 +1, diff_l/2 ,TAILLE_PLATEAU,MLV_COLOR_SKY_BLUE);

    /* BORDURE DROITE */
    MLV_draw_filled_rectangle( config->fenetre.largeur - diff_l/2 , diff_h/2 +1,diff_l/2,TAILLE_PLATEAU,MLV_COLOR_SKY_BLUE);

    /* lignes horizontales du plateau */
    for(i=0;i<=config->partie.map.n;i++){
        MLV_draw_line(diff_l/2,diff_h/2 +1 +i*opti,TAILLE_PLATEAU+diff_l/2,diff_h/2 +1+i*opti,MLV_COLOR_BLACK);
    }


    /* lignes verticales du plateau */
    for(i=0;i<=config->partie.map.n;i++){
        MLV_draw_line(diff_l/2+i*opti,diff_h/2 +1,diff_l/2+i*opti,TAILLE_PLATEAU+diff_h/2 +1,MLV_COLOR_BLACK);
    }

    /***affichage des murs***/

    for(i=0;i<config->partie.map.n;i++){
        MLV_draw_filled_rectangle( diff_l/2 + i*opti +1,diff_h/2 +1 + 0*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->murs));
        MLV_draw_filled_rectangle( diff_l/2 + i*opti +1,diff_h/2 +1 + (config->partie.map.n -1)*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->murs));   
    }

   for(i=1;i<config->partie.map.n-1;i++){
        MLV_draw_filled_rectangle( diff_l/2 +1,diff_h/2 +1 + i*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->murs));
        MLV_draw_filled_rectangle( diff_l/2 + (config->partie.map.n -1)*opti +1,diff_h/2 +1 + i*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->murs));   
    }

    /*Mur sup*/
    if(config->partie.mode_jeu==2)
        for(i=0;i<5*(config->partie.taille_plateau + 1) +10*(config->partie.taille_plateau);i++){
    MLV_draw_filled_rectangle(diff_l/2 + config->partie.map.murs_sup[i].y*opti + 1 ,diff_h/2 + config->partie.map.murs_sup[i].x*opti + 2,opti -1,opti-1,type_rgb_to_color(couleurs->murs));
}

    /* Affichage  etat de la partie */
    for(i=0;i<config->partie.nb_joueurs;i++){
    sprintf(etat,"J%d - score: %d",i+1,config->partie.joueur[i].taille -1);
    MLV_draw_text(diff_l,diff_h/2 + i*(opti/3 +2),etat,type_rgb_to_color(couleurs->textes));
}
    
    /*Afficher le timer*/
    sprintf(temps,"temps: %d:%d",config->partie.actuel.minutes,config->partie.actuel.secondes);
    MLV_draw_text(config->fenetre.largeur*9/10 - opti/3 ,diff_h/2 +1 ,temps,type_rgb_to_color(couleurs->textes));
}

void affichage_snake_pomme(configuration *config, personalisation_couleur *couleurs){

    int i,opti,diff_h,diff_l,TAILLE_PLATEAU;

    opti = find_reso(config);
    TAILLE_PLATEAU = config->partie.map.n*opti ; /*en pixel*/
    diff_h= config->fenetre.hauteur - TAILLE_PLATEAU; /* calcul les pixels en trop entre la hauteur de la fenêtre et la taille du plateau de jeu */
    diff_l= config->fenetre.largeur - TAILLE_PLATEAU; /* calcul les pixels en trop entre la hauteur de la fenêtre et la taille du plateau de jeu */



/********Affichage des serpent*******/
    switch(config->partie.nb_joueurs){

    case 1:    
        
        /*****Joueur 1*****/
         MLV_draw_filled_rectangle( diff_l/2 + config->partie.joueur[0].corp[0].y*opti +1,diff_h/2 +1 + config->partie.joueur[0].corp[0].x*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->snake_1_tete));
         
        for(i=1;i<config->partie.joueur[0].taille;i++){
            MLV_draw_filled_rectangle( diff_l/2 + config->partie.joueur[0].corp[i].y*opti +1,diff_h/2 +1 + config->partie.joueur[0].corp[i].x*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->snake_1));
        }

    break;
        case 2:    

        /*****Joueur 1*****/

        MLV_draw_filled_rectangle( diff_l/2 + config->partie.joueur[0].corp[0].y*opti +1,diff_h/2 +1 + config->partie.joueur[0].corp[0].x*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->snake_1_tete));
         
        for(i=1;i<config->partie.joueur[0].taille;i++){
            MLV_draw_filled_rectangle( diff_l/2 + config->partie.joueur[0].corp[i].y*opti +1,diff_h/2 +1 + config->partie.joueur[0].corp[i].x*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->snake_1));
        }

        /*****JOUEUR 2*****/

        MLV_draw_filled_rectangle( diff_l/2 + config->partie.joueur[1].corp[0].y*opti +1,diff_h/2 +1 + config->partie.joueur[1].corp[0].x*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->snake_2_tete));

        for(i=0;i<config->partie.joueur[1].taille;i++){
            MLV_draw_filled_rectangle( diff_l/2 + config->partie.joueur[1].corp[i].y*opti +1,diff_h/2 +1 + config->partie.joueur[1].corp[i].x*opti + 1 ,opti -1,opti-1,type_rgb_to_color(couleurs->snake_2));
        }

    
    
    break;

default: fprintf(stderr,"Erreur 82, cf doc\n");
} 
    /* Pomme */

    for(i=0;i<config->partie.nb_pommes;i++){

    switch(config->partie.map.plateau[config->partie.map.pomme[i].x][config->partie.map.pomme[i].y]){

    /*MLV_draw_filled_rectangle(diff_l/2 + config->map.pomme[i].y*opti +1,diff_h/2 +1 + config->map.pomme[i].x*opti + 1 ,opti -1,opti-1,MLV_COLOR_RED2);*/

    case '$':

    MLV_draw_filled_circle(diff_l/2 + config->partie.map.pomme[i].y*opti +1 +opti/2,diff_h/2 +1 + config->partie.map.pomme[i].x*opti + 1 +opti/2,opti/2-opti/8,type_rgb_to_color(couleurs->pomme_normal));
    break;

    case '@':

    MLV_draw_filled_circle(diff_l/2 + config->partie.map.pomme[i].y*opti +1 +opti/2,diff_h/2 +1 + config->partie.map.pomme[i].x*opti + 1 +opti/2,opti/2-opti/8,type_rgb_to_color(couleurs->pomme_malus));
    break;

    case 'v':

    MLV_draw_filled_circle(diff_l/2 + config->partie.map.pomme[i].y*opti +1 +opti/2,diff_h/2 +1 + config->partie.map.pomme[i].x*opti + 1 +opti/2,opti/2-opti/8,type_rgb_to_color(couleurs->pomme_vitesse));
    break; 

    default: fprintf(stderr,"Erreur 168\n");
}
}
}

void affichage_menu_pause(boutons b){

    MLV_Image *fond_bouton_reprendre;
    MLV_Image *fond_bouton_quitter_la_partie;
    MLV_Image *fond_bouton_sauvegarder_et_quitter;

    /* Bouton reprendre */
    fond_bouton_reprendre = MLV_load_image("images/menu-pause/bouton_reprendre.jpg");
    MLV_resize_image_with_proportions(fond_bouton_reprendre,b.largeur_bouton,b.hauteur_bouton);
    MLV_draw_image(fond_bouton_reprendre,b.reprendre.x, b.reprendre.y );

    /* Bouton quitter_la_partie; */
    fond_bouton_quitter_la_partie = MLV_load_image("images/menu-pause/bouton_quitter_la_partie.jpg");
    MLV_resize_image_with_proportions(fond_bouton_quitter_la_partie,b.largeur_bouton,b.hauteur_bouton);
    MLV_draw_image(fond_bouton_quitter_la_partie,b.quitter_la_partie.x, b.quitter_la_partie.y );

    /* Bouton sauvegarder_et_quitter; */
    fond_bouton_sauvegarder_et_quitter = MLV_load_image("images/menu-pause/bouton_save_leave.jpg");
    MLV_resize_image_with_proportions(fond_bouton_sauvegarder_et_quitter,b.largeur_bouton,b.hauteur_bouton);
    MLV_draw_image(fond_bouton_sauvegarder_et_quitter,b.sauvegarder_et_quitter.x, b.sauvegarder_et_quitter.y );

    MLV_actualise_window();
    MLV_free_image(fond_bouton_reprendre);
    MLV_free_image(fond_bouton_quitter_la_partie);
    MLV_free_image(fond_bouton_sauvegarder_et_quitter);
}


void affichage_menu_sauvegardes(boutons b,configuration config,int selection){

    MLV_Image *fond_bouton_sauvegarde1;
    MLV_Image *fond_bouton_sauvegarde2;
    MLV_Image *fond_bouton_sauvegarde3;
    MLV_Image *fond_bouton_sauvegarde4;
    MLV_Image *fond_bouton_annuler;
    MLV_Image *fond_bouton_valider;
    MLV_Image *fond_menu_pause;


    fond_menu_pause = MLV_load_image("images/menu-sauvegardes/bg_pause.jpg");
    MLV_resize_image_with_proportions(fond_menu_pause,config.fenetre.largeur,config.fenetre.largeur);
    MLV_draw_image(fond_menu_pause,0,0);

    /*Save1*/
    if(selection==1){
    fond_bouton_sauvegarde1 = MLV_load_image("images/menu-sauvegardes/save_1_valide.jpg");
    }
    else{
    fond_bouton_sauvegarde1 = MLV_load_image("images/menu-sauvegardes/save_1.jpg");
    }
    MLV_resize_image_with_proportions(fond_bouton_sauvegarde1,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_sauvegarde1,b.sauvegarde1.x, b.sauvegarde1.y);

    /*Save2*/
    if(selection==2){
    fond_bouton_sauvegarde2 = MLV_load_image("images/menu-sauvegardes/save_2_valide.jpg");
}
else{
    fond_bouton_sauvegarde2 = MLV_load_image("images/menu-sauvegardes/save_2.jpg");
}
    MLV_resize_image_with_proportions(fond_bouton_sauvegarde2,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_sauvegarde2,b.sauvegarde2.x, b.sauvegarde2.y);

    /*Save3*/
    if(selection==3){
    fond_bouton_sauvegarde3 = MLV_load_image("images/menu-sauvegardes/save_3_valide.jpg");
}
else{
    fond_bouton_sauvegarde3 = MLV_load_image("images/menu-sauvegardes/save_3.jpg");
}
    MLV_resize_image_with_proportions(fond_bouton_sauvegarde3,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_sauvegarde3,b.sauvegarde3.x, b.sauvegarde3.y);

    /*Save4*/
    if(selection==4){
    fond_bouton_sauvegarde4 = MLV_load_image("images/menu-sauvegardes/save_4_valide.jpg");
}
else{
    fond_bouton_sauvegarde4 = MLV_load_image("images/menu-sauvegardes/save_4.jpg");
}
    MLV_resize_image_with_proportions(fond_bouton_sauvegarde4,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_sauvegarde4,b.sauvegarde4.x, b.sauvegarde4.y);


    fond_bouton_annuler = MLV_load_image("images/menu-sauvegardes/bouton_annuler.jpg");
    MLV_resize_image_with_proportions(fond_bouton_annuler,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_annuler,b.annuler.x, b.annuler.y);

    fond_bouton_valider = MLV_load_image("images/menu-sauvegardes/bouton_valider.jpg");
    MLV_resize_image_with_proportions(fond_bouton_valider,(b.largeur_bouton)/2 -5,(b.hauteur_bouton)/3 *2);
    MLV_draw_image(fond_bouton_valider,b.valider.x, b.valider.y);

    MLV_actualise_window();
    MLV_free_image(fond_bouton_sauvegarde1);
    MLV_free_image(fond_bouton_sauvegarde2);
    MLV_free_image(fond_bouton_sauvegarde3);
    MLV_free_image(fond_bouton_sauvegarde4);
    MLV_free_image(fond_bouton_annuler);
    MLV_free_image(fond_bouton_valider);
    MLV_free_image(fond_menu_pause);
}