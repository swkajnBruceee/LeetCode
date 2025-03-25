#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
       vector<int> evenOddBit(int n) {
           vector<int>ans(2,0);
           while (n) {
               if (n & 1) ans[0]++;
               if (n & 2) ans[1]++;
               n>>=2;
           }
           return ans;
       }
};


int main()
{
    Solution solution;
    vector<int> arr = solution.evenOddBit(17);
    for(int r : arr)
    {
        cout<<r<<" ";
    }
    return 0;
}
