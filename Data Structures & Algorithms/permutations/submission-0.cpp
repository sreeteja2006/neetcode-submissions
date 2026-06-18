class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res,
             vector<int>& perm, vector<bool>& visited) {

        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;  

            visited[i] = true;
            perm.push_back(nums[i]);

            dfs(nums, res, perm, visited);

            perm.pop_back();           
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> visited(nums.size(), false);
        dfs(nums, res, perm, visited);
        return res;
    }
};