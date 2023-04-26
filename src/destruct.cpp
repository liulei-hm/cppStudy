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

void test_scope(){   //作用域测试：考虑lock_guard析构函数解锁时
    {
        Base base;
        cout << "1" << endl;
    }
    cout << "2" << endl;
}

void test_virtual(){
    //基类的构造函数加virtual 打印 A class delete    base delete
    //基类的构造函数不加virtual 打印  base delete
    //所以不加派生类无法析构，加virtual是为了防止内存泄漏
    Base *a = new A();
    delete a;
}

int main()
{

    test_scope();

    return 0;
}