#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "madeleine.h"
#include "parametres.h"
#include <QString>

class Individu
{
private:
    Madeleine *madeleine;

public:
    void mutation();
    Individu();
    Individu(Individu *p);
    Individu(Individu *p, Individu *m);
    int evalue();
    int getValue();
int m_genome[20];
    static bool triAptitude(Individu *i1, Individu *i2);
    QString toString();
};

#endif // INDIVIDU_H
