class Solution {
    unordered_map<int,unordered_map<int,bool>> memo;
private:
    bool dfs(int i, int j,string s1, string s2, string s3){
        if(i+j >= s3.length()){
            return true;
        }
        if(s3[i+j] != s1[i] && s3[i+j] != s2[j]){
            return false;
        }
        if(memo.count(i) && memo[i].count(j)){
            return memo[i][j];
        }
        if(s3[i+j] == s1[i] && s3[i+j] == s2[j]){
            memo[i][j] = dfs(i+1,j,s1,s2,s3) || dfs(i,j+1,s1,s2,s3);
        }
        else if(s3[i+j] == s1[i]){
            memo[i][j] = dfs(i+1,j,s1,s2,s3);
        }
        else{
            memo[i][j] = dfs(i,j+1,s1,s2,s3);
        }
        return memo[i][j];
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        return dfs(0,0,s1,s2,s3);
    }
};
