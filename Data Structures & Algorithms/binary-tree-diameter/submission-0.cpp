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
int maxdiameter = 0;
private:
    int dfs(TreeNode* root) {
    if (!root) return 0;

    int leftheight = dfs(root->left);
    int rightheight = dfs(root->right);

    maxdiameter = max(maxdiameter, leftheight + rightheight);

    return 1 + max(leftheight, rightheight);
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxdiameter;
    }
};
