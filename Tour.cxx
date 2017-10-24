#include "Piece.h"
#include <iostream>
#include "Echiquier.h"
#include "Tour.h"
#include <cmath>
using namespace std;

Tour::Tour() { }

Tour::Tour(bool white, bool left) : Piece((left?1:8),(white?1:8),white) { }
Tour::Tour(int x,int y,bool white) : Piece(x,y,white) { }
bool
Tour::mouvementValide(Echiquier &e, int x, int y) {
    int xDepla = x-m_x;
    int yDepla = y-m_y;
    int i = m_x;
    int j = m_y;
    int deltaX = 0;
    int deltaY = 0;
    if(xDepla == 0 || yDepla == 0) {
        if(xDepla != 0) {
            if(xDepla <0) {
                deltaX = -1;
            } else {
                deltaX = 1;
            }
        } else {
            if(yDepla != 0) {
                if(yDepla <0) {
                    deltaY = -1;
                } else {
                    deltaY = 1;
                }
            }
        }
    }
    i+= deltaX;
    j+= deltaY;
    while((i!=x || j!=y)) {
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
Tour::type() {
    return m_white ? 'T' : 't';
}

