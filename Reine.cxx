#include <iostream>
#include "Reine.h"
using namespace std;

Reine::Reine(bool white) : Piece(4,(white?1:8),white) { }

Reine::Reine(int x,int y,bool white) : Piece(x,y,white) { }


bool
Reine::mouvementValide(Echiquier &e, int x, int y) {
    return (Tour::mouvementValide(e,x,y) || Fou::mouvementValide(e,x,y));
}

char
Reine::type() {
    return m_white ? 'Q' : 'q';
}
