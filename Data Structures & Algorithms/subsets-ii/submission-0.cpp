class Solution {
private:
    void dfs(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& subset){
        res.push_back(subset);

        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]) continue;

            subset.push_back(nums[j]);
            dfs(j + 1, nums, res, subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // ← needed for duplicate check to work
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, res, subset);
        return res;
    }
};