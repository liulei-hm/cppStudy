//
// Created by liulei on 2023/3/10.
//
#include<iostream>//预处理
using namespace std;//命名空间
class Box
{
public: //声明公有
    Box(int,int,int);//有参构造函数
    int volume();//声明求体积函数
private: //声明私有
    int height;//定义高
    int width; //定义宽
    int length; //定义长
};
Box::Box(int h,int w,int l)//在类外定义带参数的构造函数
{
    height=h;
    width=w;
    length=l;
}
int Box::volume()//定义求体积函数
{
    return height*width*length; //长乘宽乘高
}
int main()//主函数
{
    Box volume(10,20,33);
    int number=volume.volume();
    cout<<"圆柱体积是："<<number<<endl;
    return 0; //函数返回值为0；
}
