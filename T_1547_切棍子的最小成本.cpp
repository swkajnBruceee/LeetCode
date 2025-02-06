#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    for (int len = 2; len < m; ++len) {
        for (int i = 0; i < m - len; ++i) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
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







