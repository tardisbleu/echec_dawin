#include <iostream>
#include "Roi.h"
#include "Pion.h"
#include "Reine.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Fou.h"
#include <cmath>

using namespace std;

Roi::Roi(bool white) : Piece(5,(white?1:8),white) { }

bool
Roi::mouvementValide(Echiquier &e, int x, int y) {
    if ((abs(x - m_x) <= 1) && (abs(y - m_y) <= 1)) {
        if (e.getPiece(x,y) != NULL && e.getPiece(x,y)->isWhite() != m_white) {
            return true;
        }
        return true;
    }
    return false;
}

char
Roi::type() {
    return m_white ? 'R' : 'r';
}

//Retourne true si le roi est en echec sinon retourne false
bool
Roi::isEchec(Echiquier &e) {
    bool enEchec = false;
    int xTest = 1;
    int yTest = 1;
    while(!enEchec && (xTest <= 8 && yTest <= 8)) {
        Piece *pi = e.getPiece(xTest, yTest);
        if(pi) {
            if(pi->isWhite() != m_white) {
                Roi *r = dynamic_cast<Roi*>(pi);
                Pion *p = dynamic_cast<Pion*>(pi);
                Fou *f = dynamic_cast<Fou*>(pi);
                Cavalier *c = dynamic_cast<Cavalier*>(pi);
                Reine *re = dynamic_cast<Reine*>(pi);
                Tour *t = dynamic_cast<Tour*>(pi);

                if(r)
                    enEchec = (r->mouvementValide(e, m_x, m_y));

                if(p)
                    enEchec = (p->mouvementValide(e, m_x, m_y));

                if(f)
                    enEchec = (f->mouvementValide(e, m_x, m_y));

                if(c)
                    enEchec = (c->mouvementValide(e, m_x, m_y));


                if(re)
                    enEchec = (re->mouvementValide(e, m_x, m_y));

                if(t)
                    enEchec = (t->mouvementValide(e, m_x, m_y));

            }
        }
        if(xTest == 8) {
            yTest++;
            xTest = 0;
        }

        xTest++;
    }
    return enEchec;
}
