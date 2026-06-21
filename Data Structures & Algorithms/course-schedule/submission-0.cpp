class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return false; 
        if (state[node] == 2) return true;  

        state[node] = 1; 

        for (int neighbor : adj[node]) {
            if (!dfs(neighbor, adj, state)) {
                return false;
            }
        }

        state[node] = 2; 
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); 
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state)) {
                    return false;
                }
            }
        }

        return true;
    }
};