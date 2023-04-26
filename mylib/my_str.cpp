#include <stdio.h>
#include <assert.h>
#include <string.h>
//Ϊʲôʹ��char *��β Ϊ����ʽ����strcpy(buf,strcat(dest,src));
//
//����size_t �޷�������  strlen(x)-strlen(y)>0�Ǵ���ģ��޷��������������Ǹ���
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
/* strtok �ַ����ָ��
 * ���� str��Ҫ���ֽ���ַ��� delim�������ָ������ַ���������һ����Ҳ�����Ǽ��ϣ�
 * ����ֵ �ú������ر��ֽ�ĵ�һ�����ַ��������޿ɼ������ַ������򷵻ؿ�ָ��
 * */
char *strtok(char *str, const char *delim) {
    static char *next_start = NULL;  //���浽��̬�洢�����������غ󲻻ᱻ����

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

                if (s == str)    //��һ���ַ����Ƿָ���
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
�������ã������ַ������ȣ���������ֹ�� '\0'��
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
�������ã��� src ��ָ����ַ������Ƶ� dest��
ע�⣺dest����Ŀռ�Ӧ�ñ�src��
*/
//char*������ʽ����
char *my_strcpy(char *dest, const char *src) {
    char *ret = dest;
    assert(dest != NULL);
    assert(src != NULL);
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    //���'\0'��������
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
�������ã��� src ��ָ����ַ���׷�ӵ� dest ��ָ����ַ����Ľ�β��
*/
char *my_strcat(char *dest, const char *src) {
    //1.��dest��'\0'
    //2.Դ������Ŀ��
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
    //��'\0'��������
    *dest = *src;
    return ret;
}

/*
�������ã��� str1 ��ָ����ַ����� str2 ��ָ����ַ������бȽϡ�
�ú�������ֵ���£�
�������ֵ < 0�����ʾ str1 С�� str2��
�������ֵ > 0�����ʾ str1 ���� str2��
�������ֵ = 0�����ʾ str1 ���� str2��
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
    //����һ���ַ����Ѿ��ߵ���β
    if (*str1 > *str2) {
        return 1;
    } else if (*str1 < *str2) {
        return -1;
    } else {
        return 0;
    }
}


/*
�������ã����ַ��� str �в��ҵ�һ�γ����Ӵ� substr ��λ�ã���������ֹ�� '\0'��
���أ�ָ���λ�õ�ָ�룬���substrû�������ĳ�����str���κεط�������NULL�����substrΪ�գ�����str
������
*/

char *my_strstr(const char *str, const char *substr) {
    if (*substr == '\0' || *str == '\0') {
        return (char *) str;
    }
    char *p1 = NULL;
    char *p2 = NULL;
    /* ����p1�ַ���  */
    while (*str != '\0') {
        p1 = (char *) str;
        p2 = (char *) substr;
        while (*p1++ == *p2) {
            p2++;
        }
        if (*p2 == '\0') /*����sub�Ľ���λ�ã�����srcλ��   */
        {
            return p1;
        }
        str++;
    }
    return NULL;
}
