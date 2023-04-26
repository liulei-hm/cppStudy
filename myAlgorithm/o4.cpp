#include <bits/stdc++.h>
using namespace std;

//C>W>M>W C开头智能以C或W结尾
//C>W>M>C //不能出现M>C
vector<char> path;
int total = 0;
int m,w,c; //m 2 w 1 c 0.5
unordered_map<char,int> u_m;
string str = "CWM";
unordered_map<char,double> u_m_score;
double maxScore = 0.0;
void printv(vector<char> &v)
{
    for(auto i:v)
    {
        cout << i << "->";
    }
    cout << endl;
}
double getScore(vector<char> &v){
    double score=0.0;
    int size = v.size();
    for(int i=0;i<size;i++)
    {
        score += u_m_score[v[i]];
        char one = v[i];
        char two = 0;
        char three = 0;
        if(i+2==size)
        {
            two = v[i+1];
            three = v[0];
        }else if(i+1==size)
        {
            two = v[0];
            three = v[1];
        }else {
            two = v[i+1];
            three = v[i+2];
        }
        if(one=='C'&&two=='M') //父子组合CM
        {
            score += 2.5;
        }else if(one=='C'&&two=='W') //母子组合CW
        {
            if(three=='M'){ //家庭组合CWM
                score += 3.0;
            }else
            {
                score += 2.0;
            }
        }else if(one=='M'&&two=='W') //扣分
        {
            score -= 1.0;
        }
    }
    return  score;
}
void dfs(){
    if(path.size()==total)
    {
        //一种组合
        //printv(path);
        double s = getScore(path);
        //cout << s << endl;
        maxScore = maxScore > s ? maxScore:s;
        return;
    }
    for(int i=0;i<3;i++)
    {
        char ch = str[i];
        if(u_m[ch]<=0)
        {
            continue;
        }
        if(ch=='C')
        {   //不能出现M->C
            if(!path.empty()&&path.back()!='M')
            {
                u_m[ch]--;
                path.push_back(ch);
            }else continue;
        }else {
            u_m[ch]--;
            path.push_back(ch);
        }
        dfs();
        u_m[path.back()]++;
        path.pop_back();
    }
}
int main(){
    cin >> m >> w >> c;
    total=m+w+c;
    u_m['M'] = m;
    u_m['W'] = w;
    u_m['C'] = c;
    u_m_score['M'] = 2.0;
    u_m_score['W'] = 1.0;
    u_m_score['C'] = 0.5;
    dfs();
    printf("%.1f",maxScore);
    return 0;
}