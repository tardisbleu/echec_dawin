#include <iostream>
#include "Pion.h"
#include <cmath>
using namespace std;

Pion::Pion(int x, bool white) : Piece(x, (white ? 2 : 7), white) {
}

bool
Pion::mouvementValide(Echiquier &e, int x, int y) {
    if((m_y == 2 && m_white) || (m_y == 7 && !m_white)) { // Jamais déplacé
        if ((x == m_x && y == m_y+2  && m_white && (e.getPiece(m_x, m_y+1) == NULL && e.getPiece(m_x, m_y+2) == NULL)) || (x == m_x && y == m_y-2 && !m_white &&( e.getPiece(m_x, m_y-1) == NULL && e.getPiece(m_x, m_y-2) == NULL))) { //2 case vertical[1st]
            return true;
        } else {
            if ((x == m_x && y == m_y+1 && m_white && e.getPiece(x,y) == NULL) || (x == m_x && y == m_y-1 && !m_white && e.getPiece(x,y) == NULL)) { //1 case vertical [1st]
                return true;
            } else {
                if(((1 == abs(x-m_x) && y == m_y+1 && m_white) || (1 == abs(x-m_x) && y == m_y-1 && !m_white))&& e.getPiece(x,y) != NULL && e.getPiece(x, y)->isWhite() != m_white) { // 1 case diagonal [1st]
                    return true;
                }
            }
        }
    } else { // Déjà deplacé
        if (((x == m_x && y == m_y+1 && m_white) || (x == m_x && y == m_y-1 && !m_white))&& e.getPiece(x,y) == NULL) { //1 case vertical
            return true;
        } else {
            if(((1 == abs(x-m_x) && y == m_y+1 && m_white) || (1 == abs(x-m_x) && y == m_y-1 && !m_white))&& e.getPiece(x,y) != NULL && e.getPiece(x, y)->isWhite() != m_white) { // 1 case diagonal
                return true;
            }
        }
    }
    return false;

}

char
Pion::type() {
    return m_white ? 'P' : 'p';
}
