#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        // 运用贪心策略判断x是否是合法的距离(即每个球间隔x的距离下,能否放置不少于m个球)
        bool check(int x, vector<int>& position, int m) 
        {
            int pre = position[0], num = 1;
            for (int i = 1; i < (int)position.size(); ++i) 
            {
                if (position[i] - pre >= x) 
                {
                    pre = position[i];
                    num += 1;
                }
            }
            return num >= m;
        }
    
        int maxDistance(vector<int>& position, int m) 
        {
            sort(position.begin(), position.end());
            int left = 1, right = position.back() - position[0], distance = -1;
            while (left <= right) 
            {
                int mid = (left + right) / 2;
                if (check(mid, position, m)) // 判断mid是否是合法答案
                {
                    distance = mid;          // 是则在右半部分查找(并且更新答案)
                    left = mid + 1;
                } else                       // 不是则在左半部分查找
                {
                    right = mid - 1;
                }
            }
            return distance;
        }
};
    

int main()
{
    Solution solution;
    vector<int> position = {1,2,3,4,7};
    int res = solution.maxDistance(position,3);
    cout<<res;
    return 0;
}




