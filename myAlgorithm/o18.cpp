#include <bits/stdc++.h>
using namespace std;

int dataa = 3;
int *pdata = &dataa;

void test(int *pudata){
    pudata = pdata;
}
int main() {
    int val = 0;   // 已经初始化的局部变量
    int *pudata = &val;
    pudata = pdata;

    cout << pudata << " " << *pudata << endl;

    cout << val << " " << &val << endl;

    cout << val << " " << &val << endl;

    return 0;
}
