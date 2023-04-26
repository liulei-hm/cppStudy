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

#define expA(s) printf("ǰ׺���Ϻ���ַ���Ϊ:%s\n",gc_##s)  //gc_s�������
// ע������2
#define expB(s) printf("ǰ׺���Ϻ���ַ���Ϊ:%s\n",gc_  ##  s)  //gc_s�������
// ע������1
#define gc_hello1 "I am gc_hello13"


// �����ţ�����չ������
#define MAX(A, B) ((A)>(B)? (A):(B))

// ������������, ��MAX(i++, j++);
#define MAX_PRO1(A, B) ({	\
	int a = A; 	\
	int b = B;	\
	a > b ? a : b;	\
})

// ���ݲ�ͬ�������ͣ��Ҳ�����ʽָ������
#define MAX_PRO3(A, B) ({	\
	typeof(A) a = A; 	\
	typeof(B) b = B;	\
	(void) (&a == &b);	\
	a > b ? a : b;		\
})
// (void) (&a == &b); �����ж������Ƿ�һ��,���������ж����������ĵ�ַ�Ƿ���ͬ��ʱ����ȶ������ͽ����ж�
// �����ͬ������жϵ�ַ�Ƿ���ͬ����������������һ�����棬������Ա��Ѳ������ͻ��õ�ʱ����ʱ�������ͻ�������汨��
// ����Ԥ����ʱ������ flaot * == int * �ж�
// �����������Ͳ�һ�£������ʾ���档



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
