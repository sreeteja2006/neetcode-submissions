class Solution {
private:
    void bfs(vector<vector<char>>& grid, int starti, int startj, vector<vector<int>>& visited, int rows, int cols, vector<pair<int,int>>& directions) {
        if (starti < 0 || starti >= rows || startj < 0 || startj >= cols || grid[starti][startj] == '0' || visited[starti][startj]) {
            return;
        }
        
        visited[starti][startj] = 1;
        
        for (auto direcpair : directions) {
            int nexti = starti + direcpair.first;
            int nextj = startj + direcpair.second;
            bfs(grid, nexti, nextj, visited, rows, cols, directions);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int cnt = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;
                    bfs(grid, i, j, visited, rows, cols, directions);
                }
            }
        }
        return cnt;
    }
};