#include <stdio.h>
#include <assert.h>
#include <string.h>
//为什么使用char *结尾 为了链式调用strcpy(buf,strcat(dest,src));
//
//关于size_t 无符号整数  strlen(x)-strlen(y)>0是错误的，无符号整数绝不会是负的
int lib_atoi(const char *str) {
    int num = 0;
    int sign = 1;
    const int len = strlen(str);
    int i = 0;
    while (str[i] == ' ' && i < len)
        i++;
    if (str[i] == '+')
        i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        if (num > INT_MAX / 10 ||
            (num == INT_MAX / 10 &&
             (str[i] - '0') > INT_MAX % 10)) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + str[i] - '0';
    }
    return num * sign;
}

int my_atoi(char *str) {
    int result = 0;
    int flag = 1;
    if (*str == '-') {
        flag = -1;
        str++;
    }
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        } else {
            break;
        }

        str++;
    }

    return result * flag;
}
/* strtok 字符串分割函数
 * 参数 str—要被分解的字符串 delim—用作分隔符的字符（可以是一个，也可以是集合）
 * 返回值 该函数返回被分解的第一个子字符串，若无可检索的字符串，则返回空指针
 * */
char *strtok(char *str, const char *delim) {
    static char *next_start = NULL;  //保存到静态存储区，函数返回后不会被销毁

    if (str == NULL && (str = next_start) == NULL) {
        return NULL;
    }

    char *s = str;
    const char *t = NULL;

    while (*s) {
        t = delim;

        while (*t) {
            if (*t == *s) {
                next_start = s + 1;

                if (s == str)    //第一个字符就是分隔符
                {
                    str = next_start;
                    break;
                } else {
                    *s = '\0';
                    return str;
                }
            } else {
                t++;
            }
        }

        s++;
    }

    return NULL;
}


/*
函数作用：返回字符串长度，不包含终止符 '\0'。
*/
size_t my_strlen(const char *s) {
    assert(s != NULL);
    int len;
    for (len = 0; *s != '\0'; len++) {
        s++;
    }
    return len;
}



/*
函数作用：把 src 所指向的字符串复制到 dest。
注意：dest定义的空间应该比src大。
*/
//char*用于链式访问
char *my_strcpy(char *dest, const char *src) {
    char *ret = dest;
    assert(dest != NULL);
    assert(src != NULL);
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    //最后将'\0'拷贝进入
    *dest = *src;
    return ret;
}

char *my_strcpy1(char *dest, const char *src) {
    assert(dest != NULL);
    assert(src != NULL);
    char *ret = dest;
    while ((*dest++=*src++) != '\0');
    return ret;
}


/*
函数作用：把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
*/
char *my_strcat(char *dest, const char *src) {
    //1.找dest的'\0'
    //2.源拷贝到目标
    assert(dest != NULL);
    assert(src != NULL);
    char *ret = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    //将'\0'拷贝进入
    *dest = *src;
    return ret;
}

/*
函数作用：把 str1 所指向的字符串和 str2 所指向的字符串进行比较。
该函数返回值如下：
如果返回值 < 0，则表示 str1 小于 str2。
如果返回值 > 0，则表示 str1 大于 str2。
如果返回值 = 0，则表示 str1 等于 str2。
*/
int my_strcmp(const char *str1, const char *str2) {

    assert(str1 != NULL);
    assert(str2 != NULL);
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2)
            return 1;
        else if (*str1 < *str2)
            return -1;
        else {
            str1++;
            str2++;
        }
    }
    //当有一个字符串已经走到结尾
    if (*str1 > *str2) {
        return 1;
    } else if (*str1 < *str2) {
        return -1;
    } else {
        return 0;
    }
}


/*
函数作用：在字符串 str 中查找第一次出现子串 substr 的位置，不包含终止符 '\0'。
返回：指向该位置的指针，如果substr没有完整的出现在str的任何地方，返回NULL，如果substr为空，返回str
暴力法
*/

char *my_strstr(const char *str, const char *substr) {
    if (*substr == '\0' || *str == '\0') {
        return (char *) str;
    }
    char *p1 = NULL;
    char *p2 = NULL;
    /* 遍历p1字符串  */
    while (*str != '\0') {
        p1 = (char *) str;
        p2 = (char *) substr;
        while (*p1++ == *p2) {
            p2++;
        }
        if (*p2 == '\0') /*到了sub的结束位置，返回src位置   */
        {
            return p1;
        }
        str++;
    }
    return NULL;
}
