class Solution {
    unordered_map<int, unordered_map<int,int>> memo;
private:
    int dfs(int i,vector<int>&nums,int target){
        if(i == nums.size()){
            return target==0? 1:0;
        }
        if(memo.count(i) && memo[i].count(target)){
            return memo[i][target];
        }
        
        memo[i][target] += dfs(i+1,nums,target-nums[i]) + dfs(i+1,nums,target+nums[i]);        
        return memo[i][target];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0,nums,target);    
    }
};
