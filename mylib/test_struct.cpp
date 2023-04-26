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
//ps:在头文件中只能声明结构体 不能定义出来否则会重定义
//一 直接定义结构体变量简单但是以后不再用此定义结构体
struct //（结构体名称缺省）
{
	char a;
	char b;
}st_sum1, st_sum2;


//二 直接定义结构体变量 
struct ST_NAME
{
	char a;
	char b;
};
struct ST_NAME st_sum3;

//同二
struct ST_NAME1 {
	char a;
	char b;
}st_sum4;
struct ST_NAME1 st_sum5;

//三
typedef struct {
	char a;
	char b;
}DATA;
DATA st_sum6;

//同三 比较常用
typedef struct data {
	char a;
	char b;
}DATA1;
DATA1 st_sum7;

#endif