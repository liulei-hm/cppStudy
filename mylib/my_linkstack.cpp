#include <stdio.h>
#include <stdlib.h>
#include "my_test.h"
#include "my_datastruct.h"
#include <iostream>
using namespace std;
//�ο���ַ http://data.biancheng.net/view/171.html ��ջʱ�����޸�
//https://blog.csdn.net/u014627536/article/details/41413975 c++��ʵ����ջ https://blog.csdn.net/qq_59708493/article/details/122562586
/******************************��ջ���Գ���*****************************/
void testLinkStack()
{
	linkStack * stack = NULL;
	linkStack top;
	stack = linkStack_push(stack, 1);
	stack = linkStack_push(stack, 2);
	stack = linkStack_push(stack, 3);
	stack = linkStack_push(stack, 4);
	stack = linkStack_pop(stack, &top);
	cout << top.data << endl;
	stack = linkStack_pop(stack, &top);
	cout << top.data << endl;
	stack = linkStack_pop(stack, &top);
	cout << top.data << endl;
	stack = linkStack_pop(stack, &top);
	cout << top.data << endl;
	stack = linkStack_pop(stack, &top);
	cout << top.data << endl;
}





/********************************��ջ*****************************/

//����ͷ�巨��Ԫ�ز��������У���������ջ��Ԫ��������ͷ
//���� head->1->NULL  push��2��  head->2->1->NULL

/*������ջ*/
void linkStack_init(linkStack *&S)//*&Ϊ���ã�����ֱ���޸�ʵ��ָ���λ��
{//��ջ����ͷ��㣬��ʼ����ջֻ��Ҫ��ջ����Ϊ��
	S = (linkStack *)malloc(sizeof(linkStack));
	S->next = NULL;//ջΪ�յı�־
}

/*�пղ���*/
int isStackEmpty(linkStack *S)
{
	return (S->next == NULL);
}

linkStack *linkStack_push(linkStack *stack, int val)
{
	//�����洢��Ԫ�صĽڵ�
	linkStack *LNode = (linkStack *)malloc(sizeof(linkStack));

	LNode->data = val;
	//�½ڵ���ͷ�ڵ㽨���߼���ϵ
	LNode->next = stack;    // 2 -> (stack)1 -> NULL
	//����ջ��ָ���ָ��
	stack = LNode;			// (stack)2 -> 1 -> NULL
	return stack;
};



linkStack *linkStack_pop(linkStack *stack,linkStack *top)
{
	if (stack != NULL)
	{
		top->data = stack->data;
		stack = stack->next;
		top->next = NULL;
		if (stack == NULL)
		{
			printf("��ջ�ɹ���ջ�ѿ�\n");
		}
		else printf("��ջ�ɹ���ջδ��\n");
	}else
	{
		printf("����һ����ջ\n");
	}
	return stack;
}

