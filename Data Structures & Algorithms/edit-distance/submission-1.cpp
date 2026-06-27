class Solution {
    unordered_map<int, unordered_map<int, int>> memo;

private:
    int dfs(int i, int j, string word1, const string &word2) {

        if (memo.count(i) && memo[i].count(j))
            return memo[i][j];

        if (i == word1.length())
            return word2.length() - j;

        if (j == word2.length())
            return word1.length() - i;

        if (word1[i] == word2[j]) {
            return dfs(i + 1, j + 1, word1, word2);
        }

if (word1[i] == word2[j])
{
    memo[i][j] = dfs(i + 1, j + 1,word1,word2);
    return memo[i][j]; 
}
    memo[i][j] = 1 + min({
    dfs(i + 1, j,word1,word2),     
    dfs(i, j + 1,word1,word2),     
    dfs(i + 1, j + 1,word1,word2)  
});
return memo[i][j];
    }

public:
    int minDistance(string word1, string word2) {
        return dfs(0, 0, word1, word2);
    }
};
    
