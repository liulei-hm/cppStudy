//
// Created by liulei on 2023/4/29.
//
#include <atomic>
#include <mutex>
#include "all.h"
template<class T>
class my_shared_ptr {
public:
    my_shared_ptr() : ptr(nullptr), ref_count(nullptr) {}
    explicit my_shared_ptr(T* ptr) : ptr(ptr) {
        ref_count = new std::atomic_int(1);
    }
    my_shared_ptr(my_shared_ptr<T>& other) {
        std::lock_guard<std::mutex> lock(other.ref_count_mutex);
        ptr = other.ptr;
        ref_count = other.ref_count;
        ++(*ref_count);
    }
    my_shared_ptr(my_shared_ptr<T>&& other) noexcept {
        std::lock_guard<std::mutex> lock(other.ref_count_mutex);
        ptr = other.ptr;
        ref_count = other.ref_count;
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }
    ~my_shared_ptr() {
        release();
    }
    my_shared_ptr<T>& operator=(my_shared_ptr<T>& other) {
        if (this != &other) {
            release();
            std::lock_guard<std::mutex> lock(other.ref_count_mutex);
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }
    my_shared_ptr<T>& operator=(my_shared_ptr<T>&& other) noexcept {
        if (this != &other) {
            release();
            std::lock_guard<std::mutex> lock(other.ref_count_mutex);
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }
    T* operator->() const {
        return ptr;
    }
    T& operator*() const {
        return *ptr;
    }
    operator bool() const {
        return ptr != nullptr;
    }
    int use_count(){
        return *ref_count;
    }
private:
    T* ptr;
    std::atomic_int* ref_count;
    std::mutex ref_count_mutex;

    void release() {
        if (ref_count && --(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }
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
//    my_shared_ptr<MyClass> p1(new MyClass(42));
//    cout << p1.use_count() << endl;
//    {
//        my_shared_ptr<MyClass> p2 = p1;
//        cout << p1.use_count() << endl;
//    }
//    my_shared_ptr<MyClass> p3 = p1;
//    cout << p1.use_count() << endl;
//    std::cout << "p1 points to " << p1->a << std::endl;

    MyClass a(5);


    return 0;
};

