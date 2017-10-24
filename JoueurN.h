#ifndef JOUEURN_H_INCLUDED
#define JOUEURN_H_INCLUDED

class JoueurNoir : public Joueur {
public:
        JoueurNoir();
        ~JoueurNoir();

        bool isWhite();
        bool isBlack();
};

#endif // JOUEURN_H_INCLUDED
