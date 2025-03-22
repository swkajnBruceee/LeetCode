#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        vector<long long> sumOfThree(long long num) {
            if (num % 3 == 0) {
                return {num / 3 - 1, num / 3, num / 3 + 1};
            }
            return {};
        }
    };
    


int main()
{
    Solution solution;
    vector<long long> arr;
    arr = solution.sumOfThree(1200);
    for(int r : arr)
    {
        cout<<r<<" ";
    }
    return 0;
}









