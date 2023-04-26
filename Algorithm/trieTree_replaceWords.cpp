//
// Created by liulei on 2023/3/14.
//
//����648 �滻����

#include "trieTree.h"

class Solution {
public:
    char *split(char *str,const char* s)
    {
        char *token=NULL;
        /* ��ȡ��һ�����ַ��� */
        token = strtok(str, s);
        /* ������ȡ���������ַ��� */
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, s);
        }
        return token;
    }
    vector<string> leetcode_split(string &str, char ch) {
        int pos = 0;
        int start = 0;
        vector<string> ret;
        while (pos < str.size()) {
            while (pos < str.size() && str[pos] == ch) {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != ch) {
                pos++;
            }
            if (start < str.size()) {
                ret.emplace_back(str.substr(start, pos - start));
            }
        }
        return ret;
    }
    vector<string> my_split(string &str,char ch)
    {
        vector<string> ret;
        ret.push_back("");
        for(char ch : str)
        {
            if(ch==' ')
            {
                ret.push_back("");
            }else ret.back().push_back(ch);
        }
        return ret;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        Trie *trie = new Trie();
        for(string s:dictionary)
        {
            trie->insert(s);
        }
        vector<string> words = leetcode_split(sentence,' ');
        for(string word:words)
        {
            string prefix = trie->findPrefixOfWord(word);
            if(prefix=="")
            {
                res += word + " ";
            }else{
                res += prefix + " ";
            }
        }
        res.pop_back();
        return res;
    }
};

vector<string> dictionary = {"cat","bat","rat"};
string sentence = "the cattle was rattled by the battery";

#define INFO_MAX_SZ 80
int main() {
    Solution solution;
    cout << solution.replaceWords(dictionary,sentence) << endl;

    char str[INFO_MAX_SZ] = "dream-coder-lixiaoyao";
    const char delim[2] = "-";
    /*ʹ�øú��������ַ����ָ�ʱ�����ƻ����ֽ��ַ���������������ǰ�͵��ú��s�Ѿ���һ���ˡ�
     * ��һ�ηָ�֮��ԭ�ַ���str�Ƿָ����֮��ĵ�һ���ַ�����ʣ����ַ����洢��һ����̬�����С�
     * strtok��������ȡ�ַ���ʱʹ���˾�̬����������ˣ������̲߳���ȫ�ģ����߳�ͬʱ���ʸþ�̬����ʱ�������ִ���*/
    //https://zhuanlan.zhihu.com/p/250500486
    solution.split(str,delim);

    return 0;
}

