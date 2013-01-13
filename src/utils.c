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

// Mélange des cartes
void Utils_MelangerCartes()
{
	cartes_t *temp = malloc(sizeof(cartes_t));
	cartes_t *carte;
	cartes_t *carte2;
	int nbAleatoire = 0;
	int ancienNum;
	int ok = 0;
	int i;

	// On commencer par reset l'état d'utilisation de toutes les cartes
	for(i = 0; i < MAX_CARTES; i++)
	{
		carte = &listeCartes[i];

		if(!carte)
			continue;

		carte->utilisee = 0;
		carte->utiliseePar = 0;
	}

	// Parcours de la liste des cartes de la pioche
	for(i = 0; i < MAX_CARTES; i++)
	{
		// Sélection d'une carte
		carte = &listeCartes[i];
		
		// Si la carte est introuvable, on passe à la suivante
		if(!carte)
			continue;

		// On cherche une deuxième carte avec laquelle on va échanger la première. 
		// Tant que le résultat n'est pas satisfaisant on continue la boucle.
		do
		{
			// Génération d'un nombre aléatoire compris entre 0 et MAX_CARTES
			nbAleatoire = rand() % MAX_CARTES;

			// Sélection d'une carte
			carte2 = &listeCartes[nbAleatoire];

			// Si la carte est introuvable, on en trouve une autre
			if(!carte2)
				continue;

			// Si la carte prise aléatoirement est différente de notre carte de départ, alors on peut 
			// échanger ces deux cartes. On sort donc de la boucle
			if(nbAleatoire != i)
				ok = 1;
			
		} while (!ok);

		// Stockage du contenu de la première carte dans une variable temporaire
		memcpy(temp, carte, sizeof(cartes_t));

		// Copie du contenu de la carte 2 dans la carte 1
		memcpy(carte, carte2, sizeof(cartes_t));

		// Copie du contenu de la carte 1 dans la carte 2
		memcpy(carte2, temp, sizeof(cartes_t));
	}

	// Affichage de toutes les cartes en debug une fois le tri terminé
	#ifdef DEBUG
	for(i = 0; i < MAX_CARTES; i++)
	{	
		carte = &listeCartes[i];

		if(!carte) 
			continue;

		printf("Carte #%d : %s\n", i, carte->nom);
	}
	#endif

	free(temp);

}

// Fonction permettant de détecter si la souris se trouve 
// dans une zone cliquable.
int Utils_DansBouton(SDL_Rect position)
{
	int x, y;

	// On récupère la position de la souris
	SDL_GetMouseState(&x, &y);

	// On se trouve dans la zone
	if((position.x <= x) && (position.x + position.w > x) && (position.y <= y) && (position.y + position.h > y))
		return 1;

	// On ne s'y trouve pas
	else
		return 0;
}

// Attribution d'une couleur de tortue à un joueur
void Utils_DonnerCouleurJoueur(int numero)
{
	joueur_t *joueur;
	joueur_t *other;
	int i, ok = 0, nbAleatoire = 0;

	// Récupération des informations du joueur
	joueur = &joueurs[numero];

	// On choisit un nombre aléatoire plus petit que MAX_TORTUES
	nbAleatoire = (rand() % MAX_TORTUES) + 1;

	// On parcourt tous les joueurs déjà créés pour vérifier que cette couleur de carte
	// n'a pas déjà été attribuée
	for(i = 1; i <= MAX_JOUEURS; i++)
	{
		// Récupération des informations du joueur
		other = &joueurs[i];

		// Si c'est notre joueur...
		if(other->numero == joueur->numero)
			continue;

		// Si le joueur est actif et qu'il a la même couleur, on trouve un autre nombre aléatoire
		// et on parcourt de nouveau le tableau entièrement
		if((other->actif == 1) && (other->couleur == nbAleatoire))
		{
			nbAleatoire = (rand() % MAX_TORTUES) + 1;
			i = -1;
		}
	}

	// On attribue la couleur
	joueur->couleur = nbAleatoire;
	
	return;
}

#if 1
// Donner une ou plusieurs cartes à un joueur
void Utils_DonnerCartes(int numero, int nbCartes)
{
	joueur_t *joueur;
	cartes_t *carte;
	int i, ok, j = 0;

	// On récupère les infos du joueur
	joueur = &joueurs[numero];

	// On réitère la même opération autant de fois que l'on veut piocher de cartes
	for(i = 0; i < nbCartes; i++)
	{
		ok = 0;

		// Tant qu'une carte n'a pas été attribuée..
		while(!ok)
		{
			// On récupère les infos de la carte
			carte = &listeCartes[j];

			// Si la carte n'existe pas, erreur... (ne devrait JAMAIS arriver !!)
			if(!carte)
			{
				printf("Erreur - tentative de sélection d'une carte inexistante !\n");
				exit(EXIT_FAILURE);
			}

			// Si la carte est déjà utilisée, on passe à la suivante
			if(carte->utilisee)
			{
				j++;
				continue;
			}

			// Sinon, la carte est disponible donc on l'attribue au joueur
			else
			{
				carte->utilisee = 1;
				carte->utiliseePar = joueur->numero;
				ok = 1;
			}
		}
	}

	// Affichage des informations de tous les joueurs en debug
	#ifdef DEBUG
	for(i = 0; i < MAX_CARTES; i++)
	{
		carte = &listeCartes[i];

		if(carte->utilisee && (carte->utiliseePar == joueur->numero))
		{
			printf("Le joueur %d détient la carte %s - couleur: %d\n", joueur->numero, carte->nom, carte->couleur);
		}
	}
	#endif
}

#else
// @Charles: ancienne version lorsque l'on attribuait une carte aléatoirement
// Maintenant, on prend la première qui se trouve dans la pioche
void Utils_DonnerCartes(int numero, int nbCartes)
{
	joueur_t *joueur;
	cartes_t *carte;
	int i, ok, carteAleatoire = 0;

	// On récupère les infos du joueur
	joueur = &joueurs[numero];

	// On réitère la même opération autant de fois que l'on veut piocher de cartes
	for(i = 0; i < nbCartes; i++)
	{
		ok = 0;

		// Tant qu'une carte n'a pas été attribuée..
		while(!ok)
		{
			// On génère un nombre aléatoire entre 0 et MAX_CARTES
			carteAleatoire = rand() % MAX_CARTES;

			// On récupère les infos de la carte
			carte = &listeCartes[carteAleatoire];

			// Si la carte n'existe pas, erreur... (ne devrait JAMAIS arriver !!)
			if(!carte)
			{
				printf("Erreur - tentative de sélection d'une carte inexistante !\n");
				exit(EXIT_FAILURE);
			}

			// Si la carte est déjà utilisée, on passe à la suivante
			if(carte->utilisee)
				continue;

			// Sinon, la carte est disponible donc on l'attribue au joueur
			else
			{
				carte->utilisee = 1;
				carte->utiliseePar = joueur->numero;
				ok = 1;
			}
		}
	}
}

#endif

// Un joueur a terminé de jouer, on passe au joueur suivant
void Utils_JoueurSuivant()
{
	// Si le joueur qui vient de jouer était le dernier de la liste,
	// on retourne au premier joueur
	if(partie.joueurActuel == partie.nombreJoueurs)
	{
		partie.joueurActuel = 1;
	}
		
	// Sinon on passe au joueur suivant
	else
	{
		partie.joueurActuel++;
	}

	partie.stadeJoueur = 0;

	// On s'assure de ne plus afficher le texte qui était dédié au joueur précédent
	memset(global.texteJoueur, 0, sizeof(global.texteJoueur));
	global.texteJoueurTemps = 0;
	partie.statutNuage = 0;
	
	return;
}

// Placement des tortues sur la case de départ, les unes au dessus des autres
// et aléatoirement.
void Utils_PlacerTortuesDepart()
{
	tortue_t *tortue;
	tortue_t *other;
	int i, j, random, ok = 0;

	// On commence par nettoyer pour être sûr qu'une partie précédente
	// ne laisse pas de traces...
	for(j = 0; j < MAX_TORTUES; j++)
	{
		// Récupération des infos de la tortue
		tortue = &listeTortues[j];

		if(!tortue)
			continue;

		// On reset les informations de position de la tortue
		tortue->position = 0;
		tortue->rocher = 0;
	}

	// On parcourt toutes les tortues
	for(j = 0; j < MAX_TORTUES; j++)
	{
		// On sélectionne une tortue
		tortue = &listeTortues[j];

		// Si elle n'existe pas, on passe à la suivante
		if(!tortue)
			continue;

		// Si la tortue a déjà une position, c'est qu'elle a déjà été placée
		// donc on passe à la suivante
		if(tortue->position > 0)
			continue;

		// On lui attribue une position de départ au hasard
		random = (rand() % MAX_TORTUES) + 1;

		// On fait un parcourt des autres tortues pour voir si cette position n'est pas 
		// déjà utilisée
		for(i = 0; i < MAX_TORTUES; i++)
		{
			// Sélection de l'autre tortue
			other = &listeTortues[i];

			// Si elle n'existe pas, on passe à la suivante
			if(!other)
				continue;

			// Si elle a le même nom que notre tortue, c'est que c'est notre tortue... on passe
			if(!strcmp(other->nom, tortue->nom))
				continue;

			// Si l'autre tortue n'a pas de position, elle ne nous intéresse pas
			if(!other->position)
				continue;

			// Si cette position est déjà utilisée, on en génère une nouvelle et on refait un parcours complet
			// des autres tortues
			if(random == other->position)
			{
				#ifdef DEBUG
				printf("Tentative d'attribution de la position %d à la tortue %s mais la tortue %s l'a déjà\n", random, tortue->nom, other->nom);
				#endif

				random = (rand() % MAX_TORTUES) + 1;
				i = -1;
				continue;
			}
		}

		// On attribue à la tortue sa position
		tortue->position = random;
	}
	

	#ifdef DEBUG
	// Affichage de la liste des tortues et de leur position
	for(i = 0; i < MAX_TORTUES; i++)
	{
		printf("tortue #%s - position: %d\n", listeTortues[i].nom, listeTortues[i].position);
	}
	#endif

}

// Une fois qu'une carte a été jouée, il faut la remettre au fond de la pioche.
// Pour ça, on place la carte temporairement tout au fond de la pioche, à une position
// qui n'existe pas (sachant qu'il y a 72 cartes et des positions de 0 à 71, on place 
// la carte temporairement à la place 72). Ensuite, on vide l'élément de la structure 
// correspondant à cette carte AVANT qu'elle ait été utilisée puis on effectue un 
// déplacement de -1 à toutes les cartes qui suivaient cette carte dans la pioche 
// afin de les replacer dans l'ordre allant de 0 à 71.
void Utils_ReorganiserPioche(int numCarte)
{
	cartes_t *carte;
	int i;

	// Récupération des infos de la carte
	carte = &listeCartes[numCarte];

	// Si la carte est introuvable...
	if(!carte)
		return;

	// La carte n'est plus utilisée par un joueur
	carte->utilisee = 0;
	carte->utiliseePar = 0;

	// On place la carte temporairement tout à la fin de la pioche
	listeCartes[MAX_CARTES] = *carte;

	// On vide l'élément de la structure où était placée la carte juste avant 
	// (à la position numCarte)
	memset(&listeCartes[numCarte], 0, sizeof(cartes_t));

	// Ensuite, on déplace toutes les cartes à partir de celle qu'on a supprimé,
	// afin de ne pas avoir de "trou" et de toujours avoir 72 cartes
	for(i = numCarte; i < MAX_CARTES; i++)
	{
		memcpy(&listeCartes[i], &listeCartes[i+1], sizeof(cartes_t));
	}
}

// Fonction qui compte le nombre de tortues se trouvant déjà sur un rocher.
// Il est possible d'exclure une tortue du comptage en second argument (optionnel)
int Utils_CompterTortuesRocher(int rocher, int couleurAExclure)
{
	tortue_t *tortue;
	int numTortues = 0, i;

	// Parcours de toutes les tortues
	for(i = 0; i < MAX_TORTUES; i++)
	{
		// Récupération des infos de la tortue
		tortue = &listeTortues[i];

		// Si on ne trouve pas la tortue, on chercher la suivante
		if(!tortue)
			continue;

		// Si la tortue est à exclure
		if(tortue->couleur == couleurAExclure)
			continue;

		// Si la tortue se trouve sur le rocher, on incrémente le compteur
		if(tortue->rocher == rocher)
			numTortues++;
	}

	// On retourne le nombre de tortues trouvées
	return numTortues;
}

// Fontion qui retourne le joueur gagnant en fonction de sa couleur de tortue.
// La tortue gagnante est celle qui se trouve en dessous des autres sur la ligne d'arrivée
void Utils_TrouverGagnant(int *numJoueur, char *couleurTortue)
{
	tortue_t *tortue;
	joueur_t *joueur;
	int i, ok = 0;

	// Si la partie n'est pas terminée, aucune raison d'utiliser cette fonction...
	if(partie.fenetreJeu != FENETRE_TERMINE)
		return;

	// Parcours de toutes les tortues
	for(i = 0; i < MAX_TORTUES; i++)
	{
		// Récupération des informations de la tortue
		tortue = &listeTortues[i];

		// Si la tortue n'existe pas, on passe à la suivante
		if(!tortue)
			continue;

		// Si la tortue se trouve sur la ligne d'arrivée et qu'elle est en position 1
		// (donc tout en dessous), c'est notre gagnante
		if((tortue->rocher == ROCHER_ARRIVEE) && (tortue->position == 1))
		{
			ok = 1;
			break;
		}
			

		ok = 0;
	}

	// Si aucune tortue n'a été trouvée, on quitte la fonction
	if(!ok)
		return;

	strcpy(couleurTortue, tortue->nom);

	// On cherche maintenant le joueur qui détient la tortue gagnante
	for(i = 1; i <= MAX_JOUEURS; i++)
	{
		// Récupération des infos du joueur
		joueur = &joueurs[i];

		// Si le joueur n'existe pas, on passe au suivant
		if(!joueur)
			continue;

		// Si la couleur du joueur est la même que celle de la tortue, c'est lui qui a gagné
		if(joueur->couleur == tortue->couleur)
		{
			ok = 1;
			break;
		}

		ok = 0;
	}

	// Si aucun joueur n'a été trouvé...
	if((!ok) || (joueur->actif != 1))
	{
		*numJoueur = -1;
	}
	else
	{
		*numJoueur = i;
	}

	// On retourne la structure du joueur trouvé
	return;
}

// Chargement de toutes les images du jeu
void Utils_ChargerImages()
{
	cartes_t *carte;
	tortue_t *tortue;
	int i;

	global.images.backgroundMainMenu 			= IMG_Load("img/page_main.png");
	global.images.playButton 					= IMG_Load("img/bouton_jouer.png");
	global.images.quitButton 					= IMG_Load("img/bouton_quitter.png");
	global.images.playButtonHL 					= IMG_Load("img/bouton_jouer_hl.png");
	global.images.quitButtonHL 					= IMG_Load("img/bouton_quitter_hl.png");
	global.images.boutonRetour 					= IMG_Load("img/retour.png");
	global.images.boutonRetourHL 				= IMG_Load("img/retour_hl.png");
	global.images.fondSelectionJoueurs			= IMG_Load("img_backup/fond_nb_joueurs.png");
	global.images.fondSelectionJoueursHL		= IMG_Load("img_backup/fond_nb_joueurs_highlight.png");
	global.images.pioche 						= IMG_Load("img/pioche.png");
	global.images.piocheHL 						= IMG_Load("img/pioche_hl.png");
	global.images.plateau 						= IMG_Load("img/plateau.png");
	global.images.creditsButton 				= IMG_Load("img/bouton_credits.png");
	global.images.creditsButtonHL 				= IMG_Load("img/bouton_credits_hl.png");
	global.images.reglesButton 					= IMG_Load("img/bouton_regles.png");
	global.images.reglesButtonHL 				= IMG_Load("img/bouton_regles_hl.png");
	global.images.backgroundCredits 			= IMG_Load("img/page_credits.png");
	global.images.backgroundRegles 				= IMG_Load("img/page_regles.png");
	global.images.backgroundNbJoueurs 			= IMG_Load("img/page_nb_joueurs.png");
	global.images.nuage							= IMG_Load("img/nuage.png");
	global.images.nuageHL						= IMG_Load("img/nuage_hl.png");
	global.images.bg 							= IMG_Load("img/bg.png");
	global.images.nuageOuvert					= IMG_Load("img/nuage_ouvert.png");
	global.images.derouler 						= IMG_Load("img/derouler.png");
	global.images.enrouler 						= IMG_Load("img/enrouler.png");
	global.images.joueur[0]						= IMG_Load("img/joueur1.png");
	global.images.joueur[1]						= IMG_Load("img/joueur2.png");
	global.images.joueur[2]						= IMG_Load("img/joueur3.png");
	global.images.joueur[3]						= IMG_Load("img/joueur4.png");
	global.images.joueur[4]						= IMG_Load("img/joueur5.png");
	global.images.tortueNuage[COULEUR_JAUNE] 	= IMG_Load("img/tortue_jaune_nuage.png");
	global.images.tortueNuage[COULEUR_BLEU]		= IMG_Load("img/tortue_bleue_nuage.png");
	global.images.tortueNuage[COULEUR_ROUGE]	= IMG_Load("img/tortue_rouge_nuage.png");
	global.images.tortueNuage[COULEUR_VERT]		= IMG_Load("img/tortue_verte_nuage.png");
	global.images.tortueNuage[COULEUR_VIOLET]	= IMG_Load("img/tortue_violette_nuage.png");

	// On charge les images de toutes les cartes
	for(i = 0, carte = listeCartes; i < MAX_CARTES; i++, carte++)
	{
		#ifdef DEBUG
		printf("Chargement de l'image %s %s\n", carte->nom, carte->image);
		#endif

		// Chargement de l'image
		carte->image_loaded = IMG_Load(carte->image);
		carte->utilisee = 0;
		carte->utiliseePar = 0;

		if(!carte->image_loaded)
		{
			printf("Impossible de charger l'image %s\n", carte->image);
		}
	}
	
	// On charge les images de toutes les tortues
	for(i = 0, tortue = listeTortues; i < MAX_TORTUES; i++, tortue++)
	{
		#ifdef DEBUG
		printf("Chargement de l'image tortue %s\n", tortue->nom);
		#endif

		// Chargement de l'image
		tortue->image_loaded = IMG_Load(tortue->image);
		
		if(!tortue->image_loaded)
		{
			printf("Impossible de charger l'image %s\n", tortue->image);
		}
	}
}

// Déchargement de toutes les images du jeu
void Utils_DechargerImages()
{
	cartes_t *carte;
	tortue_t *tortue;
	int i;

	SDL_FreeSurface(global.images.backgroundMainMenu);
	SDL_FreeSurface(global.images.playButton);
	SDL_FreeSurface(global.images.quitButton);
	SDL_FreeSurface(global.images.playButtonHL);
	SDL_FreeSurface(global.images.quitButtonHL);
	SDL_FreeSurface(global.images.boutonRetour);
	SDL_FreeSurface(global.images.boutonRetourHL);
	SDL_FreeSurface(global.images.fondSelectionJoueurs);
	SDL_FreeSurface(global.images.fondSelectionJoueursHL);
	SDL_FreeSurface(global.images.pioche);
	SDL_FreeSurface(global.images.piocheHL);
	SDL_FreeSurface(global.images.plateau);
	SDL_FreeSurface(global.images.creditsButton);
	SDL_FreeSurface(global.images.creditsButtonHL);
	SDL_FreeSurface(global.images.reglesButton);
	SDL_FreeSurface(global.images.reglesButtonHL);
	SDL_FreeSurface(global.images.backgroundCredits);
	SDL_FreeSurface(global.images.backgroundRegles);
	SDL_FreeSurface(global.images.backgroundNbJoueurs);
	SDL_FreeSurface(global.images.nuage);
	SDL_FreeSurface(global.images.nuageHL);
	SDL_FreeSurface(global.images.bg);
	SDL_FreeSurface(global.images.nuageOuvert);
	SDL_FreeSurface(global.images.derouler);
	SDL_FreeSurface(global.images.enrouler);
	SDL_FreeSurface(global.images.joueur[0]);
	SDL_FreeSurface(global.images.joueur[1]);
	SDL_FreeSurface(global.images.joueur[2]);
	SDL_FreeSurface(global.images.joueur[3]);
	SDL_FreeSurface(global.images.joueur[4]);
	SDL_FreeSurface(global.images.tortueNuage[COULEUR_JAUNE]);
	SDL_FreeSurface(global.images.tortueNuage[COULEUR_BLEU]);
	SDL_FreeSurface(global.images.tortueNuage[COULEUR_ROUGE]);
	SDL_FreeSurface(global.images.tortueNuage[COULEUR_VERT]);
	SDL_FreeSurface(global.images.tortueNuage[COULEUR_VIOLET]);

	// On libère la mémoire pour les images des cartes
	for(i = 0, carte = listeCartes; i < MAX_CARTES; i++, carte++)
	{
		SDL_FreeSurface(carte->image_loaded);
	}
	
	// On libère la mémoire pour les images des tortues
	for(i = 0, tortue = listeTortues; i < MAX_TORTUES; i++, tortue++)
	{
		SDL_FreeSurface(tortue->image_loaded);
	}
}
