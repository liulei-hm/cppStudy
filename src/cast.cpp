//
// Created by liulei on 2023/3/11.
//
#include "all.h"

class A
{
public:
    const double i = 5.0;
    const int j = 10;
    const string m_s = "Test String";
};

int main()
{
    A a;
    cout << a.i << '\t' << a.j << '\t' << a.m_s << endl;

    string& p_str = const_cast<string&> (a.m_s);
    p_str = "&   Test String";
    cout << a.i << '\t' << a.j << '\t' << a.m_s << endl;

    string* ps = const_cast<string*>(&a.m_s);
    *ps = "Point Test String";
    cout << a.i << '\t' << a.j << '\t' << a.m_s << endl;


}