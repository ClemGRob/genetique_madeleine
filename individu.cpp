#include "individu.h"
#include "parametres.h"
#include <QTextStream>
#include "qstd.h"
using namespace qstd;



QString Individu::toString()
{
    return madeleine->toString();
}


void Individu::mutation()
{
    float chanceMtation=MyRandom::getFloat();
    if(chanceMtation>Parametres::tauxMutation)
    {
       madeleine->mutation();
    }

}

bool Individu::triAptitude(Individu *i1, Individu *i2)
{
    return i1->evalue() > i2->evalue();
}
int Individu::getValue()
{
    return madeleine->getValue();
}
int Individu::evalue()
{
    return madeleine->getValue();
}

Individu::Individu()
{
    /*for(int i=0;i<NBREDES;i++) {
        m_genome[i]=1+Parametres::randomGenerator->get(NBREDES);
    }*/
   // mutation();

    madeleine = new Madeleine();

}

Individu::Individu(Individu *p)
{

    madeleine = new Madeleine(p->madeleine);

    mutation();
}

Individu::Individu(Individu *p, Individu *m)
{

    madeleine = new Madeleine(p->madeleine, m->madeleine);
    mutation();
}

