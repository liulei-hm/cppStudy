//
// Created by liulei on 2023/3/1.
//
#include "all.h"

int trap(vector<int>& height) {
    //单调栈 找左右大值
    int sum = 0;
    stack<int> st; //存着下标，计算的时候用下标对应的柱子高度
    int mid,left,right;
    int h,w;
    st.push(0);
    for(int i=0;i<height.size();i++)
    {
        while(!st.empty()&&height[i]>height[st.top()]) //出现半凹槽，可以接水
        {
            mid = st.top();
            st.pop();
            if(!st.empty()) //是否出现另一半凹槽
            {
                left = st.top();  //这里取top前一定要判断栈是否为空
                right = i;
                h = min(height[left],height[right]) - height[mid];
                w = right - left - 1;
                sum += h * w;
            }
        }
        st.push(i);
    }
    //维护一个单调增的栈，比当前元素小的栈顶元素要出栈
    // [0(0)]               1(1)    0出栈，未构成全凹槽，1入栈
    // [1(1)]               2(0)入栈
    // [1(1) 2(0)]          3(2)    2出栈，全凹槽 right=2 mid=0 left=1 h=1-0=1 w=1 sum=1
    // [1(1)]               3(2)    1出栈，同第一步，未构成全凹槽，3入栈
    // [3(2)]               4(1)入栈
    // [3(2) 4(1)]          5(0)入栈
    // [3(2) 4(1) 5(0)]     6(1)    5出栈，全凹槽 right=6 mid=5 left=4 h==1 w=1 sum=1+1=2，6入栈
    // [3(2) 4(1) 6(1)]     7(3)    6出栈，全凹槽 sum=2+1=3 4出栈，注意这里w=2 sum=3+2=5，7入栈
    // [7(3)]               8(2)入栈
    // [7(3) 8(2)]          9(1)入栈
    // [7(3) 8(2) 9(1)]     10(2)   9出栈，全凹槽 sum=5+1=6，10入栈
    // [7(3) 8(2) 10(2)]    11(1)入栈
    // [7(3) 8(2) 10(2) 11(1)] 结束，栈中剩余4个元素
    return sum;
}
int main()
{
    stack<int> st;
    st.push(-2);
    cout << st.top() << endl;
    cout << st.empty() << endl;
    st.pop();
    cout << st.empty() << endl;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "接雨水：" << trap(height) << endl;
    return 0;
}