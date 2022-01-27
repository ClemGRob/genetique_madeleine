#ifndef MADELEINE_H
#define MADELEINE_H

#include "parametres.h"
#include <QString>

class Madeleine
{
private:
    int sucre;
    int farinne;
    int oeuf;
    int lait;
    int beurre;
public:
    Madeleine();
    QString toString();
};

#endif // MADELEINE_H
