#include <QCoreApplication>
#include "madeleine.h"
#include "individu.h"
#include "population.h"
#include "qstd.h"
using namespace qstd;
void testIndividus() {
    Individu i1, i2;
    i1.evalue();
    i2.evalue();
    Parametres::print(i1.toString(), 1);
    Parametres::print(i2.toString(), 1);
}



int main()
{
    /*
    test madeleine
    */
    /*Madeleine a;
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";
    Madeleine z;
    cout<<z.getValue()<<"  "<<z.toString()<<"\n";
    Madeleine b;
    cout<<b.getValue()<<"  "<<b.toString()<<"\n";
    Madeleine c;
    cout<<c.getValue()<<"  "<<c.toString()<<"\n";
    */

    /*
    test individu
    */
    /*
    Individu a;
    cout<<"\n"<<a. getValue()<<"  "<<a.toString()<<"\n";
    Individu b(a);
    cout<<"\n"<<b. getValue()<<"  "<<b.toString()<<"\n";
    */

    Population p;
    p.run();



}
