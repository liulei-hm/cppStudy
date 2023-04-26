//
// Created by liulei on 2023/4/14.
//
#include <iostream>

using namespace std;
class Light_Copy
{
public:
    int *p;
    Light_Copy()
    {
        p=new int(4);
        cout << "Light_Copy default constructor" << endl;
    };
    ~Light_Copy(){ delete p; };
};

class Deep_Copy
{
public:
    int *p;
    Deep_Copy()
    {
        p=new int(4);
        cout << "Deep_Copy default constructor" << endl;
    };
    Deep_Copy(const Deep_Copy &t)
    {
        p = new int;
        *(p) = *(t.p);//为对象分配新的内存，并使用源对象中的值进行重新构造
        cout << "Deep_Copy copy constructor" << endl;
    }
    ~Deep_Copy(){ delete p; };
};

void test_copy(){
    /**默认拷贝构造函数 浅拷贝 析构时造成内存重复释放,出错****/
    //Light_Copy t1;//默认构造函数构造对象t1
    //Light_Copy t2(t1);//因为没有拷贝构造函数，调用默认复制构造函数(浅拷贝)，此时t1.p与t2.p指针指向同一地址
    //Light_Copy t3 = t1;//因为没有拷贝构造函数，调用默认复制构造函数(浅拷贝)，此时t1.p、t2.p与t3.p指针指向同一地址

    /**拷贝构造函数 深拷贝 ****/
    Deep_Copy t4;
    Deep_Copy t5(t4);  //有拷贝构造函数
    Deep_Copy t6 = t4; //有拷贝构造函数
}

//测试时最好在cmake中关闭编译器优化
int main(){
    test_copy();
    return 0;
}
