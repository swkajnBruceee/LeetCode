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

  1.���嵱ǰ�������±߽� l,r,t,b����ʼֵ num = 1��������ֵֹ tar = n * n��
  2.�� num <= tar ʱ��ʼ�հ��� ������ ���ϵ��� ���ҵ��� ���µ��� ����˳��ѭ����ÿ�������
    a:ִ�� num += 1���õ���һ����Ҫ��������֣�
    b:���±߽磺���������������ϱ߽� t += 1���൱���ϱ߽������� 1��
  3.ʹ��num <= tar������l < r || t < b��Ϊ������������Ϊ�˽����nΪ����ʱ���������������޷��ڵ��������б��������⡣
  4.���շ��� mat ���ɡ�

*/











