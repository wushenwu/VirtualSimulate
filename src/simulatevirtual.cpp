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
    //��������ݶ����m_ppfn[x]��������Ӧ�ĳ�Ա������
    //�䵱����ַ� call m_ppfn[x]

    //cout << hex << (int &)m_ppfn[0] << endl;
    typedef void (*PFN)(void);
    PFN pfn = PFN(m_ppfn[0]);   //����õĳ�Ա������ַ��ת��Ϊ��ͨ����ָ�롣
                                //���⣬����ecx(this)δ�����仯�����Բ�����ʽ�Ĵ���
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
    //��Щ�ǲ�����õ�
}

void
CStudent::vSayGoodBye(void)
{
    //cout << hex << (int &)m_ppfn[1] << endl;
    //��Щ�ǲ�����õ�
}



