#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
vector<int> g[N];
vector<int> top;
int d[N];// �����е�����

bool topSort(){
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0){
            que.push(i);
        }
    }
    while (!que.empty()){
        int t = que.front();
        que.pop();
        top.push_back(t);
        // ����t���ڱߣ����ڽӵ����-1���������Ϊ0�ģ����������
        for(int i=0;i<g[t].size();i++){
            int b = g[t][i];
            d[b]--;
            if (d[b] == 0){
                que.push(b);
            }
        }
    }
    if (top.size() == n) return true;
    else return false;


}


int main() {
    cin >> n >> m;
    while (m--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        d[b]++;
    }

    if (topSort()){
        for (int i = 0; i < n; ++i) {
            cout<<top[i]<<" ";
        }
    }
    else {
        cout<<-1;
    }


}
