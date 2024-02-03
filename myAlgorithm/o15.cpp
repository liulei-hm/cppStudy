//
// Created by liulei on 2023/5/11.
//
#include <bits/stdc++.h>
using namespace std;
class A{
public:
    void func(){
        cout << "func->A" << endl;
    }
    virtual void do_sth() const{
        cout << "A" << endl;
    };
};

class B:public A{
public:
    void func(){
        cout << "func->B" << endl;
    }
    void do_sth() const{
        cout << "B" << endl;
    };
};

void fun1(A a)
{
    a.do_sth();
}
void fun2(const A &a){
    a.do_sth();
}
void fun3(const A *a){
    a->do_sth();
}
int main(){
    B b;
    A *pa = &b;
    //pa->do_sth(); A
    fun1(b); //A
    fun2(b); //B
    fun3(&b);//B
    dynamic_cast<B *>(pa)->func();
    char *str[3] = {"dd","ddf","sad"};
    char *pstr = str[0];
    return 0;
}
