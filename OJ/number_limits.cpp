//
// Created by liulei on 2023/3/21.
//
#include "bits/stdc++.h"
using namespace std;

void num_limits(){
    //    numeric_limits<unsigned short>::min()= 0
    //    numeric_limits<unsigned short>::max()= 65535
    //    numeric_limits<short>::min()= -32768
    //    numeric_limits<short>::max()= 32767
    //    numeric_limits<unsigned int>::min()= 0
    //    numeric_limits<unsigned int>::max()= 4294967295
    //    numeric_limits<int>::min()= -2147483648
    //    numeric_limits<int>::max()= 2147483647
    //    numeric_limits<long>::min()= -2147483648
    //    numeric_limits<long>::max()= 2147483647
    //    numeric_limits<long long>::min()= -9223372036854775808
    //    numeric_limits<long long>::max()= 9223372036854775807
    //    numeric_limits<double>::min()= 2.22507e-308
    //    numeric_limits<double>::max()= 1.79769e+308
    //    numeric_limits<int>::is_signed()= 1
    //    numeric_limits<string>::is_specialized()= 0
    cout<<"numeric_limits<unsigned short>::min()= "<<numeric_limits<unsigned short>::min()<<endl;
    cout<<"numeric_limits<unsigned short>::max()= "<<numeric_limits<unsigned short>::max()<<endl;
    cout<<"numeric_limits<short>::min()= "<<numeric_limits<short>::min()<<endl;
    cout<<"numeric_limits<short>::max()= "<<numeric_limits<short>::max()<<endl;

    cout<<"numeric_limits<unsigned int>::min()= "<<numeric_limits<unsigned int>::min()<<endl;
    cout<<"numeric_limits<unsigned int>::max()= "<<numeric_limits<unsigned int>::max()<<endl;
    cout<<"numeric_limits<int>::min()= "<<numeric_limits<int>::min()<<endl;
    cout<<"numeric_limits<int>::max()= "<<numeric_limits<int>::max()<<endl;

    cout<<"numeric_limits<long>::min()= "<<numeric_limits<long>::min()<<endl;
    cout<<"numeric_limits<long>::max()= "<<numeric_limits<long>::max()<<endl;
    cout<<"numeric_limits<long long>::min()= "<<numeric_limits<long long>::min()<<endl;
    cout<<"numeric_limits<long long>::max()= "<<numeric_limits<long long>::max()<<endl;

    cout<<"numeric_limits<double>::min()= "<<numeric_limits<double>::min()<<endl;
    cout<<"numeric_limits<double>::max()= "<<numeric_limits<double>::max()<<endl;

    cout<<"numeric_limits<int>::is_signed()= "<<numeric_limits<int>::is_signed<<endl;//是否有正负号
    cout<<"numeric_limits<string>::is_specialized()= "<<numeric_limits<string>::is_specialized<<endl;//是否定义了数值极限
}

int main(){
    num_limits();
    return 0;
}