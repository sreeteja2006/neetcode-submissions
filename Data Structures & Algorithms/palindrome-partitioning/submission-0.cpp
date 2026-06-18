class Solution {
private:
   bool isPalindrome(string& s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void dfs(int i, vector<vector<string>>& res, string& s, vector<string>& subset){
    if(i == s.size()){
        res.push_back(subset);  
        return;
    }

    for(int j = i; j < s.size(); j++){
        if(isPalindrome(s, i, j)){
            subset.push_back(s.substr(i, j - i + 1));
            dfs(j + 1, res, s, subset);
            subset.pop_back();  
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset ={};
        dfs(0,res,s,subset);
        return res; 
    }
};
