//
// Created by liulei on 2023/3/16.
//
#include "all.h"

//һ�㺯��
int func(int iX, int iY)
{
    return iX + iY;
}
//lamda���� [] (int iX,int iY) {return iX+iY;}




int main(){
    int oX =3;
    int oY =4;
    //���÷�ʽ1
    auto autofun = [oX,oY](int iX,int iY){return iX+iY+oX+oY;};
    cout << autofun(1,2) << endl;
    //���÷�ʽ2
    [oX,oY](int iX,int iY){return iX+iY+oX+oY;}(1,2);
    //�޸ģ����÷�ʽ1
    auto fun = [&oX,oY](int iX,int iY)
    {
        oX++;
        //oY++;//oYδ���&������
        return iX+iY+oX+oY;
    };
    cout << fun(1,2)<< endl;
    //�ڶ���д����ȫ���������
    auto fun2 = [&](int iX,int iY)
    {
        oX++;
        oY++;
        return iX+iY+oX+oY;
    };
    cout << fun2(1,2)<< endl;
    //������д����ȫ��������ã�����Ǵ�ֵ�ĵ����г���(������)
    [&,oY](int iX,int iY)
    {
        oX++;
        //oY++;//oY�����г����Ǵ�ֵ�������޸ģ�����
        return iX+iY+oX+oY;
    };

    return 0;
}

