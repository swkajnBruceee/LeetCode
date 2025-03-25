//动态规划的思想
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0)); //二维向量 dp，dp[i][j] 表示将区间[i,j]内的木棍切割完的最小成本
                                                  //初始值都设置为0  
    for (int len = 2; len < m; ++len) //外层循环，len 表示区间的长度，从长度为 2 开始
    {                                 //（因为长度为 1 的区间不需要切割，成本为 0），逐步增加到 m - 1。 
        for (int i = 0; i < m - len; ++i) //内层循环，i 表示区间的起始位置，根据当前 len 计算出有效的起始位置范围。
        {
            int j = i + len;    //根据当前的起始位置 i 和长度 len 计算出区间的结束位置 j
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) //在区间 [i, j] 内遍历所有可能的切割点 k
            {
                //计算在 k 点切割的成本
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
        }
    }
    return dp[0][m - 1];
}


int main()
{
    vector<int> cuts = {7,8,9,2,1};
    cout<<minCost(10,cuts);
    return 0;
}

