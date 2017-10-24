#include <iostream>
#include "JoueurNoir.h"
using namespace std;

JoueurNoir::JoueurNoir() {
    init(false);
}

JoueurNoir::~JoueurNoir()
{
    //cout << "Destruction de joueur noir " << endl;
}

bool
JoueurNoir::isWhite()
{
    return false;
}

bool
JoueurNoir::isBlack()
{
    return true;
}
