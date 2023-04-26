//
// Created by liulei on 2023/3/7.
//
#include "all.h"

//仅使用List链表 力扣超时
class LRUCache {
public:
    explicit LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        int value = -1;
        auto it = LRUlist.begin();
        for (; it != LRUlist.end(); it++) {
            if (it->first == key) {
                value = it->second;
                LRUlist.erase(it);
                LRUlist.push_front({key, value}); //放入链表最前端，最近使用元素
                break;
            }
        }
        return value;
    }

    void put(int key, int value) {
        //注意这里引发了heap-use-after-free,因为下面对list进行了pop,可能导致begin被释放，应该放在下面
        //list<pair<int, int>>::iterator it = LRUlist.begin();
        // if(LRUlist.size()>=cap)  //这里判断逻辑也有问题，必须在放入key未出现在list中再判断
        // {
        //     LRUlist.pop_back(); //弹出链表最后元素,即为最长未使用页面
        // }
        auto it = LRUlist.begin();
        for (; it != LRUlist.end(); it++) {
            if (it->first == key) {
                LRUlist.erase(it);
                break;
            }
        }
        if (it == LRUlist.end()) {
            if (LRUlist.size() >= cap) {
                LRUlist.pop_back(); //弹出链表最后元素,即为最长未使用页面
            }
        }
        LRUlist.push_front({key, value}); //放入链表最前端，最近使用元素
    }

private:
    int cap;
    list<pair<int, int>> LRUlist;
    //heap-use-after-free报错用例
    //["LRUCache","put","get","put","get","get"]
    //[[1],[2,1],[2],[3,2],[2],[3]]
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
unordered_map<string, INPUTS> op = {
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
    for (int i = 0; i < inputS.size(); i++) {
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
