#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QString>
#include "myrandom.h"

#define NBREDES 6

class Parametres
{
public:
    static int nbreIndividus;
    static float tauxMutation;
    static int nbreGenerations;
    static int aptitudeMin;
    static int debug;
    static void print(QString txt, int d);
    static MyRandom *randomGenerator;
    static MyRandom *getFloat;
};

#endif // PARAMETRES_H
