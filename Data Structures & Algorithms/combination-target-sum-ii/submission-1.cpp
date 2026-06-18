class Solution {
private:
    void dfs(vector<int>& candidates, int i, vector<vector<int>>& res,
             vector<int>& subset, int currentSum, int target) {

        if (currentSum == target) {
            res.push_back(subset);
            return;
        }
        if (i >= candidates.size() || currentSum > target) return;

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j-1]) continue;

            subset.push_back(candidates[j]);
            dfs(candidates, j + 1, res, subset, currentSum + candidates[j], target);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        vector<vector<int>> res;
        dfs(candidates, 0, res, subset, 0, target);
        return res;
    }
};