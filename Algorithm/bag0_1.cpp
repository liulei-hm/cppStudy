//
// Created by liulei on 2023/3/21.
//
#include "all.h"
//动态规划
//定义  dp[i][j]  从下标为[0-i]的物品里任意取，放进容量为j的背包，总和最大的价值
//初始化 dp  dp[i][0] = 0 背包重量为0，装不了物品 dp[0][j] 如果j>weight[0]，则可以装入
//转移方程  若j能装下物品i   1、不放入第i个物品dp[i-1][j]  2、放入第i个物品(背包容量需要为j-weight)，dp[i - 1][j - weight[i]] + value[i]
//        若j就装不下物品i  1、不放入第i个物品dp[i-1][j]
//          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//  i   j   0   1   2   3   4
//  0       0   15  15  15  15
//  1       0
//  2       0
void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化
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
    // weight数组的大小 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
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
