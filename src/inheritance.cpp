//
// Created by liulei on 2023/4/17.
//
#include "all.h"

class Parent    // 做父类
{
public:
    Parent(){

    }

    void print(){
        std::cout << "parent" << std::endl;
    }

};

class Child : public Parent // 做子类
{
public:
    Child():Parent(){

    }

    void print(){
        std::cout << "child" << std::endl;
        //Parent::print(); // 这里调用父类接口
    }
};

int main()
{
    Child *a = new Child();
    a->print();    //调子类

    Parent *b = new Child();
    b->print();    //调父类
    static_cast<Child*>(b)->print();  //调子类

    Child *c = new Child(); // 实例化子类
    c->print();         // 调用子类函数
    c->Parent::print(); // 调用父类函数
    return 0;
}
