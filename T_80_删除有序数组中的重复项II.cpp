#include<iostream>
#include<vector>
using namespace std;

// 模拟栈法(时间复杂度较低，额外空间复杂度O(1))
class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int n = nums.size();
            int stack_size = 2; // 栈的大小，前两个元素默认保留
            for (int i = 2; i < n; i++) 
            {
                if (nums[i] != nums[stack_size - 2])  // 和栈顶下方的元素比较
                {
                    nums[stack_size++] = nums[i]; // 入栈
                }
            }
            return min(stack_size, n);
        }
};

int main()
{
    vector<int> arr = {1,2,3,3,3,6,6,8,9};
    Solution solution;
    int size = solution.removeDuplicates(arr);
    cout<<"size: "<<size<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}




/* 双指针法(时间复杂度较低，额外空间复杂度O(1))
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // 如果数组长度小于等于2，无需处理，直接返回原长度
        if (n <= 2) {
            return n;
        }
        // 初始化两个指针 slow 和 fast，均从索引2开始
        int slow = 2, fast = 2;
        // 遍历数组
        while (fast < n) {
            // 检查 slow 前两位的元素是否与 fast 当前元素不同
            if (nums[slow - 2] != nums[fast]) {
                // 若不同，将 fast 的值复制到 slow 位置，确保最多两个重复
                nums[slow] = nums[fast];
                slow++; // slow 指针后移，指向下一个待填充位置
            }
            fast++; // fast 始终后移，继续遍历
        }
        // 返回处理后的数组长度（slow 即为新长度）
        return slow;
    }
};
*/




/* 复杂度较高
class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int i = 0;
            for (int num : nums) 
            {
                if (i < 2 || num > nums[i - 2]) 
                {
                    nums[i++] = num;
                }
            }
       
            return i;
        }
};

*/
