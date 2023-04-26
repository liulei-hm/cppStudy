//
// Created by liulei on 2023/4/9.
//

#include <bits/stdc++.h>
using namespace std;
#define MAX(type, a, b) ({ \
           type _a = a;        \
           type _b = b;        \
           _a>_b?_a:_b;        \
    })

template<typename T>
T get_max(T a,T b)
{
    return a>b?a:b;
}

int main() {
    cout << get_max(5,4);
    return 0;
}
