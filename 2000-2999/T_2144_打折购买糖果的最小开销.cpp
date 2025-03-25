#include<iostream>
#include<queue>
#include<vector>
using namespace std;



class Solution {
    public:
        int minimumCost(vector<int>& cost) {
            sort(cost.begin(), cost.end(), greater<int>());
            int res = 0;
            int n = cost.size();
            for (int i = 0; i < n; ++i) {
                if (i % 3 != 2) {
                    res += cost[i];
                }
            }
            return res;
        }
    };

/*
    我们不妨假设 cost 数组已经按照价格降序排序，根据定义，
    免费获得糖果中价格最高的一定不大于 cost[2]（假设该下标存在，下同）。
    类似地，我们可以得出，价格第 k(0≤k≤?n/3?) 高的糖果的价格一定不大于 cost[3k+2]。
*/

