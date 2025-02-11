#include<iostream>
#include<queue>
#include<vector>
using namespace std;



class Solution {
    public:
        int minimumCost(vector<int>& cost) {
            sort(cost.begin(), cost.end(), greater<int>());
            int res = 0;
            int n = cost.size();
            for (int i = 0; i < n; ++i) {
                if (i % 3 != 2) {
                    res += cost[i];
                }
            }
            return res;
        }
    };

/*
    ���ǲ������� cost �����Ѿ����ռ۸������򣬸��ݶ��壬
    ��ѻ���ǹ��м۸���ߵ�һ�������� cost[2]��������±���ڣ���ͬ����
    ���Ƶأ����ǿ��Եó����۸�� k(0��k��?n/3?) �ߵ��ǹ��ļ۸�һ�������� cost[3k+2]��
*/

