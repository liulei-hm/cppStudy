//
// Created by liulei on 2023/5/10.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    istringstream iss(s);
    vector<string> v;
    string str;
    while(iss >> str)
    {
        v.push_back(str);
    }
    for(auto i:v)
    {
        cout << i << endl;
    }

    return 0;
}
