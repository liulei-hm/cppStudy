//
// Created by liulei on 2023/4/19.
//
#include "all.h"

class hungry_singleton{
public:
    hungry_singleton(){};
    static hungry_singleton *instance();
    static int num;
private:
    static hungry_singleton *p;
};

int hungry_singleton::num = 3;
hungry_singleton *hungry_singleton::p = new hungry_singleton();

hungry_singleton *hungry_singleton::instance() {
    return p;
}

void test_singleton(){
    hungry_singleton *s1 = hungry_singleton::instance();
    hungry_singleton *s2 = hungry_singleton::instance();

    cout << s1 << "  " << s2 << endl;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
    assert(dest != NULL);
    assert(src != NULL);
    if (dest == src) return NULL;
    char *pdest = (char *) dest; //不能用(void*)的指针++所以转化为char*
    const char *psrc = (const char *) src;
    while (n--) {
        *pdest++ = *psrc++;
    }
    return dest;
}

void my_memcpy_test() {
    char src[20] = "Hello, world!";
    char dst[20];
    my_memcpy(dst, src, strlen(src) + 1);
    printf("dst: %s\n", dst);
}

void *my_strcpy(char *dest, const char *src) {
    assert(dest != NULL);
    assert(src != NULL);
    char *temp = dest;
    while (*src != '\0') {
        *temp++ = *src++;
    }
    //最后将'\0'拷贝进入
    *temp = *src;
    return dest;
}

void my_strcpy_test() {
    char src[20] = "Hello, world!";
    char dst[20];
    my_strcpy(dst, src);
    printf("dst: %s\n", dst);
}

void *my_memmove(void *dest, const void *src, size_t n) {
    char *dst = (char *) dest;
    const char *src_ptr = (const char *) src;
    if (dst <= src_ptr || dst >= src_ptr + n) {
        // No overlap, use memcpy
        while (n--) {
            *dst++ = *src_ptr++;
        }
    } else {
        // Overlap, use memmove
        src_ptr += n - 1;
        dst += n - 1;
        while (n--) {
            *dst-- = *src_ptr--;
        }
    }
    return dest;
}

void my_memmove_test() {
    char str[20] = "hello world";
    printf("Before memmove: %s\n", str);
    memmove(str + 6, str + 1, 5);
    printf("After memmove: %s\n", str);

    char my_str[20] = "hello world";
    printf("Before my_memmove: %s\n", my_str);
    my_memmove(my_str + 6, my_str + 1, 5);
    printf("After my_memmove: %s\n", my_str);
}



int main() {
    test_singleton();
    return 0;
}