/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

class Echiquier;

/*
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Piece
{
protected:
  int m_x;
  int m_y;
  bool m_white;

public:
  Piece();
  Piece(int x, int y, bool white);
  Piece(const Piece & p);
  virtual ~Piece();
  Piece & operator=(const Piece & p);

  void init( int x, int y, bool white );
  void move( int x, int y );
  void affiche();
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  virtual bool mouvementValide(Echiquier &e, int x, int y);
  virtual char type();
};

#endif // !defined Piece_h
