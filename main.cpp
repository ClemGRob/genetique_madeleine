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
    /*
    Madeleine *a = new Madeleine();
    cout<<a->getValue()<<"  "<<a->toString()<<"\n";
    Madeleine *z = new Madeleine();
    cout<<z->getValue()<<"  "<<z->toString()<<"\n";
    Madeleine *b = new Madeleine(a, z);
    cout<<b->getValue()<<"  "<<b->toString()<<"\n";
   // Madeleine c;
    //cout<<c.getValue()<<"  "<<c.toString()<<"\n";
*/

    /*
    test individu
    */
/*
    Individu *a= new Individu();
    cout<<"\n"<<a->getValue()<<"  "<<a->toString()<<"\n";
    Individu *b = new Individu(a);
    cout<<"\n"<<b->getValue()<<"  "<<b->toString()<<"\n";
    b->mutation();

    cout<<"\n"<<a->getValue()<<"  "<<a->toString()<<"\n";

    cout<<"\n"<<b->getValue()<<"  "<<b->toString()<<"\n";
*/


    Population p;
    p.run();




}
