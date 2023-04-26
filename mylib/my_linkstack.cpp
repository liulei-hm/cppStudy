#include <stdio.h>
#include <stdlib.h>
#include "my_test.h"
#include "my_datastruct.h"
#include <iostream>
using namespace std;
//参考网址 http://data.biancheng.net/view/171.html 出栈时略有修改
//https://blog.csdn.net/u014627536/article/details/41413975 c++类实现链栈 https://blog.csdn.net/qq_59708493/article/details/122562586
/******************************链栈测试程序*****************************/
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





/********************************链栈*****************************/

//采用头插法将元素插入链表中，这样后入栈的元素在链表头
//例如 head->1->NULL  push（2）  head->2->1->NULL

/*建立空栈*/
void linkStack_init(linkStack *&S)//*&为引用，可以直接修改实参指向的位置
{//链栈不带头结点，初始化链栈只需要把栈顶置为空
	S = (linkStack *)malloc(sizeof(linkStack));
	S->next = NULL;//栈为空的标志
}

/*判空操作*/
int isStackEmpty(linkStack *S)
{
	return (S->next == NULL);
}

linkStack *linkStack_push(linkStack *stack, int val)
{
	//创建存储新元素的节点
	linkStack *LNode = (linkStack *)malloc(sizeof(linkStack));

	LNode->data = val;
	//新节点与头节点建立逻辑关系
	LNode->next = stack;    // 2 -> (stack)1 -> NULL
	//更新栈顶指针的指向
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
			printf("出栈成功，栈已空\n");
		}
		else printf("出栈成功，栈未空\n");
	}else
	{
		printf("这是一个空栈\n");
	}
	return stack;
}

