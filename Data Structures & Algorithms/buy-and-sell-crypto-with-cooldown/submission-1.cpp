class Solution {
     unordered_map<int, unordered_map<bool,int>> memo;
private:
    int dfs(int i, bool buying , vector<int> &prices){
        if(i>=prices.size()){
            return 0;
        }
        if(memo.count(i) && memo[i].count(buying)){
            return memo[i][buying];
        }
        int skip =  dfs(i+1,buying,prices);
        if(buying){
            int buy = dfs(i+1,false,prices)  - prices[i];
            memo[i][buying] = max(buy,skip);
            return memo[i][buying];
        }
        else{
            int sell = dfs(i+2,true,prices)+prices[i];
            memo[i][buying] = max(sell,skip);
            return memo[i][buying];
        }
    }
    
public:
    int maxProfit(vector<int>& prices) {
        return dfs(0,true,prices);
    }
};
