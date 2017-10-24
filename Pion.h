#if !defined Pion_h
#define Pion_h
#include "Echiquier.h"
#include "Piece.h"


class Pion : public Piece
{
public:
  Pion(int x, bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif
