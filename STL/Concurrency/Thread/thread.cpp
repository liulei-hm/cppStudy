//
// Created by liulei on 2023/3/16.
//

//https://www.runoob.com/w3cnote/cpp-std-thread.html
#include "all.h"
int test_num = 0;

void testFunc(mutex& m)
{
    for(int i = 0; i < 10; ++i)
    {

        lock_guard<mutex> l(m);  //若使用m.lock()在线程t1结束后不会自动释放
        //m.lock();
        test_num++;
        cout << this_thread::get_id() <<  ":" << test_num << " " << endl;
        //m.unlock();
    }
}


int main()
{
    mutex m;
    thread t1(testFunc, ref(m));
    thread t2(testFunc, ref(m));
    t1.join();
    t2.join();
    cout<<test_num;
}