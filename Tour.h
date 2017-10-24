#if !defined Tour_h
#define Tour_h
#include "Echiquier.h"
#include "Piece.h"

class Tour : virtual public Piece
{
public:
  Tour();
  Tour(bool white, bool left);
  Tour(int x,int y,bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};
#endif

