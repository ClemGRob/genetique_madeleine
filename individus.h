#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "parametres.h"
#include <QString>

class Individu
{
private:
    int m_genome[NBREDES];
    int m_aptitude=-1;
    void mutation();
public:
    Individu();
    Individu(Individu *p);
    Individu(Individu *p, Individu *m);

    int evalue();
    static bool triAptitude(Individu *i1, Individu *i2);
    QString toString();
};

#endif // INDIVIDU_H
