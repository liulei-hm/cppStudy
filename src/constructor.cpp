//
// Created by liulei on 2023/3/10.
//
#include<iostream>//Ԥ����
using namespace std;//�����ռ�
class Box
{
public: //��������
    Box(int,int,int);//�вι��캯��
    int volume();//�������������
private: //����˽��
    int height;//�����
    int width; //�����
    int length; //���峤
};
Box::Box(int h,int w,int l)//�����ⶨ��������Ĺ��캯��
{
    height=h;
    width=w;
    length=l;
}
int Box::volume()//�������������
{
    return height*width*length; //���˿�˸�
}
int main()//������
{
    Box volume(10,20,33);
    int number=volume.volume();
    cout<<"Բ������ǣ�"<<number<<endl;
    return 0; //��������ֵΪ0��
}
