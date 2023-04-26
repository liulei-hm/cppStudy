//
// Created by liulei on 2023/4/1.
//

#pragma warning(disable:4996)
#include<iostream>
#include <cstring>
#include <cassert>
#include "my_string.h"
using namespace std;

class Stringe
{
public:
    Stringe(const char* str = "")
    {
        if (str==nullptr)
        {
            str = " ";
        }
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }

    ~Stringe()
    {
        if (_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }

    char* _str;
};

//默认拷贝构造函数的浅拷贝测试
void StringTest()
{
    char *s = (char *)malloc(20); // 分配20个字节的动态内存
    strcpy(s, "hello"); // 将字符串复制到动态内存中
    Stringe s1(s);
    Stringe s2(s1);   //这里只是调用了默认拷贝构造函数，为浅拷贝https://blog.csdn.net/weixin_63934824/article/details/126566986
    cout << s << endl;
    s[0] = 'H';
    s1._str[0] = 'M';
    cout << s1._str << endl;
    cout << s2._str << endl;
    cout << endl;
}

void test_constructor(){
    my::string s1 = "this";
    my::string s2("is");
    my::string s3 = s2;
    my::string s4(s1);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}
void stringTest1()
{
    my::string s1("hello");
    my::string s2(s1);
    my::string s3;
    s3 = s2;

    std::cout << s1.size() << std::endl;
    std::cout << s1.capacity() << std::endl;
    std::cout << s1.empty() << std::endl;

    s1.resize(3);
    s2.resize(10);
    s3.resize(15, 'A');

    s1.reserve(4);
    s2.reserve(20);
    s3.reserve(100);

    std::cout << s1[0] << std::endl;
    std::cout << s2[3] << std::endl;
    const my::string s4("aaaaaa");
    char ch = s4[3];

}

void stringTest2()
{
    my::string s1("Hello");

    s1.push_back(' ');
    s1.append("World");
    s1 += '!';
    s1 += "~~~~";

    std::cout << s1.c_str() << std::endl;

    my::string s2("12345");
    s1.swap(s2);
    s1.clear();

}

int main()
{
    //test_constructor();
    stringTest1();
    return 0;
}

my::string::string(const char *s) {
    if(s == nullptr) assert(0);
    _size = strlen(s);
    _capacity = _size;
    _str = new char[_capacity + 1];
    strcpy(_str,s);
}

my::string::string(const my::string &str):_str(nullptr),_size(0),_capacity(0) {
    string temp(str._str);
    std::swap(_str,temp._str);
    std::swap(_size,temp._size);
    std::swap(_capacity,temp._capacity);
}

my::string &my::string::operator=(const my::string &str) {
    if(this == &str) return *this;
    string temp(str._str);
    std::swap(_str,temp._str);
    std::swap(_size,temp._size);
    std::swap(_capacity,temp._capacity);
    return *this;
}

my::string::~string() {
    if(_str!= nullptr)
    {
        delete[] _str;
        _str = nullptr;
    }
}

my::string::iterator my::string::begin() {
    return _str;
}

my::string::iterator my::string::end() {
    return _str+_size;
}

size_t my::string::size() const {
    return _size;
}

size_t my::string::capacity() const {
    return _capacity;
}

bool my::string::empty() const{
    if(_size == 0)
    {
        return true;
    }
    return false;
}

void my::string::resize(size_t n, char c) {
    if(n>_size)
    {
        if(n>_capacity)
        {
            reserve(n);
        }
        memset(_str+_size,c,n-_size);
    }
    _size = n;
    _str[_size] = '\0';
}

void my::string::reserve(size_t n) {
    if(n>_capacity)
    {
        char *temp = new char[n+1];
        strcpy(temp,_str);
        delete[] _str;
        _str = temp;
        _capacity = n;
    }
}

char &my::string::operator[](size_t index) {
    assert(index<_size);
    return _str[index];
}

const char &my::string::operator[](size_t index) const {
    assert(index<_size);
    return _str[index];
}

void my::string::push_back(char c) {
    if(_size == _capacity)
    {
        reserve(_capacity*2);
    }
    _str[_size++];
    _str[_size] = '\0';
}

my::string &my::string::operator+=(char c) {
    push_back(c);
    return *this;
}

void my::string::append(const char *str) {
    if(_size+strlen(str) >= _capacity)
    {
        //扩容
        size_t newcapacity = _capacity*2 > _size+ strlen(str) ? _capacity*2:_size+ strlen(str);
        reserve(newcapacity);
    }
    strcat(_str,str);
}
//为什么运算符重载要返回对象的引用：1、允许连续赋值 2、防止返回对象
my::string &my::string::operator+=(const char *str) {
    append(str);
    return *this;
}

void my::string::clear() {
    _size = 0;
    _str[0]='\0';
}

void my::string::swap(my::string &s) {
    std::swap(_str,s._str);
    std::swap(_size,s._size);
    std::swap(_capacity,s._capacity);
}

const char *my::string::c_str() const {
    return _str;
}

std::ostream &my::operator<<(ostream &_cout, const my::string &s) {
    _cout << s._str;
    return _cout;
}

size_t my::string::find(char c, size_t pos) const {
    for(size_t i=pos;i<_size;i++){
        if(c==_str[i]){
            return i;
        }
    }
    return -1;
}

size_t my::string::find(const char *s, size_t pos) const {
    assert(s);
    assert(pos < _size);
    const char* src = _str + pos;
    while (*src)
    {
        const char* match = s;
        const char* cur = src;
        while (*match && *match == *cur)
        {
            ++match;
            ++cur;
        }
        if (*match == '\0')
        {
            return src - _str;
        }
        else
        {
            ++src;
        }
    }
    return -1;
}

my::string &my::string::insert(size_t pos, char c) {
    assert(pos <= _size);
    if(_size == _capacity)
    {
        reserve(_capacity*2);
    }
    for(size_t i=_size;i >= pos;--i)
    {
        _str[i + 1] = _str[i];
    }
    _str[pos] = c;
    _size++;
    return *this;
}

my::string &my::string::insert(size_t pos, const char *str) {
    size_t len = strlen(str);
    if (_size + len > _capacity)//扩容
    {
        //扩容
        size_t newcapacity = _capacity*2 > _size+ strlen(str) ? _capacity*2:_size+ strlen(str);
        reserve(newcapacity);
    }
    //后移数据
    for (size_t i = _size; i >= pos; --i)
    {
        _str[len + i] = _str[i];
    }
    //拷贝字符串
    while (*str != '\0')
    {
        _str[pos++] = *str++;
    }
    _size += len;
    return *this;
}

my::string &my::string::erase(size_t pos, size_t len) {
    assert(pos < _size);

    if (pos + len >= _size)//pos位置之后全为0
    {
        _str[pos] = '\0';
        _size = pos;
    }
    else
    {
        strcpy(_str + pos, _str + pos + len);
        _size -= len;
    }
    return *this;
}

//实现类string构造函数、 拷贝构造函数、赋值函数、析构函数、运算符重载、字符串反转、排序，补全其中的函数实现部分(请勿改动其他代 码)
#if 1
namespace mystring{
    class string
    {
    public:
        string(const char* src = NULL) {
            //TODO1:构造函数 //开始添加代码
            m_length = src ? strlen(src) : 0;
            m_data = new char[m_length + 1];
            memset(m_data, 0, m_length + 1);
            if (src)
            {
                memcpy(m_data, src, m_length);
            }
            //结束添加代码
        }
        ~string() {
            //TODO2:析构函数 //开始添加代码
            delete[] m_data;
            m_length = 0; //结束添加代码
        }
        int size() const {
            return m_length;
        }
        const char *c_str() const {
            return m_data;
        }
        string(const string &src) {
            //TODO3:拷贝构造函数 //开始添加代码
            m_length = src.size();
            m_data = new char[m_length + 1];
            memset(m_data, 0, m_length + 1);
            memcpy(m_data, src.c_str(), src.size()); //结束添加代码
        }
        string operator+(const string &src) const {
            string ret;
            //TODO4:运算符+
            //开始添加代码
            ret.m_length = m_length + src.size();
            ret.m_data = new char[ret.m_length + 1];
            memset(ret.m_data, 0, m_length + 1);
            memcpy(ret.m_data, m_data, m_length);
            memcpy(ret.m_data + m_length, src.c_str(), src.size()); //结束添加代码
            return ret;
        }
        string& operator+=(const string &src) {
            //TODO5:运算符+=
            //TODO5:运算符+= //开始添加代码
            if (src.size() > 0)
            {
                int newLength = m_length + src.size();
                char *newData = new char[newLength + 1];
                memset(newData, 0, newLength + 1);
                memcpy(newData, m_data, m_length);
                memcpy(newData + m_length, src.c_str(), src.size());
                delete[] m_data;
                m_length = newLength;
                m_data = newData;
            } //结束添加代码 return *this;
        }
        bool operator==(const string &str) const {
            //TODO5:运算符== //开始添加代码
            if (m_length != str.size()) {
                return false;
            }
            return strcmp(m_data, str.m_data) == 0;
            //结束添加代码
        }
        void Reverse() {
            //TODO5:字符串反转 //开始添加代码
            char temp;
            for (int i = 0; i < m_length / 2; i++) {
                temp = m_data[i];
                m_data[i] = m_data[m_length - 1 - i];
                m_data[m_length - 1 - i] = temp;
            }
            //结束添加代码
        }
        void Sort() {
            //TODO6:字符串从小到大排序 //开始添加代码
            char temp;
            int index, offset;
            for (index = 0; index < m_length - 1; index++) {
                for (offset = index + 1; offset < m_length; offset++) {
                    if (strcmp(m_data + index, m_data + offset) > 0) {
                        temp = *(m_data + offset);
                        *(m_data + offset) = *(m_data + index); *(m_data + index) = temp;
                    }
                }
            }
            //结束添加代码
        }
    private:
        char *m_data;
        int m_length;
    };
    int test() {
        //构造函数
        string str1 = "abcde"; string str2("12345");
        //拷贝构造函数
        string str3 = str1;
        std::cout << (str3 == str1) << std::endl;
        //拷贝构造函数
        string str4(str2);
        std::cout << (str2 == str4) << std::endl;
        //+ 运算符
        string str5 = str1 + str2;
        std::cout << (str5 == "abcde12345") << std::endl;
        std::cout << (str5.size() == str1.size() + str2.size()) << std::endl;
        //+= 运算符
        str5 += str1;
        std::cout << (str5 == "abcde12345abcde") << std::endl;

        std::cout << (str5 == "abcde12345abcde") << std::endl;

        //反转
        string str6 = "12345678";
        str6.Reverse();
        std::cout << (str6 == "87654321") << std::endl;
        //排序
        string str7 = "202008131617";
        str7.Sort();
        std::cout << (str7 == "000111223678") << std::endl;
        return 0;
    }
}


#endif
