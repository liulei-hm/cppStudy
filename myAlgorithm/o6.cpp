#include <bits/stdc++.h>
using namespace std;


struct TimerNodeBase{
    time_t expire; //����ʱ��
    int64_t tid;   //����Ψһ��ʶ��ʱ��
//    bool operator < (const TimerNodeBase &n) const{
//        if(expire < n.expire) //����ʱʱ������
//            return true;
//        else if(expire > n.expire)
//            return false;
//        else if(expire == n.expire)
//        {
//            return tid<n.tid; //��ʱʱ����ͬ����ʱid��С������ǰ��
//        }
//        return false;
//    }
};

int main(){
    TimerNodeBase t;
    cout << sizeof(t) << endl;
    return 0;
}