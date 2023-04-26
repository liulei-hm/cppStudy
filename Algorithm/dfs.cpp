//
// Created by liulei on 2023/4/20.
//
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> path;  //·��
vector<vector<int>> res; //����·��

unordered_set<int> block; //�ϰ���ϣ

vector<vector<int>> v;  //��������
vector<vector<int>> edge; //�ڽӱ�

void dfs(int pos){
    if(edge[path.back()].size()==0) //�ҵ���Ҷ�ӽڵ�
    {
        res.push_back(path);
        return;
    }
    for(int i=0;i<edge[pos].size();i++)
    {
        if(edge[pos][i]==-1)
        {
            continue; //�ϰ��ڵ�
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
            return false; //�������min���бȵ�ǰ����ҪС��ֱ�ӷ���
        }else if(res[mini][i]>res[nowi][i]) return true;
    }
    return false;
}
//��ӡ���·��
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
            //�Ƿ��ҵ��˸�С������
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
    cin >> n; //�ڵ���
    cin >> size; //����
    //����ÿ��
    while(size--)
    {
        vector<int> a(2);
        cin >> a[0]; //����ͼ Դ�ڵ�
        cin >> a[1]; //����ͼ Ŀ�Ľڵ�
        v.push_back(a);
    }
    cin >> block_cnt;
    while(block_cnt--)
    {
        int x;
        cin >> x;
        block.insert(x);
    }
    //�����ڽӱ�
    edge.resize(n);
    for(int i=0;i<v.size();i++)
    {
        if(!block.count(v[i][1]))
        {
            edge[v[i][0]].push_back(v[i][1]);
        }else edge[v[i][0]].push_back(-1); //�ϰ�
    }
    path.push_back(0);
    dfs(0);
    print_shotest_path();
    return 0;
}