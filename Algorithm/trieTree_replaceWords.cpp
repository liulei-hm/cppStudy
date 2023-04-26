//
// Created by liulei on 2023/3/14.
//
//力扣648 替换单词

#include "trieTree.h"

class Solution {
public:
    char *split(char *str,const char* s)
    {
        char *token=NULL;
        /* 获取第一个子字符串 */
        token = strtok(str, s);
        /* 继续获取其他的子字符串 */
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
    /*使用该函数进行字符串分割时，会破坏被分解字符串的完整，调用前和调用后的s已经不一样了。
     * 第一次分割之后，原字符串str是分割完成之后的第一个字符串，剩余的字符串存储在一个静态变量中。
     * strtok函数在提取字符串时使用了静态缓冲区，因此，它是线程不安全的，多线程同时访问该静态变量时，则会出现错误*/
    //https://zhuanlan.zhihu.com/p/250500486
    solution.split(str,delim);

    return 0;
}

