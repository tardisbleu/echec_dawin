#ifndef JoueurBlanc_h
#define JoueurBlanc_h
#include "Joueur.h"

class JoueurBlanc : public Joueur {
public:
        JoueurBlanc();
        ~JoueurBlanc();

        bool isWhite();
        bool isBlack();
};

#endif
