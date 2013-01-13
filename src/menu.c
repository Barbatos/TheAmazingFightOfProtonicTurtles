#include "common.h"

// Création de la fenêtre de la taille des menus
void Menu_Initialiser()
{
	if(!(global.window = SDL_SetVideoMode(WINDOW_X, WINDOW_Y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)))
	{
		// Si la création de la fenêtre a échoué, on quitte le programme
		printf("Une erreur est survenue lors de la création de la fenêtre SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// Définition du menu par défaut: le menu principal
	global.fenetre = MENU_PRINCIPAL;
}

// Affichage du bouton "retour" sur les menus.
// Il se trouve sur toutes les pages aux mêmes coordonnées
void Menu_AfficherBoutonRetour()
{
	SDL_Rect posRetour = { 420, 490, 149, 65 };

	// affichage du bouton retour
	if(Utils_DansBouton(posRetour))
	{
		// Si on clic gauche, retour à l'accueil
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
		{
			global.fenetre = MENU_PRINCIPAL;
		}
		
		SDL_BlitSurface(global.images.boutonRetourHL, NULL, global.window, &posRetour);
	}
	else
	{
		SDL_BlitSurface(global.images.boutonRetour, NULL, global.window, &posRetour);
	}
}

// Affichage du menu principal
void Menu_Principal()
{
	SDL_Rect posBG 			= { 0, 0 };
	SDL_Rect boutonJouer 	= { 23, 212, 158, 81 };
	SDL_Rect boutonQuitter 	= { 198, 242, 158, 75 };
	SDL_Rect boutonRegles 	= { 450, 48, 158, 65 };
	SDL_Rect boutonCredits 	= { 365, 96, 158, 65 };

	// Affichage de l'image d'arrière-plan
	SDL_BlitSurface(global.images.backgroundMainMenu, NULL, global.window, &posBG);

	// La souris se trouve dans la zone du bouton "jouer". On highlight le bouton
	if(Utils_DansBouton(boutonJouer))
	{
		SDL_BlitSurface(global.images.playButtonHL, NULL, global.window, &boutonJouer);

		// Clic souris. SDL_BUTTON(1) = le clic gauche. 2 pour le clic droit
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
		{
			partie.nombreJoueurs = 0;
			global.fenetre = MENU_CHOIX_NB_JOUEURS;
			global.tempsSurPage = SDL_GetTicks();
		}
	}
	else
	{
		// Affichage du bouton "jouer"
		SDL_BlitSurface(global.images.playButton, NULL, global.window, &boutonJouer);
	}

	// Highlight du bouton "quitter"
	if(Utils_DansBouton(boutonQuitter))
	{
		SDL_BlitSurface(global.images.quitButtonHL, NULL, global.window, &boutonQuitter);

		// Clic souris. SDL_BUTTON(1) = le clic gauche. 2 pour le clic droit
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
		{
			global.boucle = 0;
		}
	}
	else
	{
		// Affichage du bouton "quitter"
		SDL_BlitSurface(global.images.quitButton, NULL, global.window, &boutonQuitter);
	}

	// Highlight du bouton "Regles"
	if(Utils_DansBouton(boutonRegles))
	{
		SDL_BlitSurface(global.images.reglesButtonHL, NULL, global.window, &boutonRegles);

		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
		{
			global.fenetre = MENU_REGLES;
		}
	}
	else
	{
		// Affichage du bouton "Regles"
		SDL_BlitSurface(global.images.reglesButton, NULL, global.window, &boutonRegles);
	}

	// Highlight du bouton "Crédits"
	if(Utils_DansBouton(boutonCredits))
	{
		SDL_BlitSurface(global.images.creditsButtonHL, NULL, global.window, &boutonCredits);

		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
		{
			global.fenetre = MENU_CREDITS;
		}
	}
	else
	{
		// Affichage du bouton "Crédits"
		SDL_BlitSurface(global.images.creditsButton, NULL, global.window, &boutonCredits);
	}
		
}

// Affichage du menu des crédits
void Menu_Credits()
{
	SDL_Rect posBG = { 0, 0 };
	int x, y;

	// affichage du fond
	SDL_BlitSurface(global.images.backgroundCredits, NULL, global.window, &posBG);

	Menu_AfficherBoutonRetour();
}

// Affichage du menu des règles du jeu
void Menu_Regles()
{
	SDL_Rect posBG = { 0, 0 };
	int x, y;

	// affichage du fond
	SDL_BlitSurface(global.images.backgroundRegles, NULL, global.window, &posBG);

	Menu_AfficherBoutonRetour();
}

// affichage de la page de choix du nombre de joueurs
void Menu_ChoixNbJoueurs()
{
	SDL_Surface *texte = NULL;
	SDL_Rect 	posBG 		= { 0, 0 };
	SDL_Rect 	posTexte 	= { 60, 75 };
	SDL_Rect 	posNuage 	= { 10, 60, 321, 160 };
	SDL_Color 	couleurNoir = { 0, 0, 0 };
	char 		nbJoueurs[2];
	int 		i, tempsSurPage = 0;

	// affichage de l'image de fond
	SDL_BlitSurface(global.images.backgroundNbJoueurs, NULL, global.window, &posBG);	

	// on propose de jouer de 2 à 5 joueurs
	for(i = 2; i <= MAX_JOUEURS; i++)
	{
		// si le nombre est impair, le nuage se trouve à droite
		if(i % 2 != 0)
			posNuage.x = 290;

		// sinon il est à gauche
		else
			posNuage.x = 10;

		// position du texte par rapport aux nuages
		posTexte.x = posNuage.x + 141;
		posTexte.y = posNuage.y + 63;

		sprintf(nbJoueurs, "%d", i);

		texte = TTF_RenderUTF8_Blended(global.policeRumpel, nbJoueurs, couleurNoir);

		// si on se trouve dans la zone d'un nuage
		if(Utils_DansBouton(posNuage))
		{
			// affichage du nuage "highlight"
			SDL_BlitSurface(global.images.nuageHL, NULL, global.window, &posNuage);

			// On définit un temps minimum pendant lequel on ne peut pas cliquer sur le bouton, 
			// sinon il est possible qu'en restant appuyé sur la souris on clique sur les différents
			// boutons des pages successives en quelques ms
			tempsSurPage = SDL_GetTicks() - global.tempsSurPage;

			// détection clic souris
			if((tempsSurPage > 400) && (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1)))
			{
				// définition du nombre de joueurs de la partie et changement de fenêtre
				partie.nombreJoueurs = i;
				Jeu_Initialiser();
				global.fenetre = DANS_JEU;
			}
		}
		else
		{
			// affichage du nuage
			SDL_BlitSurface(global.images.nuage, NULL, global.window, &posNuage);
		}

		// affichage du texte
		SDL_BlitSurface(texte, NULL, global.window, &posTexte);

		posNuage.y += 92;
	}

	SDL_FreeSurface(texte);

	Menu_AfficherBoutonRetour();
}

// Affichage du menu désiré par le joueur
void Menu_Afficher()
{
	switch(global.fenetre)
	{
		case MENU_PRINCIPAL:
			Menu_Principal();
			break;

		case MENU_CREDITS:
			Menu_Credits();
			break;

		case MENU_REGLES:
			Menu_Regles();
			break;

		case MENU_CHOIX_NB_JOUEURS:
			Menu_ChoixNbJoueurs();
			break;
	}

	return;
}
