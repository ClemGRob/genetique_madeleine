#include "madeleine.h"
#include "client.h"
#include "parametres.h"
#include "qstd.h"
using namespace qstd;


Madeleine::Madeleine(int lait, int sucre, int beurre, int oeuf, int farinne)
{
    m_ingrediant[0]=sucre;
    m_ingrediant[1]=farinne;
    m_ingrediant[2]=oeuf;
    m_ingrediant[3]=lait;
    m_ingrediant[4]=beurre;
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
            *m_ingrediant[indice];
    cout<<Client::c_preference[indice][i]<<" "<<Client::c_importanceClient[indice]<<" "<<m_ingrediant[indice]<<endl;
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
        cout<<client<<" : "<<ajout<<endl;
    }
    return valeur;
}



