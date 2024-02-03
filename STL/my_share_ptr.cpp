//
// Created by liulei on 2023/4/28.
//
#include "all.h"
//为什么要加explicit 防止编译器隐式类型转化，例如A(int val):m_val(val);  A a = 100;这种构造方式就很奇怪，加上explicit之后只能使用A a(100);构造

//为什么需要noexcept
//在C++ 11中类结构隐式自动声明的或者是由程序员主动声明的不带有任何修饰符的析构函数，都会被编译器默认带上noexcept (true)标记，以表示这个析构函数不会抛出异常。
//这样做是由于，我们希望析构函数的执行只有两种结果，一种是成功的将类对象的资源释放，一种是由于某些原因，导致类资源无法被释放从而直接中断程序的运行。
//抛出异常，意味着对于某种错误情况，我们不知道应该怎样处理，因此编译器将其抛给上层调用者来处理，
//但是析构函数的执行失败，通常会导致比如说资源泄漏或者空指针等潜在问题出现，因此相较于让程序继续运行，一个更加合理的方式是直接终止程序的运行。

template <class T>
class my_shared_ptr{
public:
    my_shared_ptr():ptr(nullptr),ref_count(0){};

    explicit my_shared_ptr(T *p):ptr(p),ref_count(1){};

    //拷贝构造
    my_shared_ptr(my_shared_ptr<T> &other){
        cout << "copy constructor" << endl;
        std::lock_guard<std::mutex> lock(other.ref_count_mutex);
        ptr = other.ptr;
        ref_count = other.ref_count;
        ref_count++;
    }
    //移动构造
    my_shared_ptr(my_shared_ptr<T> &&other) noexcept{
        std::lock_guard<std::mutex> lock(other.ref_count_mutex);
        ptr = other.ptr;
        other.ptr = nullptr;
        ref_count = other.ref_count;
        other.ref_count=0;
        ref_count++;
    }
    //重载=移动赋值
    my_shared_ptr& operator=(my_shared_ptr<T> &&other){
        if(this!=&other)
        {
            std::lock_guard<std::mutex> lock(other.ref_count_mutex);
            ptr = other.ptr;
            other.ptr = nullptr;
            ref_count = other.ref_count;
            other.ref_count=0;
            ref_count++;
        }
        return *this;
    }

    //重载=拷贝赋值
    my_shared_ptr& operator=(my_shared_ptr<T> &other){
        if(this!=&other)
        {
            std::lock_guard<std::mutex> lock(other.ref_count_mutex);
            ptr = other.ptr;
            ref_count = other.ref_count;
            ref_count++;
        }
        return *this;
    }
    //重载*
    T &operator*(){
        return *ptr;
    }
    //重载->
    T *operator->(){
        return ptr;
    }
    ~my_shared_ptr() {
        if (--(ref_count) == 0) {
            delete ptr;
        }
    }

    //获取引用记数
    int use_count()
    {
        return ref_count;
    }

private:
    T* ptr;
    int ref_count;
    std::mutex ref_count_mutex;
};

struct MyClass {
    int a;
    MyClass(int x) : a(x) {}
    ~MyClass() { std::cout << "destruct MyClass\n"; }
};

void f(my_shared_ptr<MyClass> p) {
    std::cout << "f() is using the object " << p->a << std::endl;
}

int main(){
    my_shared_ptr<MyClass> p1(new MyClass(42));
    cout << p1.use_count() << endl;
    my_shared_ptr<MyClass> p2 = p1;
    cout << p2.use_count() << endl;
    my_shared_ptr<MyClass> p3 = p1;
    cout << p3.use_count() << endl;
    std::cout << "p1 points to " << p1->a << std::endl;

    return 0;
};