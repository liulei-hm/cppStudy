//
// Created by liulei on 2023/4/17.
//
#include "all.h"

class Parent    // ������
{
public:
    Parent(){

    }

    void print(){
        std::cout << "parent" << std::endl;
    }

};

class Child : public Parent // ������
{
public:
    Child():Parent(){

    }

    void print(){
        std::cout << "child" << std::endl;
        //Parent::print(); // ������ø���ӿ�
    }
};

int main()
{
    Child *a = new Child();
    a->print();    //������

    Parent *b = new Child();
    b->print();    //������
    static_cast<Child*>(b)->print();  //������

    Child *c = new Child(); // ʵ��������
    c->print();         // �������ຯ��
    c->Parent::print(); // ���ø��ຯ��
    return 0;
}
