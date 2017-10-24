#include <iostream>
#include "Joueur.h"
#include "Pion.h"
#include "Roi.h"
#include "Fou.h"
#include "Reine.h"
#include "Cavalier.h"
using namespace std;


Joueur::Joueur()
{
    //cout << "Création de joueur sans paramètres " << endl;
}

Joueur::Joueur(bool white)
{
    init(white);
}

Joueur::~Joueur()
{
    for (int i=0 ; i < 16 ; i++)
        delete m_pieces[i];
}

void
Joueur::init(bool white){
    int n = 0;
    for (int i=1; i<=8; i++)
    {
        m_pieces[n++] = new Pion(i,white);
    }
    m_pieces[n++] = new Roi(white);
    m_pieces[n++] = new Reine(white);
    m_pieces[n++] = new Cavalier(white,true);
    m_pieces[n++] = new Cavalier(white,false);
    m_pieces[n++] = new Fou(white,true);
    m_pieces[n++] = new Fou(white,false);
    m_pieces[n++] = new Tour(white,true);
    m_pieces[n++] = new Tour(white,false);
}

void
Joueur::affiche()
{
    for (int i=0; i < 16; i++)
        m_pieces[i]->affiche();
}

bool
Joueur::placerPieces(Echiquier & e)
{
    bool returned = true;
    for (int i=0; i < 16; i++)
        returned &= e.placer(m_pieces[i]);

    return returned;
}
