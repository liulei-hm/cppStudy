//
// Created by liulei on 2023/3/15.
//

#include "all.h"
//懒汉，第一次使用时才new
//饿汉，声明时直接new
//不加同步的懒汉式是线程不安全的, 饿汉式是线程安全的

//双重检查锁+内嵌自动回收
class lazy_single {
private:
    lazy_single() {}
    static lazy_single *p;
    static mutex lock_;
public:
    static lazy_single *instance();

    // 实现一个内嵌垃圾回收类
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if(lazy_single::p)
                delete lazy_single::p;
        }
    };
    static CGarbo Garbo; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
};

lazy_single *lazy_single::p = nullptr;
lazy_single::CGarbo Garbo;
std::mutex lazy_single::lock_;

lazy_single* lazy_single::instance() {
    if (p == nullptr) {
        lock_guard<mutex> guard(lock_);
        if (p == nullptr)
            p = new lazy_single();
    }
    return p;
}




class hungry_single {
private:
    hungry_single() {}   //构造函数私有化（单例模式Singleton）
    //一般来说，构造函数都是放在公有区，要是把构造函数放在私有区，就是不允许被外界创建对象,我们只需要一个对象即可
    static hungry_single *p;
public:
    static hungry_single *instance();
    bool isShow = false;
};

hungry_single *hungry_single::p = new hungry_single();

hungry_single* hungry_single::instance() {
    return p;
}

class h_single{
public:
    static h_single *instance();
    class GC{
    public:
        ~GC(){
            if(h_single::p!= nullptr)
            {
                delete h_single::p;
                h_single::p= nullptr;
            }
        }
    };
private:
    h_single(){}
    static h_single *p;
};

h_single * h_single::p = new h_single();
h_single *h_single::instance() {
    return p;
}

int main(){
    hungry_single *s1 = hungry_single::instance();
    hungry_single *s2 = hungry_single::instance();
    s2->isShow = true;
    cout << s1->isShow << endl;
    return 0;
}

