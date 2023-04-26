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

        // ��Ϣ��ӵ�����
        m_mutex.lock();
        msg_queue.push_back(msg);
        m_mutex.unlock();
        this_thread::sleep_for(chrono::seconds(2));
    }
}

// ģ���ȡ����
void CMutexTest::read_msg()
{
    // ���Լ���
    while(true)
    {
        //cout << "1" << endl;
        if (m_mutex.try_lock())
        {
            // �����ɹ�
            if (!msg_queue.empty())
            {
                // ������Ϣ���Ƴ�
                string msg = msg_queue.front();
                cout << "read the msg " << msg << endl;
                msg_queue.erase(msg_queue.begin());
            }
            m_mutex.unlock();
        }
        else
        {
            // ����ʧ��
            cout << "trylock failed" <<  endl;
            this_thread::sleep_for(chrono::seconds (2));
        }
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
