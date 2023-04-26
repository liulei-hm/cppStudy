//
// Created by liulei on 2023/2/7.
//
#include "all.h"

class Animal{
public:
    string name;
public:
    virtual void bark(){
        cout << "animall" << endl;
    }
};

class Dog:public Animal{
public:
    virtual void bark(){
        cout << "wang wang" << endl;
    }
};

class Cat:public Animal{   // 必须为共有继承，否则后面调用不到，class默认为私有继承！
public:
    virtual void bark(){
        cout << "miao miao" << endl;
    }
};

typedef void (*pf)();

typedef struct _A{
    pf _f;
}A;

typedef struct _B{
    A _b; ///< 在子类中定义一个基类的对象即可实现对父类的继承。
}B;

void FunA()
{
    printf("%s\n","Base A::fun()");
}

void FunB()
{
    printf("%s\n","Derived B::fun()");
}

int main(){
    Dog dog;
    Cat cat;
    Animal animal;

    Animal* panimal = &animal; //父类指针指向父类对象
    panimal->bark();

    panimal = &cat; //父类指针指向子类对象，多态实现
    panimal->bark();

    A a;
    B b;

    a._f = FunA;
    b._b._f = FunB;

    A *pa = &a;
    pa->_f();
    pa = (A *)&b;   /// 让父类指针指向子类的对象,由于类型不匹配所以要进行强转
    pa->_f();
    return 0;
}