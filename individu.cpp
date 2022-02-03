#include "individu.h"
#include "parametres.h"
#include <QTextStream>




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
    return i1->evalue() < i2->evalue();
}
int Individu::getValue()
{
    return madeleine->getValue();
}
int Individu::evalue()
{
    return 0;
}

Individu::Individu()
{
    for(int i=0;i<NBREDES;i++) {
        m_genome[i]=1+Parametres::randomGenerator->get(NBREDES);
    }
   // mutation();
}

Individu::Individu(Individu *p)
{
    for(int i=0;i<NBREDES;i++) {
        m_genome[i]=p->m_genome[i];
    }
    mutation();
}

Individu::Individu(Individu *p, Individu *m)
{

    int position=Parametres::randomGenerator->get(NBREDES);
    for(int i =0; i<position; i++)m_genome[i]=p->m_genome[i];
    for(int i =position; i<6; i++)m_genome[i]=m->m_genome[i];
    mutation();
}


QString Individu::toString()
{
    QString res;
    QTextStream buf(&res);
    return res;
}

