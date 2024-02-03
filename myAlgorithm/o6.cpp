#include <bits/stdc++.h>
using namespace std;


struct TimerNodeBase{
    time_t expire; //到达时间
    int64_t tid;   //用来唯一标识定时器
//    bool operator < (const TimerNodeBase &n) const{
//        if(expire < n.expire) //按超时时间排序
//            return true;
//        else if(expire > n.expire)
//            return false;
//        else if(expire == n.expire)
//        {
//            return tid<n.tid; //超时时间相同，此时id更小的排在前面
//        }
//        return false;
//    }
};

int main(){
    TimerNodeBase t;
    cout << sizeof(t) << endl;
    return 0;
}