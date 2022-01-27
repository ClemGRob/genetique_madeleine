#ifndef CLIENT_H
#define CLIENT_H

#include "QList"
# include "QString"

class Client
{
public:

    static QList<QString> c_categorie;
    //enfant, adulte, vieux, ado

    static QList<QString> c_ingredient[5];
    /* sucre farinne oeuf lait  beurre;*/
    static int c_importanceClient[4];
    static int c_preference[4][5];

};

#endif // CLIENT_H
