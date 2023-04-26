#include <bits/stdc++.h>
using namespace std;
#if 0
3 12
3 4 7
9 3 2
11 6 11
#endif
//3种作物，一共有12天
//成熟需要t1 t2 t3  3  4  7
//买入价格a1 a2 a3  9  3  2
//卖出价格b1 b2 b3  11 6  11
//卖出价格m1 m2 m3  2  3  9
//赚钱最多的方案是先种一个第二种作物，然后种一个第三种作物，
//耗时4+7=11天，赚的钱数为 6-3+11-2=12，可以证明这是最优的方案（当然先种第三种再种第二种也行）。
void printv(vector<vector<int>> &v)
{
    for(auto i:v)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//dp[i][j] 表示i种作物，一共j天的情况下可以获得的最大收益
//转移方程    dp[i][j] = max(dp[i-1][j],dp[i][j-t[m]]+money[m])
int main(){
    int n,day;
    cin >> n >> day;
    vector<int> t(n);
    vector<int> a(n);
    vector<int> b(n);
    vector<int> money(n);
    for(int i=0;i<n;i++)
    {
        cin >> t[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        money[i] = b[i] - a[i];
    }
    vector<vector<int>> dp(n,vector<int>(day+1,0));
    for(int j=0;j<day+1;j++)
    {
        if(j>=t[0])
        {
            dp[0][j] = money[0]*(j/t[0]);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<day+1;j++)
        {
            if(j>=t[i])
            {
                for(int d=t[i]-1;d<=j;d++)
                {
                    int fen = d/t[i];
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-t[i]*fen]+money[i]*fen);
                }
            }
        }
    }
    //printv(dp);
    cout << dp[n-1][day] << endl;
}