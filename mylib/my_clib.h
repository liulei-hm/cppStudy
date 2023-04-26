#pragma once
#include <iostream>
#include <iomanip>

using namespace std;
//定义链表节点
template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList
{
public:
	LinkedList();//建立链表
	~LinkedList();//删除链表
	int getLength();//返回长度
	void print();//打印
	Node<T>* findKthNode(int k);//查找第K个元素
	void insert(int data, int position);// 插入元素
	void pushBack(int data);//添加元素
	void remove(int position);//删除元素
	bool findNode(int data);//查找元素是否存在
	void reverse();//逆序
private:
	Node<T>* head;
	int length;
};




template <class T>
LinkedList<T>::LinkedList()
{
	head = new Node<T>;
	head->next = NULL;
	head->data = 0;
	length = 0;
}
//返回长度
template <class T>
int LinkedList<T>::getLength()
{
	return length;
}
//删除链表
template <class T>
LinkedList<T>::~LinkedList()
{
	if (length == 0)
	{
		delete head;
		head = NULL;
		return;
	}
	Node<T>* p = head->next;
	delete head;
	head = NULL;
	while (p != NULL)
	{
		Node<T>* temp = p->next;
		delete p;
		p = temp;
	}
	delete p;
	length = 0;
}
//
template <class T>
void LinkedList<T>::print()
{
	if (length == 0) return;
	Node<T>* temp = head->next;
	//cout << temp->data << " " << temp->next;
	cout << "Current list is:";
	for (int i = 0; i < length; i++)
	{
		cout  << temp->data  << "->" ;
		temp = temp->next;
	}
	cout << "NULL" << endl;
	temp = NULL;
}

template <class T>
Node<T>* LinkedList<T>::findKthNode(int k)
{
	Node<T>* temp;
	if (k > length)
	{
		cout << "K is out of range! " << endl;
		temp = new Node<T>;
		temp->data = NULL;
		temp->next = NULL;
	}
	else
	{
		temp = head;
		while (k--)
			temp = temp->next;
	}
	return temp;

}

template <class T>
void LinkedList<T>::insert(int data, int position)
{
	if (position > length + 1 || position < 1)
	{
		cout << "Position " << position << " is out of range! " << endl;
		cout << endl;
	}
	else if (position == length + 1)
	{
		pushBack(data);
	}
	else
	{
		//找到插入的位置
		Node<T>* pre = findKthNode(position - 1);
		Node<T>* cur = new Node<T>;
		cur->data = data;
		cur->next = pre->next;
		pre->next = cur;
		pre = cur = NULL;
		length++;
		cout << "Successfully insert " << data << " to position " << position << " !" << endl;

	}
	return;
}

template <class T>
void LinkedList<T>::pushBack(int data)
{
	Node<T>* cur = new Node<T>;
	cur->data = data;
	cur->next = NULL;
	Node<T>* temp = findKthNode(length);
	temp->next = cur;
	temp = NULL;
	cur = NULL;
	cout << "Successfully push back " << data << " to linked list! " << endl;
	length++;
}

template <class T>
void LinkedList<T>::remove(int position)
{
	if (position > length || position < 1)
	{
		cout << "Position " << position << " is out of range! " << endl;
		cout << endl;
		return;
	}
	Node<T>* pre = findKthNode(position - 1);
	Node<T>* cur = pre->next;
	pre->next = cur->next;
	delete cur;
	cur = pre = NULL;
	length--;
	cout << "Successfully remove the node on position " << position << " !" << endl;
}

template <class T>
bool LinkedList<T>::findNode(int data)
{
	Node<T>* temp = head;
	bool isExist = 0;
	for (int i = 0; i < length; i++)
	{
		temp = temp->next;
		if (temp->data == data)
		{
			isExist = 1;
			cout << "Find " << data << " in position " << i << "." << endl;
		}
	}
	if (!isExist)
		cout << "Can not find " << data << " in current list." << endl;
	cout << endl;
	return isExist;
}


template <class T>
void LinkedList<T>::reverse()
{
	Node<T>* pre = head;
	Node<T>* cur = pre->next;
	Node<T>* next = cur->next;
	cur->next = NULL;
	for (int i = 0; i < length - 2; i++)
	{
		pre = cur;
		cur = next;
		next = next->next;
		cur->next = pre;
	}
	next->next = cur;
	head->next = next;
	pre = cur = next = NULL;
	cout << "Successfully reverse current list! " << endl;
}
