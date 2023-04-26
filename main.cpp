//设计一个字符串类String，通过运算符重载实现字符串的输入、输出以及+=、==、!=、<、>、>=、[ ]等运算。
#include <iostream>
#include <cstring>
#include <vector>
#include "include/override.h"
#include "iterator.h"
#include "iostream.h"

using namespace std;
class myString
{
public:
    myString(const char * = "");
    myString operator+(char *s){
    }
    friend ostream &operator<<(ostream &os, const myString &s)
    {
        return os << s.sPtr;
    };
private:
    char *sPtr;
    int length;
public:
};
myString::myString(const char *str)
{
    sPtr = new char[strlen(str) + 1];
    strcpy(sPtr, str);
    length = strlen(str);
};
void myquickSort(vector<int>& a,int low,int high){
    int pivot=a[low];
    int i=low,j=high;
    if(low>high) return;
    while(i<j)
    {
        for(;i<j&&a[j]>=pivot;j--);
        if(i<j) a[i++]=a[j]; //从右边找到小于pivot的值放在左边
        for(;i<j&&a[i]<pivot;i++);
        if(i<j) a[j--]=a[i]; //从左边找到大于等于pivot的值放在右边
        a[i]=pivot;
        myquickSort(a,low,i-1);
        myquickSort(a,i+1,high);
    }
}

int partition(vector<int>& a,int left,int right){
    static int cnt = 1;
    int pivot = a[left];
    int i=left,j=right;
    cout.width(2);
    cout << "第" << cnt++ << "轮" << ",基准值为：" << pivot << ",区间为：[";
    for(int k=left;k<=right;k++)
    {
        cout.width(2);
        cout << a[k] << " ";
    }
    while(i<j)
    {
        for(;i<j&&a[j]>=pivot;j--);
        if(i<j) a[i++]=a[j]; //从右边找到小于pivot的值放在左边
        for(;i<j&&a[i]<pivot;i++);
        if(i<j) a[j--]=a[i]; //从左边找到大于等于pivot的值放在右边
    }
    a[i]=pivot;

    cout << "],数组变为：";
    for(auto &i:a)
    {
        cout.width(2);
        cout << i << " ";
    }
    cout<<endl;
    return i;
}
void quickSort(vector<int>& a,int left,int right){
    if(left>=right) return;
    int pos = partition(a,left,right);
    quickSort(a,left,pos-1);
    quickSort(a,pos+1,right);
}

vector<int> counting_sort(vector<int> a, int k) {
    int n = a.size();
    vector<int> c(k + 1, 0), b(n);
    for (int i = 0; i < n; i++)
        c[a[i]]++;   //c[i]中保存的就是a数组中等于下标的元素个数
    for (int i = 1; i <= k; i++)
        c[i] += c[i - 1]; //c[i]中保存的是小于或等于i的元素个数
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    return b;
}

int main()
{
//    car c(5,7);
//    car cw[3] = {car(13,3),car(32,3),car(312,323)};
//    cw[1].show();
//    myString s1("s1");
//    myString s2("s2");
//    //s1 = s1 + s2;
//    coutArgSet();

//    vector<int> a={-2,1,-3,4,-1,2,1,-5,4};
//    cout << "排序前：";
//
//    for(auto &i:a)
//    {
//        cout.width(2);
//        cout << i << " ";
//    }
//    cout << endl;
//    quickSort(a,0,a.size()-1);
//    cout << "排序后：";
//    for(auto &i:a)
//    {
//        cout.width(2);
//        cout << i << " ";
//    }
//    cout << endl;

    system("pause");
    return 0;
}
