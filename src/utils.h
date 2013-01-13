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

#ifndef _UTILS_H_
#define _UTILS_H_

void 		Utils_ChargerImages();
void 		Utils_DechargerImages();
void 		Utils_MelangerCartes();
int 		Utils_DansBouton(SDL_Rect position);
void 		Utils_DonnerCouleurJoueur(int numero);
void 		Utils_DonnerCartes(int numero, int nbCartes);
void 		Utils_JoueurSuivant();
void 		Utils_PlacerTortuesDepart();
void 		Utils_ReorganiserPioche(int numCarte);
int 		Utils_CompterTortuesRocher(int rocher, int couleurAExclure);
void		Utils_TrouverGagnant(int *numJoueur, char *couleurTortue);

#endif
