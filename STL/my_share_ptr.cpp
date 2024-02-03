//
// Created by liulei on 2023/4/28.
//
#include "all.h"
//ΪʲôҪ��explicit ��ֹ��������ʽ����ת��������A(int val):m_val(val);  A a = 100;���ֹ��췽ʽ�ͺ���֣�����explicit֮��ֻ��ʹ��A a(100);����

//Ϊʲô��Ҫnoexcept
//��C++ 11����ṹ��ʽ�Զ������Ļ������ɳ���Ա���������Ĳ������κ����η����������������ᱻ������Ĭ�ϴ���noexcept (true)��ǣ��Ա�ʾ����������������׳��쳣��
//�����������ڣ�����ϣ������������ִ��ֻ�����ֽ����һ���ǳɹ��Ľ���������Դ�ͷţ�һ��������ĳЩԭ�򣬵�������Դ�޷����ͷŴӶ�ֱ���жϳ�������С�
//�׳��쳣����ζ�Ŷ���ĳ�ִ�����������ǲ�֪��Ӧ������������˱����������׸��ϲ������������
//��������������ִ��ʧ�ܣ�ͨ���ᵼ�±���˵��Դй©���߿�ָ���Ǳ��������֣����������ó���������У�һ�����Ӻ���ķ�ʽ��ֱ����ֹ��������С�

template <class T>
class my_shared_ptr{
public:
    my_shared_ptr():ptr(nullptr),ref_count(0){};

    explicit my_shared_ptr(T *p):ptr(p),ref_count(1){};

    //��������
    my_shared_ptr(my_shared_ptr<T> &other){
        cout << "copy constructor" << endl;
        std::lock_guard<std::mutex> lock(other.ref_count_mutex);
        ptr = other.ptr;
        ref_count = other.ref_count;
        ref_count++;
    }
    //�ƶ�����
    my_shared_ptr(my_shared_ptr<T> &&other) noexcept{
        std::lock_guard<std::mutex> lock(other.ref_count_mutex);
        ptr = other.ptr;
        other.ptr = nullptr;
        ref_count = other.ref_count;
        other.ref_count=0;
        ref_count++;
    }
    //����=�ƶ���ֵ
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

    //����=������ֵ
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
    //����*
    T &operator*(){
        return *ptr;
    }
    //����->
    T *operator->(){
        return ptr;
    }
    ~my_shared_ptr() {
        if (--(ref_count) == 0) {
            delete ptr;
        }
    }

    //��ȡ���ü���
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