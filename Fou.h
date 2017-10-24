#if !defined Fou_h
#define Fou_h
#include "Echiquier.h"
#include "Piece.h"

class Fou : virtual public Piece
{
public:
  Fou();
  Fou(bool white, bool left);
  Fou(int x,int y,bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif

