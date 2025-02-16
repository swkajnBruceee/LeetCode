#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution 
{
    public:
        vector<int> replaceElements(vector<int>& arr) 
        {
            int len = arr.size();
            int maxRight = -1;
            // ���������������
            for (int i = len - 1; i >= 0; i--) 
            {
                int temp = arr[i];
                arr[i] = maxRight;
                // �����Ҳ����Ԫ��
                if (temp > maxRight) {
                    maxRight = temp;
                }
            }
            return arr;
        }
};

int main()
{
    Solution solution;
    vector<int> arr = {17,18,5,4,6,1};
    arr = solution.replaceElements(arr);
    for(int r : arr)
    {
        cout<<r<<" ";
    }
    return 0;
}


