//
// Created by liulei on 2023/4/15.
//

#include "all.h"

// 3.58
subq: ִ�������������ļ�����������洢��Ŀ��������С�
imulq: ִ�������������ĳ˷���������洢��Ŀ��������С���ָ�������Ը���һ�����������߼Ĵ�����ָ��������
movq: ��Դ��������ֵ���Ƶ�Ŀ��������С�
salq: ִ�����Ʋ������������������ƶ�ָ��λ��������0����ұߵĿ�λ��
sarq: ִ���������Ʋ������������������ƶ�ָ��λ��������λ���ֲ��䣬���÷���λ�����ߵĿ�λ��
xorq: ִ��������������������������������㣬��������洢��Ŀ��������С�
long decode(long x, long y, long z) {
    long tmp = y - z;
    return (tmp * x) ^ (tmp << 63 >> 63);
}

// 3.60
A��
x	%rdi
n	%esi
result	%rax
mask	%rdx
B��
result ��ʼֵΪ 0
mask ��ʼֵΪ 1
C��
mask���������� mask != 0
D��
mask = mask << n
E��
result |= (x & mask);
F��
long loop2(long x, int n) {
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask <<= n) {
        result |= (x & mask);
    }
    return result;
}
// 3.63
long switch_prob(long x, long n) {
    long result = x;
    switch(n) {
        /* Fill in code here */
        case 60:
        case 62:
            result = x * 8;
            break;
        case 63:
            result = x >> 3;
            break;
        case 64:
            x = x << 4 - x;
        case 65:
            x = x * x;
        default:
            result = x + 0x4B;
    }
    return result;
}

// 3.69
A:
7*40 + 8 = 288 = 0x120
CNT = 7
B:
typedef struct {
    long idx,
    long x[4]
} a_struct

// 3.70
A:
e1.p	0
e1.y	8
e2.x	0
e2.next	8
B:
�ܹ�16�ֽ�
C:
void proc(union ele *up) {
    up->e2.x = *( *(up->e2.next).e1.p ) - *(up->e2.next).e1.y
}