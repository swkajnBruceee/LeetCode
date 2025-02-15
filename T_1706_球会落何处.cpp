#include<iostream>
#include<vector>
using namespace std;

// ���顢����ģ��
class Solution 
{
    public:
        
        int find(vector<vector<int>>& grid, int j, int m, int n)
        {
            for(int i = 0; i < m; i++)
            {
                // ����ͬ����ߣ�����ס
                if((j+1) < n && grid[i][j] == 1 && grid[i][j+1] == 1)
                {
                    j++;
                }
                else if((j-1) >= 0 && grid[i][j] == -1 && grid[i][j-1] == -1)
                {
                    j--;
                }
                else return -1;
            }
            return j;
        }
    
        vector<int> findBall(vector<vector<int>>& grid) 
        {
            
            int m = grid.size();
            int n = grid[0].size();
            vector<int> answer(n);
            
            for(int column = 0; column < n; column++)
            {
                answer[column] = find(grid, column, m, n);
            }
            return answer;
        }
        
};








