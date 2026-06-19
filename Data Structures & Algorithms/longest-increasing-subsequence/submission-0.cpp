class Solution {
private:
    unordered_map<int, int> memo;
    
    int dfs(int i, const vector<int>& nums) {
        if (memo.count(i)) {
            return memo[i];
        }
        
        int local_max = 1; 
        
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                local_max = max(local_max, 1 + dfs(j, nums)); 
            }
        }
        
        memo[i] = local_max;
        return local_max;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int global_max = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            global_max = max(global_max, dfs(i, nums));
        }
        
        return global_max;
    }
};