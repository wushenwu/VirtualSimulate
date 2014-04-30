#include <iostream>

#include "simulatevirutal.h"

void
SayHello(CPerson *pobj)
{
    pobj->vSayHello();
}

void 
SayGoodBye(CPerson *pobj)
{
    pobj->vSayGoodBye();
}

void
test_hello(void)
{
    CPerson *personobj = NULL;

    personobj = new CPerson;
    SayHello(personobj);
    SayGoodBye(personobj);

    personobj = new CStudent;
    SayHello(personobj);
    SayGoodBye(personobj);

    if (personobj != NULL)
    {
        delete personobj;
        personobj = NULL;
    }   
}

int
main(void)
{
    test_hello();

    return 0;
}