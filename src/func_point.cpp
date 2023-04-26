//
// Created by liulei on 2023/3/20.
//
#include <stdio.h>
#include <cstring>
#include "all.h"

void function_1(int a) {
    printf("function_1: %d\n", a);
}

void function_2(int a) {
    printf("function_2: %d\n", a);
}

void function_3(int a) {
    printf("function_3: %d\n", a);
}

//函数指针作为形参  实质：void(* cp)(int) = function_1
void call_f(void(*p)(int), int a) {
    p(a);
}

//回调函数
typedef struct {
    string name;
    int age;
} stu;

void callback_function_1(stu *stu_t);

void callback_function_2(stu *stu_t);

void callback_function_3(stu *stu_t);

typedef struct {
    char *name;

    void (*p)(stu *);

} work_list;


work_list work_list_t[3] =
        {
                {"f1", callback_function_1},
                {"f2", callback_function_2},
                {"f3", callback_function_3},
        };

void callback_function_1(stu *stu_t) {
    printf("[callback_function_1]$ ");
    printf("age:%d,name:%s\n", stu_t->age, stu_t->name.c_str());

}

void callback_function_2(stu *stu_t) {
    printf("[callback_function_2]$ ");
    printf("age:%d,name:%s\n", stu_t->age, stu_t->name.c_str());

}

void callback_function_3(stu *stu_t) {
    printf("[callback_function_3]$ ");
    printf("age:%d,name:%s\n", stu_t->age, stu_t->name.c_str());

}

void work_callback_function(char *inchars) {
    stu stu_t;
    for (int i = 0; i < 3; i++) {
        if (strcmp(work_list_t[i].name, inchars) == 0) {
            stu_t.age = i;
            stu_t.name = work_list_t[i].name;
            return work_list_t[i].p(&stu_t);
        }
    }
    printf("NO this function\n");
}


void test_loop() {
    char inchars[20];
    while (1) {
        printf("[Lng-> ]$ ");
        scanf("%s", inchars);
        work_callback_function(inchars);
    }
}


int main() {
    //1.一般函数指针
    void (*p_1)(int);//定义一个函数指针
    p_1 = function_1;//该指针指向function_1入口
    printf("%p\n", p_1);
    printf("%p\n", function_1);
    p_1(1);//调用该函数

    //2.函数指针作形参
    void (*p_2)(int) = function_2;//定义一个函数指针
    call_f(p_1, 2);
    call_f(p_2, 3);

    //3.函数指针数组
    void (*p_arr[3])(int) = {function_1, function_2, function_3};
    p_arr[0](1);
    p_arr[1](2);
    p_arr[2](3);

    //回调函数
    stu stu_t = {"liulei", 1};
    work_list_t[0].p(&stu_t);

}
