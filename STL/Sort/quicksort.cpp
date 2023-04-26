//
// Created by liulei on 2023/3/16.
//
#include "all.h"
void my_quickSort(vector<int>& arr, int start, int end){
    if(start >= end) return;
    int index = rand()%(end-start+1) + start; // ������������ڵ�һ���±�
    int pivot = arr[index];   // ������Ϊ�ڱ�
    swap(arr[start], arr[index]); // ע�⣺�Ȱ���������ǰ��
    int i=start,j=end;
    while(i<j){
        // ע�⣺���ƶ��ұ�j������while������i���Ǳ�pivotС�����֣��ſ�����pivot����
        while(i<j && arr[j]>=pivot) // ע�⣺���ڵ��ڵķ��ұ�
            j--;
        while(i<j && arr[i]<=pivot) // С�ڵ��ڵķ����
            i++;
        if(i!=j) // ���i==j
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[i]); // �ٰ�start����pivot�����м�
    my_quickSort(arr, start, i-1);
    my_quickSort(arr, i+1, end); // ע�⣺i�Ѿ��Ź���
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