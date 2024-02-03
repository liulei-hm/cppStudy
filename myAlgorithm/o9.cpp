//
// Created by liulei on 2023/5/1.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path; // ���Ѿ����ĵ��Ӵ�
    void backtracking (const string& s, int startIndex) {
        // �����ʼλ���Ѿ�����s�Ĵ�С��˵���Ѿ��ҵ���һ��ָ����
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            string str = s.substr(startIndex, i - startIndex + 1);
            if (isPalindrome(str)) {   // �ǻ����Ӵ�
                // ��ȡ[startIndex,i]��s�е��Ӵ�
                path.push_back(str);
            } else {                                // ���ǻ��ģ�����
                continue;
            }
            backtracking(s, i + 1); // Ѱ��i+1Ϊ��ʼλ�õ��Ӵ�
            path.pop_back(); // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
        }
    }
    bool isPalindrome(const string& s) {
        for (int i = 0, j = s.size()-1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

int main(){
    Solution a;
    string s = "010010";

    return 0;
}