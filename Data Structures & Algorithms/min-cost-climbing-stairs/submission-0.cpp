class Solution {
private:
    unordered_map<int, int> memo;

    int dfs(int i, vector<int>& cost){
        if(i >= cost.size()) return 0;  
        if(memo.count(i)) return memo[i];

        memo[i] = cost[i] + min(dfs(i+1, cost), dfs(i+2, cost));
        return memo[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(0, cost), dfs(1, cost));
    }
};