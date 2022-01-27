#include <QCoreApplication>
#include "madeleine.h"
#include "qstd.h"
using namespace qstd;
int main()
{

    Madeleine a(10,20,30,20,20);
    cout<<a.getValue()<<"\n"<<"\n";
    Madeleine b(30,10,30,10,20);
    cout<<b.getValue()<<"\n";
    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";

    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";

    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";

    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";
    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";
    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";
    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";
    a.mutation();
    cout<<a.getValue()<<"  "<<a.toString()<<"\n";


}
