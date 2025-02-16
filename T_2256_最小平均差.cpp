#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution 
{
    public:
        int minimumAverageDifference(vector<int>& nums) 
        {
            int res = INT_MAX;
            long sum = 0, preSum = 0;
            int index = 0;
            int n = nums.size();
            for(int r : nums)
            {
                sum += r;
            }
            for(int i = 0; i < n; i++)
            {             
                preSum += nums[i];
                long last = (i == n-1) ? 0 : (sum - preSum)/(n-i-1);
                long dif = abs(preSum/(i+1) - last);
                if(dif < res)
                {
                    res = dif;
                    index = i;
                }
            }
            return index;
        }
};


int main()
{
    Solution solution;
    vector<int> nums = {2,5,3,9,5,3};
    cout<<"最小平均差："<<solution.minimumAverageDifference(nums);
    return 0;
}
