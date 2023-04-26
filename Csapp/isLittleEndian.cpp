//
// Created by liulei on 2023/3/19.
//
#include "all.h"

void getByteOrder_byUnion()
{
    union un {       //����һ������������
        int i;
        char c;
    }u;
    u.i = 0x1234;       //�޸�i��ֵ��c��ֵҲ����֮�����仯
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
//char b =  *(char *)&a;  //ͨ����int(4�ֽ�)ǿ������ת����char���ֽڣ�bָ��a����ʼ�ֽڣ��͵�ַ��
bool is_little_endian()
{
    int a = 0xabcd;
    unsigned char *pa = (unsigned char *)&a;
    if(pa[0] == 0xcd)  //�͵�ַ��������ݵĵ�λ����
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*2.61*/
//ֻ�е�xΪ0��ʱ��!x ���Ϊ1�����κη�0��x��!x �����Ϊ0
int test_bit(int condition,int x){
    switch (condition) {
        case 1:
            return ~x;  //x���κ�һλ������1
        case 2:
            return !x;  //x���κ�һλ������0
        case 3:
            cout << hex << x << endl;           //0x123456ef
            cout << hex << ~0xff << endl;       //0xffffff00
            cout << hex << (x|~0xff) << endl;   //0xffffffef
            cout << hex << ~(x|~0xff) << endl;  //0x00000010
            return !~(x|~0xff);    //x�������Ч�ֽڵ�λ������1 ����1
        case 4:
            cout << hex << x << endl;                                   //0x123456ef
            cout << sizeof(int) - 1 << endl;                            //3
            cout << dec << ((sizeof(int)-1) << 3) << endl;              //24 = 3 << 3 = 3 x 2 x 2 x 2
            cout << hex << (x >>  ((sizeof(int)-1) << 3) ) << endl;     //0x12
            cout << hex << ((x >> ((sizeof(int)-1) << 3)) & 0xff) << endl;    //0x12
            return !((x >> ((sizeof(int)-1) << 3)) & 0xff);    //x�������Ч�ֽڵ�λ������0 ����1
        default:
            return 0;
    }
}
/*2.77*/
//��ʹ�� + - <<��д�� x*K �ı��ʽ
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
//����һ���޷���32λ����
unsigned f2u(float x) {
    return *(unsigned*)&x;
}
//��x<=y ����1 ���򷵻�0 ��ʹ�ü���
int float_le(float x,float y){
    cout << (y-x>=0) << endl;

    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    int con_1 = (ux<<1==0) && (uy<<1==0);  //������Ϊ0,��������λ
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
    srand(time(nullptr));//�������������
    int x =  rand();
    int y =  rand();
    int z =  rand();
    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;


    int con_1 = ((float)x == (float)dx);
    int con_2 = (dx-dy == (double)(x-y));
    int con_3 = ((dx+dy)+dz == dx+(dy+dz));
    int con_4 = ((dx*dy)*dz == dx*(dy*dz)); //����Ϊ1
    int con_5 = ((dx/dx == dz/dz));   //����Ϊ1 dz=0
//    A.��ȷ
//    B.���󣬵�yΪINT_MINʱ��x-y���
//    C.��ȷ
//    D.���󣬵�x��y��z�ϴ�ʱ��32λ�˷����ܵ��½������2^53���ᵼ������
//    E.����dx��dz����Ϊ0
    cout << x << " " << y << " " << z << " " << endl;
    cout << dx << " " << dy << " " << dz << " " << endl;
    cout << con_1 << " " << con_2 << " " << con_3 << " " << con_4 << " " << con_5 << endl;
}

/*2.91*/
//0x40490FDB -> 01000000 01001001 00001111 11011011 -> 0 10000000 10010010000111111011011
//A.0b11.0010010000111111011011
//B.0b11.001(001)
//C.С�����ھ�λ����2^?9λ

int main()
{
    //getByteOrder_byUnion();
    //is_little_endian();
    compare_random_float();
    return 0;
}
