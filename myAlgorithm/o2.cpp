#include <bits/stdc++.h>
using namespace std;
#if 0
101110110
#endif
//����֮���������Ĵ���Ϊ����������֮�ͣ�
//
//1. ��ɾ�����ַ�1�ĸ����� ɾ��1��������
//2. ʣ�µ��Ӵ����ַ�0�ĸ��� ����0��������
//��ɾ��ǰ׺�ͺ�׺ʱ����ɾ����ǰ�ַ����Ƿ���Խ������0ɾ��
//�ھ�������ɾ��1������£���0ɾ��
//ɾ��1��ʱ�򣬺���
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
        m[str[i]]++; //ͳ�Ƴ��ַ���01�ĸ���
    }
    //���ȫɾ��
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