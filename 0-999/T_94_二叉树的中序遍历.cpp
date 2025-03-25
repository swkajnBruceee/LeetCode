#include<iostream>
#include<vector>
using namespace std;
// ÖÐÐò±éÀú£¨×ó¡¢Í·¡¢ÓÒ£©- µÝ¹é
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
        
    
    void inOrderRecur(vector<int>& arr, TreeNode* node)
    {
        if(node == nullptr) return;   
        inOrderRecur(arr, node->left);
        arr.push_back(node->val);
        inOrderRecur(arr, node->right);

    }
    vector<int> inorderTraversal(TreeNode* root) 
        {
            TreeNode* node = root;
            vector<int> arr;
            inOrderRecur(arr, node);
            return arr;
        }

    };
















