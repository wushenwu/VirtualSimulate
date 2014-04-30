/************************************************************************/
/* C++(不用virtual)模拟虚函数来表现出多态性：
写一基类Person, 有sayHello，sayGoodbye函数
有一子类Student, 它也有自己的sayHello, sayGoodbye函数
  
请在这两个类里加入函数vsayHello, vsayGoodbye函数
来表现出对象的多态性(分别调用自己的对应的sayHello和sayGoodbye)
*/
/************************************************************************/
#ifndef SIMULATE_H_810BC488_4927_4dc6_A312_572BBF49A25F

#define SIMULATE_H_810BC488_4927_4dc6_A312_572BBF49A25F

class CPerson
{
public:
    CPerson();

    void SayHello(void);
    void SayGoodBye(void);
    
    void vSayHello(void);
    void vSayGoodBye(void);

private:
    void Init(void);
    static int pfntable[2];   //函数指针表，存放着该函数的指针。为类对象所共享
    
protected:
    int *m_ppfn;            //每对象都有一个指向函数指针表的指针
};

class CStudent: public CPerson
{
public:
    CStudent();

    void SayHello(void);
    void SayGoodBye(void);

    void vSayHello(void);
    void vSayGoodBye(void);

private:
    void Init(void);
    static int pfntable[2]; //每个类都有其独立的函数指针表
};


#endif