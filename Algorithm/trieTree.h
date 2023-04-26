//
// Created by liulei on 2023/3/14.
//

#ifndef CPPTHING_TRIETREE_H
#define CPPTHING_TRIETREE_H

#include "all.h"

class Trie{
public:
    Trie():isEnd(false),next(26, nullptr){
        //isEnd = false;
        //memset(next,0,sizeof(next));
    }

private:
    bool isEnd;
    //Trie *next[26];
    vector<Trie *> next;   //注意类中不能定义vector的初始大小，编译器有歧义，认为是函数
public:
    //向前缀树中插入一个单词
    void insert(string word){
        if(word.empty()) return;
        Trie *node = this;
        for(char ch:word)
        {
            if(node->next[ch-'a'] == NULL)
            {
                node->next[ch-'a'] = new Trie();
            }
            node = node->next[ch-'a'];
        }
        node->isEnd = true;
    }
    //查找某个单词是否存在
    bool search(string word){
        if(word.empty()) return false;
        bool isFind=false;
        Trie *node = this;
        int i=0;
        for(i=0;i<word.size();i++)
        {
            char ch = word[i];
            node = node->next[ch-'a'];
            if(node == NULL)
            {
                isFind = false;
                break;
            }
        }
        if(i==word.size()&&node->isEnd)
        {
            isFind = true;
        }
        return isFind;
    }
    //查找某个前缀是否存在
    bool startsWith(string prefix) {
        if(prefix.empty()) return false;
        bool isStart = false;
        Trie *node = this;
        int i=0;
        for(i=0;i<prefix.size();i++)
        {
            char ch = prefix[i];
            node = node->next[ch-'a'];
            if(node == nullptr)
            {
                isStart = false;
                break;
            }
        }
        if(i==prefix.size())
        {
            isStart = true;
        }
        return isStart;
    }
    //查找单词的最短前缀
    string findPrefixOfWord(string word) {
        if(word.empty()) return "";
        string prefix;
        Trie *node = this;
        for(char ch : word)
        {
            node = node->next[ch-'a'];
            if(node == nullptr)
            {
                return "";
            }
            prefix += ch;
            if(node->isEnd)
            {
                break;
            }
        }
        //如果是word提前结束，而node->isEnd没有为true 返回空
        if(!node->isEnd)
        {
            return "";
        }
        return prefix;
    }

    virtual ~Trie() {
        cout << "Trie-over" << endl;
    }
};

namespace leetcode{
    class Trie {
    private:
        vector<Trie*> children;
        bool isEnd;
        Trie* searchPrefix(string prefix) {
            Trie* node = this;
            for (char ch : prefix) {
                ch -= 'a';
                if (node->children[ch] == nullptr) {
                    return nullptr;
                }
                node = node->children[ch];
            }
            return node;
        }
    public:
        Trie() : children(26), isEnd(false) {}

        void insert(string word) {
            Trie* node = this;
            for (char ch : word) {
                ch -= 'a';
                if (node->children[ch] == nullptr) {
                    node->children[ch] = new Trie();
                }
                node = node->children[ch];
            }
            node->isEnd = true;
        }

        bool search(string word) {
            Trie* node = this->searchPrefix(word);
            return node != nullptr && node->isEnd;
        }

        bool startsWith(string prefix) {
            return this->searchPrefix(prefix) != nullptr;
        }
    };
}

namespace leetcodemap{
    class Trie {
    private:
        unordered_map<char,Trie*> children;
        bool isEnd;

        Trie* searchPrefix(string prefix) {
            Trie* node = this;
            for (char ch : prefix) {
                ch -= 'a';
                auto it =  node->children.find(ch);
                if(it==node->children.end())
                {
                    return nullptr;
                }
                node = node->children.find(ch)->second;
            }
            return node;
        }

    public:

        Trie() : children(0), isEnd(false) {}

        void insert(string word) {
            Trie* node = this;
            for (char ch : word) {
                ch -= 'a';
                auto it =  node->children.find(ch);
                if(it==node->children.end())
                {
                    node->children.insert(pair<char,Trie *>{ch,new Trie()});
                }
                node = node->children.find(ch)->second;
            }
            node->isEnd= true;
        }

        bool search(string word) {
            Trie* node = this->searchPrefix(word);
            return node != nullptr && node->isEnd;
        }

        bool startsWith(string prefix) {
            return this->searchPrefix(prefix) != nullptr;
        }
    };
}
#endif //CPPTHING_TRIETREE_H
