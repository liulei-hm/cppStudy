//
// Created by liulei on 2023/3/16.
//
#include <iostream>
#include <mutex>
#include <vector>
#include <string>
#include <ctime>
#include <thread>

using namespace std;

// 时间模拟消息
string mock_msg()
{
    char buff[30] = { 0 };
    static int i = 10;
    sprintf_s(buff, "%d", i--);
    return buff;
}

class CMutexTest
{
public:
    void recv_msg(); //接收消息
    void read_msg(); //处理消息
private:
    vector<string> msg_queue; //消息队列
    mutex m_mutex;	//互斥量
};

// 模拟接收消息
void CMutexTest::recv_msg()
{
    while (true)
    {
        string msg = mock_msg();
        cout << "recv the msg " << msg << endl;

        // 使用"{ }"限定lock_guard作用域
        {
            lock_guard<mutex> mylockguard(m_mutex);
            // 消息添加到队列
            msg_queue.push_back(msg);
        }
        this_thread::sleep_for(chrono::milliseconds(10));//方便观察数据
    }
}

// 模拟读取处理
void CMutexTest::read_msg()
{
    while (true)
    {
        // 已经加锁
        m_mutex.lock();
        // 传递所有权给lock_guard,并传入adopt_lock表示已获得所有权
        lock_guard<mutex> mylockguard(m_mutex, adopt_lock);
        if (!msg_queue.empty())
        {
            // 处理消息并移除
            string msg = msg_queue.front();
            cout << "read the msg " << msg << endl;
            msg_queue.erase(msg_queue.begin());
        }
        this_thread::sleep_for(chrono::milliseconds(15));//方便观察数据
    }
}

int main()
{
    CMutexTest my_test;
    thread recv_thread(&CMutexTest::recv_msg, &my_test); //接收线程
    thread read_thread(&CMutexTest::read_msg, &my_test); //处理线程

    recv_thread.join();
    read_thread.join();
}
#if 0 //源码，自身作用域（生命周期）中具有构造时加锁，析构时解锁的功能
template <class _Mutex>
class lock_guard { // class with destructor that unlocks a mutex
public:
    using mutex_type = _Mutex;
    //无adopt_lock参数，构造时加锁
    explicit lock_guard(_Mutex& _Mtx) : _MyMutex(_Mtx) { // construct and lock
        _MyMutex.lock();
    }
    //有adopt_lock参数，构造时不加锁
    lock_guard(_Mutex& _Mtx, adopt_lock_t) : _MyMutex(_Mtx) {} // construct but don't lock
    //析构解锁
    ~lock_guard() noexcept {
        _MyMutex.unlock();
    }
    //屏蔽拷贝构造
    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;

private:
    _Mutex& _MyMutex;
};
#endif

