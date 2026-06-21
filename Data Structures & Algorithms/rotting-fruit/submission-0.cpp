class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int time = 0;
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!q.empty() && fresh > 0){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                auto curr = q.front();
                q.pop();
                
                int r = curr.first;
                int c = curr.second;
                
                for(auto dir: directions){
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            time++;
        }
        
        return fresh == 0 ? time : -1;
    }
};