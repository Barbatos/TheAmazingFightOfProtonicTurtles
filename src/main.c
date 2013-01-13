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

#include "common.h"

// Fonction permettant de quitter le jeu proprement
void Quitter()
{
	// On ferme toutes les polices utilisées
	TTF_CloseFont(global.police);
	TTF_CloseFont(global.policeTitres);
	TTF_CloseFont(global.policeMini);
	TTF_CloseFont(global.policeRumpel);

	// On quitte la librairie SDL_ttf
	TTF_Quit();

	// On décharge toutes les images
	Utils_DechargerImages();

	// On quitte la SDL
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	SDL_Event event;

	global.boucle = 1;
	
	// Centrage de la fenêtre par défaut
	putenv("SDL_VIDEO_WINDOW_POS=center");

	// Initialisation de la SDL
	if(SDL_Init(SDL_INIT_VIDEO))
	{
		// Si l'initialisation a échoué, on quitte le programme
		fprintf(stderr, "Une erreur est survenue lors de l'initialisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// Initialisation de la librairie SDL_ttf qui permet d'écrire du texte
	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Une erreur est survenue lors de l'initialisation de la librairie SDL_TTF.\n");
		exit(EXIT_FAILURE);
	}

	// Initialisation de rand
	srand(time(NULL));

	// Chargement des polices de différentes tailles
	global.policeTitres = TTF_OpenFont("img/arial_black.ttf", 32);
	global.police 		= TTF_OpenFont("img/arial_black.ttf", 21);
	global.policeMini 	= TTF_OpenFont("img/arial_black.ttf", 12);
	global.policeRumpel	= TTF_OpenFont("img/Rumpelstiltskin.ttf", 45);

	// Définition de l'icône de la fenêtre, à faire avant la création de la fenêtre
	#ifdef _WIN32
	SDL_WM_SetIcon(IMG_Load("img/icone.png"), NULL);
	#endif

	// Définition du nom de la fenêtre
	SDL_WM_SetCaption("The Amazing Fight of Protonic Turtles", NULL);

	// Initialisation des menus (création de la fenêtre SDL, définition du menu par défaut)
	Menu_Initialiser();

	// Chargement de toutes les images du programme
	Utils_ChargerImages();
	
	// Tant que boucle != 0, on exécute le programme
	while(global.boucle)
	{
		// On attend de recevoir un évènement (appui de touche souris, clavier...).
		// Il vaut mieux utiliser cette fonction que SDL_WaitEvent() qui est identique 
		// mais qui bloque l'exécution du programme tant qu'un évènement n'est pas détecté.
		SDL_PollEvent(&event);

		// Effacement de l'écran
		SDL_FillRect(global.window, NULL, SDL_MapRGB(global.window->format, 0, 0, 0));
		
		// On cherche le type d'évènement détecté
		switch(event.type)
		{
			// Une touche est pressée sur le clavier
			case SDL_KEYDOWN:

				// On cherche à savoir quelle touche précisément a été pressée
				switch(event.key.keysym.sym)
                {
                	// Appui sur la touche echap
                    case SDLK_ESCAPE: 

                    	// Si on se trouve dans un sous-menu ou dans le jeu, 
                    	// on retourne au menu principal
                        if(global.fenetre != MENU_PRINCIPAL)
                        {
							// Si on se trouvait dans le jeu et qu'on retourne dans les menus
							// on redimensionne la fenêtre à la taille des menus
							// (car la fenêtre du jeu est plus grande)
							if(global.fenetre == DANS_JEU)
							{
								Jeu_Quitter();
								Menu_Initialiser();
							}
                        }

                        // Si on fait echap et qu'on se trouve sur le menu principal, 
                        // alors on quitte le jeu
                        else
                        {
                        	global.boucle = 0;
                        }

                    break;
                }

                break;

			// On demande à quitter la fenêtre, on met la variable "boucle" à zéro pour sortir de la boucle
			case SDL_QUIT:
				global.boucle = 0;
				break;
		}

		// Si on n'est pas en train de jouer, c'est qu'on veut afficher un menu
		if(global.fenetre != DANS_JEU)
		{	
			Menu_Afficher();
		}

		// Sinon, on affiche le jeu
		else
		{
			Jeu_Afficher();
		}

		// Affichage de l'écran
    	SDL_Flip(global.window);

    	// Enfin, on fait une petite pause pour ne pas utiliser inutilement trop de CPU
    	// Attention: j'ai remarqué qu'en mettant une attente de plus de 30ms, certains 
    	// clics venaient à ne pas être détectés.
    	// Ici on attend 30ms donc 1000/30 = 33 frames par seconde
    	SDL_Delay(30); 
	}

	// Fin du programme, on ferme la fenêtre
	Quitter();

	return EXIT_SUCCESS;
}
