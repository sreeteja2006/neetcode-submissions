class Solution{
    unordered_map<int, unordered_map<int, int>> dp;
private:
    int solve(int i ,int j,string &text1, string &text2){
        if(i==text1.length() || j == text2.length()){
            return 0;
        }
        if(text1[i] == text2[j]){
            return 1+solve(i+1,j+1,text1,text2);
        }
        if(dp.count(i) && dp[i].count(j)){
            return dp[i][j];
        }
        dp[i][j] = max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(0,0,text1,text2);
    }
};
