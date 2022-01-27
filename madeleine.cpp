#include "madeleine.h"
#include "client.h"
#include "parametres.h"
#include "qstd.h"
using namespace qstd;


Madeleine::Madeleine(int lait, int sucre, int beurre, int oeuf, int farinne)
{
    m_ingredient[0]=sucre;
    m_ingredient[1]=farinne;
    m_ingredient[2]=oeuf;
    m_ingredient[3]=lait;
    m_ingredient[4]=beurre;
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
    float chanceMutation = MyRandom::getFloat();
    if(chanceMutation> 0.7)
    {
        int variation = MyRandom::get(10)+1;
        int ingredient1=0;
        int ingredient2=0;

        while(ingredient1==ingredient2 || (m_ingredient[ingredient1]+variation)<0 || (m_ingredient[ingredient1]-variation)<0)
        {
            ingredient1=MyRandom::get(5);
            ingredient2=MyRandom::get(5);
        }
        m_ingredient[ingredient1]+=variation;
        m_ingredient[ingredient2]-=variation;
    }
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

