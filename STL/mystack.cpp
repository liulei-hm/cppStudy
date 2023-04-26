//
// Created by liulei on 2023/3/1.
//
#include "all.h"

int trap(vector<int>& height) {
    //����ջ �����Ҵ�ֵ
    int sum = 0;
    stack<int> st; //�����±꣬�����ʱ�����±��Ӧ�����Ӹ߶�
    int mid,left,right;
    int h,w;
    st.push(0);
    for(int i=0;i<height.size();i++)
    {
        while(!st.empty()&&height[i]>height[st.top()]) //���ְ밼�ۣ����Խ�ˮ
        {
            mid = st.top();
            st.pop();
            if(!st.empty()) //�Ƿ������һ�밼��
            {
                left = st.top();  //����ȡtopǰһ��Ҫ�ж�ջ�Ƿ�Ϊ��
                right = i;
                h = min(height[left],height[right]) - height[mid];
                w = right - left - 1;
                sum += h * w;
            }
        }
        st.push(i);
    }
    //ά��һ����������ջ���ȵ�ǰԪ��С��ջ��Ԫ��Ҫ��ջ
    // [0(0)]               1(1)    0��ջ��δ����ȫ���ۣ�1��ջ
    // [1(1)]               2(0)��ջ
    // [1(1) 2(0)]          3(2)    2��ջ��ȫ���� right=2 mid=0 left=1 h=1-0=1 w=1 sum=1
    // [1(1)]               3(2)    1��ջ��ͬ��һ����δ����ȫ���ۣ�3��ջ
    // [3(2)]               4(1)��ջ
    // [3(2) 4(1)]          5(0)��ջ
    // [3(2) 4(1) 5(0)]     6(1)    5��ջ��ȫ���� right=6 mid=5 left=4 h==1 w=1 sum=1+1=2��6��ջ
    // [3(2) 4(1) 6(1)]     7(3)    6��ջ��ȫ���� sum=2+1=3 4��ջ��ע������w=2 sum=3+2=5��7��ջ
    // [7(3)]               8(2)��ջ
    // [7(3) 8(2)]          9(1)��ջ
    // [7(3) 8(2) 9(1)]     10(2)   9��ջ��ȫ���� sum=5+1=6��10��ջ
    // [7(3) 8(2) 10(2)]    11(1)��ջ
    // [7(3) 8(2) 10(2) 11(1)] ������ջ��ʣ��4��Ԫ��
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
    cout << "����ˮ��" << trap(height) << endl;
    return 0;
}