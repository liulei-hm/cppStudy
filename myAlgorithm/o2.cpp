#include <bits/stdc++.h>
using namespace std;
#if 0
101110110
#endif
//操作之后整个串的代价为下面两部分之和：
//
//1. 被删除的字符1的个数； 删除1产生代价
//2. 剩下的子串的字符0的个数 保留0产生代价
//在删除前缀和后缀时考虑删除当前字符串是否可以将后面的0删掉
//在尽可能少删除1的情况下，把0删除
//删除1的时候，后面
int main(){
    string str;
    cin >> str;
    int minOP=0;
    int maxO=0;
    int maxZ=0;
    unordered_map<char,int> m;
    int len = str.size();
    for(int i=0;i<str.size();i++)
    {
        m[str[i]]++; //统计出字符串01的个数
    }
    //如果全删除
    maxO = m['1'];
    minOP = m['1'];
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            int resZ=0;
            int resO=0;
            string substr = str.substr(i,j-i+1);
            for(char c:substr)
            {
                if(c=='0')
                {
                    resZ++;
                }else resO++;
            }
            int cntOP = resZ + maxO-resO;
            minOP = minOP < cntOP ? minOP:cntOP;
        }
    }
    cout <<minOP << endl;
    //cout << m['0'] << " " << m['1'] << endl;
    return 0;
}