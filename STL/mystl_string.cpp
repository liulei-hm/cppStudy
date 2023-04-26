//
// Created by liulei on 2023/3/31.
//

#include <iostream>
#include <cstring>
using namespace std;
class Mystring
{
    friend ostream & operator<<(ostream & o, const  Mystring & temp);
public:
    Mystring(char * temp );
    Mystring(const Mystring & temp);
    char & operator[](int index);
    Mystring operator+(Mystring & temp);
    Mystring & operator=(Mystring & temp);
    Mystring & operator=(char * temp);
    Mystring & operator+=(char * temp);
    Mystring & operator+=(Mystring & temp);
private:
    char * p;
};
ostream & operator<<(ostream & o,const  Mystring & temp)
{
    o << temp.p ;
    return o;
}

Mystring::Mystring(char * temp)
{
    //cout << "我是构造函数1" << endl;
    p = new char(strlen(temp)+1);
    strcpy(p,temp);
    p[strlen(temp)] = '\0';
}
Mystring::Mystring( const Mystring & temp)
{
    //cout << "我是构造函数2" << endl;
    p = new char(strlen(temp.p) + 1);
    strcpy(p,temp.p);
    p[strlen(temp.p)] = '\0';

}

char & Mystring::operator[](int index)
{
    //cout << "我是下标运算符" << endl;
    if (index >= 0 && index < strlen(p))
    {
        return p[index];
    }
    return p[0];
}
Mystring  Mystring::operator+(Mystring & temp)
{
    //cout << " 我是+号运算符1" << endl;
    strcat(p,temp.p);
    return *this;
}
Mystring & Mystring::operator=(char * temp)
{
    //cout << " 我是=号运算符1" << endl;
    strcpy(p,temp);
    p[strlen(temp)] = '\0';
    return *this;
}
Mystring & Mystring::operator=(Mystring & temp)
{
    //cout << " 我是=号运算符2" << endl;
    strcpy(p,temp.p);
    p[strlen(temp.p)] = '\0';
    return *this;
}
Mystring & Mystring::operator+=(char * temp)
{
    //cout << " 我是+=号运算符1" << endl;
    strcat(p,temp);
    return *this;
}
Mystring & Mystring::operator+=(Mystring & temp)
{
    //cout << " 我是+=号运算符2" << endl;
    strcat(p,temp.p);
    return *this;
}


int main(){
    return 0;
}