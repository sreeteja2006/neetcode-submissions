class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, set<int>& path, vector<int>& visited, vector<int>& res) {
        if (path.contains(node)) {
            return false;
        }
        if (visited[node]) {
            return true;
        }
        
        visited[node] = 1;
        path.insert(node);
        
        for (int neighbor : adj[node]) {
            if (!dfs(neighbor, adj, path, visited, res)) {
                return false;
            }
        }
        
        path.erase(node);
        res.push_back(node);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); 
        }
        
        vector<int> visited(numCourses, 0);
        set<int> path;
        vector<int> res;
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, adj, path, visited, res)) {
                    return {};
                }
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};