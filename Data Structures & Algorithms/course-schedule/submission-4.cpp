class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, set<int>&path,vector<int>&visited) {
        if(path.contains(node)){
            return false;
        }
        if(visited[node]){
            return true;
        }
        visited[node] =1;
        path.insert(node);
        for (int neighbor : adj[node]) {
            if (!dfs(neighbor, adj, path,visited)) {
                return false;
            }
        }
        path.erase(node);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); 
        }
        vector<int> visited(adj.size(),0);

        for (int i = 0; i < numCourses; i++) {
            set<int> path = {};
            if(!visited[i]){
                if (!dfs(i, adj,path,visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};