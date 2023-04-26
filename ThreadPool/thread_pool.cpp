//
// Created by liulei on 2023/4/15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
using  namespace  std;
class ThreadPool {
public:
    ThreadPool(int num_threads) : stop(false) {
        for (int i = 0; i < num_threads; ++i) {
            threads.emplace_back(std::thread(&ThreadPool::worker_thread, this));
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }

        condition.notify_all();
        for (std::thread &thread : threads) {
            thread.join();
        }
    }

    template<typename Func, typename... Args>
    void enqueue(Func&& func, Args&&... args) {
        auto task = std::make_shared<std::packaged_task<void()>>(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            if (stop) {
                throw std::runtime_error("enqueue on stopped ThreadPool");
            }

            tasks.emplace([task]() { (*task)(); });
        }

        condition.notify_one();
    }

private:
    void worker_thread() {
        while (true) {
            std::function<void()> task;

            {
                std::unique_lock<std::mutex> lock(queue_mutex);

                condition.wait(lock, [this]() { return stop || !tasks.empty(); });

                if (stop && tasks.empty()) {
                    return;
                }

                task = std::move(tasks.front());
                tasks.pop();
            }

            task();
        }
    }

    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};
std::mutex print_mtx;
void print_hello(int i) {
    lock_guard<mutex> print_lock(print_mtx);
    std::cout << "Hello from thread " << i << std::endl;
}

int main() {
    ThreadPool pool(4);

    for (int i = 0; i < 8; ++i) {
        pool.enqueue(print_hello, i);
    }

    return 0;
}
