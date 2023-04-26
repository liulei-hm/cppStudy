#include <bits/stdc++.h>

using namespace std;

#if 0
1 2 3 4 5 31
1 2 11 14 25 15
31,41,
#endif
vector<vector<int>> grid = {
        {1,  2,  3,  4,  5},
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35},
        {41, 42, 43, 44, 45},
};
void printv(vector<vector<int>> v)
{
    for(auto i:v)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main() {
    int a;
    int dis[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}}; //上下左右
    while (cin >> a) {
        vector<int> v(6);
        vector<pair<int, int>> vpos(6);
        v[0] = a;
        for (int i = 1; i < 6; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < 6; i++) {
            int x = v[i] / 10;
            int y = v[i] % 10 - 1;
            vpos[i] = {x, y};
        }
        //如果六个点相邻那么从起点开始bfs一定可以遍历到所有节点
        queue<pair<int, int>> que;
        vector<vector<int>> visited(5, vector<int>(5, 0));
        que.push(vpos[0]);
        while (!que.empty()) {
            int size = que.size();
            for (int c = 0; c < size; c++) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                visited[x][y] = 1;
                if(x==0&&y==4)
                {
                    cout << endl;
                }
                for (int i = 0; i < 4; i++) {
                    int newx = x + dis[0][i];
                    int newy = y + dis[1][i];
                    if (newx >= 0 && newx < 5 && newy >= 0 && newy < 5 &&visited[newx][newy] == 0) {
                        //cout << newx << " " << newy << endl;
                        visited[newx][newy] = 1;
                        for (auto p: vpos) {
                            if (p.first == newx && p.second == newy) {
                                que.push({newx, newy});
                                break;
                            }
                        }
                    }
                }
            }
        }
        //printv(visited);
        int flag = 1;
        for (auto p: vpos) {
            if (visited[p.first][p.second] == 0) {
                flag = 0;
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}