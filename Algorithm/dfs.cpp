//
// Created by liulei on 2023/4/20.
//
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> path;  //路径
vector<vector<int>> res; //所有路径

unordered_set<int> block; //障碍哈希

vector<vector<int>> v;  //输入数组
vector<vector<int>> edge; //邻接表

void dfs(int pos){
    if(edge[path.back()].size()==0) //找到了叶子节点
    {
        res.push_back(path);
        return;
    }
    for(int i=0;i<edge[pos].size();i++)
    {
        if(edge[pos][i]==-1)
        {
            continue; //障碍节点
        }
        int nextpos = edge[pos][i];
        path.push_back(nextpos);
        dfs(nextpos);
        path.pop_back();
    }
}
bool check(int mini,int nowi)
{
    for(size_t i=0;i<res[nowi].size();i++)
    {
        if(res[mini][i]<res[nowi][i])
        {
            return false; //如果发现min序列比当前序列要小，直接返回
        }else if(res[mini][i]>res[nowi][i]) return true;
    }
    return false;
}
//打印最短路径
void print_shotest_path()
{
    if(res.size()==0){
        cout << "NULL";
        return;
    }
    int mini = 0;
    for(size_t i=0;i<res.size();i++)
    {
        if(res[mini].size() > res[i].size())
        {
            mini = i;
        }else if(res[mini].size() == res[i].size())
        {
            //是否找到了更小的序列
            if(check(mini,i)==true)
            {
                mini = i;
            }
        }
    }
    for(size_t i=0;i<res[mini].size();i++)
    {
        if(i!=res[mini].size()-1)
        {
            cout << res[mini][i] << "->";
        }else  cout << res[mini][i];
    }
}
int main(){
    int n;
    int size;
    int block_cnt;
    cin >> n; //节点数
    cin >> size; //边数
    //输入每行
    while(size--)
    {
        vector<int> a(2);
        cin >> a[0]; //有向图 源节点
        cin >> a[1]; //有向图 目的节点
        v.push_back(a);
    }
    cin >> block_cnt;
    while(block_cnt--)
    {
        int x;
        cin >> x;
        block.insert(x);
    }
    //构建邻接表
    edge.resize(n);
    for(int i=0;i<v.size();i++)
    {
        if(!block.count(v[i][1]))
        {
            edge[v[i][0]].push_back(v[i][1]);
        }else edge[v[i][0]].push_back(-1); //障碍
    }
    path.push_back(0);
    dfs(0);
    print_shotest_path();
    return 0;
}