class Solution {
    unordered_map<int,int> memo;
    int dfs(int i, vector<int>& nums){
        if(i >= nums.size()) return 0;
        if(memo.count(i)) return memo[i];

        memo[i] = max(nums[i] + dfs(i+2, nums),
                      dfs(i+1, nums));             
        return memo[i];
    }
public:
    int rob(vector<int>& nums) {
        return dfs(0, nums);
    }
};