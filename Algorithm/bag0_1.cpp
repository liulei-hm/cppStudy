//
// Created by liulei on 2023/3/21.
//
#include "all.h"
//��̬�滮
//����  dp[i][j]  ���±�Ϊ[0-i]����Ʒ������ȡ���Ž�����Ϊj�ı������ܺ����ļ�ֵ
//��ʼ�� dp  dp[i][0] = 0 ��������Ϊ0��װ������Ʒ dp[0][j] ���j>weight[0]�������װ��
//ת�Ʒ���  ��j��װ����Ʒi   1���������i����Ʒdp[i-1][j]  2�������i����Ʒ(����������ҪΪj-weight)��dp[i - 1][j - weight[i]] + value[i]
//        ��j��װ������Ʒi  1���������i����Ʒdp[i-1][j]
//          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//  i   j   0   1   2   3   4
//  0       0   15  15  15  15
//  1       0
//  2       0
void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    // ��ά����
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // ��ʼ��
    for(int i=0;i<weight.size();i++)
    {
        dp[i][0] = 0;
    }
    for(int j=0;j<bagweight+1;j++)
    {
        if(j>weight[0])
        {
            dp[0][j] = value[0];
        }else dp[0][j] = 0;
    }
    // weight����Ĵ�С ������Ʒ����
    for(int i = 1; i < weight.size(); i++) { // ������Ʒ
        for(int j = 0; j <= bagweight; j++) { // ������������
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
}
#include "bag0_1.h"
