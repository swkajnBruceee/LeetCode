#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int maximumSum(vector<int> &arr) {
            int ans = INT_MIN / 2, f0 = ans, f1 = ans;
            for (int x: arr) {
                f1 = max(f1 + x, f0);
                f0 = max(f0, 0) + x;
                ans = max(ans, max(f0, f1));
            }
            return ans;
        }
    };

