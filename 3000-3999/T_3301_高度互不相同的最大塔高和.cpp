#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        long long maximumTotalSum(vector<int>& maximumHeight) 
        {
            long long sum = 0;
            int size = maximumHeight.size();
            sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
            for(int i = 1; i < size; i++) 
            {
                maximumHeight[i] = min(maximumHeight[i], maximumHeight[i-1]-1);
                if(maximumHeight[i] <= 0) return -1;
                sum += maximumHeight[i];
            }
            sum += maximumHeight[0];
            return sum;
        }
};

int main()
{
    Solution solution;
    vector<int> arr = {2,3,4,3};
    long long res = solution.maximumTotalSum(arr);
    cout<<res;
    return 0;
}



