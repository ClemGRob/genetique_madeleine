#ifndef MADELEINE_H
#define MADELEINE_H

#include "parametres.h"
#include <QString>

class Madeleine
{
private:
    int m_ingredient[5];
public:
    Madeleine(int lait, int sucre, int beurre, int oeuf, int farrine);
    QString toString();
    int getValueClient(QString client);
    int getValue();
    void mutation();

};

#endif // MADELEINE_H
