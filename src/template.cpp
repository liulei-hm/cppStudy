//
// Created by liulei on 2023/3/4.
//
#include "all.h"
//C++����ģ�����ֶ��巽ʽ template < typename T>  ��  template <class T>
//�������������ؿ��Ժ�������������ͬ�����Ͳ�ͬ����ģ��ֻ�����Ͳ�ͬ��ͬʱ����ʱ���ȵ�������
//ģ����������ͳ�Ա�����������һ��.h�ļ���
/********************************************��ģ��****************************************************/
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
    T1 m_x; //x����
    T2 m_y; //y����
};

template<typename T1, typename T2>  //ģ��ͷ
T1 Point<T1, T2>::getX() const /*����ͷ*/ {
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

/********************************************��ģ��ʵ�ֿɱ䳤����****************************************************/
//ÿ������1����newһ���µĿռ�Ȼ�󿽱���ȥ
template <class T>
class VariableArray
{
    int lenth; //����Ԫ�صĸ���
    T *ptr; //ָ��̬���������
public:
    //���캯������
    VariableArray(int num = 0);  //s��������Ԫ�صĸ���
    VariableArray(VariableArray & a);
    ~VariableArray();
    void push_back(const T & v); //����������β�����һ��Ԫ��v
    VariableArray & operator=(const VariableArray & a); //������������ĸ�ֵ
    T size()
    {
        return lenth;
    }
    T & operator[](int i)
    {//����֧�ָ����±��������Ԫ�أ���a[i] = 4;��n = a[i]���������
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
{ //��ֵ�ŵ�������ʹ"="��߶������ŵ����飬��С�����ݶ����ұߵĶ���һ��
    if (this == &a) //��ֹa=a�����ĸ�ֵ���³���
        return *this;
    if (a.ptr == NULL) {  //���a����������ǿյ�
        if (ptr)
            delete[] ptr;
        ptr = NULL;
        lenth = 0;
        return *this;
    }
    if (lenth < a.lenth) { //���ԭ�пռ乻�󣬾Ͳ��÷����µĿռ�
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
{  //������β�����һ��Ԫ��
    if (ptr) {
        T *tmpPtr = new T[lenth + 1]; //���·���ռ�
        memcpy(tmpPtr, ptr, sizeof(T)*lenth); //����ԭ��������
        delete[]ptr;
        ptr = tmpPtr;
    }
    else  //���鱾���ǿյ�
        ptr = new T[1];
    ptr[lenth++] = v; //�����µ�����Ԫ��
}



int main()
{
    Point<int, int> p1(10,20);
    cout << "x=" << p1.getX() << ", y=" << p1.getY() << endl;

    Point<int, char*> p2(10, "����180��");
    cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;

    Point<char*, char*> *p3 = new Point<char*, char*>("����180��", "��γ210��");
    cout << "x=" << p3->getX() << ", y=" << p3->getY() << endl;

    VariableArray<int> a;
    for (int i = 0; i < 5; ++i)
        a.push_back(i);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}