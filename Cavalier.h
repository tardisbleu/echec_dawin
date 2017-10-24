#if !defined Cavalier_h
#define Cavalier_h
#include "Echiquier.h"
#include "Piece.h"

class Cavalier : public Piece
{
public:
  Cavalier(bool white, bool left);
  Cavalier(int x,int y,bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};
#endif
