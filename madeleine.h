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
    Madeleine();
    Madeleine(Madeleine *madeleine_parent);

    int somme();
    Madeleine(Madeleine *madeleine_pere, Madeleine *madeleine_mere);//, float difference);
    QString toString();
    int getValueClient(QString client);
    int get_ingredient(int index);
    int getValue();
    void mutation();

    static int m_nombreIngredient;
};

#endif // MADELEINE_H
