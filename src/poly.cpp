//
// Created by liulei on 2023/2/7.
//
#include "all.h"

//多态学习

class Animal{
public:
    string name;
    void func(){
        cout << "animal func" <<endl;
    }
    virtual void age() {
        cout << "animal age" << endl;
    }
    virtual void color() = 0;
    virtual void bark() = 0;
};

class Dog:public Animal{
public:
    void func() {
        cout << "Dog func" <<endl;
    }
    void age() override{
        cout << "Dog age" <<endl;
    }
    virtual void color(){
        cout << "Dog red" << endl;
    }
    virtual void bark(){
        cout << "wang wang" << endl;
    }
};


class Cat:public Animal{   // 必须为共有继承，否则后面调用不到，class默认为私有继承！
public:
    void age(){
        cout << "Cat age" <<endl;
    }
    virtual void color(){
        cout << "Cat red" << endl;
    }
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

    DogDog *dogdog = dynamic_cast<DogDog *>(&dog);
    DogDogDog *dogdogdog = dynamic_cast<DogDogDog *>(&dog);
    //DogDog dogdog* = &dog;
    //Animal animal;
    Cat cat;
    Animal* panimal = &cat; //父类指针指向子类对象，多态实现
    panimal->func();
    panimal->age();
    panimal->bark();
    panimal->name = "cat";

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