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
    {
        m_population.append(new Individu);
    }

    }

/*QString Population::toString()
{
    return madeleine->toString();
}*/


void Population::run()
{
    Individu max =new Individu();
    int iteration_reference;
    for(int i =0; i<Parametres::nbreGenerations; i++){
        qstd::cout<<endl<<i<<" sur "<<Parametres::nbreGenerations<<endl;

        foreach (Individu *ind, m_population)
        {

            //qstd::cout<<ind->toString()<<"    ";
            int a = ind->evalue();
            //qstd::cout<<a<<endl;


        }
        //qstd::cout<<i<<endl;
        qstd::cout<<m_population.at(0)->toString()<<endl;
        // tri
        std::sort(m_population.begin(), m_population.end(), Individu::triAptitude);
        if(max.evalue()<m_population.at(0)->evalue())
        {
            max = m_population.at(0);
            iteration_reference = i;
        }

        //Parametres::print("Affichage apres evaluation et tri : ",1);
        //foreach (Individu *ind, m_population) Parametres::print(ind->toString(),1);

        Individu *meilleur = m_population.at(0);
        //  Parametres::print("On stocke l'alpha dans une nouvelle generation : "+meilleur->toString(),2);
        QList<Individu *> nouvelleGeneration;
        nouvelleGeneration.append(meilleur);
        // pour les n-1 autres, on en choisit 1 par roulette biais
        for(int i=1;i<Parametres::nbreIndividus-1;i++)
        {
            m_population.at(i)->mutation();


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

        }
    }
    qstd::cout<<"la meilleure recette est : "<<max.toString()<<"avec un score de : "<<max.evalue()<<"  à l'iteration : "<<iteration_reference<<endl;

}
