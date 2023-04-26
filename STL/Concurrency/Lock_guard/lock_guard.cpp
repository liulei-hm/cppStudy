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

// ʱ��ģ����Ϣ
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
    void recv_msg(); //������Ϣ
    void read_msg(); //������Ϣ
private:
    vector<string> msg_queue; //��Ϣ����
    mutex m_mutex;	//������
};

// ģ�������Ϣ
void CMutexTest::recv_msg()
{
    while (true)
    {
        string msg = mock_msg();
        cout << "recv the msg " << msg << endl;

        // ʹ��"{ }"�޶�lock_guard������
        {
            lock_guard<mutex> mylockguard(m_mutex);
            // ��Ϣ��ӵ�����
            msg_queue.push_back(msg);
        }
        this_thread::sleep_for(chrono::milliseconds(10));//����۲�����
    }
}

// ģ���ȡ����
void CMutexTest::read_msg()
{
    while (true)
    {
        // �Ѿ�����
        m_mutex.lock();
        // ��������Ȩ��lock_guard,������adopt_lock��ʾ�ѻ������Ȩ
        lock_guard<mutex> mylockguard(m_mutex, adopt_lock);
        if (!msg_queue.empty())
        {
            // ������Ϣ���Ƴ�
            string msg = msg_queue.front();
            cout << "read the msg " << msg << endl;
            msg_queue.erase(msg_queue.begin());
        }
        this_thread::sleep_for(chrono::milliseconds(15));//����۲�����
    }
}

int main()
{
    CMutexTest my_test;
    thread recv_thread(&CMutexTest::recv_msg, &my_test); //�����߳�
    thread read_thread(&CMutexTest::read_msg, &my_test); //�����߳�

    recv_thread.join();
    read_thread.join();
}
#if 0 //Դ�룬�����������������ڣ��о��й���ʱ����������ʱ�����Ĺ���
template <class _Mutex>
class lock_guard { // class with destructor that unlocks a mutex
public:
    using mutex_type = _Mutex;
    //��adopt_lock����������ʱ����
    explicit lock_guard(_Mutex& _Mtx) : _MyMutex(_Mtx) { // construct and lock
        _MyMutex.lock();
    }
    //��adopt_lock����������ʱ������
    lock_guard(_Mutex& _Mtx, adopt_lock_t) : _MyMutex(_Mtx) {} // construct but don't lock
    //��������
    ~lock_guard() noexcept {
        _MyMutex.unlock();
    }
    //���ο�������
    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;

private:
    _Mutex& _MyMutex;
};
#endif

