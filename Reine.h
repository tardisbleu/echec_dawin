#if !defined Reine_h
#define Reine_h
#include "Echiquier.h"
#include "Piece.h"
#include "Fou.h"
#include "Tour.h"

class Reine : public Fou, public Tour
{
public:
  Reine(bool white);
  Reine(int x,int y,bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};
#endif

