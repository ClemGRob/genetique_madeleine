#ifndef MADELEINE_H
#define MADELEINE_H

#include "parametres.h"
#include <QString>

class Madeleine
{
private:
    int m_ingrediant[5];
public:
    Madeleine(int lait, int sucre, int beurre, int oeuf, int farrine);
    QString toString();
    int getValueClient(QString client);
    int getValue();
};

#endif // MADELEINE_H
