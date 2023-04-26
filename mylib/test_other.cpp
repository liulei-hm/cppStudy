#include <iostream>
#include <windows.h>
#include <time.h>
#include "my_test.h"
#include "my_datastruct.h"
#pragma pack(1)
using namespace std;

class A
{
	//int i;			//4
	union U
	{
		char buff[13];
		int i;
	}u;
	//void foo() {};
	//typedef char * (*f)(void *);
	//enum {red,green,blue} color;
}a;
union  dt {
	int a;
	char b;
	double c;
}daaa;

struct T {
	char a;
	int *d;
	int b;
	int c : 16;
	double e;
};
T *p = new T;

long fib_output[2000] = { 0 };


//测试指针字符串数组
void test_arrstr() {
	char *p1 = "Hello";
	char p2[] = "Hello";
	char p3[] = { 'H','e','l','l','o','\0' };

	cout << "*************p1是常量指针*************" << endl;
	cout << "strlen(p1)=" << strlen(p1) << endl;
	cout << "sizeof(p1)=" << sizeof(p1) << endl;
	cout << "*p1=" << *p1 << endl;
	//cout << "*p1++=" << *p1++ << endl;
	cout << "*(p1+1)=" << *(p1 + 1) << endl;
	cout << "*++p1=" << *++p1 << endl;
	cout << endl;

	cout << "*************p2是数组的初始化方式*************" << endl;
	cout << "strlen(p2)=" << strlen(p2) << endl;
	cout << "sizeof(p2)=" << sizeof(p2) << endl;
	cout << "*p2=" << *p2 << endl;
	cout << "*(p2+1)=" << *(p2 + 1) << endl;
	//cout << "*(p2+1)=" << *p2++ << endl; //错误 p2必须是可以修改的左值 
	//实际上p2是一个常量指针，而p2++的操作是p2=p2+1故错误
	//cout << "*p2=" << *++p2 << endl;
	cout << endl;


	cout << "*************p3是数组的初始化方式*************" << endl;
	cout << "strlen(p3)=" << strlen(p3) << endl;
	cout << "sizeof(p3)=" << sizeof(p3) << endl;
	cout << endl;

}
//添加函数指针作形参，必须写明变量名
void printAll(void *arr, int eleSize, int len, void(*print)(void *data)) {

	char *start = (char*)arr; //强制转型
	for (int i = 0; i < len; ++i) {
		char *eleAddr = start + i*eleSize;
		print(eleAddr);
		//print(start+i*eleSize);
	}
}

//自定义的被调用函数
void Myprint(void * data) {
	int *p = (int *)data;
	printf("%d\n", *p);
}

struct Person {
	char name[64];
	int age;
};

//添加自定义的数据类型打印函数
void MyprintStruct(void * data) {
	struct Person *p = (struct Person  *)data;
	printf("%s,%d\n", p->name, p->age);
}


int countmem_s(char *s) {
	char *t = s;
	while (*t++);
	return(t - s);
}



int getMax(int a, int b)
{
	return a > b ? a : b;
}


void func_piontofs(char *p)
{
	p = p + 1;
	*p = '8';
	cout << "p=" << p << endl;
}


int func_countstring(char *s) {
	//这时s、t、a三个地址不同，但指向的内容相同
	char *t = s;
	cout << "&t=" << &t << endl;
	cout << "&s=" << &s << endl;
	cout << "t=" << *t << endl;
	cout << "s=" << *s << endl;
	while (*t++);//每次地址加一
	return(t - s);
}


void test_mymem()
{
	char arr[20] = { 0 };
	my_strcpy(arr, " hello ");
	my_strcat(arr, " world! ");
	cout << arr << endl;
	const char *p = "abbbbbbb";
	const char *q = "abbbbbbb";

	if (my_strcmp(p, q)>0) {
		cout << "p>q" << endl;
	}
	else if (my_strcmp(p, q) < 0)
	{
		cout << "p<q" << endl;
	}
	else cout << "p=q" << endl;
	const char *a = "deee";
	char *ret = my_strstr(a, "de");
	if (ret == NULL) {
		cout << "not found" << endl;
	}
	else {
		cout << ret << endl;
	}
	cout << my_strlen(a) << endl;
	char p1[8];
	my_memcpy(p1, a, sizeof(a));
	cout << "p1:" << p1 << endl;
}

//计算文件内容的字节数
void test_filebyte() {
	FILE *fp;
	long int n;
	fp = fopen("wj.txt", "rb");
	fseek(fp, 0, SEEK_END);
	n = ftell(fp);
	fclose(fp);
	printf("the filebyte=%ld\n", n);
}
//
//计算字符串的内存大小 包括'\0'
void test_countstring() {
	char a[] = "ssadfff";
	cout << "&a=" << &a << endl;
	cout << "a=" << func_countstring(a) << endl;
	cout << "sizeof(a)=" << sizeof(a) << endl;
	cout << "strlen(a)=" << strlen(a) << endl;
}

//指针传递 函数形参是一个新的指针指向原地址，可以修改内容，但不会改变原来的指针
void test_piontofs() {
	char s[5] = { '1', '2', '3', '4','\0' };
	cout << "s=" << s << endl;
	func_piontofs(s);
	cout << "s=" << s << endl;
}

//自我存储地址 一次性使用
void test_piontofself() {
	long long a;
	a = (long long)&a;
	*(long long *)a = 10;
	cout << "a=" << a << endl;
}

//函数指针
void test_piont1() {
	int(*p)(int, int) = &getMax;
	cout << p(50, 30) << endl;
}


void testfunpiont() {
	int arr[5] = { 1,2,3,4,5 };
	printAll(arr, sizeof(int), 5, Myprint);

	struct Person person[] = {
		{ "aaa", 10 },
		{ "bbb", 20 }
	};
	printAll(person, sizeof(struct Person), 2, MyprintStruct);

}


long fib(int n) {
	if (n <= 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}
long fibss(int n)
{
	long result = fib_output[n];
	if (result == 0)
	{
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		else {
			result = fibss(n - 1) + fibss(n - 2);
			fib_output[n] = result;
		}
	}
	return result;
}

long long fibs(int n) {
	long long result;
	long long previous_res;
	long long last_res;
	result = previous_res = 1;
	while (n > 2) {
		n = n - 1;
		last_res = previous_res;
		previous_res = result;
		result = previous_res + last_res;
	}
	return result;
}


void testfib()
{
	int n;
	cin >> n;
	clock_t start_time = clock();
	for (int i = 1; i <= n; ++i) {
		cout << "fibs(" << i << "):" << fibs(i) << endl;
	}
	clock_t end_time = clock();
	cout << "程序段运行时间：" << static_cast<double> (end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}



void testfun()
{
	int f = 6;
	int aa[3][3] = { { 2 },{ 4 },{ 6 } };
	int i, *ps = &aa[0][0];
	for (i = 0; i < 2; i++) {
		if (i == 0) {
			aa[i][i + 1] = *ps + 1;
		}
		else ++ps;
		printf("aaaaaaaa %d\n", *ps);
	}
	char a = 3, b = 6, tt, hh;
	hh = a^b;
	tt = a^b << 2;
	//printf("tt = %d\n", tt);
	double x = 5;
	p->a = 2;
	p->d = &f;
	p->b = 0xdc;
	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;
	cout << sizeof(p->a) << endl;
}

void testStr()
{
	/*为什么使用指针数组而不是二维数组，二维数组要指定列数行数，若按最长的字符串来定义列数，会浪费许多的内存单元*/
	//c是一个指针数组，每个数组元素都是char*类型的指针,存放的是指针即元素地址，指针指向其中的元素
	//c[0] = "HELLO"; cpp=c+3=c[3]="SAYHI"
	char *c[] = { "HELLO", "NEW", "WORLD", "SAYHI" };
	printf("c[0]=%s\n", c[1]);
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***cpp = cp;
	printf("%s,", **++cpp);
	printf("%s,", *--*++cpp + 3);
	printf("%s,", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
}


char *str = NULL;

//这里传入的str指针的地址，一定不为空
void GetMemory(char **p, int num) {
	if (NULL == p || num <= 0)//1
		return;
	*p = (char*)malloc(num);
	return;
}


void testGetMem()
{
	GetMemory(&str, 20); //2
	if (NULL != str) {
		strcpy(str, "dasdadffs\n"); //3
		printf(str);
	}
	free(str);
	str = NULL;

}


void test_malloc() {
	int *p = (int *)malloc(sizeof(int) * 100);
	p[10] = 2;
	cout << &p << endl;
	cout << p << endl;
	free(p);
	if (p == NULL) {
		cout << "dd" << endl;
	}
	else
	{
		cout << p[10] << endl;
		cout << &p << endl;
		cout << *p << endl;
		cout << p << endl;
	}
}

void little_test()
{
	char st[20] = "hello\0\t\\\"";
	printf("%d %d \n", my_strlen(st), sizeof(st));
	printf("%s \n", st);
	int *k[10][30];
	int *p[10];
	char *str = "asdafffggghhhh";
	printf("sizeof(str)=%d\n", sizeof(str));
	printf("sizeof(p)=%d\n", sizeof(p));
	printf("sizeof(k)=%d\n", sizeof(k));
	char c = 128;
	printf("c=%d\n", c);
}
