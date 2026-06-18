class Solution {
bool dfs(vector<vector<char>>& board, int row, int col, 
         vector<vector<int>>& visited, string& word, int i) {
    
    if(i == word.size()) return true;
    if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
    if(visited[row][col] || board[row][col] != word[i]) return false;

    visited[row][col] = 1;

    bool found = dfs(board, row+1, col, visited, word, i+1) ||
                 dfs(board, row-1, col, visited, word, i+1) ||
                 dfs(board, row, col+1, visited, word, i+1) ||
                 dfs(board, row, col-1, visited, word, i+1);

    visited[row][col] = 0;  // backtrack
    return found;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),vector<int> (board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(dfs(board, i,j,visited,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
