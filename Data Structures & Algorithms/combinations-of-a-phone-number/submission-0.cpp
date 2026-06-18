class Solution {
private:
    unordered_map<char, string> mapper = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void dfs(int i, vector<string>& res, string& digits, string curr){
        if(i >= digits.length()){
            res.push_back(curr);
            return;
        }

        for(int j = 0; j < mapper[digits[i]].length(); j++){
            dfs(i + 1, res, digits, curr + mapper[digits[i]][j]); // backtrack via copy
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        dfs(0, res, digits, "");
        return res;
    }
};