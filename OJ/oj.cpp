//
// Created by liulei on 2023/3/3.
//
#include "all.h"




//面向行的输入
void inputLine()
{
    const int Arsize = 20;
    char name[Arsize];
    char dessert[Arsize];
    cout<<"Enter your name\n";
    cin.getline(name,Arsize);
    cout<<"enter yr favorite dessert:\n";
    cin.getline(dessert,Arsize);
    cout <<"I have some delicious "<<dessert;
    cout<<" for you,"<<name<<".\n";
}

void inputVector()
{
    vector<int> v;
    int n=0;
    int m=0;
    cin >> n >> m;
    int value = 0;
    while(n--)
    {
        cin >> value;
        v.push_back(value);
    }
    for(auto i:v)
        cout<< i << " ";

}



