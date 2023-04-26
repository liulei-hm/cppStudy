//
// Created by liulei on 2023/3/16.
//
#include "all.h"
void my_quickSort(vector<int>& arr, int start, int end){
    if(start >= end) return;
    int index = rand()%(end-start+1) + start; // 随机产生区间内的一个下标
    int pivot = arr[index];   // 把它作为哨兵
    swap(arr[start], arr[index]); // 注意：先把它放在最前面
    int i=start,j=end;
    while(i<j){
        // 注意：先移动右边j，这样while结束后i处是比pivot小的数字，才可以与pivot交换
        while(i<j && arr[j]>=pivot) // 注意：大于等于的放右边
            j--;
        while(i<j && arr[i]<=pivot) // 小于等于的放左边
            i++;
        if(i!=j) // 最多i==j
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[i]); // 再把start处的pivot放在中间
    my_quickSort(arr, start, i-1);
    my_quickSort(arr, i+1, end); // 注意：i已经排过序
    return;
}

int main(){
    vector<int> arr = { 2,1,3,5,6,8,7,4,10,5,3,21,1,2,2,2,8 };
    my_quickSort(arr,0,arr.size()-1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}