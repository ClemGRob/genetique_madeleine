#include "client.h"

QList<QString> Client::c_categorie={"enfant", "ado", "adulte", "vieux"};
    //enfant, adulte, vieux, ado


//QList<QString> Client::c_ingredient[5]={ "sucre", "farinne", "oeuf", "lait",  "beurre"};
int Client::c_importanceClient[4]={35,15,30,20};
int Client::c_preference[4][5]=
{
    {30, 10, 10, 30, 20},//enfant
    {25, 15, 30, 15, 25}, //ado
    {15, 30, 20, 25, 20}, //adulte
    {10, 25, 15, 10, 40}  // vieux
};
