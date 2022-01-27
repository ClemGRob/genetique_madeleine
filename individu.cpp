#include "individu.h"
#include "parametres.h"
#include <QTextStream>




void Individu::mutation()
{
    // si lancé de dé float < taux mutation
    // indice aléatoire dans le génôme
    // à cet emplacement, on retire le dé

    float chanceMtation=MyRandom::getFloat();
    if(chanceMtation>Parametres::tauxMutation)
    {
        int posMutation=Parametres::randomGenerator->get(NBREDES);
        m_genome[posMutation]=1+Parametres::randomGenerator->get(NBREDES);
    }

}
bool Individu::triAptitude(Individu *i1, Individu *i2)
{
    return i1->m_aptitude < i2->m_aptitude;
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
    //mutation
    // indice aléatoire de position dans le génôme
    // boucle pour placer la partie gauche du père
    // boucle pour placer la partie droite de la mère
    // mutation
}

int Individu::evalue()
{
    m_aptitude=0;
    for(int i=0;i<NBREDES;i++)
        m_aptitude += std::abs(m_genome[i]-(i+1));
    return m_aptitude;
}

QString Individu::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<m_aptitude<<" : [";
    for(int i=0;i<NBREDES;i++)
        buf<<m_genome[i]<<", ";
    buf<<"]";
    return res;
}

