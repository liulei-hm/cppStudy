//
// Created by liulei on 2023/3/4.
//
#include "all.h"
//C++函数模版两种定义方式 template < typename T>  或  template <class T>
//和重载区别：重载可以函数参数个数不同，类型不同，但模板只能类型不同，同时满足时优先调用重载
//模板的类声明和成员函数必须放在一个.h文件中
/********************************************类模板****************************************************/
template<typename T1, typename T2>
class Point {
public:
    Point(T1 x, T2 y) :m_x(x), m_y(y) {}
public:
    T1 getX() const;
    void setX(T1 x);
    T2 getY() const;
    void setY(T2 y);
private:
    T1 m_x; //x坐标
    T2 m_y; //y坐标
};

template<typename T1, typename T2>  //模板头
T1 Point<T1, T2>::getX() const /*函数头*/ {
    return m_x;
}
template<typename T1, typename T2>
void Point<T1, T2>::setX(T1 x) {
    m_x = x;
}
template<typename T1, typename T2>
T2 Point<T1, T2>::getY() const {
    return m_y;
}
template<typename T1, typename T2>
void Point<T1, T2>::setY(T2 y) {
    m_y = y;
}

/********************************************类模板实现可变长数组****************************************************/
//每次扩容1个，new一个新的空间然后拷贝过去
template <class T>
class VariableArray
{
    int lenth; //数组元素的个数
    T *ptr; //指向动态分配的数组
public:
    //构造函数重载
    VariableArray(int num = 0);  //s代表数组元素的个数
    VariableArray(VariableArray & a);
    ~VariableArray();
    void push_back(const T & v); //用于在数组尾部添加一个元素v
    VariableArray & operator=(const VariableArray & a); //用于数组对象间的赋值
    T size()
    {
        return lenth;
    }
    T & operator[](int i)
    {//用以支持根据下标访问数组元素，如a[i] = 4;和n = a[i]这样的语句
        return ptr[i];
    }
};

template<class T>
VariableArray<T>::VariableArray(int num):lenth(num)
{
    if (num == 0)
        ptr = NULL;
    else
        ptr = new T[num];
}

template<class T>
VariableArray<T>::VariableArray(VariableArray & a)
{
    if (!a.ptr) {
        ptr = NULL;
        lenth = 0;
        return;
    }
    ptr = new T[a.lenth];
    memcpy(ptr, a.ptr, lenthof(T) * a.lenth);
    lenth = a.lenth;
}

template <class T>
VariableArray<T>::~VariableArray()
{
    if (ptr) delete[] ptr;
}

template <class T>
VariableArray<T> & VariableArray<T>::operator=(const VariableArray & a)
{ //赋值号的作用是使"="左边对象里存放的数组，大小和内容都和右边的对象一样
    if (this == &a) //防止a=a这样的赋值导致出错
        return *this;
    if (a.ptr == NULL) {  //如果a里面的数组是空的
        if (ptr)
            delete[] ptr;
        ptr = NULL;
        lenth = 0;
        return *this;
    }
    if (lenth < a.lenth) { //如果原有空间够大，就不用分配新的空间
        if (ptr)
            delete[] ptr;
        ptr = new T[a.lenth];
    }
    memcpy(ptr, a.ptr, sizeof(T)*a.lenth);
    lenth = a.lenth;
    return *this;
}

template <class T>
void VariableArray<T>::push_back(const T & v)
{  //在数组尾部添加一个元素
    if (ptr) {
        T *tmpPtr = new T[lenth + 1]; //重新分配空间
        memcpy(tmpPtr, ptr, sizeof(T)*lenth); //拷贝原数组内容
        delete[]ptr;
        ptr = tmpPtr;
    }
    else  //数组本来是空的
        ptr = new T[1];
    ptr[lenth++] = v; //加入新的数组元素
}



int main()
{
    Point<int, int> p1(10,20);
    cout << "x=" << p1.getX() << ", y=" << p1.getY() << endl;

    Point<int, char*> p2(10, "东经180度");
    cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;

    Point<char*, char*> *p3 = new Point<char*, char*>("东经180度", "北纬210度");
    cout << "x=" << p3->getX() << ", y=" << p3->getY() << endl;

    VariableArray<int> a;
    for (int i = 0; i < 5; ++i)
        a.push_back(i);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}