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
    TreeNode* invert(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = invert(root->right);
        newroot->right = invert(root->left);

        return newroot;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};

