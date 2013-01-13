/*
*	This file is part of The Amazing Fight of Protonic Turtles.
*
*   The Amazing Fight of Protonic Turtles is free software: you can 
*	redistribute it and/or modify it under the terms of the GNU 
*   General Public License as published by the Free Software Foundation, 
*   either version 3 of the License, or (at your option) any later version.
*
*   The Amazing Fight of Protonic Turtles is distributed in the hope that 
*   it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
*   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
*   See the GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with The Amazing Fight of Protonic Turtles.  
*   If not, see <http://www.gnu.org/licenses/>.
*
* 	@copyright  (c) The Amazing Fight of Protonic Turtles 2012/2013
*   @author     Charles 'Barbatos' Duprey
*   @email      cduprey@f1m.fr
*   @url 		https://github.com/Barbatos
*/

#ifndef _COMMON_H_
#define _COMMON_H_

// Inclusion des librairies standard
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Commenter la ligne ci-dessous pour ne pas avoir tous les messages 
// de debug en sortie du programme
#define DEBUG 1

// Inclusion de la SDL
#ifdef _WIN32
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_ttf.h>
	#include <SDL/SDL_getenv.h>
#else
	#include <SDL.h>
	#include <SDL_image.h>
	#include <SDL_ttf.h>
	#include <SDL_getenv.h>
#endif

// Taille de la fenêtre SDL pour les menus
#define WINDOW_X 		600
#define WINDOW_Y 		585

// Taille de la fenêtre SDL pour le jeu
#define WINDOW_JEU_X 	500
#define WINDOW_JEU_Y 	667

// Définition des maximums
#define MAX_CARTES 		72
#define MAX_TORTUES 	5
#define MAX_JOUEURS 	5

// Liste des menus possibles
enum 
{ 
	MENU_PRINCIPAL, 
	MENU_REGLES,
	MENU_CREDITS,
	MENU_CHOIX_NB_JOUEURS,
	DANS_JEU,
};

// Liste des images utilisées dans tout le programme
typedef struct 
{
	SDL_Surface 	*backgroundMainMenu; 		// l'image de fond du menu principal
	SDL_Surface 	*playButton; 				// le bouton "jouer" du menu principal
	SDL_Surface 	*quitButton; 				// le bouton "quitter" du menu principal
	SDL_Surface 	*playButtonHL; 				// etc.
	SDL_Surface 	*quitButtonHL; 				
	SDL_Surface		*boutonRetour;				
	SDL_Surface		*boutonRetourHL;			
	SDL_Surface		*fondSelectionJoueurs;		
	SDL_Surface		*fondSelectionJoueursHL; 	
	SDL_Surface		*pioche;					
	SDL_Surface		*piocheHL;					
	SDL_Surface		*plateau;					
	SDL_Surface		*creditsButton;
	SDL_Surface		*creditsButtonHL;
	SDL_Surface		*reglesButton;
	SDL_Surface		*reglesButtonHL;
	SDL_Surface		*backgroundCredits;
	SDL_Surface		*backgroundRegles;
	SDL_Surface		*backgroundNbJoueurs;
	SDL_Surface		*nuage;
	SDL_Surface		*nuageHL;
	SDL_Surface		*bg;
	SDL_Surface 	*tortueNuage[6];
	SDL_Surface		*derouler;
	SDL_Surface		*enrouler;
	SDL_Surface		*nuageOuvert;
	SDL_Surface		*joueur[5];
} images_s;

// Structure "globale" dans laquelle sont stockées diverses choses
// comme la fenêtre SDL, les images, les polices, le numéro du menu en consultation...
typedef struct 
{
	SDL_Surface 	*window; 			// La fenêtre du jeu
	images_s 		images; 			// Liste des images
	int				fenetre; 			// Numéro du menu ou de la fenêtre sur laquelle on se trouve (menu principal, règles, jeu...)
	int 			boucle; 			// Tant que boucle = 1, le jeu s'exécute
	TTF_Font		*police; 			// Police principal du jeu (Arial black)
	TTF_Font		*policeTitres; 		// Police plus grosse que la police principale pour les titres
	TTF_Font		*policeMini; 		// Police plus petite que la police principale
	TTF_Font		*policeRumpel;		// police "rigolote" qui correspond à la police utilisée pour les différentes images du jeu
	char 			texteJoueur[64];	// Texte personnalisé à afficher au joueur
	int				texteJoueurTemps;	// Temps d'affichage du texte personnalisé
	int 			tempsSurPage;

} global_s;

// Instanciation de la structure globale
global_s global;

// Inclusion des fichiers .h 
#include "menu.h"
#include "jeu.h"
#include "utils.h"

#endif
