#include "madeleine.h"
#include "client.h"
#include "parametres.h"
#include "qstd.h"
using namespace qstd;

int Madeleine::m_nombreIngredient=5;

Madeleine::Madeleine(int lait, int sucre, int beurre, int oeuf, int farinne)
{
    m_ingredient[0]=sucre;
    m_ingredient[1]=farinne;
    m_ingredient[2]=oeuf;
    m_ingredient[3]=lait;
    m_ingredient[4]=beurre;
}

Madeleine::Madeleine()
{
    for (int i = 0; i<5; i++)m_ingredient[i]=MyRandom::get(15)+5;

    int somme =-100;
    for(int i =0; i<Madeleine::m_nombreIngredient; i++)somme +=m_ingredient[i];

    cout<<"la somme "<<somme<<"  valeur repere "<<somme/Madeleine::m_nombreIngredient<<"\n";
    cout<<"la composition : \n";
    cout<<m_ingredient[0]<<" "<<m_ingredient[1]<<" "<<m_ingredient[2]<<" "<<m_ingredient[3]<<" "<<m_ingredient[4]<<" ";

    for(int j =0; j<-1*somme/Madeleine::m_nombreIngredient; j++)
        for(int k = 0; k<Madeleine::m_nombreIngredient; k++)
            m_ingredient[k]+=1;
    for(int j =0; j<-1*somme%Madeleine::m_nombreIngredient; j++)m_ingredient[j]+=1;

}

Madeleine::Madeleine(Madeleine *madeleine_parent)
{

}

int Madeleine::getValueClient(QString client)
{
    int retour = 0;
    int indice = 0;
    if(client=="enfant") indice = 0;
    else if(client=="ado") indice = 1;
    else if(client=="adulte") indice = 2;
    else if(client=="vieux") indice = 3;
    for(int i = 0; i<5; i++)
    {
        retour += Client::c_preference[indice][i]
                *Client::c_importanceClient[indice]
                *m_ingredient[i];
    }
    return retour;
}
int Madeleine::getValue()
{
    int valeur = 0;
    foreach(QString client, Client::c_categorie)
    {
        int ajout =getValueClient(client);
        valeur += ajout;
    }
    return valeur;
}


void Madeleine::mutation()
{

    int variation = MyRandom::get(10)+1;
    int ingredient1=0;
    int ingredient2=0;
    cout<<"mutation\n";

    while(ingredient1==ingredient2 || (m_ingredient[ingredient2]-variation)<5 || (m_ingredient[ingredient1]+variation)>60)
    {
        variation = MyRandom::get(10)+1;
        ingredient1=MyRandom::get(5);
        ingredient2=MyRandom::get(5);
    }
    m_ingredient[ingredient1]+=variation;
    m_ingredient[ingredient2]-=variation;

}


QString Madeleine::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"ingredient"<<" : [";
    for(int i = 0; i <5; i++)
    {

        buf<<m_ingredient[i];
        if(i!=4) buf<<", ";
    }

    buf<<"]";
    return res;

}

