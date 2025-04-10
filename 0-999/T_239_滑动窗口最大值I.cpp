#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 优先队列法
class Solution 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            priority_queue<pair<int, int>> q;
            int n = nums.size();
            for(int i = 0; i < k; i++)
            {
                q.emplace(nums[i], i);  // first存放该元素，second 存放该元素在数组中对应的索引，便于后期维护(清除过期元素)
            }
            vector<int> ans = {q.top().first};
            for(int i = k; i < n; i++)
            {
                q.emplace(nums[i], i);
                while(q.top().second <= i - k) // 不能用if，否则过期元素可能不被清理干净
                {
                    q.pop();
                }
                ans.push_back(q.top().first); // 大根堆堆顶即为最大元素
            }
            return ans;
        }
};