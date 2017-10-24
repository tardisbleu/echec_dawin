/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "Joueur.h"
#include "JoueurNoir.h"
#include "JoueurBlanc.h"
#include "Echiquier.h"
#include "Pion.h"
#include "Roi.h"
#include "Reine.h"
#include "Cavalier.h"
#include "service.cxx"
#include <typeinfo>
using namespace std;

int main( int argc, char** argv ) {
    //Initialise la partie (Créer les joueurs,l'echiquier et place les piéces)
    JoueurNoir jn;
    JoueurBlanc jb;
    Echiquier e;
    bool piecesOK;
    piecesOK = jn.placerPieces(e);
    assert(piecesOK);
    piecesOK = jb.placerPieces(e);
    assert(piecesOK);
    //Systeme de partie tour par tour
    bool JoueurBMat = false;
    bool JoueurNMat = false;
    bool mouvementOK;
    int xPiece = 0;
    int yPiece = 0;
    int xPieceD = 0;
    int yPieceD = 0;
    bool AJoueurBlanc = true;
    e.affiche();
    bool fin = false ;
    while(fin == false) {
        mouvementOK = false;
        while(!mouvementOK) {
            afficherLigne();
            if (AJoueurBlanc) {
                cout << " -> Joueur blanc : " << endl ;
            } else {
                cout << " -> Joueur noir : " << endl ;
            }
            cout << "Quel piece voulez-vous deplacer ?( X puis Y )" << endl;
            cin >> xPiece;
            cin >> yPiece;
            //Si au coordonné xPiece/yPiece est il y a une piece et qu'elle est valide
            if(danslEchiquier(xPiece,yPiece) && e.getPiece(xPiece,yPiece)!= NULL) {
                //Si la piece est bien de la même couleur que le joueur
                if(e.getPiece(xPiece,yPiece)->isWhite() == AJoueurBlanc || !e.getPiece(xPiece,yPiece)->isWhite() == !AJoueurBlanc) {
                    cout << "Ou voulez-vous la deplacer ? ( X puis Y )" << endl;
                    cin >> xPieceD;
                    cin >> yPieceD;
                    // Si qui verifie que xPieceD/yPieceD est bien dans l'echiquier et evite un surplace
                    if(danslEchiquier(xPieceD,yPieceD) && !(xPiece == xPieceD && yPiece == yPieceD)) {
                        cout << "Vous voulez deplacer la piece X = " << xPiece << " / Y = " << yPiece<< " en X = "<< xPieceD << " / Y = "<< yPieceD << endl;
                        //Si la piece peut effecteur le mouvement
                        if(e.getPiece(xPiece,yPiece)->mouvementValide(e, xPieceD, yPieceD)) {
                            if(e.getPiece(xPieceD,yPieceD) != NULL) {
                                e.enleverPiece(xPieceD,yPieceD);
                            }
                            e.deplacer(e.getPiece(xPiece,yPiece),xPieceD,yPieceD);
                            cout << "Mouvement effectue." << endl;
                            mouvementOK = true;
                            //En Commentaire : Début du systéme de mise en Echec et mat
                            //JoueurBMat = estEnEchecEtMat(e,AJoueurBlanc);
                            //JoueurNMat = estEnEchecEtMat(e,!AJoueurBlanc);
                            //if(!JoueurBMat && !JoueurNMat) {
                            //Savoir si le roi adverse est en echec
                            adversaireEnEchec(e,AJoueurBlanc);
                            //Savoir sur le la piéce deplacée a le droit à une promotion
                            promotion(xPieceD,yPieceD,AJoueurBlanc,e);
                            //}
                        } else {
                            cout << "Le mouvement est invalide pour la piéce." << endl;
                        }
                    } else {
                        cout << "Coordonnee du deplacement invalide ( Hors de l echiquier ou sur lui meme ) " << endl;
                    }
                } else {
                    cout << "Merci de choisir une piece de ta couleur. Retry... " << endl;
                }
            } else {
                cout << "Coordonnee de la piece invalide ( pas de piece ici )" << endl;
            }
            afficherLigne();
            e.affiche();
        }
        AJoueurBlanc = !AJoueurBlanc;
        //Si un joueur en est echec et mat => Fin de la partie
        if(JoueurBMat || JoueurNMat) {
            fin = !fin;
        }
    }
    return 0;
}


