#include <stdio.h>
#include <stdlib.h>

//Ԫ��elem��ջ��aΪ���飬topֵΪ��ǰջ��ջ��λ��
int push(int *a,int top,int elem) {
	a[++top] = elem;
	return top;
}

//����Ԫ�س�ջ
int pop(int * a, int top) {
	if (top == -1) {
		printf("��ջ");
		return -1;
	}
	printf("��ջԪ�أ�%d\n", a[top]);
	top--;
	return top;
}


//����ʱ  int a[100]; int top=-1��