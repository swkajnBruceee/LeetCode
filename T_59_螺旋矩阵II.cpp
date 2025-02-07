#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> generateMatrix(int n) 
        {
            vector<vector<int>> matrix(n,vector<int>(n));
                int l = 0, r = n - 1, t = 0, b = n - 1;
                int num = 1, sum = n * n;
                while(num <= sum)
                {
                    for(int i = l; i <= r; i++) matrix[t][i] = num++; // left to right.
                    t++;
                    for(int i = t; i <= b; i++) matrix[i][r] = num++; // top to bottom.
                    r--;
                    for(int i = r; i >= l; i--) matrix[b][i] = num++; // right to left.
                    b--;
                    for(int i = b; i >= t; i--) matrix[i][l] = num++; // bottom to top.
                    l++;
                }
                return matrix;
        }
    };


/*

  1.定义当前左右上下边界 l,r,t,b，初始值 num = 1，迭代终止值 tar = n * n；
  2.当 num <= tar 时，始终按照 从左到右 从上到下 从右到左 从下到上 填入顺序循环，每次填入后：
    a:执行 num += 1：得到下一个需要填入的数字；
    b:更新边界：例如从左到右填完后，上边界 t += 1，相当于上边界向内缩 1。
  3.使用num <= tar而不是l < r || t < b作为迭代条件，是为了解决当n为奇数时，矩阵中心数字无法在迭代过程中被填充的问题。
  4.最终返回 mat 即可。

*/











