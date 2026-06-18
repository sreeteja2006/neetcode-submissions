class Solution {
void dfs(int open, int close, int n, string curr, vector<string>& res){
    if(open == n && close == n){
        res.push_back(curr);
        return;
    }

    if(open < n){
        dfs(open + 1, close, n, curr + '(', res);
    }
    if(close < open){ 
        dfs(open, close + 1, n, curr + ')', res);
    }
}

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, n, "", res);
        return res;
    }
};
