//
// Created by liulei on 2023/2/27.
//
#include "all.h"
vector<bool> status;
template<class T>
void printVector1(vector<T> &v){
    for(auto &i:v)
    {
        cout<< i << " ";
        i=777;
    }
    cout<<endl;
    for(auto i:v)
        cout<< i << " ";
    cout<<endl;
}

template<class T>
void printVector2(vector<T> v){
    typename vector<T>::iterator it;  //typename是将vector<T>定义为类型的关键字,不加的话，编译器会认为vector<T>::iterator是一种成员变量，编译不通过
    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
bool cmp(const vector<int>& u, const vector<int>& v)
{
    return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
}

void vector_2(){
    //status.resize(3,false); //全局变量使用resize初始化
    int n = 5;
    vector<int> a(n,55); //将含有n个数据的一维动态数组初始为55
    printVector1(a);
    printVector2(a);

    //1定义二维数组dp
    vector<vector<int>> dp(n,vector<int>(2,3));
    dp[3][0] = 5;
    dp[4][0] = 7;
//    sort(dp.begin(), dp.end(), [](const vector<int>& u, const vector<int>& v) {
//        return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
//    });
    sort(dp.begin(), dp.end(),cmp);
    for(const vector<int>& row:dp)
    {
        for(const auto col:row)
        {
            cout << col ;
        }
        cout << endl;
    }
    int row = dp.size();          //获取行数
    int column = dp[0].size();    //获取列数
    //2定义二维数组new_mat
    vector<vector<int>> new_mat(row);//注意这个r是不可缺少的，规定其有多少行
    for(int i=0 ;i<row; i++) //二维vector的初始化时有要求的
    {
        new_mat[i].resize(column);
    }
    //3每行不一定几个数，就是想对每行的列进行操作,但是在声明时，行数一定要有！！然后push_back就可以了！，
    vector<vector<int>> mat(row);//每行的定义
    mat[2].push_back(31);//这就是该第3行的插入一个元素，值为31
    mat.push_back({ 1,1 }); //直接赋值

    vector<vector<int>> b(n,vector<int>(n,0));
    auto it = b.begin();
    b.erase(++it);//删除第一行
    //https://blog.csdn.net/m0_57298796/article/details/123952640

    //删除vector最后一个字符 v.pop_back();
}

void test_vector_head(){
    int b[] =  {4,5,8,94,21,23,1};
    int *pb = b;
    printf("%p\n",b);       //00000068527ffc50
    printf("%p\n",b+2);     //00000068527ffc58
    printf("%p\n",&b[0]+2); //00000068527ffc58
    printf("%d\n",*b);      //4

    printf("%d\n",*b+2);    //4+2 = 6
    printf("%d\n",*(b+2));  //8;

    printf("%p\n",pb);      //00000068527ffc50
    printf("%p\n",pb+2);    //00000068527ffc58
    printf("%d\n",*pb);     //4
    printf("%d\n",*pb+2);   //6
    printf("%d\n",*(pb+2));  //8

    //https://blog.csdn.net/sandalphon4869/article/details/98452007
    //p[i]:指向栈上的vector
    vector<int> a = {4,5,8,94,21,23,1};
    vector<int> *pa = &a;
    printf("%p\n",&a);       //00000089951ffa00
    printf("%p\n",&a[0]+2);  //0000028026ec1908

    printf("%p\n",pa);       //00000089951ffa00
    printf("%p\n",pa+2);     //00000089951ffa30
    printf("%d\n",pa->at(2));      //8
    for (int i = 0; i < pa->size(); i++)
    {
        cout << &pa[i] << ' ';  //0x89951ffa00 0x89951ffa18 0x89951ffa30 0x89951ffa48 0x89951ffa60 0x89951ffa78 0x89951ffa90
    }

    //p[i]:指向堆上的vector
    auto *p = new vector<int>{ 1,2,3 };
    for (int i = 0; i < p->size(); i++)
    {
        cout << p->at(i) << ' '; //1 2 3
    }

    vector<int> va{ 1,2,3 }, vb{ 4,5,6 }, vc{7,8,9,10};

    //写法1
    vector<int>* vp[3] = { &va,&vb,&vc };

    /*
    //写法2
    vector<int>* vp[3];
    vp[0] = &va, vp[1] = &vb, vp[2] = v&c;
    */

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < vp[i]->size(); j++)
        {
            cout << vp[i]->at(j) << ' ';
        }
        cout << endl;
    }
    /*
    1 2 3
    4 5 6
    7 8 9 10
    */
}

void test_array_point(){
    int a[]={1,5,8};
    int *pa = a;
    printf("pa = %p\n",pa);  //这四个一样
    printf("a = %p\n",a);
    printf("&a = %p\n",&a);
    printf("&a[0] = %p\n",&a[0]);

    printf("&a+1 = %p\n",&a+1);  //这个越界

    printf("&a[0]+1 = %p\n",&a[0]+1);   //这两个一样
    printf("pa+1 = %p\n",pa+1);
}
void test_array_array(){
    int b[3][4] = {0,1,2,3,
                   4,5,6,7,
                   8,10,11,12};
    int (*pb)[4] = b;
    printf("*(pb[1]+1) = %d\n",*(pb[1]+1)); //5
}

void call_c_api(int *v,int size){

}
void test_vector_pointer(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    //vector.data()即为获取指向vector数据的指针，下面三个指针相同
    int* ptr1 = vec.data();
    int* ptr2 = &vec[0];
    int* ptr3 = &(*vec.begin());

    std::vector<int> my_vec = {1, 2, 3, 4, 5};
    int my_array[5];
    //vector.data()用法1
    std::memcpy(my_array, my_vec.data(), my_vec.size() * sizeof(int));
    //vector.data()用法2 传递给c语言api
    call_c_api(my_vec.data(), my_vec.size());
}

int main(){
    //test_vector_pointer();
    int n=6;
    while(n--){
        int i=3;
        switch (i) {
            case 3:
                cout << "3" << endl;
                continue;
            default:
                break;
        }
        cout << "after continue";
    }
    return 0;
}