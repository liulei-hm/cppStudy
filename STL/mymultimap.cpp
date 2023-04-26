//
// Created by liulei on 2023/4/26.
//
#include <iostream>
#include <map>
#include <string>

using namespace std;

void deleteOperator()
{
    //1.clear清除内容
    multimap<int, string> map1 = {{1,"draggonfruit"}, {2,"rambutan"}, {3,"guava"}};
    cout << "1 size = " << map1.size() << " empty = " << map1.empty() << endl;
    map1.clear();
    cout << "2 size = " << map1.size() << " empty = " << map1.empty() << endl;
    //2.erase擦除元素
    map1.insert({3, "sugercane"});
    map1.emplace(4, "grapefruit");
    map1.insert({5, "blackberry"});
    map1.insert({6, "kiwi"});
    map1.emplace(3, "gooseberry");
    map1.insert({7, "apple"});

    cout << "multimap元素如下:" << endl;
    for(auto val: map1)
    {
        cout << val.first << ": " << val.second << endl;
    }
    map1.erase(3);
    cout << "关键字3删除元素" << endl;
    for(auto val: map1)
    {
        cout << val.first << ": " << val.second << endl;
    }
    cout << "迭代器begin删除元素" << endl;
    auto mapIt = map1.begin();
    map1.erase(mapIt);
    for(auto val: map1)
    {
        cout << val.first << ": " << val.second << endl;
    }
    cout << "范围删除元素" << endl;
    auto startIter = map1.begin();
    auto endIter = ++startIter;
    ++endIter;
    ++endIter;
    map1.erase(startIter, endIter);
    for(auto val: map1)
    {
        cout << val.first << ": " << val.second << endl;
    }
    auto mapIter2 = map1.begin();
    while(mapIter2 != map1.end())
    {
        cout << mapIter2->first << ": " << mapIter2->second << endl;
        ++mapIter2;
    }

    //3.swap交换内容
    multimap<int, string> map2 = {{11,"fig"}, {12,"lemon"}, {13,"olive"}};;
    auto map2Iter = map2.begin();
    while(map2Iter != map2.end())
    {
        cout << map2Iter->first << ": " << map2Iter->second << endl;
        ++map2Iter;
    }
    map2.swap(map1);
    cout << "map1: " << endl;
    for(auto map1iter = map1.begin(); map1iter != map1.end(); ++map1iter)
    {
        cout << map1iter->first << ": " << map1iter->second << endl;
    }

    cout << "map2: " << endl;
    for(auto map2iter = map2.begin(); map2iter != map2.end(); ++map2iter)
    {
        cout << map2iter->first << ": " << map2iter->second << endl;
    }

    //4.extract从另一容器释出结点   C++17 提取
    cout << "map3: " << endl;
    multimap<int, string> map3{{1,"apple"}, {5,"pear"}, {5,"peach"}, {3,"grape"}};
    auto nh = map3.extract(5);//参数key
    nh.key() = 2;
    map3.insert(move(nh));
    for(auto map3iter = map3.begin(); map3iter != map3.end(); ++map3iter)
    {
        cout << map3iter->first << ": " << map3iter->second << endl;
    }
    cout << "map3.size = " << map3.size() << endl;
    //5.merge从另一容器接合结点   C++17
    multimap<int, string> map4{{2, "durian"}, {5, "mango"}};;
    multimap<int, string> map5{{1, "strawberry"}, {5, "banana"}, {8, "orange"}};
    map5.merge(map4);//相同的关键字也会合并，例如5
    cout << "map4: " << endl;
    for(auto const &value: map4)
    {
        cout << value.first << ": " << value.second << endl;
    }

    cout << "map5: " << endl;
    for(auto const &value: map5)
    {
        cout << value.first << ": " << value.second << endl;
    }
}

int main()
{
    deleteOperator();
    cout << "Hello, world!" << endl;
    return 0;
}