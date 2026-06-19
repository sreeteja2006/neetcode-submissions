class Solution {
private:
    unordered_map<int, int> memo;  // cache

    int dfs(int i, int n){
        if(i == n) return 1;
        if(i > n) return 0;
        
        if(memo.count(i)) return memo[i];  
        
        memo[i] = dfs(i+1, n) + dfs(i+2, n);  
        return memo[i];
    }
public:
    int climbStairs(int n) {
        return dfs(0, n);
    }
};