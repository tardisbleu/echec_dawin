//Savoir si le roi adverse est en echec
bool adversaireEnEchec(Echiquier &e,bool AJoueurBlanc) {
    bool trouverRoi = false;
    int xTest = 1;
    int yTest = 1;
    while(!trouverRoi && (xTest <= 8 && yTest <= 8)) {
        if(dynamic_cast<Roi*>(e.getPiece(xTest,yTest)) && (AJoueurBlanc == !e.getPiece(xTest,yTest)->isWhite() || !AJoueurBlanc == e.getPiece(xTest,yTest)->isWhite())) {
            trouverRoi = !trouverRoi;
            Roi* r = dynamic_cast<Roi*>(e.getPiece(xTest,yTest));
            //Demande au roi si il est en echec
            if(r->isEchec(e)) {
                if(AJoueurBlanc) {
                    std::cout << " /!\\ ATTENTION : Roi noir en echec  /!\\ " << std::endl;
                } else {
                    std::cout << " /!\\ ATTENTION : Roi blanc en echec  /!\\ " << std::endl;
                }
                return true;
            }
        }
        if(xTest == 8) {
            yTest++;
            xTest = 0;
        }
        xTest++;

    }
    return false;
}

//Savoir si un joueur est en echec et mat
//Pas fonctionnelle
/**<
bool estEnEchecEtMat(Echiquier &e,bool AJoueurBlanc) {
    bool echecEtMat = true;
    int x = 1;
    int y = 1;
    int xDep;
    int yDep;
    Echiquier* eClone;
    bool valide = false;
    //Parcours d'échiquier pour trouver un piéce
    while((x <= 8 && y <= 8) || !echecEtMat) {
        //Clone l'échiquier pour tester un déplacement
        eClone = new Echiquier(e);
        Piece *pi = eClone->getPiece(x, y);
        //Si y'a une piéce
        if(pi) {
            //et que la piéce est de la couleur du joueur
            if(pi->isWhite() == AJoueurBlanc) {
                xDep = 1;
                yDep = 1;
                //Parcours d'échiquier pour le déplacement de la piéce
                while((xDep <= 8 && yDep <= 8) || !echecEtMat) {
                    eClone = new Echiquier(e);
                    Roi *r = dynamic_cast<Roi*>(pi);
                    Pion *p = dynamic_cast<Pion*>(pi);
                    Fou *f = dynamic_cast<Fou*>(pi);
                    Cavalier *c = dynamic_cast<Cavalier*>(pi);
                    Reine *re = dynamic_cast<Reine*>(pi);
                    Tour *t = dynamic_cast<Tour*>(pi);
                    if(r)
                        valide = (r->mouvementValide(*eClone, xDep, yDep));

                    if(p)
                        valide = (p->mouvementValide(*eClone, xDep, yDep));

                    if(f)
                        valide = (f->mouvementValide(*eClone, xDep, yDep));

                    if(c)
                        valide = (c->mouvementValide(*eClone, xDep, yDep));

                    if(re)
                        valide = (re->mouvementValide(*eClone, xDep, yDep));

                    if(t)
                        valide = (t->mouvementValide(*eClone, xDep, yDep));
                    //Si le mouvement est valide
                    if(valide) {
                        if(eClone->getPiece(xDep,yDep) != NULL) {
                            eClone->enleverPiece(xDep,yDep);
                        }
                        eClone->deplacer(eClone->getPiece(x,y),xDep,yDep);
                        //Si le joueur n'est plus en echec aprés ce déplacement
                        if(!(adversaireEnEchec(*eClone,AJoueurBlanc))) {
                            echecEtMat = !echecEtMat;
                        }
                    }
                    if(xDep == 8) {
                        yDep++;
                        xDep = 0;
                    }
                    xDep++;
                    valide = false;
                }
            }
        }
        if(x == 8) {
            y++;
            x = 0;
        }
        x++;
    }
    return echecEtMat;
}
*/

//Test si les coordonnées x et y sont dans l'echiquier
bool danslEchiquier(int x,int y) {
    if((x>=1) && (x<=8) && (y>=1) && (y<=8)) {
        return true;
    }
    return false;
}

//Affiche une ligne sur le terminal
void afficherLigne() {
    std::cout << "_______________________________________________________________" << std::endl;
}

//Promotion d'un pion qui arrive en (Joueur blanc y=1) ou (Joueur noir y=8) en reine,tour,fou,cavalier
//L'utilisateur ecrit le type de piéce (r,t,f,c)
//Création de la piéce
void promotion(int xPiece,int yPiece,bool AJoueurBlanc,Echiquier &e) {
    if(dynamic_cast<Pion*>(e.getPiece(xPiece,yPiece))) {
        if( (AJoueurBlanc && yPiece == 8) || (!AJoueurBlanc && yPiece == 1)) {
            bool typePieceOk = false;
            char typePiece = 'a';
            while(!typePieceOk) {
                std::cout << "Quel type de piéce voulez vous ? Reine : r / Tour : t / Fou : f / Cavalier : c" << std::endl;
                std::cin >> typePiece;
                if(typePiece == 'r' || typePiece == 't' ||typePiece == 'f' ||typePiece == 'c' ) {
                    typePieceOk = !typePieceOk;
                    e.enleverPiece(xPiece,yPiece);
                }
            }
            switch(typePiece) {
            case 'r': {
                Reine *r = new Reine(xPiece,yPiece,AJoueurBlanc);
                e.placer(r);
                break;
            }
            case 't': {
                Tour *t = new Tour(xPiece,yPiece,AJoueurBlanc);
                e.placer(t);
                break;
            }
            case 'f': {
                Fou *f = new Fou(xPiece,yPiece,AJoueurBlanc);
                e.placer(f);
                break;
            }
            default: {
                Cavalier *c = new Cavalier(xPiece,yPiece,AJoueurBlanc);
                e.placer(c);
            }
            }
        }
    }
}

