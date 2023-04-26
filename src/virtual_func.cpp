//
// Created by liulei on 2023/3/20.
//

#include "all.h"

class Base {
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
};

class A:Base{
public:
    void f() override{
        cout << "A::f()" << endl;
    };
    void g() override{
        cout << "A::g()" << endl;
    };
};

class B:Base{
public:
    void f() override{
        cout << "B::f()" << endl;
    };
};




int main()
{
    Base b;
    cout << "virtual_table addr:" << (int*)(&b) << endl;
    cout << "virtual_table first_func addr:" << (int*)*(int*)(&b) << endl;

    void (Base::*p)();
    p = &Base::f;
    printf("%p\n", p);
    printf("%p\n", &Base::f);
    cout << sizeof(b) << endl;


}