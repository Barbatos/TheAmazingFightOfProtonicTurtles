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

// Liste des tortues : nom - image - couleur - image chargée - position et taille image
tortue_t listeTortues[] = 
{
	{ "Jaune", 		"img/tortue_jaune.png", 	COULEUR_JAUNE,	NULL, { 0 } },
	{ "Verte", 		"img/tortue_verte.png", 	COULEUR_VERT,	NULL, { 0 } },
	{ "Bleue", 		"img/tortue_bleue.png", 	COULEUR_BLEU,	NULL, { 0 } },
	{ "Rouge", 		"img/tortue_rouge.png", 	COULEUR_ROUGE,	NULL, { 0 } },
	{ "Violette", 	"img/tortue_violette.png", 	COULEUR_VIOLET,	NULL, { 0 } },
};


// Liste des cartes : nom - image - couleur - valeur - image chargee - position et taille image - utilisee
cartes_t listeCartes[] = 
{	
	// 12 cartes jaunes
	{ "Jaune Reculer 1", 		"img/carte_jaune_moins.png", 		COULEUR_JAUNE, 	VALEUR_RECULER, 	NULL, 	{0}, 0 },
	{ "Jaune Reculer 2", 		"img/carte_jaune_moins.png", 		COULEUR_JAUNE, 	VALEUR_RECULER, 	NULL,	{0}, 0 },

	{ "Jaune Avancer 1", 		"img/carte_jaune_plus.png", 		COULEUR_JAUNE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Jaune Avancer 2", 		"img/carte_jaune_plus.png", 		COULEUR_JAUNE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Jaune Avancer 3", 		"img/carte_jaune_plus.png", 		COULEUR_JAUNE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Jaune Avancer 4", 		"img/carte_jaune_plus.png", 		COULEUR_JAUNE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Jaune Avancer 5", 		"img/carte_jaune_plus.png", 		COULEUR_JAUNE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },

	{ "Jaune Avancer x2 1", 	"img/carte_jaune_plusplus.png", 	COULEUR_JAUNE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Jaune Avancer x2 2", 	"img/carte_jaune_plusplus.png", 	COULEUR_JAUNE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Jaune Avancer x2 3", 	"img/carte_jaune_plusplus.png", 	COULEUR_JAUNE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Jaune Avancer x2 4", 	"img/carte_jaune_plusplus.png", 	COULEUR_JAUNE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Jaune Avancer x2 5", 	"img/carte_jaune_plusplus.png", 	COULEUR_JAUNE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },


	// 12 cartes vertes
	{ "Verte Reculer 1", 		"img/carte_verte_moins.png", 		COULEUR_VERT, 	VALEUR_RECULER,		NULL,	{0}, 0 },
	{ "Verte Reculer 2", 		"img/carte_verte_moins.png", 		COULEUR_VERT, 	VALEUR_RECULER,		NULL,	{0}, 0 },

	{ "Verte Avancer 1", 		"img/carte_verte_plus.png", 		COULEUR_VERT, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Verte Avancer 2", 		"img/carte_verte_plus.png", 		COULEUR_VERT, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Verte Avancer 3", 		"img/carte_verte_plus.png", 		COULEUR_VERT, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Verte Avancer 4", 		"img/carte_verte_plus.png", 		COULEUR_VERT, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Verte Avancer 5", 		"img/carte_verte_plus.png", 		COULEUR_VERT, 	VALEUR_AVANCER,		NULL,	{0}, 0 },

	{ "Verte Avancer x2 1", 	"img/carte_verte_plusplus.png", 	COULEUR_VERT, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Verte Avancer x2 2", 	"img/carte_verte_plusplus.png", 	COULEUR_VERT, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Verte Avancer x2 3", 	"img/carte_verte_plusplus.png", 	COULEUR_VERT, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Verte Avancer x2 4", 	"img/carte_verte_plusplus.png", 	COULEUR_VERT, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Verte Avancer x2 5", 	"img/carte_verte_plusplus.png", 	COULEUR_VERT, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },


	// 12 cartes rouges
	{ "Rouge Reculer 1", 		"img/carte_rouge_moins.png", 		COULEUR_ROUGE, 	VALEUR_RECULER,		NULL,	{0}, 0 },
	{ "Rouge Reculer 2", 		"img/carte_rouge_moins.png", 		COULEUR_ROUGE, 	VALEUR_RECULER,		NULL,	{0}, 0 },

	{ "Rouge Avancer 1", 		"img/carte_rouge_plus.png", 		COULEUR_ROUGE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Rouge Avancer 2", 		"img/carte_rouge_plus.png", 		COULEUR_ROUGE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Rouge Avancer 3", 		"img/carte_rouge_plus.png", 		COULEUR_ROUGE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Rouge Avancer 4", 		"img/carte_rouge_plus.png", 		COULEUR_ROUGE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Rouge Avancer 5", 		"img/carte_rouge_plus.png", 		COULEUR_ROUGE, 	VALEUR_AVANCER,		NULL,	{0}, 0 },

	{ "Rouge Avancer x2 1", 	"img/carte_rouge_plusplus.png", 	COULEUR_ROUGE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Rouge Avancer x2 2", 	"img/carte_rouge_plusplus.png", 	COULEUR_ROUGE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Rouge Avancer x2 3", 	"img/carte_rouge_plusplus.png", 	COULEUR_ROUGE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Rouge Avancer x2 4", 	"img/carte_rouge_plusplus.png", 	COULEUR_ROUGE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Rouge Avancer x2 5", 	"img/carte_rouge_plusplus.png", 	COULEUR_ROUGE, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },


	// 12 cartes bleues
	{ "Bleue Reculer 1", 		"img/carte_bleue_moins.png", 		COULEUR_BLEU, 	VALEUR_RECULER,		NULL,	{0}, 0 },
	{ "Bleue Reculer 2", 		"img/carte_bleue_moins.png", 		COULEUR_BLEU, 	VALEUR_RECULER,		NULL,	{0}, 0 },

	{ "Bleue Avancer 1", 		"img/carte_bleue_plus.png", 		COULEUR_BLEU, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Bleue Avancer 2", 		"img/carte_bleue_plus.png", 		COULEUR_BLEU, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Bleue Avancer 3", 		"img/carte_bleue_plus.png", 		COULEUR_BLEU, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Bleue Avancer 4", 		"img/carte_bleue_plus.png", 		COULEUR_BLEU, 	VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Bleue Avancer 5", 		"img/carte_bleue_plus.png", 		COULEUR_BLEU, 	VALEUR_AVANCER,		NULL,	{0}, 0 },

	{ "Bleue Avancer x2 1", 	"img/carte_bleue_plusplus.png", 	COULEUR_BLEU, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Bleue Avancer x2 2", 	"img/carte_bleue_plusplus.png", 	COULEUR_BLEU, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Bleue Avancer x2 3", 	"img/carte_bleue_plusplus.png", 	COULEUR_BLEU, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Bleue Avancer x2 4", 	"img/carte_bleue_plusplus.png", 	COULEUR_BLEU, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Bleue Avancer x2 5", 	"img/carte_bleue_plusplus.png", 	COULEUR_BLEU, 	VALEUR_AVANCERX2,	NULL,	{0}, 0 },


	// 12 cartes violettes
	{ "Violette Reculer 1", 	"img/carte_violette_moins.png", 	COULEUR_VIOLET, VALEUR_RECULER,		NULL,	{0}, 0 },
	{ "Violette Reculer 2", 	"img/carte_violette_moins.png", 	COULEUR_VIOLET, VALEUR_RECULER,		NULL,	{0}, 0 },

	{ "Violette Avancer 1", 	"img/carte_violette_plus.png", 		COULEUR_VIOLET, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Violette Avancer 2", 	"img/carte_violette_plus.png", 		COULEUR_VIOLET, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Violette Avancer 3", 	"img/carte_violette_plus.png", 		COULEUR_VIOLET, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Violette Avancer 4", 	"img/carte_violette_plus.png", 		COULEUR_VIOLET, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Violette Avancer 5", 	"img/carte_violette_plus.png", 		COULEUR_VIOLET, VALEUR_AVANCER,		NULL,	{0}, 0 },

	{ "Violette Avancer x2 1", 	"img/carte_violette_plusplus.png", 	COULEUR_VIOLET, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Violette Avancer x2 2", 	"img/carte_violette_plusplus.png", 	COULEUR_VIOLET, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Violette Avancer x2 3", 	"img/carte_violette_plusplus.png", 	COULEUR_VIOLET, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Violette Avancer x2 4", 	"img/carte_violette_plusplus.png", 	COULEUR_VIOLET, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Violette Avancer x2 5", 	"img/carte_violette_plusplus.png", 	COULEUR_VIOLET, VALEUR_AVANCERX2,	NULL,	{0}, 0 },


	// 12 cartes neutres
	{ "Neutre Reculer 1",		"img/carte_neutre_moins.png",		COULEUR_TOUTES, VALEUR_RECULER,		NULL,	{0}, 0 },
	{ "Neutre Reculer 2",		"img/carte_neutre_moins.png",		COULEUR_TOUTES, VALEUR_RECULER,		NULL,	{0}, 0 },

	{ "Neutre Avancer 1",		"img/carte_neutre_plus.png",		COULEUR_TOUTES, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Neutre Avancer 2",		"img/carte_neutre_plus.png",		COULEUR_TOUTES, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Neutre Avancer 3",		"img/carte_neutre_plus.png",		COULEUR_TOUTES, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Neutre Avancer 4",		"img/carte_neutre_plus.png",		COULEUR_TOUTES, VALEUR_AVANCER,		NULL,	{0}, 0 },
	{ "Neutre Avancer 5",		"img/carte_neutre_plus.png",		COULEUR_TOUTES, VALEUR_AVANCER,		NULL,	{0}, 0 },

	{ "Neutre Avancer x2 1",	"img/carte_neutre_plusplus.png",	COULEUR_TOUTES, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Neutre Avancer x2 2",	"img/carte_neutre_plusplus.png",	COULEUR_TOUTES, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Neutre Avancer x2 3",	"img/carte_neutre_plusplus.png",	COULEUR_TOUTES, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Neutre Avancer x2 4",	"img/carte_neutre_plusplus.png",	COULEUR_TOUTES, VALEUR_AVANCERX2,	NULL,	{0}, 0 },
	{ "Neutre Avancer x2 5",	"img/carte_neutre_plusplus.png",	COULEUR_TOUTES, VALEUR_AVANCERX2,	NULL,	{0}, 0 },

};

// Liste des rochers: numéro - position x - position y
rocher_t listeRochers[] = 
{
	{ ROCHER_DEPART, 	100, 	450 },
	{ ROCHER_2, 		255, 	410 },
	{ ROCHER_3, 		385, 	340 },
	{ ROCHER_4, 		340, 	230 },
	{ ROCHER_5, 		160, 	253 },
	{ ROCHER_6, 		33, 	193 },
	{ ROCHER_7, 		-15, 	110 },
	{ ROCHER_8, 		104, 	87 	},
	{ ROCHER_9, 		212, 	35 	},
	{ ROCHER_ARRIVEE,	337, 	11 	},
};

// Initialisation du jeu
void Jeu_Initialiser()
{
	SDL_Rect posBG = { 0, 0 };
	int i;

	// On redimensionne la fenêtre (on utilise une fenêtre de taille différente pour le jeu)
	if(!(global.window = SDL_SetVideoMode(WINDOW_JEU_X, WINDOW_JEU_Y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)))
	{
		// Si la création de la fenêtre a échoué, on quitte le programme
		printf("Une erreur est survenue lors de la création de la fenêtre SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// On reset tout
	partie.debutPartie = SDL_GetTicks();
	partie.finPartie = 0;
	partie.stadeJoueur = 0;
	partie.statutNuage = 0;

	// Mélange des cartes
	Utils_MelangerCartes();

	// On place les tortues sur la case départ de façon aléatoire
	Utils_PlacerTortuesDepart();

	// Initialisation de tous les joueurs
	for(i = 1; i <= partie.nombreJoueurs; i++)
	{
		Jeu_InitialiserJoueur(i);
	}

	// Le premier joueur à jouer est le numéro 1
	partie.joueurActuel = 1;

	// Initialisation de la fenêtre par défaut du jeu
	partie.fenetreJeu = FENETRE_INGAME;
}

// Fonction appelée lorsque l'on quitte le jeu
void Jeu_Quitter()
{
	
}

// Initialisation d'un joueur
void Jeu_InitialiserJoueur(int numero)
{
	joueur_t *joueur;

	// On récupère les informations du joueur
	joueur = &joueurs[numero];

	// On s'assure de vider l'élément de la structure
	memset(joueur, 0, sizeof(joueur));

	// On définit le nom et le numéro du joueur, et on indique qu'il est actif
	sprintf(joueur->nom, "Joueur #%d", numero);
	joueur->numero = numero;
	joueur->actif = 1;

	// On attribue une couleur au joueur
	Utils_DonnerCouleurJoueur(numero);

	#ifdef DEBUG
	printf("%s: numero: %d - couleur: %d - actif: %d\n", joueur->nom, joueur->numero, joueur->couleur, joueur->actif);
	#endif

	// On donne 5 cartes au hasard au joueur
	Utils_DonnerCartes(numero, 5);
}

// fonction appelée lorsqu'un joueur pioche une carte
void Jeu_Piocher(int numJoueur)
{
	joueur_t *joueur;

	// récupération des infos du joueur
	joueur = &joueurs[numJoueur];

	// si le joueur est inexistant, on quitte
	if(!joueur)
	{
		printf("Erreur, joueur inexistant!\n");
		exit(1);
	}

	// si ce n'est pas à ce joueur de jouer
	if(numJoueur != partie.joueurActuel)
	{
		printf("Ce n'est pas à ce joueur de jouer !\n");
		return;
	}

	// si le joueur n'a pas encore joué de carte
	if(partie.stadeJoueur != 1)
	{
		printf("Ce joueur n'a pas encore joué une carte ou ce n'est pas son tour !\n");
		return;
	}

	// on donne une carte au joueur
	Utils_DonnerCartes(numJoueur, 1);

	//
	//
	// TODO: attendre un temps x avant de passer au joueur suivant
	//
	//
	//
	
	// petit délai avant passage au prochain joueur pour que 
	// le joueur puisse voir sa nouvelle carte
	//SDL_Delay(2000);

	// passage au joueur suivant
	Utils_JoueurSuivant();
}

// fonction de déplacement d'une tortue et de toutes les tortues se trouvant au-dessus d'elle
void Jeu_DeplacerTortue(int numCarte, couleur_t couleur)
{
	tortue_t *tortue;
	tortue_t *other;
	cartes_t *carte;
	char message[128];
	int i, minRocher = ROCHER_MAX, minTortue = -1, numRocher = -1, ancienRocher = -1, posAncienRocher = -1, numTortuesNouveauRocher = 0;

	// on récupère les informations de la carte jouée
	carte = &listeCartes[numCarte];

	// la carte n'a pas été trouvée, on abandonne
	if(!carte)
		return;

	// dans le cas où c'est une carte "normale", à savoir toutes les cartes sauf 
	// la carte spéciale
	if(carte->couleur != COULEUR_TOUTES)
	{
		// parcours de toutes les tortues
		for(i = 0; i < MAX_TORTUES; i++)
		{
			// récupération des infos de la tortue
			tortue = &listeTortues[i];

			// si la tortue n'existe pas, on passe à la suivante
			if(!tortue)
				continue;

			// si la couleur de la tortue correspond à la couleur de la carte, c'est cette 
			// tortue qu'on veut bouger
			if(tortue->couleur == carte->couleur)
			{
				break;
			}
		}
	}

	// si on joue la carte multicolore qui déplace la ou les dernière(s) tortue(s)
	else
	{
		// parcours de toutes les tortues à la recherche de la "dernière" tortue
		for(i = 0; i < MAX_TORTUES; i++)
		{
			// récupération des infos de la tortue
			tortue = &listeTortues[i];

			// si la tortue n'existe pas, on passe à la suivante
			if(!tortue)
				continue;

			// on récupère seulement la tortue à la position 0 du rocher, on s'occupera plus bas
			// des tortues se trouvant au dessus d'elle
			if((tortue->rocher < minRocher) && (tortue->position == 1))
			{
				minRocher = tortue->rocher;
				minTortue = i;
			}
		}

		// récupération des infos de la dernière tortue
		tortue = &listeTortues[minTortue];

		// la tortue est introuvable, erreur
		if(!tortue)
		{
			printf("Erreur de sélection d'une tortue avec une carte multicolore.\n");
			exit(1);
		}

		// on force tortue->position à 0 pour être sûr que TOUTES les dernières tortues sont bougées
		tortue->position = 1;
		i = minTortue;
	}
	
	// récupération des infos de la tortue que l'on souhaite bouger
	// si i==-1 alors aucune tortue n'a été trouvée plus haut, on 
	// quitte la fonction
	if(i == -1)
		return;

	// sauvegarde du numéro de "l'ancien" rocher de la tortue et de sa position sur le rocher
	numRocher = tortue->rocher;
	posAncienRocher = tortue->position;

	printf("La tortue %s se trouve sur le rocher %d à la position %d\n", tortue->nom, numRocher, posAncienRocher);

	// on cherche maintenant à savoir quel est le type de la carte (avancer, reculer, etc)
	switch(carte->valeur)
	{
		// c'est une carte reculer
		case VALEUR_RECULER:
			// on recule d'un rocher
			numRocher -= 1;

			// si on se trouvait déjà sur la ligne de départ, donc le rocher "minimum"
			// on ne fait rien
			if(numRocher < ROCHER_DEPART)
			{
				return;
			}
				
			sprintf(message, "Vous avez reculé la tortue %s d'une case.", tortue->nom);
			break;

		// c'est une carte avancer
		case VALEUR_AVANCER:
			// on avance d'un rocher
			numRocher += 1;

			// si à l'issue de l'avancée on se trouve sur le rocher d'arrivée
			if(numRocher >= ROCHER_ARRIVEE)
			{
				numRocher = ROCHER_ARRIVEE;
			}

			sprintf(message, "Vous avez avancé la tortue %s d'une case.", tortue->nom);
			break;

		// c'est une carte d'avancement de deux cases
		case VALEUR_AVANCERX2:
			// on avance de deux rochers
			numRocher += 2;

			// si à l'issue de l'avancée on est sur le rocher d'arrivée ou si on le dépasse
			if(numRocher >= ROCHER_ARRIVEE)
			{
				numRocher = ROCHER_ARRIVEE;
			}

			sprintf(message, "Vous avez avancé la tortue %s de deux cases.", tortue->nom);
			break;

		// autrement, on ne fait rien : ne devrait JAMAIS arriver!
		default:
			return;
	}

	// on affiche au joueur un message lui indiquant quelle tortue il a déplacé
	strcpy(global.texteJoueur, message);

	// on définit le temps d'affichage du message
	global.texteJoueurTemps = SDL_GetTicks() + 3500;


	printf("La tortue %s se déplace sur le rocher %d\n", tortue->nom, numRocher);

	// on compte le nombre de tortues qu'il y a déjà sur le NOUVEAU rocher
	numTortuesNouveauRocher = Utils_CompterTortuesRocher(numRocher, tortue->couleur);

	printf("Nombre de tortues sur le 'nouveau' rocher: %d\n", numTortuesNouveauRocher);

	// sauvegarde du numéro de l'ancien rocher
	ancienRocher = tortue->rocher;

	// on définit la position de notre tortue sur le nouveau rocher
	// on la place au-dessus de toutes les tortues s'y trouvant déjà
	tortue->rocher = numRocher;
	tortue->position = ++numTortuesNouveauRocher;

	printf("La tortue %s se trouve maintenant sur le rocher %d à la position %d\n", tortue->nom, tortue->rocher, tortue->position);

	// on cherche maintenant toutes les tortues qui étaient au-dessus de notre tortue sur l'ANCIEN rocher
	for(i = 0; i < MAX_TORTUES; i++)
	{
		// récupération des infos de la tortue
		other = &listeTortues[i];

		// si la tortue n'existe pas, on passe à la suivante
		if(!other)
			continue;

		// si cette tortue est notre tortue, on passe à la suivante. Ici, ce scénario ne devrait JAMAIS arriver !
		if(other->couleur == tortue->couleur)
			continue;

		// 'l'autre' tortue est sur l'ancien rocher et était au-dessus de notre tortue
		if((other->rocher == ancienRocher) && (other->position > posAncienRocher))
		{
			printf("La tortue %s qui se trouvait à la position %d sur le rocher %d ...", other->nom, other->position, ancienRocher);

			// on déplace donc cette tortue sur le nouveau rocher et on la place au-dessus de toutes les autres 
			// tortues s'y trouvant déjà
			other->rocher = numRocher;
			other->position = ++numTortuesNouveauRocher;
			printf("se trouve maintenant à la position %d sur le rocher %d\n", other->position, other->rocher);
		}
	}

	// il y a un gagnant, c'est terminé, on affiche la fenêtre du gagnant
	if(numRocher == ROCHER_ARRIVEE)
	{
		partie.fenetreJeu = FENETRE_TERMINE;
		partie.finPartie = SDL_GetTicks();
		global.tempsSurPage = SDL_GetTicks();
	}

}

void Jeu_JouerCarte(int numJoueur, int numCarte)
{
	joueur_t *joueur;
	cartes_t *carte;

	// récupération du joueur et de la carte jouée
	joueur = &joueurs[numJoueur];
	carte = &listeCartes[numCarte];

	// si l'un des deux est introuvable, on quitte (ne devrait JAMAIS arriver !)
	if(!joueur || !carte)
	{
		printf("Erreur, joueur ou carte inexistants!\n");
		exit(1);
	}

	// si ce n'est pas à ce joueur de jouer une carte
	if(numJoueur != partie.joueurActuel)
	{
		printf("Ce n'est pas à ce joueur de jouer !\n");
		return;
	}

	// ce joueur a déjà joué pour ce tour
	if(partie.stadeJoueur > 0)
	{
		printf("Ce joueur a déjà joué une carte !\n");
		return;
	}

	// on déplace la tortue de la couleur de la carte jouée
	Jeu_DeplacerTortue(numCarte, carte->couleur);

	// on réorganise la pioche, càd qu'on place notre carte en dernière position de la pioche
	Utils_ReorganiserPioche(numCarte);

	// on passe le "stade" du joueur à 1, c'est-à-dire qu'il est en stade d'attente
	// de clic sur la pioche
	partie.stadeJoueur = 1;

}


// Affichage de l'image du plateau de jeu
void Jeu_AfficherPlateau()
{
	// position du plateau (x, y,  w,   h)
	SDL_Rect posPlateau = { 0, 0, 600, 800 };
	
	// coloration du fond en vert
	SDL_FillRect(global.window, NULL, SDL_MapRGB(global.window->format, 162, 185, 63));
	
	// image du plateau
	SDL_BlitSurface(global.images.plateau, NULL, global.window, &posPlateau);
}


// affichage de la pioche
void Jeu_AfficherPioche()
{
	SDL_Rect posPioche 	 = { 413, 460, 93, 122 };
	SDL_Rect posPiocheHL = { 394, 441, 112, 160 };

	// si la souris se trouve sur l'image de la pioche, on la met en valeur
	if(Utils_DansBouton(posPioche)) 
	{
		// si on clique sur la pioche... on pioche
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
			Jeu_Piocher(partie.joueurActuel);

		SDL_BlitSurface(global.images.piocheHL, NULL, global.window, &posPiocheHL);
	} 
	else
	{
		// si le joueur doit piocher (staderJoueur = 1) et qu'il ne le fait pas,
		// on essaye d'attirer son attention en faisant clignoter la pioche
		if((partie.stadeJoueur == 1) && ((SDL_GetTicks() >> 9) & 1))
		{
			SDL_BlitSurface(global.images.piocheHL, NULL, global.window, &posPiocheHL);
		}

		// sinon, on affiche la pioche normalement
		else
		{
			SDL_BlitSurface(global.images.pioche, NULL, global.window, &posPioche);
		}
		
	}
}

// affichage du jeu du joueur en cours (cartes, pioche, etc)
void Jeu_AfficherJeuJoueur()
{
	cartes_t *carte;
	int i, x = 5;

	// affichage des 5 cartes du joueur
	for(i = 0; i < MAX_CARTES; i++)
	{
		// sélection d'une carte
		carte = &listeCartes[i];

		// si elle n'existe pas, on passe à la suivante...
		if(!carte)
			continue;

		// si la carte appartient à notre joueur, on l'affiche
		if(carte->utilisee && (carte->utiliseePar == partie.joueurActuel))
		{
			carte->infosImage.x = x;
			carte->infosImage.y = 570;

			// si on se trouve dans la zone de la carte, on regarde si le joueur clique dessus
			if(Utils_DansBouton(carte->infosImage))
			{
				// détection clic souris
				if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1) && partie.stadeJoueur < 1)
				{
					// Le joueur joue la carte i
					Jeu_JouerCarte(partie.joueurActuel, i);
				}
			}

			SDL_BlitSurface(carte->image_loaded, NULL, global.window, &carte->infosImage);
			x += 75;
		}
	}
}

// affichage des informations "Joueur <num>, c'est à votre tour !"
void Jeu_AfficherInfos()
{
	SDL_Rect posTexte 			= { 10, 528 };
	SDL_Rect posNuageFerme 		= { -240, 220, 298, 225 };
	SDL_Rect posNuageOuvert 	= { -30, 220, 298, 225 };
	SDL_Rect posFlechesFerme 	= { -4, 320, 29, 24 };
	SDL_Rect posFLechesOuvert 	= { 200, 320, 29, 24 };
	SDL_Rect posInfoCouleur 	= { 32, 265, 118, 101 };
	SDL_Rect posInfoJoueur 		= { 5, 363, 188, 39 };
	SDL_Color couleurNoir 		= { 23, 95, 5 };
	SDL_Surface *texte 			= NULL;
	joueur_t *joueur;
	char txt[32];
	int tempsSurNuage = 0;

	// Récupération des informations du joueur
	joueur = &joueurs[partie.joueurActuel];

	if(!joueur)
		return;

	// Affichage du texte
	sprintf(txt, "%s c'est à votre tour !", joueur->nom);

	texte = TTF_RenderUTF8_Blended(global.police, txt, couleurNoir);
	SDL_BlitSurface(texte, NULL, global.window, &posTexte);

	SDL_FreeSurface(texte);

	// Affichage du "nuage" dans lequel le joueur peut se rappeler quelle est sa couleur
	// Il suffit de cliquer dessus pour l'enrouler / le dérouler

	// On définit un temps minimum pendant lequel on ne peut pas cliquer sur le bouton, 
	// sinon il est possible qu'en étant un peu long à cliquer sur la souris, le nuage 
	// s'ouvre et se ferme très rapidement des dizaines de fois
	tempsSurNuage = SDL_GetTicks() - global.tempsSurPage;

	// Le nuage est ouvert
	if(partie.statutNuage == 1)
	{
		SDL_BlitSurface(global.images.nuageOuvert, NULL, global.window, &posNuageOuvert);

		SDL_BlitSurface(global.images.derouler, NULL, global.window, &posFLechesOuvert);

		posFLechesOuvert.y += 25;
		posFLechesOuvert.x -= 1;

		SDL_BlitSurface(global.images.enrouler, NULL, global.window, &posFLechesOuvert);

		SDL_BlitSurface(global.images.tortueNuage[joueur->couleur], NULL, global.window, &posInfoCouleur);

		SDL_BlitSurface(global.images.joueur[partie.joueurActuel-1], NULL, global.window, &posInfoJoueur);

		// Si on clique sur le nuage, on le ferme
		if((tempsSurNuage > 180) && Utils_DansBouton(posNuageOuvert) && (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1)))
		{	
			partie.statutNuage ^= 1;
			global.tempsSurPage = SDL_GetTicks();
		}
	}

	// Le nuage est fermé
	else
	{
		SDL_BlitSurface(global.images.nuageOuvert, NULL, global.window, &posNuageFerme);
		SDL_BlitSurface(global.images.derouler, NULL, global.window, &posFlechesFerme);

		posFlechesFerme.y += 25;
		posFlechesFerme.x -= 5;

		SDL_BlitSurface(global.images.enrouler, NULL, global.window, &posFlechesFerme);

		// Si on clique sur le nuage, on l'ouvre
		if((tempsSurNuage > 300) && Utils_DansBouton(posNuageFerme) && (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1)))
		{	
			partie.statutNuage ^= 1;
			global.tempsSurPage = SDL_GetTicks();
		}
	}
}

// affichage d'un texte au joueur pendant une durée déterminée
// par exemple : "vous avez avancé la tortue rouge" etc.
void Jeu_AfficherTexteJoueur()
{
	SDL_Surface *texte = NULL;
	SDL_Color 	couleurNoir = { 0, 0, 0 };
	SDL_Rect 	posTexte = { 10, 551 };
	int 		tempsDifference;

	// global.texteJoueurTemps contient le temps jusqu'auquel on
	// veut afficher le texte
	tempsDifference = global.texteJoueurTemps - SDL_GetTicks();

	// si on n'a pas encore dépassé ce temps, on affiche le texte
	if(tempsDifference > 0)
	{
		texte = TTF_RenderUTF8_Blended(global.policeMini, global.texteJoueur, couleurNoir);
		SDL_BlitSurface(texte, NULL, global.window, &posTexte);

		SDL_FreeSurface(texte);
	}
}


// affichage des tortues sur le plateau
void Jeu_AfficherTortues()
{
	tortue_t *tortue;
	rocher_t *rocher;
	int i, j, position;
	SDL_Rect posTortue;

	// ici j'ai été confronté à un problème: il faut que les images des tortues soient correctement superposées,
	// et donc que l'image de la tortue en position 2 soit AU DESSUS de l'image de la tortue en position 1, etc.
	// on fait donc un parcours de toutes les positions et on commence par placer toutes les tortues en position 1 sur leur
	// rocher, puis toutes celles en position 2, etc.
	for(position = 1; position < MAX_TORTUES+1; position++)
	{
		// parcours de toutes les tortues
		for(i = 0; i < MAX_TORTUES; i++)
		{
			// récupération des infos de la tortue
			tortue = &listeTortues[i];

			// si la tortue n'existe pas, on passe à la suivante
			if(!tortue)
				continue;

			// si la position de la tortue n'est pas égale à "position", on passe à la tortue suivante
			if(tortue->position != position)
				continue;

			// parcours de tous les rochers afin de trouver les informations
			// de celui sur lequel se trouve notre tortue
			for(j = 0; j < ROCHER_MAX; j++)
			{
				// récupération des infos du rocher
				rocher = &listeRochers[j];

				// si le rocher n'existe pas, on quitte
				if(!rocher)
				{
					printf("Erreur: un rocher est introuvable.\n");
					exit(1);
				}
					
				// si le rocher est celui sur lequel se trouve notre tortue
				if(tortue->rocher == rocher->num)
				{
					// récupération de la position du rocher
					posTortue.y = rocher->posY;
					posTortue.x = rocher->posX;
					break;
				}
			}

			// on met les tortues les unes au dessus des autres
			// en fonction de leur position sur le rocher
			posTortue.y -= tortue->position * 20;

			// récupération de la taille de l'image des tortues
			posTortue.w = tortue->infosImage.w;
			posTortue.h = tortue->infosImage.h;

			// affichage de l'image
			SDL_BlitSurface(tortue->image_loaded, NULL, global.window, &posTortue);

		}
	}
}

// c'est la fin du jeu, on affiche le gagnant
// c'est celui qui a la tortue sur la ligne d'arrivée et en position 1
// càd celle qui est en dessous des autres
void Jeu_AfficherGagnant()
{
	joueur_t 	*joueur;
	SDL_Rect 	posBG 		= { 0, 0 };
	SDL_Rect 	posTexte 	= { 135, 60 };
	SDL_Rect 	posRetour 	= { 330, 545, 149, 65 };
	SDL_Color 	couleurNoir = { 0, 0, 0 };
	SDL_Surface *texte 		= NULL;
	char 		txt[128];
	char 		couleurTortue[10];
	int 		id = -1, tempsDeJeu, secs, mins, tens, tempsSurPage = 0;

	// si la partie n'est pas terminée, pas de raisons d'afficher cette page
	if(partie.fenetreJeu != FENETRE_TERMINE)
		return;

	memset(txt, 0, sizeof(txt));
	memset(couleurTortue, 0, sizeof(couleurTortue));

	// on cherche le joueur gagnant
	Utils_TrouverGagnant(&id, couleurTortue);

	// affichage de l'image de fond
	SDL_BlitSurface(global.images.bg, NULL, global.window, &posBG);

	// Aucun joueur n'a été trouvé, cela peut arriver quand toutes les tortues n'ont pas 
	// été attribuées à des joueurs et que l'une d'entre elles gagne.
	if(id == -1)
	{
		posTexte.x -= 20;

		// Affichage du texte "aucun gagnant !"
		sprintf(txt, "Aucun gagnant !");
		texte = TTF_RenderUTF8_Blended(global.policeRumpel, txt, couleurNoir);
		SDL_BlitSurface(texte, NULL, global.window, &posTexte);

		// alignement du texte
		posTexte.y += 40;
		posTexte.x -= 20;
	}

	else
	{
		joueur = &joueurs[id];

		// si aucun joueur n'a été trouvé...
		if(!joueur)
			return;

		#ifdef DEBUG
		printf("=== le %s a gagné la partie !\n", joueur->nom);
		#endif

		// affichage du texte "Le joueur #numero"...
		sprintf(txt, "Le %s", joueur->nom);
		texte = TTF_RenderUTF8_Blended(global.policeRumpel, txt, couleurNoir);
		SDL_BlitSurface(texte, NULL, global.window, &posTexte);

		// alignement du texte
		posTexte.y += 40;
		posTexte.x -= 40;

		// affichage du texte "a gagné la partie !"
		sprintf(txt, "a gagné la partie !");
		texte = TTF_RenderUTF8_Blended(global.policeRumpel, txt, couleurNoir);
		SDL_BlitSurface(texte, NULL, global.window, &posTexte);

	}
	

	posTexte.y += 210;
	posTexte.x -= 22;

	sprintf(txt, "Tortue: %s", couleurTortue);

	texte = TTF_RenderUTF8_Blended(global.policeRumpel, txt, couleurNoir);
	SDL_BlitSurface(texte, NULL, global.window, &posTexte);

	posTexte.y += 50;

	// temps de jeu en millisecondes
	tempsDeJeu = partie.finPartie - partie.debutPartie;

	// calcul des minutes, dizaines de secondes et secondes
	secs  = tempsDeJeu / 1000;
	mins  = secs / 60;
	secs -= mins * 60;
	tens  = secs / 10;
	secs -= tens * 10;

	// Affichage du temps de jeu
	sprintf(txt, "Temps de jeu: %dmn %d%ds", mins, tens, secs);
	texte = TTF_RenderUTF8_Blended(global.policeRumpel, txt, couleurNoir);
	SDL_BlitSurface(texte, NULL, global.window, &posTexte);

	// affichage du bouton retour
	if(Utils_DansBouton(posRetour))
	{
		// On définit un temps minimum pendant lequel on ne peut pas cliquer sur le bouton, 
		// sinon il est possible qu'en restant appuyé sur la souris on clique sur les différents
		// boutons des pages successives en quelques ms
		tempsSurPage = SDL_GetTicks() - global.tempsSurPage;

		// Si on clic gauche, retour à l'accueil
		if((tempsSurPage > 600) && (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1)))
		{
			Jeu_Quitter();
			Menu_Initialiser();
		}
		
		SDL_BlitSurface(global.images.boutonRetourHL, NULL, global.window, &posRetour);
	}
	else
	{
		SDL_BlitSurface(global.images.boutonRetour, NULL, global.window, &posRetour);
	}

	SDL_FreeSurface(texte);
}

// Fonction de gestion de l'affichage des pages
void Jeu_Afficher()
{
	switch(partie.fenetreJeu)
	{
		case FENETRE_INGAME:
			// Affichage du plateau
			Jeu_AfficherPlateau();
			
			// Affichage des tortues sur le plateau
			Jeu_AfficherTortues();

			// Affichage de la pioche
			Jeu_AfficherPioche();

			// Affichage du jeu du joueur (cartes, pioche, etc)
			Jeu_AfficherJeuJoueur();

			// Affichage de textes d'actions au joueur
			Jeu_AfficherTexteJoueur();

			// Affichage du texte rappellant quel joueur doit jouer
			Jeu_AfficherInfos();
			
			break;

		case FENETRE_TERMINE:
			Jeu_AfficherGagnant();
			break;
	}

}
