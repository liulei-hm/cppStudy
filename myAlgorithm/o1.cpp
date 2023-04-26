#include <bits/stdc++.h>
using namespace std;
#if 0
3 12
3 4 7
9 3 2
11 6 11
#endif
//3�����һ����12��
//������Ҫt1 t2 t3  3  4  7
//����۸�a1 a2 a3  9  3  2
//�����۸�b1 b2 b3  11 6  11
//�����۸�m1 m2 m3  2  3  9
//׬Ǯ���ķ���������һ���ڶ������Ȼ����һ�����������
//��ʱ4+7=11�죬׬��Ǯ��Ϊ 6-3+11-2=12������֤���������ŵķ�������Ȼ���ֵ��������ֵڶ���Ҳ�У���
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
//dp[i][j] ��ʾi�����һ��j�������¿��Ի�õ��������
//ת�Ʒ���    dp[i][j] = max(dp[i-1][j],dp[i][j-t[m]]+money[m])
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