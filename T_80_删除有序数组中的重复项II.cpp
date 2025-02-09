#include<iostream>
#include<vector>
using namespace std;

// ģ��ջ��(ʱ�临�ӶȽϵͣ�����ռ临�Ӷ�O(1))
class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int n = nums.size();
            int stack_size = 2; // ջ�Ĵ�С��ǰ����Ԫ��Ĭ�ϱ���
            for (int i = 2; i < n; i++) 
            {
                if (nums[i] != nums[stack_size - 2])  // ��ջ���·���Ԫ�رȽ�
                {
                    nums[stack_size++] = nums[i]; // ��ջ
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




/* ˫ָ�뷨(ʱ�临�ӶȽϵͣ�����ռ临�Ӷ�O(1))
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // ������鳤��С�ڵ���2�����账��ֱ�ӷ���ԭ����
        if (n <= 2) {
            return n;
        }
        // ��ʼ������ָ�� slow �� fast����������2��ʼ
        int slow = 2, fast = 2;
        // ��������
        while (fast < n) {
            // ��� slow ǰ��λ��Ԫ���Ƿ��� fast ��ǰԪ�ز�ͬ
            if (nums[slow - 2] != nums[fast]) {
                // ����ͬ���� fast ��ֵ���Ƶ� slow λ�ã�ȷ����������ظ�
                nums[slow] = nums[fast];
                slow++; // slow ָ����ƣ�ָ����һ�������λ��
            }
            fast++; // fast ʼ�պ��ƣ���������
        }
        // ���ش��������鳤�ȣ�slow ��Ϊ�³��ȣ�
        return slow;
    }
};
*/




/* ���ӶȽϸ�
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
