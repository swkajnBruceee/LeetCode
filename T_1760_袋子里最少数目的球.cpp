#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        int minimumSize(vector<int>& nums, int maxOperations) 
        {
            int left = 1, right = *max_element(nums.begin(), nums.end());
            int ans = 0; // ���ڴ洢���յĽ��

            // ���ж��ֲ���
            while (left <= right) {
                int y = (left + right) / 2; // ȡ�м�ֵ
    
                long long ops = 0; // ���ڼ��������
                for (int x : nums) 
                { 
                    // ����ÿ������Ҫ���еĲ������������ָ�ɴ�СΪ y �Ĳ��֣�
                    ops += (x - 1) / y; 
                }
    
                if (ops <= maxOperations) 
                { 
                    ans = y; // ���½��
                    right = y - 1; // ��С������Χ���ұ߽�
                } 
                else 
                { 
                    // ���������������������
                    left = y + 1; // ��С������Χ����߽�
                }
            }
    
            return ans; 
        }
};
        

/*(21�еĽ���)
�����Ƕ��ֲ��ҵ� y ʱ�����ڵ� i �����ӣ������� nums[i] ������ô��Ҫ�Ĳ�������Ϊ��

                       ? (nums[i]?1)/y ?

  ���� ?x? ��ʾ�� x ������ȡ�������ĺ���Ϊ��
    1.�� nums[i]��y ʱ������������в�����
    2.�� y<nums[i]��2y ʱ��������Ҫ���� 1 �β�����
    3.�� 2y<nums[i]��3y ʱ��������Ҫ���� 2 �β�����
...
*/

























