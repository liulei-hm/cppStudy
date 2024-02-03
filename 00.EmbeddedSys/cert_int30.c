//
// Created by liulei on 2023/6/18.
//

#include "cert_int30.h"


#include <stdio.h>
#include <stdint.h>

#define CHECK_UINT32(a) \
    do { \
        typeof(a) _a = a; \
        uint32_t _b;    \
        (void) (&_a == &_b);\
        if (sizeof(a) != sizeof(uint32_t)) { \
            fprintf(stderr, "参数a不是uint32_t类型\n"); \
            /* 进行相应的处理 */ \
        } else { \
            /* 参数a是uint32_t类型，进行相应的操作 */ \
        } \
    } while (0)



#define MAX(a, b) { \
    if (a > b) { \
        printf("%d is greater\n", a); \
    } else { \
        printf("%d is greater\n", b); \
    } \
}


int main() {
    uint32_t value = 42;
    uint8_t v = 3;
    CHECK_UINT32(value);
    int x = -15;
    int y = 10;

    char array[] = {7,2,3,4,5,6,7};
    int *pa = (int *) array;
    char *pb = array;
    pa++;
    pb++;
    printf("%d,%d\n",*(char *)pa,*pb);
    return 0;
}
