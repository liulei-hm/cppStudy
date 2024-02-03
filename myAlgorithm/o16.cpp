//
// Created by liulei on 2023/5/11.
//
#include <bits/stdc++.h>
using namespace std;
template <class T1,typename T2>
class A{
protected:
    T1 val1=4; //外部不可以，子类可以，不可直接通过 A a访问a.val1
private:
    T2 val2=5; //外部不可以，子类可以，不可直接通过 A a访问a.val1
public:
    T1 a = 0;
    A(T1 v1,T2 v2):val1(v1),val2(v2){};
};
int main(){
    A<int,int> t(1,4);
    //cout << t.val1;
    //A<int,int> arr1[2] = {(1,3),(3,5)};
    A<int,int> arr[2] = {A(1,3),A(3,5)};
    A<int,int> arr1[2] = { {1, 3}, {3, 5} };
    auto [a, b] = std::make_tuple(1, 3);
    auto [c, d] = std::make_tuple(3, 5);
    A<int,int> arr2[2] = { {a, b}, {c, d} };
    int i=5;
    int v;
    v = (++i)--;
    cout << i << " " << v;
    return 0;
}
