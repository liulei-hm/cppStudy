//
// Created by liulei on 2023/3/15.
//

#include "all.h"
//��������һ��ʹ��ʱ��new
//����������ʱֱ��new
//����ͬ��������ʽ���̲߳���ȫ��, ����ʽ���̰߳�ȫ��

//˫�ؼ����+��Ƕ�Զ�����
class lazy_single {
private:
    lazy_single() {}
    static lazy_single *p;
    static mutex lock_;
public:
    static lazy_single *instance();

    // ʵ��һ����Ƕ����������
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            if(lazy_single::p)
                delete lazy_single::p;
        }
    };
    static CGarbo Garbo; // ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
};

lazy_single *lazy_single::p = nullptr;
lazy_single::CGarbo Garbo;
std::mutex lazy_single::lock_;

lazy_single* lazy_single::instance() {
    if (p == nullptr) {
        lock_guard<mutex> guard(lock_);
        if (p == nullptr)
            p = new lazy_single();
    }
    return p;
}




class hungry_single {
private:
    hungry_single() {}   //���캯��˽�л�������ģʽSingleton��
    //һ����˵�����캯�����Ƿ��ڹ�������Ҫ�ǰѹ��캯������˽���������ǲ�������紴������,����ֻ��Ҫһ�����󼴿�
    static hungry_single *p;
public:
    static hungry_single *instance();
    bool isShow = false;
};

hungry_single *hungry_single::p = new hungry_single();

hungry_single* hungry_single::instance() {
    return p;
}

class h_single{
public:
    static h_single *instance();
    class GC{
    public:
        ~GC(){
            if(h_single::p!= nullptr)
            {
                delete h_single::p;
                h_single::p= nullptr;
            }
        }
    };
private:
    h_single(){}
    static h_single *p;
};

h_single * h_single::p = new h_single();
h_single *h_single::instance() {
    return p;
}

int main(){
    hungry_single *s1 = hungry_single::instance();
    hungry_single *s2 = hungry_single::instance();
    s2->isShow = true;
    cout << s1->isShow << endl;
    return 0;
}

