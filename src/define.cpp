//
// Created by liulei on 2023/2/8.
//
#include "all.h"

void quit_command(){
    printf("I am quit command\n");
}
void help_command(){
    printf("I am help command\n");
}
struct command
{
    char * name;
    void (*function) (void);
};
#define COMMAND(NAME) {#NAME,NAME##_command}
#define PRINT(NAME) printf("token"#NAME"=%d\n", token##NAME)

#define expA(s) printf("前缀加上后的字符串为:%s\n",gc_##s)  //gc_s必须存在
// 注意事项2
#define expB(s) printf("前缀加上后的字符串为:%s\n",gc_  ##  s)  //gc_s必须存在
// 注意事项1
#define gc_hello1 "I am gc_hello13"


// 加括号，避免展开出错
#define MAX(A, B) ((A)>(B)? (A):(B))

// 避免自增问题, 如MAX(i++, j++);
#define MAX_PRO1(A, B) ({	\
	int a = A; 	\
	int b = B;	\
	a > b ? a : b;	\
})

// 兼容不同数据类型，且不用显式指定类型
#define MAX_PRO3(A, B) ({	\
	typeof(A) a = A; 	\
	typeof(B) b = B;	\
	(void) (&a == &b);	\
	a > b ? a : b;		\
})
// (void) (&a == &b); 用于判断类型是否一致,编译器在判断两个参数的地址是否相同的时候会先对其类型进行判断
// 如果相同则继续判断地址是否相同，否则编译器会给出一个警告，当程序员误把参数类型混用的时候，这时编译器就会给出警告报警
// 宏在预处理时，进行 flaot * == int * 判断
// 如果传入的类型不一致，则会提示警告。



int main(){
    int token9=9;
    PRINT(9);
    struct command commands[] = {
            COMMAND(quit),
            COMMAND(help),
    };
    commands[0].function();
    const char * gc_hello = "I am gc_hello";
    expA(hello);
    expB(hello1);
    int i= 2, j = 6;
    printf("MAX(i, j) = %d\n", MAX(i, j));
    printf("MAX(i++, j++) = %d\n", MAX(i++, j++));

    i= 2, j = 6;
    printf("MAX_PRO1(i++, j++) = %d\n", MAX_PRO1(i++, j++));

    printf("MAX_PRO3(3.1412, 3.145) = %f\n", MAX_PRO3(3.1412, 3.145));
    //printf("MAX_PRO3(3.1412, 3.145) = %f\n", MAX_PRO3(3, 3.145));
    //printf("MAX_PRO3(2.9, 3) = %f\n", MAX_PRO3(2.9, 3));
}
