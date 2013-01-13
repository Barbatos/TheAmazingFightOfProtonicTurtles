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

#ifndef _JEU_H_
#define _JEU_H_

// les fenêtres du jeu
typedef enum 
{
	FENETRE_AUCUNE,
	FENETRE_CHARGEMENT,
	FENETRE_INGAME,
	FENETRE_TERMINE,
} fenetre_t;


// les différentes couleurs des tortues
typedef enum 
{
	COULEUR_AUCUNE,
	COULEUR_JAUNE,
	COULEUR_BLEU,
	COULEUR_ROUGE,
	COULEUR_VERT,
	COULEUR_VIOLET,
	COULEUR_TOUTES
} couleur_t;


// les valeurs des cartes
typedef enum 
{
	VALEUR_AUCUNE,
	VALEUR_RECULER,				// la tortue recule d'une case
	VALEUR_AVANCER,				// la tortue avance d'une case
	VALEUR_AVANCERX2,			// la tortue avance de deux cases
} valeur_t;

// liste des rochers
typedef enum 
{
	ROCHER_DEPART,
	ROCHER_2,
	ROCHER_3,
	ROCHER_4,
	ROCHER_5,
	ROCHER_6,
	ROCHER_7,
	ROCHER_8,
	ROCHER_9,
	ROCHER_ARRIVEE,
	ROCHER_MAX,
} numRocher_t;


// Structure des rochers contenant leur numéro
// ainsi que leur position (permettant de placer
// les tortues)
typedef struct
{
	numRocher_t		num;			// numéro du rocher
	int				posX;			// position en x
	int				posY;			// position en y
} rocher_t;


// Structure de la liste des tortues
typedef struct 
{
	char 			nom[32];		// nom de la tortue
	char 			image[32];		// lien vers l'image associée à la couleur de la tortue
	couleur_t 		couleur;		// couleur de la tortue
	SDL_Surface 	*image_loaded;	// image associée à la couleur de la tortue
	SDL_Rect		infosImage; 	// position (x,y) et taille(w,h) de l'image
	numRocher_t		rocher; 		// numéro de la case sur laquelle est la tortue
	int				position; 		// position de la tortue sur la carte
} tortue_t;


// Structure de la liste des cartes
typedef struct 
{
	char 			nom[32];		// nom de la carte
	char 			image[32];		// lien vers l'image de la carte
	couleur_t 		couleur;		// couleur de la carte
	valeur_t 		valeur;			// valeur de la carte (avancer, reculer...)
	SDL_Surface 	*image_loaded;	// image de la carte
	SDL_Rect		infosImage; 	// position (x,y) et taille(w,h) de l'image
	int				utilisee;		// 1 si la carte est utilisée par un joueur
	int				utiliseePar; 	// par qui la carte est-elle utilisée ? 0 = la pioche
} cartes_t;


// Structure de la partie
typedef struct 
{
	fenetre_t 		fenetreJeu;		// dans quelle fenêtre du jeu se trouve-t-on ?
	int 			nombreJoueurs; 	// nombre de joueurs participants (2 à 5);
	int 			debutPartie; 	// timestamp du moment où l'on a débuté la partie (afin de calculer le temps total à la fin)
	int 			finPartie;		// timestamp du moment où l'on a terminé la partie (un joueur a gagné)
	int 			joueurActuel; 	// le joueur actuellement en train de jouer
	int 			stadeJoueur; 	// le stade du jeu du joueur actuellement en train de jouer. 0 => carte pas encore sélectionnée, 1 => carte sélectionnée et en attente de pioche
	int 			statutNuage;	// le nuage qui renseigne la couleur au joueur est-il ouvert ou fermé ?
} partie_t;


// Structure des joueurs
typedef struct 
{
	int 			numero;			// numéro du joueur
	char 			nom[32];		// nom du joueur - @Charles TODO: faire en sorte que le joueur puisse entrer lui-même son pseudo
	couleur_t 		couleur;		// couleur de tortue du joueur
	int				actif;			// le joueur est-il actif?
	int				cartes[5];		// liste des 5 cartes du joueur
} joueur_t;


// Création des tableaux de structures
partie_t 	partie;				
cartes_t 	listeCartes[MAX_CARTES+1];
tortue_t 	listeTortues[MAX_TORTUES];
joueur_t 	joueurs[MAX_JOUEURS+1];
rocher_t 	listeRochers[ROCHER_MAX];


void 	Jeu_Initialiser();
void 	Jeu_Quitter();
void 	Jeu_AfficherPlateau();
void 	Jeu_InitialiserJoueur(int numero);
void 	Jeu_InitialiserJoueurs();
void 	Jeu_Piocher(int numJoueur);
void 	Jeu_AfficherPioche();
void 	Jeu_DeplacerTortue(int numCarte, couleur_t couleur);
void 	Jeu_JouerCarte(int numJoueur, int numCarte);
void 	Jeu_AfficherJeuJoueur();
void 	Jeu_AfficherInfos();
void 	Jeu_AfficherTexteJoueur();
void 	Jeu_AfficherTortues();
void 	Jeu_AfficherGagnant();
void 	Jeu_Afficher();

#endif
