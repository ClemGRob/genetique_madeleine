#ifndef POPULATION_H
#define POPULATION_H
#include "individu.h"
#include <QList>

class Population
{
private:
    Individu *selection();
    QList<Individu *> m_population;
public:
    Population();
    void run();
    QString toString();
};

#endif // POPULATION_H
