class Solution {
private:
    void bfs(vector<vector<int>>& grid, int starti, int startj, vector<vector<int>>& visited, int rows, int cols, vector<pair<int,int>>& directions, int& area) {
        queue<pair<int, int>> q;
        q.push({starti, startj});
        visited[starti][startj] = 1;
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for (auto direcpair : directions) {
                int nexti = curr.first + direcpair.first;
                int nextj = curr.second + direcpair.second;
                
                if (nexti >= 0 && nexti < rows && nextj >= 0 && nextj < cols && grid[nexti][nextj] == 1 && !visited[nexti][nextj]) {
                    visited[nexti][nextj] = 1;
                    area = area + 1;
                    q.push({nexti, nextj});
                }
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int maxarea = 0;
        int area = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    area = 1;
                    bfs(grid, i, j, visited, rows, cols, directions, area);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;        
    }
};