class Solution {
    unordered_map<int,unordered_map<int,int>> memo;
private:
    int dfs(int i , vector<int>&coins,int amount){
        if(amount ==0){
            return 1;
        }
        if(amount <0){
            return 0;
        }
        if(i >= coins.size()){
            return 0;
        }
        if(memo.count(i) && memo[i].count(amount)){
            return memo[i][amount];
        }
        for(int j = i ;j< coins.size();j++){
            memo[i][amount] += dfs(j,coins,amount -coins[j]);
        }
        return memo[i][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        return dfs(0,coins,amount);
    }
};
