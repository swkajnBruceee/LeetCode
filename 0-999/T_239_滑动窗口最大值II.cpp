#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// �������з�(˫�˶���)

/*
����������Ҫ������ǻ������ڵ����ֵ�������ǰ�Ļ����������������±� i �� j������ i �� j ����ࣨi<j����
���� i ��Ӧ��Ԫ�ز����� j ��Ӧ��Ԫ�أ�nums[i]��nums[j]����
���������������ƶ�ʱ��ֻҪ i ���ڴ����У���ô j һ��Ҳ���ڴ����У����� i �� j ���������֤�ġ�
��ˣ����� nums[j] �Ĵ��ڣ�nums[i] һ�������ǻ��������е����ֵ�ˣ����ǿ��Խ� nums[i] ���õ��Ƴ���
*/

class Solution 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            deque<int> q; // ˫�˶����д洢�±���Ϣ
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
