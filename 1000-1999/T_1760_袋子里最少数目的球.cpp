#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        int minimumSize(vector<int>& nums, int maxOperations) 
        {
            int left = 1, right = *max_element(nums.begin(), nums.end());
            int ans = 0; // 用于存储最终的结果

            // 进行二分查找
            while (left <= right) {
                int y = (left + right) / 2; // 取中间值
    
                long long ops = 0; // 用于计算操作数
                for (int x : nums) 
                { 
                    // 计算每个数需要进行的操作数（将数分割成大小为 y 的部分）
                    ops += (x - 1) / y; 
                }
    
                if (ops <= maxOperations) 
                { 
                    ans = y; // 更新结果
                    right = y - 1; // 缩小搜索范围的右边界
                } 
                else 
                { 
                    // 如果操作数大于最大操作数
                    left = y + 1; // 缩小搜索范围的左边界
                }
            }
    
            return ans; 
        }
};
        

/*(21行的解释)
当我们二分查找到 y 时，对于第 i 个袋子，其中有 nums[i] 个球，那么需要的操作次数为：

                       ? (nums[i]?1)/y ?

  其中 ?x? 表示将 x 进行下取整。它的含义为：
    1.当 nums[i]≤y 时，我们无需进行操作；
    2.当 y<nums[i]≤2y 时，我们需要进行 1 次操作；
    3.当 2y<nums[i]≤3y 时，我们需要进行 2 次操作；
...
*/

























