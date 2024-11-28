#include "../heads/types.h"

int retour_click_menu_principale(int x,int y,boutons b){

/*BOUTON PLAY*/
    if(x>=b.play.x && x<= b.largeur_bouton + b.play.x){ 
        if(y>=b.play.y && y<=b.hauteur_bouton + b.play.y){
            return 1;
        }
    }

/*BOUTON MULTI*/
    if(x>=b.multi.x && x<=b.largeur_bouton + b.multi.x){
        if(y>=b.multi.y && y<=b.hauteur_bouton+ b.multi.y){
            return 2;
        }
    }

/*BOUTON OPTIONS*/
    if(x>=b.options.x && x<=(b.largeur_bouton)/2 -5 + b.options.x){ 
        if(y>=b.options.y && y<=(b.hauteur_bouton)/3 *2 +b.options.y ){ 
            return 3;
        }
    }

/*BOUTON QUITTER*/
    if(x>=b.quitter.x && x<=(b.largeur_bouton)/2 -5 + b.quitter.x){
        if(y>=b.quitter.y && y<= (b.hauteur_bouton)/3 *2 + b.quitter.y ){
            return 4;
        }
    }
    return 0;
}

int retour_click_menu_play(int x,int y,boutons b){

/*BOUTON NOUVELLE PARTIE*/
    if(x>=b.nouvelle_partie.x && x<= b.largeur_bouton + b.nouvelle_partie.x){ 
        if(y>=b.nouvelle_partie.y && y<=b.hauteur_bouton + b.nouvelle_partie.y){
            return 1;
        }
    }

/*BOUTON SAVE1*/
    if(x>=b.save1.x && x<=(b.largeur_bouton)/2 -5 + b.save1.x){ 
        if(y>=b.save1.y && y<=(b.hauteur_bouton)/3 *2 +b.save1.y ){ 
            return 2;
        }
    }

/*BOUTON SAVE2*/
    if(x>=b.save2.x && x<=(b.largeur_bouton)/2 -5 + b.save2.x){ 
        if(y>=b.save2.y && y<=(b.hauteur_bouton)/3 *2 +b.save2.y ){ 
            return 3;
        }
    }

/*BOUTON SAVE3*/
    if(x>=b.save3.x && x<=(b.largeur_bouton)/2 -5 + b.save3.x){ 
        if(y>=b.save3.y && y<=(b.hauteur_bouton)/3 *2 +b.save3.y ){ 
            return 4;
        }
    }

/*BOUTON SAVE4*/
    if(x>=b.save4.x && x<=(b.largeur_bouton)/2 -5 + b.save4.x){ 
        if(y>=b.save4.y && y<=(b.hauteur_bouton)/3 *2 +b.save4.y ){ 
            return 5;
        }
    }


/*BOUTON LEADERBOARD*/
    if(x>=b.leaderboard.x && x<= b.leaderboard.x + (b.largeur_bouton)/2 -5){
        if(y>=b.leaderboard.y && y<= b.leaderboard.y + (b.hauteur_bouton)/3 *2){
            return 6;
        }
    }

/*BOUTON RETOUR*/
    if(x>=b.quitter_play.x && x<=(b.largeur_bouton)/2 -5 + b.quitter_play.x){
        if(y>=b.quitter_play.y && y<= (b.hauteur_bouton)/3 *2 + b.quitter_play.y ){
            return 7;
        }
    }
    return 0;
}

int retour_click_menu_nouvelle_partie(int x,int y,boutons b){

/*BOUTON VITESSE*/
    if(x>=b.vitesse.x && x<=b.largeur_bouton  + b.vitesse.x){ 
        if(y>=b.vitesse.y && y<= b.hauteur_bouton + b.vitesse.y){
            return 1;
        }
    }

/*BOUTON TAILLE MAP*/
    if(x>=b.taille_map.x && x<=b.largeur_bouton  + b.taille_map.x){ 
        if(y>=b.taille_map.y && y<= b.hauteur_bouton + b.taille_map.y){
            return 2;
        }
    }

/*BOUTON MODE*/
    if(x>=b.mode_jeu.x && x<=b.largeur_bouton  + b.mode_jeu.x){ 
        if(y>=b.mode_jeu.y && y<= b.hauteur_bouton + b.mode_jeu.y){
            return 3;
        }
    }

/*BOUTON LANCER*/
    if(x>=b.lancer_partie.x && x<= (b.largeur_bouton)/2 -5 + b.lancer_partie.x){ 
        if(y>=b.lancer_partie.y && y<= (b.hauteur_bouton)/3 *2 + b.lancer_partie.y){
            return 4;
        }
    }
/*BOUTON LANCER*/
    if(x>=b.retour.x && x<= (b.largeur_bouton)/2 -5 + b.retour.x){ 
        if(y>=b.retour.y && y<= (b.hauteur_bouton)/3 *2 + b.retour.y){
            return 5;
        }
    }

    return 0;
}

int retour_click_menu_pause(int x,int y,boutons b){

/*BOUTON REPRENDRE*/
    if(x>= b.reprendre.x && x<= b.largeur_bouton + b.reprendre.x){ 
        if(y>= b.reprendre.y && y<=b.hauteur_bouton +b.reprendre.y){
            return 1;
        }
    }

/*BOUTON QUITTER LA PARTIE*/
    if(x>= b.quitter_la_partie.x && x<=b.largeur_bouton + b.quitter_la_partie.x){
        if(y>=b.quitter_la_partie.y && y<=b.hauteur_bouton+ b.quitter_la_partie.y){
            return 2;
        }
    }

/*BOUTON SAUVEGARDER ET QUITTER*/
    if(x>= b.sauvegarder_et_quitter.x && x<=(b.largeur_bouton) + b.sauvegarder_et_quitter.x){ 
        if(y>= b.sauvegarder_et_quitter.y && y<=(b.hauteur_bouton)/3 *2 + b.sauvegarder_et_quitter.y){ 
            return 3;
        }
    }

    return 0;
}

int retour_click_menu_sauvegarde(int x,int y,boutons b){

/*BOUTON SAUVEGARDE1*/
    if(x>= b.sauvegarde1.x && x<= (b.largeur_bouton)/2 -5 + b.sauvegarde1.x){ 
        if(y>= b.sauvegarde1.y && y<=(b.hauteur_bouton)/3 *2 +b.sauvegarde1.y){
            return 1;
        }
    }

/*BOUTON SAUVEGARDE2*/
    if(x>= b.sauvegarde2.x && x<= (b.largeur_bouton)/2 -5 + b.sauvegarde2.x){
        if(y>= b.sauvegarde2.y && y<=(b.hauteur_bouton)/3 *2+ b.sauvegarde2.y){
            return 2;
        }
    }

/*BOUTON SAUVEGARDE3*/
    if(x>= b.sauvegarde3.x && x<=(b.largeur_bouton)/2 -5 + b.sauvegarde3.x){ 
        if(y>= b.sauvegarde3.x && y<=(b.hauteur_bouton)/3 *2 + b.sauvegarde3.y){ 
            return 3;
        }
    }

/*BOUTON SAUVEGARDE4*/
    if(x>= b.sauvegarde4.x && x<= (b.largeur_bouton)/2 -5 + b.sauvegarde4.x){
        if(y>= b.sauvegarde4.y && y<=(b.hauteur_bouton)/3 *2+ b.sauvegarde4.y){
            return 4;
        }
    }

/*BOUTON VALIDER*/
    if(x>=b.valider.x  && x<=(b.largeur_bouton)/2 -5 + b.valider.x){ 
        if(y>= b.valider.y && y<=(b.hauteur_bouton)/3 *2 + b.valider.y){ 
            return 5;
        }
    }

/*BOUTON ANNULER*/
    if(x>= b.annuler.x && x<=(b.largeur_bouton)/2 -5+ b.annuler.x){
        if(y>= b.annuler.y&& y<=(b.hauteur_bouton)/3 *2+ b.annuler.y){
            return 6;
        }
    }

    return 0;
}
