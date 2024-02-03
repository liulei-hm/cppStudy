//
// Created by liulei on 2023/5/18.
//
#include <stdio.h>


int main()
{

    char strArray[][10] = { "Hello", "World", "OpenAI" };
    int size = sizeof(strArray) / sizeof(strArray[0]);

    for (int i = 0; i < size; i++) {
        printf("%s\n", strArray[i]);
    }

    char *str[3]={"ab","ddd","sadw"};
    int size1 = sizeof(str) / sizeof(str[0]);

    for (int i = 0; i < size1; i++) {
        printf("%s\n", str[i]);
    }



    return 0;
}