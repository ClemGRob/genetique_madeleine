#include "myrandom.h"
#include <QDateTime>

MyRandom::MyRandom(int seed)
{
    srand(seed);
}

int MyRandom::get(int max)
{
    return rand()%max;
}

double MyRandom::getFloat()
{
    return (rand()%1001)/1000.0;
}
