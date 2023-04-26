#include  <stdio.h>
#include  <stdlib.h>
/*将参数输入文本 再从文本中逐个读出*/
void fun1(char  *s, int  a, double  f)
{
	/**********found**********/
	FILE* fp;
	char  str[100], str1[100], str2[100];
	int  a1;     double  f1;
	fp = fopen("file1.txt", "w");
	fprintf(fp, "%s  %d  %f\n", s, a, f);
	/**********found**********/
	fclose(fp);
	fp = fopen("file1.txt", "r");
	/**********found**********/
	fscanf(fp, "%s%s%s", str, str1, str2);
	fclose(fp);
	a1 = atoi(str1);
	f1 = atof(str2);
	printf("\nThe result :\n\n%s %d %f\n", str, a1, f1);
}
void fun11(char  *s, int  a, double  f)
{
	/**********found**********/
	FILE* fp;
	char  ch;
	fp = fopen("file1.txt", "w");
	fprintf(fp, "%s %d %f\n", s, a, f);
	fclose(fp);
	fp = fopen("file1.txt", "r");
	printf("\nThe result :\n\n");
	ch = fgetc(fp);
	/**********found**********/
	while (!feof(fp)) {
		/**********found**********/
		putchar(ch); ch = fgetc(fp);
	}
	putchar('\n');
	fclose(fp);
}
void test1()
{
	char  a[10] = "Hello!";    int  b = 12345;
	double  c = 98.76;
	fun1(a, b, c);
	getchar();
}

/*逆置数组元素*/
void fun2(int  a[], int  n)
{
	int  i, t;
	/**********found**********/
	for (i = 0; i<n / 2; i++)
	{
		t = a[i];
		/**********found**********/
		a[i] = a[n - 1 - i];
		/**********found**********/
		a[n - 1 - i] = t;
	}
}