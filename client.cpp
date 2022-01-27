#include "client.h"

QList<QString> Client::c_categorie={"enfant", "ado", "adulte", "vieux"};
    //enfant, adulte, vieux, ado


//int Client::c_ingredient[5]={ "sucre", "farinne", "oeuf", "lait",  "beurre"};

int c_preference[4][5]=
{
    {40, 15, 10, 15, 20},//enfant
    {30, 15, 15, 15, 25}, //ado
    {15, 30, 20, 25, 20}, //adulte
    {10, 35, 15, 15, 25}  // vieux
};
