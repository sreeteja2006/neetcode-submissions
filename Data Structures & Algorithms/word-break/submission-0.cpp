class Solution {
private:
    bool dfs(int start, const string& s, const unordered_set<string>& wordSet, vector<int>& memo) {
        if (start == s.length()) {
            return true;
        }

        if (memo[start] != -1) {
            return memo[start] == 1;
        }

        for (int end = start + 1; end <= s.length(); ++end) {
            string current_slice = s.substr(start, end - start);

            if (wordSet.count(current_slice) && dfs(end, s, wordSet, memo)) {
                memo[start] = 1; 
                return true;
            }
        }

        memo[start] = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        vector<int> memo(s.length(), -1);
        
        return dfs(0, s, wordSet, memo);
    }
};