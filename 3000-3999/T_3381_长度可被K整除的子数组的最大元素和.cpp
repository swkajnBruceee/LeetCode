#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1); // ǰ׺������
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i]; // ����ǰ׺��
        }

        vector<long long> min_s(k, LLONG_MAX / 2); // ÿ�������������Сǰ׺�ͣ���ֹ���
        long long ans = LLONG_MIN; // ��ʼ����Ϊ��С
      

        for (int j = 0; j <= n; ++j) { // ��������ǰ׺��
            int i = j % k; // ��ǰ����
            ans = max(ans, sum[j] - min_s[i]); // ��������������
            min_s[i] = min(min_s[i], sum[j]); // ���µ�ǰ��������Сǰ׺��
        }

        return ans;
    }
};

// �Ż���һ�߼���ǰ׺�ͣ�һ��ά�� minS��

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