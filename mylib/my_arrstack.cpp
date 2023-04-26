#include <stdio.h>
#include <stdlib.h>

//元素elem进栈，a为数组，top值为当前栈的栈顶位置
int push(int *a,int top,int elem) {
	a[++top] = elem;
	return top;
}

//数据元素出栈
int pop(int * a, int top) {
	if (top == -1) {
		printf("空栈");
		return -1;
	}
	printf("弹栈元素：%d\n", a[top]);
	top--;
	return top;
}


//定义时  int a[100]; int top=-1；