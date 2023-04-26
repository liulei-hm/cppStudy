//
// Created by liulei on 2023/3/7.
//
#include "all.h"

//��ʹ��List���� ���۳�ʱ
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
                LRUlist.push_front({key, value}); //����������ǰ�ˣ����ʹ��Ԫ��
                break;
            }
        }
        return value;
    }

    void put(int key, int value) {
        //ע������������heap-use-after-free,��Ϊ�����list������pop,���ܵ���begin���ͷţ�Ӧ�÷�������
        //list<pair<int, int>>::iterator it = LRUlist.begin();
        // if(LRUlist.size()>=cap)  //�����ж��߼�Ҳ�����⣬�����ڷ���keyδ������list�����ж�
        // {
        //     LRUlist.pop_back(); //�����������Ԫ��,��Ϊ�δʹ��ҳ��
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
                LRUlist.pop_back(); //�����������Ԫ��,��Ϊ�δʹ��ҳ��
            }
        }
        LRUlist.push_front({key, value}); //����������ǰ�ˣ����ʹ��Ԫ��
    }

private:
    int cap;
    list<pair<int, int>> LRUlist;
    //heap-use-after-free��������
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
