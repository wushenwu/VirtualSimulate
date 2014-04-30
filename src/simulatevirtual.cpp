#include <iostream>
using namespace std;

#include "simulatevirutal.h"

typedef void (CPerson::*PFNHello)(void);
typedef void (CPerson::*PFNGoodBye)(void);

PFNHello pfnPersonHello = CPerson::SayHello;
PFNGoodBye pfnPersonGoodBye = CPerson::SayGoodBye;

int CPerson::pfntable[2] = {
        //*(int *)&pfnPersonHello,
        (int &)pfnPersonHello,
        (int &)pfnPersonGoodBye
};

CPerson::CPerson()
{
    Init();
}

void
CPerson::Init(void)
{
    m_ppfn = pfntable;
}

void 
CPerson::SayHello(void) 
{ 
    cout << "CPerson SayHello" << endl;
}

void 
CPerson::SayGoodBye(void) 
{ 
    cout << "CPerson SayGoodBye" << endl; 
}

void
CPerson::vSayHello(void)
{
    //在这里，根据对象的m_ppfn[x]来调用相应的成员函数。
    //充当虚表、分发 call m_ppfn[x]

    //cout << hex << (int &)m_ppfn[0] << endl;
    typedef void (*PFN)(void);
    PFN pfn = PFN(m_ppfn[0]);   //将获得的成员函数地址，转化为普通函数指针。
                                //此外，这里ecx(this)未发生变化。所以不用显式的传递
    pfn();
}

void
CPerson::vSayGoodBye(void)
{
    //cout << hex << (int &)m_ppfn[1] << endl;
    typedef void (*PFN)(void);
    PFN pfn = PFN(m_ppfn[1]);
    pfn();
}

//////////////////////////////////////////////////////////////////////////
//CStudent
//////////////////////////////////////////////////////////////////////////
typedef void (CStudent::*PFNStudHello)(void);
typedef void (CStudent::*PFNStudGoodBye)(void);

PFNStudHello pfnStudHello = CStudent::SayHello;
PFNStudGoodBye pfnStudGoodBye = CStudent::SayGoodBye;
int CStudent::pfntable[2] = {
        (int &)pfnStudHello,
        (int &)pfnStudGoodBye
};

CStudent::CStudent()
{
    Init();
}

void
CStudent::Init(void)
{
    m_ppfn = pfntable;
}

void 
CStudent::SayHello(void) 
{ 
    cout << "CStudent SayHello" << endl;
}

void 
CStudent::SayGoodBye(void) 
{ 
    cout << "CStudent SayGoodBye" << endl; 
}

void
CStudent::vSayHello(void)
{
    //cout << hex << (int &)m_ppfn[0] << endl;
    //这些是不会调用的
}

void
CStudent::vSayGoodBye(void)
{
    //cout << hex << (int &)m_ppfn[1] << endl;
    //这些是不会调用的
}



