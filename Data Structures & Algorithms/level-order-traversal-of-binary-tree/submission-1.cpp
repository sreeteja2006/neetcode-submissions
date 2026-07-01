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
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        int n = depth(root);
        ans.resize(n);
        if(root==NULL) return ans;
        q.push({root,0});
        while(!q.empty()){
            auto [node,level] = q.front();
            q.pop();
            ans[level].push_back(node->val);
            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        return ans;
            
    }
};