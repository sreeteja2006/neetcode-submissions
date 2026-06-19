class Solution {
private:
    unordered_map<string, bool> memo;
    
    bool isPalindrome(string& s, int l, int r){
        if(l >= r) return true;
        string key = to_string(l) + "," + to_string(r);
        if(memo.count(key)) return memo[key];
        
        memo[key] = (s[l] == s[r]) && isPalindrome(s, l+1, r-1);
        return memo[key];
    }

public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                if(isPalindrome(s, i, j) ){
                    res++;
                }
            }
        }
        return res;
        
    }
};
