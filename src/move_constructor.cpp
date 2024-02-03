//
// Created by liulei on 2023/4/13.
//
#include "all.h"

using namespace std;

/* 左值：表示可寻址。是保存在内存中，具有确切地址，并能取地址，进行访问，修改等操作的表达式(变量)。
 *      可以取地址&的值，如变量a,字符串常量"hello",++x,
 *
 * 右值：表示可读不可寻址。是保存在内存中，或者寄存器中，不知道也无法获得其确切地址，在得到计算表达式结果后就销毁的临时表达式。
 *      不能取地址&的值,一会就销毁的，如临时变量x++,表达式a+b
 *
 * 函数返回值为左值：当返回值为指针类型或引用类型的参数时，或者static、全局变量时，函数返回值为左值。
 * 函数返回值为右值：当返回值为函数内部定义的局部变量时，函数返回值为右值，因为函数内部该变量已被销毁。
 *
 * 左值引用(对左值的引用)：&a=b  常量左值引用：const &a=1
 * 右值引用(对右值的引用)：int &&b = 3 + 4 ; 表示即将过期但还没过期的值。移动语义c++11
 *         主要作用是解决大对象在作为函数返回值返回时的深度拷贝问题，以及大对象之间的快速复制
 *
 * https://zhuanlan.zhihu.com/p/598564624
 * 移动语义:std::move()   int a;//左值   int &&b = std::move(a);
 *  move作用是可以将一个左值转换成右值引用，从而可以调用C++11的拷贝构造函数。
 *  由于在C++11中的移动构造函数的入参是右值引用，因此当传入左值时，无法调用该移动构造函数，需要借助move将左值转换成右值引用。
 *
 * 完美转发std::forward()
 *  完美转发是指在函数模板中，完全依照模板的参数类型，将参数传递给当前函数模板中的另外一个函数。
 *  因此，为了实现完美转发，除了使用万能引用之外，还要用到std::forward（C++11），它在传参的过程中保留对象的原生类型属性。
 *  这样右值引用在传递过程中就能够保持右值的属性。
 *  只要是右值引用，由当前函数再传递给其它函数调用，要保持右值属性，必须实现完美转发。
 *
 *https://blog.csdn.net/m0_59938453/article/details/125858335?spm=1001.2101.3001.6650.12&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-12-125858335-blog-114479140.pc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-12-125858335-blog-114479140.pc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=16
 * */

void test_yinyong(){
    //int &a = 1;//错误，1是右值，a是左值引用，无法直接初始化，需要用左值初始化；
    int b = 1; //正确，b是左值不是左值引用，可以被赋值；
    int const &c = 1;//正确，c是常量左值引用，右值可以绑定到常左值引用；
    int &&d = 1;//正确，这是C++11中的右值引用，d为左值；
}
class Move_Copy
{
public:
    int *p;
    std::map<string,Move_Copy> *m_object;
    std::vector<int> v;
    Move_Copy()
    {
        p=new int;
        *p = 0;
        m_object = new std::map<string,Move_Copy>();
        cout << " default constructor" << endl;
    };
    Move_Copy(const Move_Copy &other)
    {
        p = new int;
        m_object = new std::map<string,Move_Copy>(*(other.m_object));
        *(p) = *(other.p);//为对象分配新的内存，并使用源对象中的值进行重新构造
        v = other.v;   //向量深拷贝
        cout << " copy constructor" << endl;
    }

    Move_Copy(Move_Copy &&other)  noexcept // 移动构造函数，参数是右值引用
    {
        p = other.p; // 直接从右值对象中“偷取”资源
        other.p = nullptr; //将右值对象中的资源指针设为空指针，避免重复释放内存
        m_object = other.m_object;
        other.m_object = nullptr;
        v = std::move(other.v);
        cout << " move constructor" << endl;
    }

    Move_Copy &operator[](const string &key){
        return (*m_object)[key];
    };

    //在对一个已经存在的对象进行赋值操作时，编译器会自动为该对象调用默认的拷贝赋值运算符（copy assignment operator），这个操作会将右侧对象的值复制到左侧对象中。
    //重点：但是，如果一个类定义了移动构造函数或移动赋值运算符，那么编译器就不会自动生成默认的拷贝构造函数和拷贝赋值运算符了，就会删除他们，需要手动提供。
    Move_Copy& operator=(const Move_Copy& other) {
        if (this != &other) {
            delete p;
            delete m_object;
            p = new int(*other.p);
            m_object = new std::map<string, Move_Copy>(*other.m_object);
            //当对一个vector进行赋值操作时，vector的赋值运算符会先清除左边vector的内容，然后将右边vector的内容复制到左边。
            //这也意味着在进行vector的赋值操作时，左边vector的容量会被释放，因此可以将左边vector的容量重用，而不需要重新分配内存
            v = other.v;  //直接赋值即可
        }
        cout << " operator = copy assignment constructor" << endl;
        return *this;
    }
    Move_Copy& operator=(Move_Copy &&other)  noexcept {
        if (this != &other) {
            delete p;
            delete m_object;
            p = other.p; // 直接从右值对象中“偷取”资源
            other.p = nullptr; // 将右值对象中的资源指针设为空指针，避免重复释放内存
            m_object = other.m_object;
            other.m_object = nullptr;
            v = other.v;
            cout << " operator = move assignment constructor" << endl;
        }
        return *this;
    }

    ~Move_Copy()
    {
        delete p;
        delete m_object;
        //为什么没有v?在对象析构时，C++ 会自动调用对象内部成员变量的析构函数。对于 std::vector 类型的成员变量，其析构函数会自动销毁其内部分配的内存。
        //因此，不需要在对象的析构函数中手动清除 std::vector 内部的内容，因为其析构函数会自动处理。
    };
};

void test_copy(){
    /**拷贝构造函数 深拷贝 ****/
    Move_Copy t1;
    Move_Copy t2(t1);
    Move_Copy t3 = t1;

    /**移动构造函数 速度更快 ****/
    //在C++11中，当我们使用右值引用作为构造函数的参数时，编译器会自动选择移动构造函数。我们无需显式地指定使用移动构造函数，编译器会自动进行判断。
    Move_Copy t4 = std::move(t1);  //调用移动构造函数，这里的=号，其实是实际上拷贝初始化（copy initialization）的一种形式，而非赋值操作
    Move_Copy t5;
    t5 = std::move(t4);            //调用移动构造的=操作符，这时已经不是初始化，所以无法调用移动构造函数
}

Move_Copy fun(){
    Move_Copy a;
    *a.p = 4;
    return a;
}
void test_func(){
    /* t6的构造使用了移动构造函数。在函数fun()中，a是一个局部变量，在其作用域结束时将被销毁。
    当函数返回时，编译器将创建一个临时的右值对象，并将局部变量a的资源转移给这个临时的右值对象。
    当临时右值对象被返回到调用点时，编译器将使用移动构造函数来将临时右值对象的资源移动到t6对象中。**/
    Move_Copy t6 = fun();
    cout << *t6.p << endl; //4
    /*为什么没有打印“move constructor”，因为在该程序中，fun()函数返回的Move_Copy对象会被直接赋值给t6，因此编译器会进行返回值优化（Return Value Optimization, RVO），
     * 直接将a对象构造在t6对象的内存空间中，而不是将a对象先构造出来再移动构造到t6对象中。这样可以避免额外的对象构造和移动操作，提高代码的执行效率。
     * 因为没有进行移动构造，所以程序中并没有打印"move constructor"。*/
}

/**构造函数调用的几种场景
 *  Example obj1(5);    // 创建一个 Example 类型的对象，调用构造函数
    Example obj2 = 10;  // 创建一个 Example 类型的对象，调用构造函数
    Example *obj3 = new Example(15);  // 动态创建一个 Example 类型的对象，调用构造函数
    Example ex1; // 调用默认构造函数
    Example ex2 = ex1; // 调用拷贝构造函数
    Example ex3(ex1); // 调用拷贝构造函数
    Example ex4; // 调用默认构造函数
    ex4 = ex1; // 调用拷贝赋值运算符函数
    Example ex3 = std::move(ex1); // 初始化时，调用移动构造函数
    ex2 = ex3; // 调用拷贝赋值运算符函数
    ex2 = std::move(ex3); // 调用移动赋值运算符函数
 * */
void func(Move_Copy &t1){
    cout << "左值引用" << endl;
}
void func(Move_Copy &&t1){
    cout << "右值引用" << endl;
}
//右值引用变量其实是左值
void test_Rightyinyong(Move_Copy &&t1){
    //func(std::forward<Move_Copy>(t1));
    func(t1);
}

//测试时最好在cmake中关闭编译器优化
int main(){
    Move_Copy t1;
    test_Rightyinyong(std::move(t1));
    return 0;
}

