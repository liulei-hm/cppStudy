//
// Created by liulei on 2023/4/27.
//
#include "all.h"
#include "../yazi-json/timer.h"

class MyString {
public:
    //=default 来要求编译器生成默认构造函数，仅仅是因为我们既需要其他形式的构造函数，也需要默认的构造函数。
    //如果我们定义了构造函数 ，则编译器就不会再生成默认构造函数了。
    //MyString() = default;
    MyString():m_Size(0),m_Data(nullptr){};
    MyString(const char *str) {
        //printf("Created!\n");
        m_Size = strlen(str);
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, str, m_Size + 1);
    }

    MyString(const MyString &other) {
        //printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, other.m_Data, m_Size + 1);
    }

    MyString(MyString &&other) noexcept {
        //printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    MyString &operator=(const MyString &other) {
        //printf("Copied Assign!\n");
        if (this != &other) {
            m_Size = other.m_Size;
            m_Data = new char[m_Size + 1];
            memcpy(m_Data, other.m_Data, m_Size + 1);
        }
    }


    MyString &operator=(MyString &&other) noexcept {
        //printf("Moved Assign!\n");
        if (this != &other) {   //1、防止自身赋值
            m_Size = other.m_Size;
            delete[] m_Data;    //2、防止内存泄漏
            m_Data = other.m_Data; //3、如果不是指针类型，需要用move

            other.m_Size = 0;
            other.m_Data = nullptr;
        }
    }

    void printStr() {
        //printf("%s\n", m_Data);
    }

    ~MyString() {
        //printf("Destroyed!\n");
        delete[] m_Data; //基本类型可以不用[]?
    }

private:
    uint32_t m_Size = 0;
    char *m_Data;
};

class Entity {
public:
    Entity(const MyString &name) : m_Name(name) {

    }

    Entity(MyString &&name) : m_Name(std::move(name)) {
        //其实这里使用m_Name(std::forward<MyString>(name))
        //和m_Name((MyString &&)name)是一样的
    }

    void printName() {
        m_Name.printStr();
    }

private:
    MyString m_Name;
};

MyString test(){
    MyString s1;
    return s1;
}

void test_timeofCopy(){
    HighTimer highTimer;
    for(int i=0;i<50000;i++)
    {
        MyString s2 = "dsad";
        MyString s3 = s2;
    }
    cout << highTimer.elapsed_micro();
}


void test_timeofMove(){
    HighTimer highTimer;
    for(int i=0;i<50000;i++)
    {
        MyString s2 = "dsad";
        MyString s3;
        s3 = std::move(s2);
    }
    cout << highTimer.elapsed_micro();
}

int main() {
//    MyString str1 = "hello";
//    //拷贝
//    MyString dest_copy = str1;
//    Entity entity_copy(MyString("liulei"));
//    entity_copy.printName();
//
//    //移动
//    MyString dest_move = std::move(str1);
//    Entity entity_move("liulei");
//    entity_move.printName();

    //移动赋值
    MyString str2 = "hello";
    MyString dest = "adad";
    dest = str2;
    dest = std::move(str2);
    flush(cout);
    return 0;
};