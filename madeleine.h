#ifndef MADELEINE_H
#define MADELEINE_H

#include "parametres.h"
#include <QString>

class Madeleine
{
private:
    int m_ingrediant[5];
/*
    int m_sucre;
    int m_farinne;
    int m_oeuf;
    int m_lait;
    int m_beurre;*/
public:
    Madeleine(int lait, int sucre, int beurre, int oeuf, int farrine);
    QString toString();
    int getValueClient(QString client);
    int getValue
};

#endif // MADELEINE_H
