class Solution {
private:
    vector<vector<int>> memo;

    bool dfs(int i, vector<int>& nums, int target) {
        if (target == 0) {
            return true; 
        }
        if (i >= nums.size() || target < 0) {
            return false; 
        }

        if (memo[i][target] != -1) {
            return memo[i][target] == 1;
        }

        bool pick = dfs(i + 1, nums, target - nums[i]);
        
        bool dontPick = dfs(i + 1, nums, target);

        memo[i][target] = (pick || dontPick) ? 1 : 0;
        return pick || dontPick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int target = totalSum / 2;
        
        memo = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));
        
        return dfs(0, nums, target);
    }
};