#include <iostream>
#include "JoueurBlanc.h"
using namespace std;

JoueurBlanc::JoueurBlanc() {
    init(true);
}

JoueurBlanc::~JoueurBlanc()
{
    //cout << "Destruction de joueur blanc " << endl;
}

bool
JoueurBlanc::isWhite()
{
    return true;
}

bool
JoueurBlanc::isBlack()
{
    return false;
}
