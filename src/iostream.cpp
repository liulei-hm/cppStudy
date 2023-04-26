//
// Created by liulei on 2022/12/5.
//

#include <fstream>
#include <iomanip>
#include "iostream.h"

void singleCharRead()
{
    char ch;
    cout << "input a string:\n";
    while(cin.get(ch)){
        cout.put(ch);
    }
}
void coutArgSet()
{
    //设置左右对齐
    cout.setf(ios::left,ios::adjustfield);
    //ios中还有很多参数设置例如跳过空格字符ios::skipws 输出十六进制 ios::hex
    for(int i=0;i<=10;i++)
    {
        //设置输出域宽
        cout.width(3);
        //设置填充
        cout.fill('-');
        cout << hex << i;
    }
    cout << '\n';
    double pi=3.141592;
    cout.precision(4);
    cout << "圆周率精度输出" << pi << endl;
    cout << setprecision(12) << pi << endl;
}

void fileopen(){
    ofstream fout("test0.txt");
    if(!fout){
        cout << "打不开" << endl;
        return;
    }
    fout << "hello\n";
    fout << "goodbye\n";
    fout.close();
}

void fileinput(){
    ifstream fin("test.txt");
    if(!fin)
    {
        cout << "打不开";
        return;
    }
    char str1[16];
    char str2[16];

    fin >> str1 >> str2;
    cout << str1;
    cout << str2;
    fin.close();
}

