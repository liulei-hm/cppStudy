//
// Created by liulei on 2023/3/7.
//
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#include "all.h"
// Node��Ա����public�ģ��Ƽ�����NodeΪstruct
struct Node {
    int key;
    int val;
    Node *next, *prev;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
    Node *head, *tail;
public:
    DoubleLinkedList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void push_front(Node* node) {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    void erase(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    Node* back() {
        return tail->prev;
    }

    void pop_back() {
        erase(tail->prev);
    }
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> key_node_map;
    DoubleLinkedList* node_list;
public:
    LRUCache(int capacity) {
        cap = capacity;
        node_list = new DoubleLinkedList();
    }

    int get(int key) {
        // �����ڸ�key
        if (key_node_map.find(key) == key_node_map.end()) {
            return -1;
        } else {
            // ����ǰ�ڵ����ƶ���˫�������λ
            Node* node = key_node_map[key];
            node_list->erase(node);
            node_list->push_front(node);
            return node->val;
        }
    }

    void put(int key, int value) {
        // ���key���ڣ����޸Ķ�Ӧ��value���ƶ��������׶�
        if (key_node_map.find(key) != key_node_map.end()) {
            Node *node = key_node_map[key];
            node->val = value;
            node_list->erase(node);
            node_list->push_front(node);
        } else {
            // ���������������ɾ��˫����ĩ�˽ڵ�
            if (key_node_map.size() == cap) {
                key_node_map.erase(node_list->back()->key);
                node_list->pop_back();
            }
            // �����½ڵ�
            Node *node = new Node(key, value);
            key_node_map[key] = node;
            node_list->push_front(node);
        }
    }
};

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