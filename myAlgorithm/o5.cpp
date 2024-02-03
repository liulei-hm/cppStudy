#include <bits/stdc++.h>
using namespace std;

bool check(long long num){
    string s = to_string(num);

    int len = s.size();
    long long sum = 0;
    for(int j=0;j<len;j++)
    {
        sum += pow(s[j]-'0',len);
    }
    if(sum==num)
    {
        cout << s << endl;
        return true;
    }else
    {
        return false;
    }

}
void fun(char aa[128])
{
    cout << sizeof(aa) << endl;
}
int main(){
    long long num=0;
    cin >> num;
    for(long long i=num;i>100;i--)
    {
        if(check(i)==true){
            cout << i << endl;
        }
    }
    return 0;
}