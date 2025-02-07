// 深度优先搜索(对于二叉树，实质上就是先序遍历)
#include<iostream>
#include<stack>
using namespace std;



struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == nullptr) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };