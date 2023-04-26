//
// Created by liulei on 2023/3/13.
//
#include "trieTree.h"



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

enum INPUTS {
    TRIE = 0,
    INSERT,
    SEARCH,
    STARTSWITH
};
enum INPUTN {
    KEY = 0,
    VALUE,
};
unordered_map<string, INPUTS> op = {
        {"Trie", TRIE},
        {"insert", INSERT},
        {"search", SEARCH},
        {"startsWith", STARTSWITH},
};
vector<string> inputS = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
vector<string> inputN = { ""  ,  "apple" ,  "apple" ,  "app" ,  "app" ,  "app" ,  "app" };

void test(){
    Trie *trie = new Trie();
    trie->insert("das");
    trie->search("d");
    //delete trie;
}
int main()
{
    leetcodemap::Trie *trie = nullptr;
    test();
    for (int i = 0; i < inputS.size(); i++) {
        INPUTS opcase = op[inputS[i]];
        if(trie==nullptr&&opcase!=TRIE)
        {
            cout << "INIT ERROR!";
            break;
        }
        switch (opcase) {
            case TRIE:
                trie = new leetcodemap::Trie();
                cout << "null,";
                break;
            case INSERT:
                trie->insert(inputN[i]);
                cout << "null,";
                break;
            case SEARCH:
                cout << trie->search(inputN[i]) << ",";
                break;
            case STARTSWITH:
                cout << trie->startsWith(inputN[i]) << ",";
                break;
            default:
                cout << "INPUT ERROR!";
                break;
        }
    }
    return 0;
}
