#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        long long maxSubarraySum(vector<int>& nums, int k) 
        {
            int n = nums.size();
            vector<long long> sum(n + 1);
            for(int i = 0; i < n; i++)
            {
                sum[i+1] = sum[i] + nums[i]; // ¼ÆËãÇ°×ººÍ
            }
            
        }
};