#include "parametres.h"
#include "qstd.h"
using namespace qstd;

int Parametres::nbreIndividus=50;
float Parametres::tauxMutation=0.3;
int Parametres::nbreGenerations=500;
int Parametres::aptitudeMin=0;

//int Parametres::debug=2;
MyRandom *Parametres::randomGenerator=new MyRandom(0);
/*
void Parametres::print(QString txt, int d)
{
    if(d<=debug)
        cout<<txt<<endl;
}
*/
