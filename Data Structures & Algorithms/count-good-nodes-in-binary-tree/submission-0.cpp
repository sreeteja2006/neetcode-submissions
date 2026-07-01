/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




class Solution {
private:
    int helper(TreeNode* root,int maxima) {
        if(!root) return 0;
        if(root->val >= maxima) {
            maxima = root->val;
            return 1+ helper(root->left,maxima) + helper(root->right,maxima);
        }
        else {
            return helper(root->left,maxima) + helper(root->right,maxima);
        }
        
    }
public:
    int goodNodes(TreeNode* root) {
        int maxima = root->val;
        return helper(root,maxima);
    }
};