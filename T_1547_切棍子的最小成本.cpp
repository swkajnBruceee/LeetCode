//��̬�滮��˼��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0)); //��ά���� dp��dp[i][j] ��ʾ������[i,j]�ڵ�ľ���и������С�ɱ�
                                                  //��ʼֵ������Ϊ0  
    for (int len = 2; len < m; ++len) //���ѭ����len ��ʾ����ĳ��ȣ��ӳ���Ϊ 2 ��ʼ
    {                                 //����Ϊ����Ϊ 1 �����䲻��Ҫ�и�ɱ�Ϊ 0���������ӵ� m - 1�� 
        for (int i = 0; i < m - len; ++i) //�ڲ�ѭ����i ��ʾ�������ʼλ�ã����ݵ�ǰ len �������Ч����ʼλ�÷�Χ��
        {
            int j = i + len;    //���ݵ�ǰ����ʼλ�� i �ͳ��� len ���������Ľ���λ�� j
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) //������ [i, j] �ڱ������п��ܵ��и�� k
            {
                //������ k ���и�ĳɱ�
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
        }
    }
    return dp[0][m - 1];
}


int main()
{
    vector<int> cuts = {7,8,9,2,1};
    cout<<minCost(10,cuts);
    return 0;
}

