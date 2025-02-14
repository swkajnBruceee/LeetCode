#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        // ����̰�Ĳ����ж�x�Ƿ��ǺϷ��ľ���(��ÿ������x�ľ�����,�ܷ���ò�����m����)
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
                if (check(mid, position, m)) // �ж�mid�Ƿ��ǺϷ���
                {
                    distance = mid;          // �������Ұ벿�ֲ���(���Ҹ��´�)
                    left = mid + 1;
                } else                       // ����������벿�ֲ���
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




