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
    char buff[64] = { 0 };
    time_t time_result = time(nullptr);
    tm tm;
    localtime_s(&tm, &time_result);
    strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &tm);
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

        // 消息添加到队列
        m_mutex.lock();
        msg_queue.push_back(msg);
        m_mutex.unlock();
        this_thread::sleep_for(chrono::seconds(2));
    }
}

// 模拟读取处理
void CMutexTest::read_msg()
{
    // 尝试加锁
    while(true)
    {
        //cout << "1" << endl;
        if (m_mutex.try_lock())
        {
            // 加锁成功
            if (!msg_queue.empty())
            {
                // 处理消息并移除
                string msg = msg_queue.front();
                cout << "read the msg " << msg << endl;
                msg_queue.erase(msg_queue.begin());
            }
            m_mutex.unlock();
        }
        else
        {
            // 加锁失败
            cout << "trylock failed" <<  endl;
            this_thread::sleep_for(chrono::seconds (2));
        }
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
