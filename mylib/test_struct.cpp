#include <iostream>
using namespace std;
struct  A{
	int a;                            //4 bytes
	char b;                        //1 bytes
								   //char pad[3]               //3 bytes
	int c;                           //4 bytes
	char d;                       //1 bytes
								  //char pad[3]              //3 bytes
};                            // total = 16 bytes

struct  P{
	struct A w[2];    // 2 * 16 bytes
	short b;            //2 bytes
	int ss;
	//struct A* p;      //4 bytes
};  // total = 40 bytes


void test_sizeofstruct()
{
	cout << "sizeof(A)=" << sizeof(A) << endl;
	cout << "sizeof(p)=" << sizeof(P) << endl;
	cout << "sizeof(struct A*)=" << sizeof(struct A*) << endl;
	cout << "sizeof(int*)=" << sizeof(int *) << endl;
}









#if 0
//ps:��ͷ�ļ���ֻ�������ṹ�� ���ܶ������������ض���
//һ ֱ�Ӷ���ṹ������򵥵����Ժ����ô˶���ṹ��
struct //���ṹ������ȱʡ��
{
	char a;
	char b;
}st_sum1, st_sum2;


//�� ֱ�Ӷ���ṹ����� 
struct ST_NAME
{
	char a;
	char b;
};
struct ST_NAME st_sum3;

//ͬ��
struct ST_NAME1 {
	char a;
	char b;
}st_sum4;
struct ST_NAME1 st_sum5;

//��
typedef struct {
	char a;
	char b;
}DATA;
DATA st_sum6;

//ͬ�� �Ƚϳ���
typedef struct data {
	char a;
	char b;
}DATA1;
DATA1 st_sum7;

#endif