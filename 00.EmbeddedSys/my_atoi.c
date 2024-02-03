//
// Created by liulei on 2023/6/18.
//

#include "my_atoi.h"
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

int my_atoi(const char *str) {
    int result = 0;
    bool isNegative = false;
    // ����ָ��
    if (str == NULL)
    {

    }
    else
    {
        // ����ǰ���ո�
        while (*str == ' ')
        {
            str++;
        }
        // ����������
        if (*str == '+' || *str == '-')
        {
            isNegative = (*str == '-');
            str++;
        }
        // ���������ַ�
        while (*str >= '0' && *str <= '9')
        {
            // ����������
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (*str - '0') > INT_MAX % 10))
            {
                if (isNegative == 1)
                {
                    result = INT_MIN;
                }
                else
                {
                    result = INT_MAX;
                }
                isNegative = 0;
                break;
            }
            result = result * 10 + (*str - '0');
            str++;
        }
        // ���������
        if (isNegative == 1)
        {
            result = -result;
        }
    }
    return result;
}

int my_atoi_nowrap(const char *str) {
    int result = 0;
    bool isNegative = false;
    // ����ָ��
    if (str == NULL)
    {

    }
    else
    {
        // ����ǰ���ո�
        while (*str == ' ')
        {
            str++;
        }
        // ����������
        if (*str == '+' || *str == '-')
        {
            isNegative = (*str == '-');
            str++;
        }
        // ���������ַ�
        while (*str >= '0' && *str <= '9')
        {
            result = result * 10 + (*str - '0');
            str++;
        }
        // ���������
        if (isNegative == 1)
        {
            result = -result;
        }
    }
    return result;
}

int main(){
    char *s1 = "-2147483649";
    char *s = NULL;
    printf("%d\n", my_atoi(s));
    printf("%d\n", my_atoi_nowrap(s));
    printf("%d\n", atoi(s));
    return 0;
}

