//
// Created by liulei on 2023/3/16.
//
#include "all.h"
#if 0
/*左值引用实例*/
int a=10;              //非常量左值（有确定存储地址，也有变量名）
const int a1=10;       //常量左值（有确定存储地址，也有变量名）
const int a2=20;       //常量左值（有确定存储地址，也有变量名）

//非常量左值引用
int &b1=a;            //正确，a是一个非常量左值，可以被非常量左值引用绑定
int &b2=a1;           //错误,a1是一个常量左值，不可以被非常量左值引用绑定
int &b3=10;           //错误，10是一个非常量右值，不可以被非常量左值引用绑定
int &b4=a1+a2;        //错误,（a1+a2）是一个常量右值，不可以被非常量左值引用绑定

//常量左值引用
const int &c1=a;      //正确，a是一个非常量左值，可以被非常量右值引用绑定
const int &c2=a1;     //正确,a1是一个常量左值，可以被非常量右值引用绑定
const int &c3=a+a1;   //正确，（a+a1）是一个非常量右值，可以被常量右值引用绑定
const int &c4=a1+a2;  //正确,（a1+a2）是一个常量右值，可以被非常量右值引用绑定


/*右值引用实例*/
int a=10;             //非常量左值（有确定存储地址，也有变量名）
const int a1=20;      //常量左值（有确定存储地址，也有变量名）
const int a2=20;      //常量左值（有确定存储地址，也有变量名）

//非常量右值引用
int &&b1=a;            //错误，a是一个非常量左值，不可以被非常量右值引用绑定
int &&b2=a1;           //错误,a1是一个常量左值，不可以被非常量右值引用绑定
int &&b3=10;           //正确，10是一个非常量右值，可以被非常量右值引用绑定
int &&b4=a1+a2;        //错误,（a1+a2）是一个常量右值，不可以被非常量右值引用绑定

//常量右值引用
const int &&c1=a;      //错误，a是一个非常量左值，不可以被常量右值引用绑定
const int &&c2=a1;     //错误,a1是一个常量左值，不可以被常量右值引用绑定
const int &&c3=a+a1;   //正确，（a+a1）是一个非常量右值，可以被常量右值引用绑定
const int &&c4=a1+a2;  //正确,（a1+a2）是一个常量右值，不可以被常量右值引用绑定

/*move实例,C++11中提供了一个标准库move函数获得绑定到左值上的右值引用，
 * 即直接调用std::move告诉编译器将左值像对待同类型右值一样处理，
 * 但是被调用后的左值将不能再被使用。*/
int a=10;                 //非常量左值（有确定存储地址，也有变量名）
const int a1=20;          //常量左值（有确定存储地址，也有变量名）

//非常量右值引用
int &&d1=std::move(a);    //正确，将非常量左值a转换为非常量右值，可以被非常量右值引用绑定
int &&d2=std::move(a1);    //错误,将常量左值a1转换为常量右值，不可以被非常量右值引用绑定

//常量右值引用
const int &&c1=std::move(a);      //正确，将非常量左值a转换为非常量右值，可以被常量右值引用绑定
const int &&c2=std::move(a1);     //正确,将常量左值a1转换为常量右值，可以被常量右值引用绑定

#endif

#if 0 //如果不使用右值引用 大量构造和析构A  https://blog.csdn.net/caojianfa969/article/details/118927852
class A
{
public:
    A(size_t N):m_p(new char[N])
    {
        cout << "A:construct" << endl;
    }
    A(const A & a)
    {
        cout << "A:construct1" << endl;
        if (this != &a)
        {
            delete[]m_p;
            m_p = new char[strlen(m_p) + 1];
            memcpy(m_p, a.m_p, strlen(m_p) + 1);
        }
    }
    ~A()
    {
        cout << "A:destruct1" << endl;
        delete []m_p;
    }

public:
    char *m_p = nullptr;
};

A createA(size_t N)
{
    return A(N);
}

#endif

class A
{
public:
    A(size_t N):m_p(new char[N])
    {
    }
    ~A()
    {
        delete []m_p;
    }

public:
    char *m_p = nullptr;
};

A&& createA(size_t N)
{
    return (A&&)A(100);
}

void func(A a)
{

}

int main()
{
    int iLV1 = 100;
    int && pLV2 = iLV1 + 100;   //pLV2是右值引用，右值(iLV1 + 100)作为临时变量绑定到pLV2
    cout << pLV2 << endl;


    func(createA(100));

    return 0;
}

