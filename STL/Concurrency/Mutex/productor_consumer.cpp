//
// Created by liulei on 2023/4/6.
//
//
// Created by liulei on 2023/4/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10  // 缓冲区大小

int buffer[BUFFER_SIZE];  // 缓冲区数组
int count = 0;  // 缓冲区内数据数量

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // 互斥锁
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  // 条件变量

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;  // 产生一个随机数
        pthread_mutex_lock(&mutex);  // 加锁
        while (count == BUFFER_SIZE) {  // 缓冲区已满，等待
            pthread_cond_wait(&cond, &mutex);  // 等待条件变量并解锁
        }
        buffer[count++] = item;  // 将数据添加到缓冲区
        printf("producer produces item %d\n", item);
        pthread_cond_signal(&cond);  // 唤醒一个等待的线程
        pthread_mutex_unlock(&mutex);  // 解锁
        sleep(2);
    }
    return NULL;
}

void *consumer(void *arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex);  // 加锁
        while (count == 0) {  // 缓冲区为空，等待
            pthread_cond_wait(&cond, &mutex);  // 等待条件变量
        }
        item = buffer[--count];  // 从缓冲区取出数据
        printf("consumer consumes item %d\n", item);
        pthread_cond_signal(&cond);  // 唤醒一个等待的线程
        pthread_mutex_unlock(&mutex);  // 解锁
    }
    return NULL;
}

int main() {
    pthread_t producer_tid, consumer_tid;
    srand(time(NULL));  // 初始化随机数种子

    // 创建生产者和消费者线程
    pthread_create(&producer_tid, NULL, producer, NULL);
    pthread_create(&consumer_tid, NULL, consumer, NULL);

    // 等待线程结束
    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    return 0;
}
