#include <iostream>
#include <windows.h>
#include <time.h>
#include <typeinfo>
#include <sys/types.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "my_test.h"
#include "my_clib.h"
#include "leetcode25.h"
#include "leetcode155.h"
//#pragma pack(1)
using namespace std;



void printList(ListNode *head)
{
	while (head != NULL)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL";
	cout << endl;
}

void creatList(ListNode *&head)
{
	head = new ListNode(1); //ͷ�ڵ�
	ListNode *p = head;                //ָ��
	int i = 2;
	while (i<6) {
		ListNode *node = new ListNode(i); // ��ʼ��һ���ڵ�
		p->next = node;
		p = p->next;
		i++;
	}
	p->next = NULL;//���һ���ڵ��ָ��ָ���
}
void testlink()
{
	revKGroup a;
	ListNode *list = NULL;
	creatList(list);
	printList(list);
	ListNode *res = a.reverseKGroup(list, 2);
	printList(res);
}
void testn()
{
	LinkedList<int> list;
	cout << list.getLength()<<endl;
	list.insert(1,1);
	list.insert(3,1);
	list.insert(3,3);
	cout << list.getLength() << endl;
	list.print();
}

int  main()
{

	system("pause");
	return  0;
}


