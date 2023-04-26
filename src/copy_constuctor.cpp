//
// Created by liulei on 2023/4/14.
//
#include <iostream>

using namespace std;
class Light_Copy
{
public:
    int *p;
    Light_Copy()
    {
        p=new int(4);
        cout << "Light_Copy default constructor" << endl;
    };
    ~Light_Copy(){ delete p; };
};

class Deep_Copy
{
public:
    int *p;
    Deep_Copy()
    {
        p=new int(4);
        cout << "Deep_Copy default constructor" << endl;
    };
    Deep_Copy(const Deep_Copy &t)
    {
        p = new int;
        *(p) = *(t.p);//Ϊ��������µ��ڴ棬��ʹ��Դ�����е�ֵ�������¹���
        cout << "Deep_Copy copy constructor" << endl;
    }
    ~Deep_Copy(){ delete p; };
};

void test_copy(){
    /**Ĭ�Ͽ������캯�� ǳ���� ����ʱ����ڴ��ظ��ͷ�,����****/
    //Light_Copy t1;//Ĭ�Ϲ��캯���������t1
    //Light_Copy t2(t1);//��Ϊû�п������캯��������Ĭ�ϸ��ƹ��캯��(ǳ����)����ʱt1.p��t2.pָ��ָ��ͬһ��ַ
    //Light_Copy t3 = t1;//��Ϊû�п������캯��������Ĭ�ϸ��ƹ��캯��(ǳ����)����ʱt1.p��t2.p��t3.pָ��ָ��ͬһ��ַ

    /**�������캯�� ��� ****/
    Deep_Copy t4;
    Deep_Copy t5(t4);  //�п������캯��
    Deep_Copy t6 = t4; //�п������캯��
}

//����ʱ�����cmake�йرձ������Ż�
int main(){
    test_copy();
    return 0;
}
