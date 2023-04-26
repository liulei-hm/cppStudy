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

#define BUFFER_SIZE 10  // ��������С

int buffer[BUFFER_SIZE];  // ����������
int count = 0;  // ����������������

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // ������
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  // ��������

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;  // ����һ�������
        pthread_mutex_lock(&mutex);  // ����
        while (count == BUFFER_SIZE) {  // �������������ȴ�
            pthread_cond_wait(&cond, &mutex);  // �ȴ���������������
        }
        buffer[count++] = item;  // ��������ӵ�������
        printf("producer produces item %d\n", item);
        pthread_cond_signal(&cond);  // ����һ���ȴ����߳�
        pthread_mutex_unlock(&mutex);  // ����
        sleep(2);
    }
    return NULL;
}

void *consumer(void *arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex);  // ����
        while (count == 0) {  // ������Ϊ�գ��ȴ�
            pthread_cond_wait(&cond, &mutex);  // �ȴ���������
        }
        item = buffer[--count];  // �ӻ�����ȡ������
        printf("consumer consumes item %d\n", item);
        pthread_cond_signal(&cond);  // ����һ���ȴ����߳�
        pthread_mutex_unlock(&mutex);  // ����
    }
    return NULL;
}

int main() {
    pthread_t producer_tid, consumer_tid;
    srand(time(NULL));  // ��ʼ�����������

    // ���������ߺ��������߳�
    pthread_create(&producer_tid, NULL, producer, NULL);
    pthread_create(&consumer_tid, NULL, consumer, NULL);

    // �ȴ��߳̽���
    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    return 0;
}
