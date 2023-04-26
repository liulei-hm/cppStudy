//
// Created by liulei on 2023/3/16.
//
#include "all.h"

#include <stdio.h>

class Base
{
public:
    Base(){}
    virtual ~Base(){
        printf("base delete\n");
    }
};

class A:public Base
{
public:
    A(){}
    ~A(){
        printf("A class delete\n");
    }
};

void test_scope(){   //��������ԣ�����lock_guard������������ʱ
    {
        Base base;
        cout << "1" << endl;
    }
    cout << "2" << endl;
}

void test_virtual(){
    //����Ĺ��캯����virtual ��ӡ A class delete    base delete
    //����Ĺ��캯������virtual ��ӡ  base delete
    //���Բ����������޷���������virtual��Ϊ�˷�ֹ�ڴ�й©
    Base *a = new A();
    delete a;
}

int main()
{

    test_scope();

    return 0;
}