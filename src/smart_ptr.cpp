//
// Created by liulei on 2023/4/14.
//
#include "all.h"
//1、auto_ptr一般不再使用，是c++98版本库中提供的智能指针，该指针解决上诉的问题采取的措施是管理权转移的思想，
//也就是原对象拷贝给新对象的时候，原对象就会被设置为nullptr，此时就只有新对象指向一块资源空间。

//2、unique_ptr是c++11版本库中提供的智能指针,它直接将拷贝构造函数和赋值重载函数给禁用(设为private或=delete)掉，因此，不让其进行拷贝和赋值。
//unique_ptr 之所以叫这个名字，是因为它只能指向一个对象，即当它指向其他对象时，之前所指向的对象会被摧毁。
//其次，当 unique_ptr 超出作用域时，指向的对象也会被自动摧毁，帮助程序员实现了自动释放的功能。

//3、为什么要禁用拷贝构造函数？
//(1)浅拷贝问题，也就是上面提到的二次析构。
//(2)自定义了基类和派生类的拷贝构造函数，但派生类对象拷贝时，调用了派生类的拷贝，没有调用自定义的基类拷贝而是调用默认的基类拷贝。
//这样可能造成不安全，比如出现二次析构问题时，因为不会调用我们自定义的基类深拷贝，还是默认的浅拷贝。

//4、share_ptr是c++11版本库中的智能指针，shared_ptr允许多个智能指针可以指向同一块资源，并且能够保证共享的资源只会被释放一次，程序不会崩溃掉。
//采用的是引用计数原理来实现多个shared_ptr对象之间共享资源：
//(1)shared_ptr在内部会维护着一份引用计数，用来记录该份资源被几个对象共享。
//(2)当一个shared_ptr对象被销毁时（调用析构函数），析构函数内就会将该计数减1。
//(3)如果引用计数减为0后，则表示自己是最后一个使用该资源的shared_ptr对象，必须释放资源。
//(4)如果引用计数不是0，就说明自己还有其他对象在使用，则不能释放该资源，否则其他对象就成为野指针。
//(5)引用计数是用来记录资源对象中有多少个指针指向该资源对象。

//5、shared_ptr的问题
//(1)非环形数据结构中没有问题，但是在环形结构中，比如链表中出现循环引用问题。
//(2)延长了对象的生命周期，忘记留有一个拷贝，其实也未能达到释放内存的效果

//6、weak_ptr可以指向shared_ptr，并且不会改变shared_ptr的引用计数。一旦最后一个shared_ptr被销毁时，对象就会被释放。用于解决循环引用问题
//share_ptr的循环引用https://blog.csdn.net/sjp11/article/details/123899141
//例如：当双向链表中节点也声明为share_ptr时，会出现pre和next的循环引用，导致最后引用计数器不为0，无法释放指向的对象,见weak_ptr.cpp
struct ListNode{
    weak_ptr<ListNode> next;
    weak_ptr<ListNode> pre;
};
//使用weakptr访问对象，需要用lock先获取一个临时的shared_ptr
//if (auto sptr = wptr.lock()) {
//    // 使用 shared_ptr 访问对象
//    std::cout << "Object value: " << sptr->value << std::endl;
//} else {
//    // weak_ptr 指向的对象已经被释放
//    std::cout << "Object has been deleted" << std::endl;
//}

class A
{
public:
    int *p;
    A()
    {
        p=new int(4);
        cout << "A default constructor" << endl;
    };
    ~A()
    {
        delete p;
        cout << "A destructor" << endl;
    };
};

void test_unique_ptr(){
    //常规初始化
    unique_ptr<int> up1(new int(8)); // 创建一个指向int型对象的指针，删除器缺省为delete
    unique_ptr<int[]> up2(new int[10]); // 指向一个10个元素的int型数组，删除器缺省为delete[]

    //make_unique初始化，c++14
    unique_ptr<double> up3 = make_unique<double>(1.88);    //unptr2是指向一个double型对象val为1.88的unique_ptr智能指针
    auto up4 = make_unique<float>(1.98f);    //unptr4是指向一个float型对象val为1.98f的unique_ptr智能指针

    unique_ptr<string> ptr1 = make_unique<string>("I Love China!");
    cout << "*ptr1 = "<< *ptr1 << endl;
    //下面四行代码都是错误的！因为unique_ptr不支持这些拷贝和赋值给别的指针的操作！
    //unique_ptr<string> ptr2(ptr1);
    //unique_ptr<string> ptr3 = ptr1;
    //unique_ptr<string> ptr4;
    //ptr4 = ptr1;

    {
        unique_ptr<A> pA = make_unique<A>();
    }//超出指针作用域，对象自动释放

    unique_ptr<string> ptr2(std::move(ptr1));
    //cout << "*ptr1" << *ptr1 << endl; //奔溃，构造函数将ptr1的内存控制权限移动给（交给）了ptr2
    cout << "*ptr2 = " << *ptr2 << endl;

}

void test_share_ptr(){
    {
        shared_ptr<A> pB;
        {
            shared_ptr<A> pA = make_unique<A>();
            pB = pA;
            cout << pA.get() << endl;  //两个指针指向的地址相同
            cout << pB.get() << endl;  //两个指针指向的地址相同
            cout << "引用计数：" << pB.use_count() << endl;
        } //当一个shared_ptr对象被销毁时（调用析构函数），析构函数内就会将该计数减1
        cout << "引用计数：" << pB.use_count() << endl;
    }//超出作用域，引用计数器为0，对象自动释放
}
int main(){
    //test_share_ptr();
    int a = 4;
    int &&c = std::move(a); // ok
    cout << a;
    return 0;
}