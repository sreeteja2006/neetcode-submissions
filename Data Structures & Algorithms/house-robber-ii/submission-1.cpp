class Solution {
    unordered_map<int,int> memo;
    int dfs(int i,int end, vector<int>& nums){
        if(i >= end) return 0;
        if(memo.count(i)) return memo[i];

        memo[i] = max(nums[i] + dfs(i+2, end,nums),
                      dfs(i+1,end, nums));             
        return memo[i];
    }
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    if(n ==1){
        return nums[0];
    }
    int ans1 = dfs(0, n-1, nums);  
    memo.clear();
    int ans2 = dfs(1, n, nums);
    return max(ans1, ans2);
}
};