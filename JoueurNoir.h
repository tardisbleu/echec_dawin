#ifndef JoueurNoir_h
#define JoueurNoir_h
#include "Joueur.h"

class JoueurNoir : public Joueur {
public:
        JoueurNoir();
        ~JoueurNoir();

        bool isWhite();
        bool isBlack();
};

#endif
