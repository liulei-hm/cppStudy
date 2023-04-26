//
// Created by liulei on 2023/3/19.
//
#include "all.h"

void getByteOrder_byUnion()
{
    union un {       //定义一个联合体类型
        int i;
        char c;
    }u;
    u.i = 0x1234;       //修改i的值，c的值也会随之发生变化
    if (u.c == 0x34)
    {
        cout << "little"<<endl;
    }
    else
    {
        cout << "big"<<endl;
    }
}

/*2.58*/
//char b =  *(char *)&a;  //通过将int(4字节)强制类型转换成char单字节，b指向a的起始字节（低地址）
bool is_little_endian()
{
    int a = 0xabcd;
    unsigned char *pa = (unsigned char *)&a;
    if(pa[0] == 0xcd)  //低地址存的是数据的低位数据
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*2.61*/
//只有当x为0的时候，!x 结果为1，对任何非0的x，!x 结果都为0
int test_bit(int condition,int x){
    switch (condition) {
        case 1:
            return ~x;  //x的任何一位都等于1
        case 2:
            return !x;  //x的任何一位都等于0
        case 3:
            cout << hex << x << endl;           //0x123456ef
            cout << hex << ~0xff << endl;       //0xffffff00
            cout << hex << (x|~0xff) << endl;   //0xffffffef
            cout << hex << ~(x|~0xff) << endl;  //0x00000010
            return !~(x|~0xff);    //x的最低有效字节的位都等于1 返回1
        case 4:
            cout << hex << x << endl;                                   //0x123456ef
            cout << sizeof(int) - 1 << endl;                            //3
            cout << dec << ((sizeof(int)-1) << 3) << endl;              //24 = 3 << 3 = 3 x 2 x 2 x 2
            cout << hex << (x >>  ((sizeof(int)-1) << 3) ) << endl;     //0x12
            cout << hex << ((x >> ((sizeof(int)-1) << 3)) & 0xff) << endl;    //0x12
            return !((x >> ((sizeof(int)-1) << 3)) & 0xff);    //x的最高有效字节的位都等于0 返回1
        default:
            return 0;
    }
}
/*2.77*/
//仅使用 + - <<，写出 x*K 的表达式
int test_mul(int condition,int x,int k){
    int res = 0;
    cout << "res = " << x*k << endl;
    switch (condition) {
        case 1:
            res = (x << 4) + x;
            return res;  //x*17
        case 2:
            res = x - (x<<3);
            return res;  //x*-7
        case 3:
            res = (x << 6) - ( x << 2);
            return res;    //x*60
        case 4:
            res = (x << 4) - (x << 7);
            return res;    //x*-112
        default:
            return 0;
    }
}

/*2.84*/
//返回一个无符号32位数字
unsigned f2u(float x) {
    return *(unsigned*)&x;
}
//若x<=y 返回1 否则返回0 不使用减法
int float_le(float x,float y){
    cout << (y-x>=0) << endl;

    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    int con_1 = (ux<<1==0) && (uy<<1==0);  //两数都为0,不看符号位
    int con_2 =  sx && !sy;                 //x<0 y>0
    int con_3 = (sx && sy) && (ux>=uy);    //x<0 y<0
    int con_4 = (!sx && !sy) && (ux<=uy);  //x>0 y>0
    int res = con_1 || con_2 || con_3 || con_4 ;
    return (ux<<1==0) && (uy<<1==0) ||
    sx && !sy ||
    (sx && sy) && (ux>=uy) ||
    (!sx && !sy) && (ux<=uy);
}

/*2.89*/
void compare_random_float(){
    srand(time(nullptr));//设置随机数种子
    int x =  rand();
    int y =  rand();
    int z =  rand();
    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;


    int con_1 = ((float)x == (float)dx);
    int con_2 = (dx-dy == (double)(x-y));
    int con_3 = ((dx+dy)+dz == dx+(dy+dz));
    int con_4 = ((dx*dy)*dz == dx*(dy*dz)); //不总为1
    int con_5 = ((dx/dx == dz/dz));   //不总为1 dz=0
//    A.正确
//    B.错误，当y为INT_MIN时，x-y溢出
//    C.正确
//    D.错误，当x、y、z较大时，32位乘法可能导致结果超出2^53，会导致舍入
//    E.错误，dx、dz可能为0
    cout << x << " " << y << " " << z << " " << endl;
    cout << dx << " " << dy << " " << dz << " " << endl;
    cout << con_1 << " " << con_2 << " " << con_3 << " " << con_4 << " " << con_5 << endl;
}

/*2.91*/
//0x40490FDB -> 01000000 01001001 00001111 11011011 -> 0 10000000 10010010000111111011011
//A.0b11.0010010000111111011011
//B.0b11.001(001)
//C.小数点后第九位，即2^?9位

int main()
{
    //getByteOrder_byUnion();
    //is_little_endian();
    compare_random_float();
    return 0;
}
