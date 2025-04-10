#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ���ȶ��з�
class Solution 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            priority_queue<pair<int, int>> q;
            int n = nums.size();
            for(int i = 0; i < k; i++)
            {
                q.emplace(nums[i], i);  // first��Ÿ�Ԫ�أ�second ��Ÿ�Ԫ���������ж�Ӧ�����������ں���ά��(�������Ԫ��)
            }
            vector<int> ans = {q.top().first};
            for(int i = k; i < n; i++)
            {
                q.emplace(nums[i], i);
                while(q.top().second <= i - k) // ������if���������Ԫ�ؿ��ܲ�������ɾ�
                {
                    q.pop();
                }
                ans.push_back(q.top().first); // ����ѶѶ���Ϊ���Ԫ��
            }
            return ans;
        }
};