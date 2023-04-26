//
// Created by liulei on 2023/3/16.
//
#include "all.h"

//一般函数
int func(int iX, int iY)
{
    return iX + iY;
}
//lamda函数 [] (int iX,int iY) {return iX+iY;}




int main(){
    int oX =3;
    int oY =4;
    //调用方式1
    auto autofun = [oX,oY](int iX,int iY){return iX+iY+oX+oY;};
    cout << autofun(1,2) << endl;
    //调用方式2
    [oX,oY](int iX,int iY){return iX+iY+oX+oY;}(1,2);
    //修改，调用方式1
    auto fun = [&oX,oY](int iX,int iY)
    {
        oX++;
        //oY++;//oY未添加&，报错
        return iX+iY+oX+oY;
    };
    cout << fun(1,2)<< endl;
    //第二种写法，全部添加引用
    auto fun2 = [&](int iX,int iY)
    {
        oX++;
        oY++;
        return iX+iY+oX+oY;
    };
    cout << fun2(1,2)<< endl;
    //第三种写法：全部添加引用，如果是传值的单独列出来(即例外)
    [&,oY](int iX,int iY)
    {
        oX++;
        //oY++;//oY单独列出来是传值，不可修改，报错
        return iX+iY+oX+oY;
    };

    return 0;
}

