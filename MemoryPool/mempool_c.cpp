//
// Created by liulei on 2023/4/15.
//
#include <stdio.h>
#include <iostream>
#define POOL_SIZE 1024

typedef struct mempool {
    char buffer[POOL_SIZE];
    size_t used;
} mempool_t;

void* mp_alloc(mempool_t* mp, size_t size) {
    if (mp->used + size > POOL_SIZE) {
        return NULL;
    }

    void* p = mp->buffer + mp->used;
    mp->used += size;

    return p;
}

void mp_free(mempool_t* mp, void* ptr) {
    // �ڴ���в���Ҫ��ʽ�ͷ��ڴ�
}

// ʾ���÷�
int main() {
    mempool_t mp = { 0 };

    int* p = (int*)mp_alloc(&mp, sizeof(int));
    *p = 42;
    std::cout << *p;
    // �ڴ���в���Ҫ��ʽ�ͷ��ڴ�

    return 0;
}
