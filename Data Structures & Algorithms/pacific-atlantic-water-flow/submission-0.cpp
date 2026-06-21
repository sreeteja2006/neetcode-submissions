class Solution {
private:
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>& heights, pair<bool,bool>& pb, vector<vector<int>>& visited) {
        if ((pb.first && pb.second) || i >= rows || j >= cols || i < 0 || j < 0 || visited[i][j]) {
            return;
        }
        
        if (i == 0 || j == 0) {
            pb.first = true;
        }
        if (i == rows - 1 || j == cols - 1) {
            pb.second = true;
        }
        
        visited[i][j] = 1;
        
        if (i + 1 < rows && heights[i + 1][j] <= heights[i][j]) {
            dfs(i + 1, j, rows, cols, heights, pb, visited);
        }
        if (j + 1 < cols && heights[i][j + 1] <= heights[i][j]) {
            dfs(i, j + 1, rows, cols, heights, pb, visited);
        }
        if (i - 1 >= 0 && heights[i - 1][j] <= heights[i][j]) {
            dfs(i - 1, j, rows, cols, heights, pb, visited);
        }
        if (j - 1 >= 0 && heights[i][j - 1] <= heights[i][j]) {
            dfs(i, j - 1, rows, cols, heights, pb, visited);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if (heights.empty()) return res;
        int rows = heights.size();
        int cols = heights[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                pair<bool,bool> pb = {false, false};
                vector<vector<int>> visited(rows, vector<int>(cols, 0));
                dfs(i, j, rows, cols, heights, pb, visited);
                if (pb.first && pb.second) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};