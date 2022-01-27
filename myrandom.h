#ifndef MYRANDOM_H
#define MYRANDOM_H


class MyRandom
{
public:
    MyRandom(int seed);
    int get(int max);
    static double getFloat();
};

#endif // MYRANDOM_H
