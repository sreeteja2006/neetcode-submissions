class Solution {
private:
    unordered_map<int,int> memo;
    int dfs(int i, string& s){
        if(i == s.length()) return 1;  
        if(s[i] == '0') return 0;      
        if(memo.count(i)) return memo[i];

        int res = dfs(i+1, s);  

        
        if(i+1 < s.length() && stoi(s.substr(i,2)) <= 26){
            res += dfs(i+2, s);
        }

        memo[i] = res;
        return memo[i];
    }

public:
    int numDecodings(string s) {
        return dfs(0, s);
    }
};