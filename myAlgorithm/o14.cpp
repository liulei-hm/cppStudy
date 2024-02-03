//
// Created by liulei on 2023/5/11.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, string> u_map = {
            {"&quot;","\""},
            {"&apos;","'"},
            {"&amp","&"},
            {"&gt",">"},
            {"&lt","<"},
            {"&frasl","/"},
            };

    string entityParser(string text) {
        string html;
        string key;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]=='&')
            {
                key += text[i];
            }else if(text[i] == ';')
            {
                key += text[i];
                if(u_map.count(key))
                {
                    html += key;
                    key.clear();
                }
            }else{
                key += text[i];
            }
        }
        return html;
    }
};

int main() {

    return 0;
}
