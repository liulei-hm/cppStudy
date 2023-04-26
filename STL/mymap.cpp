//
// Created by liulei on 2023/2/3.
//

#include "all.h"

//ֻ����һ�ε�����
//���룺nums = [0,1,0,1,0,1,100]
//�����100
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
//���ⷨ2λ���㡹 ���� [2 2 3 2] �ռ� 10 10 11 10 ��ÿһλ֮�ͣ��������3���õ��ļ���11��һλ��ֵ

void diff_unorderMapAndMap()
{
    unordered_map<int,string> u_map;

    u_map.insert({3, "333"});

    u_map.insert(pair<int,string>(1, "111"));

    u_map.insert(pair<int,string>(4, "444"));

    u_map.insert(pair<int,string>(2, "222"));

    u_map.insert(pair<int,string>(5, "555"));

    unordered_map<int,string>::iterator u_iter = u_map.begin();
    cout << "unordered_map ������ԭ���������" << endl;
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
    cout << "map �����keyֵ�������� ��" << endl;
    for (iter; iter != m_map.end(); iter++)

    {
        cout << iter->first << "," << iter->second.c_str() << endl;
    }
}

void mymultimap(){
    //map��multimap���ᰴkey�Ĵ�С˳�����򣬶�multimap(�����)���Դ�Ų�ͬ��key
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
    //node->children.insert({ch,tmpNode}); ����
    //node->children.insert(std::make_pair(ch, tmpNode)); ����
    m.insert(pair<int, string>(22, "Jim"));
    //��������������ͷ������������
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

    //���鷽ʽ���� ���������ķ�ʽ
    for (int i = m.begin()->first; i <= m.size(); i++) {
        cout << i << " " << m[i] << endl;
    }

    //map�ĵײ��Ǻ�����������в��������ͬ��key��
    //���map.count(key)�Ľ��ֻ��Ϊ0��1�������������ж�key�Ƿ���ڡ�
    if (m.count(5)) {
        cout << "�����Ԫ��" << endl;
    } else cout << "û�����Ԫ��" << endl;
    if (m.find(5)==m.end())
        cout << "û�����Ԫ��" << endl;
    vector<int> num = {0, 1, 0, 1, 0, 1, 100};
    cout << "singleNumber:" << singleNumber(num) << endl;


    map<int, string> list1;
    map<int, string> list2 = {{1, "java�̳�"},
                              {2, "c++�̳�"},
                              {3, "python�̳�"}};
    map<int, string> list3 =
            {pair<int, string>(1, "java�̳�"), pair<int, string>(2, "c++�̳�")};

    //��������list1
    for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
        cout << iter->first << "  " << iter->second << endl;
    }

    map<int, int> list4;
    list4.insert(pair<int, int>(1, 15));
    list4[1] = 5;                     //��ֱ�Ӹ���
    cout << list4[1] << endl;            //������Ϊ5������15

    //���ַ�ʽ���Ԫ��
    map<int, int> list5;
    list5.insert(pair<int, int>(1, 15));
    list5.insert({2, 13});
}
//map<key,value> key����Ψһ
int main() {
    //diff_unorderMapAndMap();
    mymultimap();

}