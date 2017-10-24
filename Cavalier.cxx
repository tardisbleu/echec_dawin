#include <iostream>
#include "Cavalier.h"
#include <cmath>
using namespace std;

Cavalier::Cavalier(bool white, bool left) : Piece((left?2:7),(white?1:8),white) { }
Cavalier::Cavalier(int x,int y,bool white) : Piece(x,y,white) { }
bool
Cavalier::mouvementValide(Echiquier &e, int x, int y) {
    if ((abs(x-m_x) == 2 && abs(y-m_y) == 1) || (abs(x-m_x) == 1 && abs(y-m_y) == 2)) {
        if (e.getPiece(x,y) != NULL && e.getPiece(x,y)->isWhite() != m_white) {
            return true;
        }
        return true;
    }
    return false;
}

char
Cavalier::type() {
    return m_white ? 'C' : 'c';
}
