//
// Created by liulei on 2023/4/14.
//

#include "all.h"

#include <iostream>
using namespace std;

template <typename T>
class RefCount {
private:
    T *ptr;
    int *count;

public:
    RefCount(T *p = nullptr) {
        ptr = p;
        count = new int;
        *count = 1;
        cout << "defaut constructor" << endl;
    }

    RefCount(const RefCount &obj) {
        ptr = obj.ptr;
        count = obj.count;
        ++(*count);
        cout << "copy constructor" << endl;
    }

    RefCount &operator=(const RefCount &obj) {
        if (this != &obj) {
            ptr = obj.ptr;
            count = obj.count;
            ++(*count);
        }
        cout << "copy assignment constructor" << endl;
        return *this;
    }

    ~RefCount() {
        --(*count);
        if (*count == 0) {
            delete ptr;
            delete count;
            cout << "Memory freed." << endl;
        }
    }

    T *get() const {
        return ptr;
    }

    int use_count() const
    {
        return count ? *count : 0;
    }
};

int main() {
    RefCount<int> a(new int(10));
    RefCount<int> b = a;
    cout << *(b.get()) << endl;
    cout << b.use_count() << endl;
    RefCount<int> c(new int(20));
    b = c;
    {
        RefCount<int> d(c);
    }
    return 0;
}
