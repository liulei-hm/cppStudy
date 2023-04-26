//
// Created by liulei on 2023/2/3.
//

#include "all.h"

//只出现一次的数字
//输入：nums = [0,1,0,1,0,1,100]
//输出：100
int singleNumber(vector<int> &nums) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }
    unordered_map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second == 1) {
            return it->first;
        }
    }
    return INT_MIN;
}
//「解法2位运算」 例如 [2 2 3 2] 收集 10 10 11 10 的每一位之和，将其除以3，得到的即是11那一位的值

void diff_unorderMapAndMap()
{
    unordered_map<int,string> u_map;

    u_map.insert({3, "333"});

    u_map.insert(pair<int,string>(1, "111"));

    u_map.insert(pair<int,string>(4, "444"));

    u_map.insert(pair<int,string>(2, "222"));

    u_map.insert(pair<int,string>(5, "555"));

    unordered_map<int,string>::iterator u_iter = u_map.begin();
    cout << "unordered_map 保留了原插入的逆序：" << endl;
    for (u_iter; u_iter != u_map.end(); u_iter++)

    {
        cout << u_iter->first << "," << u_iter->second.c_str() << endl;
    }

    map<int,string> m_map;

    m_map.insert(pair<int,string>(3, "333"));

    m_map.insert(pair<int,string>(1, "111"));

    m_map.insert(pair<int,string>(4, "444"));

    m_map.insert(pair<int,string>(2, "222"));

    m_map.insert(pair<int,string>(5, "555"));

    map<int,string>::iterator iter = m_map.begin();
    cout << "map 红黑树key值排列有序 ：" << endl;
    for (iter; iter != m_map.end(); iter++)

    {
        cout << iter->first << "," << iter->second.c_str() << endl;
    }
}

void mymultimap(){
    //map和multimap都会按key的大小顺序排序，而multimap(红黑树)可以存放不同的key
    multimap<int,string> m_map={
            {1,"yi"},
            {2,"er"},
            {5,"wu"},
            {4,"si"},
            {2,"two"}
    };
    for(auto i:m_map){
        cout << i.first <<  " " << i.second << endl;
    }
    cout << m_map.find(2)->second ;
}
void mymap(){
    map<int, string> m;
    m[4] = "student_one";
    m[7] = "student_two";
    m[9] = "student_three";
    //node->children.insert({ch,tmpNode}); 可以
    //node->children.insert(std::make_pair(ch, tmpNode)); 可以
    m.insert(pair<int, string>(22, "Jim"));
    //正向迭代器遍历和反向迭代器遍历
    map<int, string>::reverse_iterator rit;
    for (rit = m.rbegin(); rit != m.rend(); rit++) {
        cout << rit->first << " " << rit->second << endl;
    }
    map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << ' ' << it->second << endl;
    }
    cout << "for auto" << endl;
    for (auto [key, value]: m) {
        cout << key << " " << value << endl;
    }

    //数组方式遍历 仅在连续的方式
    for (int i = m.begin()->first; i <= m.size(); i++) {
        cout << i << " " << m[i] << endl;
    }

    //map的底层是红黑树，容器中不会出现相同的key，
    //因此map.count(key)的结果只能为0和1，可以用于来判断key是否存在。
    if (m.count(5)) {
        cout << "有这个元素" << endl;
    } else cout << "没有这个元素" << endl;
    if (m.find(5)==m.end())
        cout << "没有这个元素" << endl;
    vector<int> num = {0, 1, 0, 1, 0, 1, 100};
    cout << "singleNumber:" << singleNumber(num) << endl;


    map<int, string> list1;
    map<int, string> list2 = {{1, "java教程"},
                              {2, "c++教程"},
                              {3, "python教程"}};
    map<int, string> list3 =
            {pair<int, string>(1, "java教程"), pair<int, string>(2, "c++教程")};

    //遍历整个list1
    for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
        cout << iter->first << "  " << iter->second << endl;
    }

    map<int, int> list4;
    list4.insert(pair<int, int>(1, 15));
    list4[1] = 5;                     //会直接覆盖
    cout << list4[1] << endl;            //输出结果为5而不是15

    //两种方式添加元素
    map<int, int> list5;
    list5.insert(pair<int, int>(1, 15));
    list5.insert({2, 13});
}
//map<key,value> key必须唯一
int main() {
    //diff_unorderMapAndMap();
    mymultimap();

}