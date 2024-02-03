//
// Created by liulei on 2023/4/27.
//
#include "all.h"
#include "../yazi-json/timer.h"

class MyString {
public:
    //=default ��Ҫ�����������Ĭ�Ϲ��캯������������Ϊ���Ǽ���Ҫ������ʽ�Ĺ��캯����Ҳ��ҪĬ�ϵĹ��캯����
    //������Ƕ����˹��캯�� ����������Ͳ���������Ĭ�Ϲ��캯���ˡ�
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
        if (this != &other) {   //1����ֹ����ֵ
            m_Size = other.m_Size;
            delete[] m_Data;    //2����ֹ�ڴ�й©
            m_Data = other.m_Data; //3���������ָ�����ͣ���Ҫ��move

            other.m_Size = 0;
            other.m_Data = nullptr;
        }
    }

    void printStr() {
        //printf("%s\n", m_Data);
    }

    ~MyString() {
        //printf("Destroyed!\n");
        delete[] m_Data; //�������Ϳ��Բ���[]?
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
        //��ʵ����ʹ��m_Name(std::forward<MyString>(name))
        //��m_Name((MyString &&)name)��һ����
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
//    //����
//    MyString dest_copy = str1;
//    Entity entity_copy(MyString("liulei"));
//    entity_copy.printName();
//
//    //�ƶ�
//    MyString dest_move = std::move(str1);
//    Entity entity_move("liulei");
//    entity_move.printName();

    //�ƶ���ֵ
    MyString str2 = "hello";
    MyString dest = "adad";
    dest = str2;
    dest = std::move(str2);
    flush(cout);
    return 0;
};