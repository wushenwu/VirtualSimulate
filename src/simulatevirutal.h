/************************************************************************/
/* C++(����virtual)ģ���麯�������ֳ���̬�ԣ�
дһ����Person, ��sayHello��sayGoodbye����
��һ����Student, ��Ҳ���Լ���sayHello, sayGoodbye����
  
����������������뺯��vsayHello, vsayGoodbye����
�����ֳ�����Ķ�̬��(�ֱ�����Լ��Ķ�Ӧ��sayHello��sayGoodbye)
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
    static int pfntable[2];   //����ָ�������Ÿú�����ָ�롣Ϊ�����������
    
protected:
    int *m_ppfn;            //ÿ������һ��ָ����ָ����ָ��
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
    static int pfntable[2]; //ÿ���඼��������ĺ���ָ���
};


#endif