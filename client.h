#ifndef CLIENT_H
#define CLIENT_H

#include "QList"
# include "QString"

class Client
{
public:

    static QList<QString> c_categorie;
    //enfant, adulte, vieux, ado

    static int c_ingredient[5];
    /* sucre farinne oeuf lait  beurre;*/


    static int c_preference[4][5];

    static int quantiteIndividu[4];

};

#endif // CLIENT_H
