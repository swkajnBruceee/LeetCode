#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void rotate(vector<vector<int>>& matrix) 
        {
            int n = matrix.size();
            //1. 转置矩阵(按对角线反转)
            for(int i = 0; i < n; i++)
            {
                for(int j = i; j < n; j++)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
            //2. 做初等列变换(按中轴线交换)
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n/2; j++)
                {
                    int arr = matrix[i][j];
                    matrix[i][j] = matrix[i][n-j-1];
                    matrix[i][n-j-1] = arr;
                }

            }
        }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    solution.rotate(matrix);
    for(auto r : matrix)
    {
        for(auto i : r)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    return 0;
}
