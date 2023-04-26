#pragma once
#include <stack>
#include <climits>

using namespace std;
//面试的时候被问到不能用额外空间，就去网上搜了下不用额外空间的做法。思路是栈里保存差值。
class MinStack {
public:
	stack<long> dist;
	long min_s;
	MinStack() : min_s(0) {}

	void push(int val) {
		if (dist.empty()) {
			min_s = val;
			dist.push(0);
		}
		else {
			long diff = val - min_s;
			dist.push(diff);
			min_s = diff > 0 ? min_s : val;
		}
	}

	void pop() {
		if (!dist.empty()) {
			long diff = dist.top();
			dist.pop();
			min_s = diff > 0 ? min_s : min_s - diff;
		}
	}

	int top() {
		if (dist.empty()) {
			return -1;
		}
		else {
			long diff = dist.top();
			if (diff > 0) {
				return (diff + min_s);
			}
			else {
				return min_s;
			}
		}
	}

	int getMin() {
		if (dist.empty()) {
			return -1;
		}
		else {
			return min_s;
		}
	}
};

class MinStack1 {
public:
	int min = INT_MAX;
	stack<int> st;
	stack<int> minst;
	MinStack1() {
		//cout<<min<<endl;
	}
	void push(int val) {
		if (val <= min)
		{
			min = val;
		}
		st.push(val);
		minst.push(min);  //每次都要push进去一个min
	}
	void pop() {
		if (st.empty())
		{
			return;
		}
		st.pop();
		minst.pop();
		//当minst弹出或为空时需要更新min
		if (minst.empty())
		{
			min = INT_MAX;
		}
		else {
			min = minst.top();
		}
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return minst.top();
	}
};