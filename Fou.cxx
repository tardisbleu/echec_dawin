#include "Piece.h"
#include <iostream>
#include "Echiquier.h"
#include "Fou.h"

using namespace std;
Fou::Fou() { }

Fou::Fou(bool white, bool left) : Piece((left?3:6),(white?1:8),white) { }
Fou::Fou(int x,int y,bool white) : Piece(x,y,white) { }
bool
Fou::mouvementValide(Echiquier &e, int x, int y) {
    int xDepla = x-m_x;
    int yDepla = y-m_y;
    int i = m_x;
    int j = m_y;
    int deltaX = 0;
    int deltaY = 0;
    if(xDepla != 0 && yDepla != 0) {
        if(xDepla <0) {
            deltaX = -1;
            if(yDepla < 0) {
                deltaY = -1;
            } else {
                deltaY = 1;
            }
        } else {
            deltaX = 1;
            if(yDepla < 0) {
                deltaY = -1;
            } else {
                deltaY = 1;
            }
        }
    } else {
        return false;
    }

    i+= deltaX;
    j+= deltaY;
    while(i!=x && j!=y) {
        if(e.getPiece(i,j) != NULL) {
            break;
        } else {
            i+= deltaX;
            j+= deltaY;
        }
    }

    if (i!=x || j!=y)
        return(false);

    Piece *p = e.getPiece(i,j);
    if (p != NULL) {
        if(p->isWhite() != m_white) {
            return(true);
        }
    } else {
        return(true);
    }
    return(false);
}

char
Fou::type() {
    return m_white ? 'F' : 'f';
}
