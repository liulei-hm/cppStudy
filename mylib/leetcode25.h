#pragma once
#include <iostream>
using namespace std;
//K��һ�鷭ת����
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class revKGroup {
public:
	ListNode* getEnd(ListNode *head, int k)
	{
		while (head != NULL)
		{
			k--;
			if (k == 0) return head;
			head = head->next;
		}
		return NULL;
	}
	ListNode* reverseOneGroup(ListNode* head, ListNode *end)
	{
		ListNode *last = head;  //last-head-1  
		head = head->next;      //last-1  head-2
		last->next = NULL;
		while (head != end)
		{
			ListNode *temp = head->next; //temp=3  4
			head->next = last; //2->next = 1  3->next=2
			last = head; //last-2
			head = temp; //head=3
		}
		return head;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *listhead = new ListNode(0, head);
		ListNode *last = listhead;
		while (head != NULL)
		{
			//1.����
			ListNode *end = getEnd(head, k);

			if (end == NULL)
			{
				break;
			}
			//cout << "end=" << end->val <<endl;
			ListNode *nextGroupHead = end->next;  //������ǰ���next
			//2.�����ڽ�������
			reverseOneGroup(head, nextGroupHead);
			//3.����ǰһ��βlast->nextΪend�����µ�ǰ��βhead->nextΪ֮ǰ��nextGroupHead
			last->next = end;
			head->next = nextGroupHead;
			//4.����headΪnextGroupHead
			last = head;
			head = nextGroupHead;
		}
		return listhead->next;
	}
};