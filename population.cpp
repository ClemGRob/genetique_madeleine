#include "population.h"
#include "parametres.h"
#include "individu.h"
#include "qstd.h"
#include <stdlib.h>

Individu *Population::selection()
{
    int totalRanks = Parametres::nbreIndividus*(Parametres::nbreIndividus+1)/2;
    int rand=Parametres::randomGenerator->get(totalRanks);
    int indIndex=0;
    int nbParts = Parametres::nbreIndividus;
    int totalParts=0;
    while(totalParts<rand) {
        indIndex++;
        totalParts+=nbParts;
        nbParts--;
    }
    return m_population.at(indIndex);
}



Population::Population()
{
    for(int i=0; i<Parametres::nbreIndividus; i++)
        m_population.append(new Individu);
}

void Population::run()
{
    for(int i =0; i<Parametres::nbreGenerations; i++){
        foreach (Individu *ind, m_population)
        {
            int a = ind->evalue();
            if(a==0)
            {
                qstd::cout<<"bon pour : "<<i<<endl;
                exit(1);
            }

        }
        qstd::cout<<i<<endl;
        qstd::cout<<m_population.at(0)->toString()<<endl;
        // tri
        std::sort(m_population.begin(), m_population.end(), Individu::triAptitude);

        //Parametres::print("Affichage apres evaluation et tri : ",1);
        //foreach (Individu *ind, m_population) Parametres::print(ind->toString(),1);

        Individu *meilleur = m_population.at(0);
        //  Parametres::print("On stocke l'alpha dans une nouvelle generation : "+meilleur->toString(),2);
        QList<Individu *> nouvelleGeneration;
        nouvelleGeneration.append(meilleur);
        // pour les n-1 autres, on en choisit 1 par roulette biaisée
        for(int i=1;i<Parametres::nbreIndividus-1;i++)
        {
            if(i%2==0)
            {
                Individu *sel = selection();
                Individu *enfant = new Individu(sel);
                m_population.removeOne(sel);
                m_population.append(enfant);
            }
            else
            {
                Individu *sel1 = selection();
                Individu *sel2 = selection();
                Individu *enfant = new Individu(sel1, sel2);
                m_population.removeOne(sel1);
                m_population.append(enfant);
            }
            //Parametres::print("\tIl devient "+enfant->toString(),2);
        }
    }
}
