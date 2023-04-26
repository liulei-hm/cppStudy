//
// Created by liulei on 2022/12/5.
//

#include "iterator.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class myVec : vector<int>{
public:
    myVec() {}

};
void vectorSort()
{
    vector<int> a;
    for(int i=10;i>0;i--)
    {
        a.push_back(i);
    }
    cout << "ÅÅÐòÇ°£º";
    vector<int>::iterator it = a.begin();
    while(it!=a.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    sort(a.begin(),a.end());
    cout << "ÅÅÐòºó£º";
    for(auto &i:a)
    {
        cout << i << " ";
    }
    cout<<endl;

}
