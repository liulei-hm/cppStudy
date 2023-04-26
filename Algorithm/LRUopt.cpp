//
// Created by liulei on 2023/3/7.
//
//
// Created by liulei on 2023/3/7.
//
#include "all.h"

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        int value=-1;
        if(u_map.count(key))
        {
            value = u_map[key]->second;
            LRUlist.erase(u_map[key]);
            LRUlist.push_front({key,value}); //放入链表最前端，最近使用元素
            u_map[key] = LRUlist.begin();
        }
        return value;
    }

    void put(int key, int value) {
        if(u_map.count(key))
        {
            LRUlist.erase(u_map[key]);
        }else{
            if(u_map.size()>=cap) //注意这里若使用LRUlist.size()>=cap链表的size时间复杂度并非O(1)https://wenfh2020.com/2021/04/09/stl-list-size/
            {
                u_map.erase(LRUlist.back().first);
                LRUlist.pop_back(); //弹出链表最后元素,即为最长未使用页面
            }
        }
        LRUlist.push_front({key, value}); //放入链表最前端，最近使用元素
        u_map[key] = LRUlist.begin();
    }

private:
    int cap;
    list<pair<int, int>> LRUlist;
    unordered_map<int,list<pair<int, int>>::iterator> u_map;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
enum INPUTS {
    LRUCACHE = 0,
    GET,
    PUT
};
enum INPUTN {
    KEY = 0,
    VALUE,
};
map<string, INPUTS> op = {
        {"LRUCache", LRUCACHE},
        {"get", GET},
        {"put", PUT},
};
vector<string> inputS = {"LRUCache", "get", "put", "get", "put", "put", "get", "get"};
vector<vector<int>> inputN = {{2},
                              {2},
                              {2, 6},
                              {1},
                              {1, 5},
                              {1, 2},
                              {1},
                              {2}};

int main() {
    LRUCache *lruCache = NULL;
    for (int i = LRUCACHE; i < inputS.size(); i++) {
        INPUTS opcase = op[inputS[i]];
        if(lruCache==NULL&&opcase!=LRUCACHE)
        {
            cout << "INIT ERROR!";
            break;
        }
        switch (opcase) {
            case LRUCACHE:
                lruCache = new LRUCache(inputN[LRUCACHE][LRUCACHE]);
                cout << "null,";
                break;
            case GET:
                cout << lruCache->get(inputN[i][KEY]) << ",";
                break;
            case PUT:
                cout << "null,";
                lruCache->put(inputN[i][KEY], inputN[i][VALUE]);
                break;
            default:
                cout << "INPUT ERROR!";
                break;
        }
    }
    cout << endl;
    return 0;
}
