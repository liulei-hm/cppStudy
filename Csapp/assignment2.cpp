//
// Created by liulei on 2023/4/15.
//

#include "all.h"

// 3.58
subq: 执行两个操作数的减法，将结果存储到目标操作数中。
imulq: 执行两个操作数的乘法，将结果存储到目标操作数中。在指令后面可以跟着一个立即数或者寄存器来指定乘数。
movq: 将源操作数的值复制到目标操作数中。
salq: 执行左移操作，将操作数向左移动指定位数，并用0填充右边的空位。
sarq: 执行算术右移操作，将操作数向右移动指定位数，符号位保持不变，并用符号位填充左边的空位。
xorq: 执行异或操作，将两个操作数进行异或运算，并将结果存储到目标操作数中。
long decode(long x, long y, long z) {
    long tmp = y - z;
    return (tmp * x) ^ (tmp << 63 >> 63);
}

// 3.60
A：
x	%rdi
n	%esi
result	%rax
mask	%rdx
B：
result 初始值为 0
mask 初始值为 1
C：
mask测试条件是 mask != 0
D：
mask = mask << n
E：
result |= (x & mask);
F：
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
总共16字节
C:
void proc(union ele *up) {
    up->e2.x = *( *(up->e2.next).e1.p ) - *(up->e2.next).e1.y
}