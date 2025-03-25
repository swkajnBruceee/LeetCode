#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1); // 前缀和数组
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i]; // 计算前缀和
        }

        vector<long long> min_s(k, LLONG_MAX / 2); // 每个余数分组的最小前缀和，防止溢出
        long long ans = LLONG_MIN; // 初始答案设为最小
      

        for (int j = 0; j <= n; ++j) { // 遍历所有前缀和
            int i = j % k; // 当前余数
            ans = max(ans, sum[j] - min_s[i]); // 更新最大子数组和
            min_s[i] = min(min_s[i], sum[j]); // 更新当前余数的最小前缀和
        }

        return ans;
    }
};

// 优化（一边计算前缀和，一边维护 minS）

/*
class Solution 
{
    public:
        long long maxSubarraySum(vector<int>& nums, int k) 
        {
            vector<long long> min_s(k, LLONG_MAX / 2); 
            min_s.back() = 0;
    
            long long ans = LLONG_MIN, s = 0;
            for (int j = 0; j < nums.size(); j++) 
            {
                s += nums[j];
                int i = j % k;
                ans = max(ans, s - min_s[i]);
                min_s[i] = min(min_s[i], s);
            }
            return ans;
        }
    };
*/ 

int main()
{
    Solution solution;
    vector<int> arr = {-5,1,2,-3,4};
    cout<<solution.maxSubarraySum(arr,2);
    return 0;
}