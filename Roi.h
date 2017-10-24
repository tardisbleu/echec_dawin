#if !defined Roi_h
#define Roi_h
#include "Echiquier.h"
#include "Piece.h"

class Roi : public Piece
{
public:
  Roi(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
  bool isEchec(Echiquier &e);
};
#endif
