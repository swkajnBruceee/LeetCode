#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// 单调队列法(双端队列)

/*
由于我们需要求出的是滑动窗口的最大值，如果当前的滑动窗口中有两个下标 i 和 j，其中 i 在 j 的左侧（i<j），
并且 i 对应的元素不大于 j 对应的元素（nums[i]≤nums[j]），
当滑动窗口向右移动时，只要 i 还在窗口中，那么 j 一定也还在窗口中，这是 i 在 j 的左侧所保证的。
因此，由于 nums[j] 的存在，nums[i] 一定不会是滑动窗口中的最大值了，我们可以将 nums[i] 永久地移除。
*/

class Solution 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            deque<int> q; // 双端队列中存储下标信息
            int n = nums.size();
            for(int i = 0; i < k; i++)
            {
                while(!q.empty() && nums[i] >= nums[q.back()])
                {
                    q.pop_back();
                }
                q.push_back(i);
            }
            vector<int> ans = {nums[q.front()]};
            for(int i = k; i < n; i++) 
            {
                while(!q.empty() && nums[i] >= nums[q.back()])
                {
                    q.pop_back();
                }
                q.push_back(i);
                while(q.front() <= i - k)
                {
                    q.pop_front();
                }
                ans.push_back(nums[q.front()]);
            }
            return ans;
        }
};
