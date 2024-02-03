#include <bits/stdc++.h>

using namespace std;

class A{
public:
    A(){};
    A(int a): age(a) {};
    ~A(){};
private:
    int age;
};

int main()	{
    A *a = new A(10);
    shared_ptr<A> p1(a);
    shared_ptr<A> p2(a);
    cout << hex;
    cout << ~0x7 << endl;
    return 0;
}