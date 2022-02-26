#include "madeleine.h"
#include "client.h"
#include "parametres.h"
#include "qstd.h"
using namespace qstd;

int Madeleine::m_nombreIngredient=5;

int Madeleine::somme()
{
    int retour = 0;
    for(int i = 0; i < 5 ; i ++)retour +=m_ingredient[i];
    return retour;
}

Madeleine::Madeleine(int lait, int sucre, int beurre, int oeuf, int farinne)
{
    m_ingredient[0]=sucre;
    m_ingredient[1]=farinne;
    m_ingredient[2]=oeuf;
    m_ingredient[3]=lait;
    m_ingredient[4]=beurre;

}

int Madeleine::get_ingredient(int index)
{
    if(index < 5 && index >-1)return m_ingredient[index];
    return 0;
}
Madeleine::Madeleine()
{

    for (int i = 0; i<5; i++)m_ingredient[i]=MyRandom::get(15)+5;


    int i = 0;
    while(somme() < 100)
    {
        m_ingredient[i]+=1;
        i++;
        if(i==5)i = 0;
    }
    while(somme() > 100)
    {
        m_ingredient[i]-=1;
        i++;
        if(i==5)i = 0;
    }



}

Madeleine::Madeleine(Madeleine *madeleine_parent)
{


    for (int i = 0; i<5; i++)
    {
        m_ingredient[i]=madeleine_parent->m_ingredient[i];
    }
        /*m_ingredient[0]=madeleine_parent->m_ingredient[0];
    qstd::cout<<"a"<<endl;
    m_ingredient[1]=madeleine_parent->m_ingredient[1];
    qstd::cout<<"a"<<endl;
    m_ingredient[2]=madeleine_parent->m_ingredient[2];
    qstd::cout<<"a"<<endl;
    m_ingredient[3]=madeleine_parent->m_ingredient[3];
    qstd::cout<<"a"<<endl;
    m_ingredient[4]=madeleine_parent->m_ingredient[4];*/
}



Madeleine::Madeleine(Madeleine *madeleine_pere, Madeleine *madeleine_mere)
{
    float myrandfloat = 0;//MyRandom::getFloat();
    while (myrandfloat > 0.8 || myrandfloat < 0.2)myrandfloat = MyRandom::getFloat();
    for(int i = 0; i<5; i++)m_ingredient[i]=(madeleine_pere->m_ingredient[i]*myrandfloat)+(madeleine_mere->m_ingredient[i]*(1-myrandfloat));


    // armonisation
    int i = 0;
    //int s = somme();
    while(somme() < 100)
    {
        m_ingredient[i]+=1;
        i++;
        if(i==5)i = 0;
    }
    while(somme() > 100)
    {
        m_ingredient[i]-=1;
        i++;
        if(i==5)i = 0;
    }

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

    while(ingredient1==ingredient2 || (m_ingredient[ingredient2]-variation)<10 || (m_ingredient[ingredient1]+variation)>50)
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

