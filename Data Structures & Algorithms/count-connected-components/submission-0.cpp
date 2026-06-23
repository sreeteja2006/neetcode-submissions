class Solution {
private:
     void dfs(int i, vector<int> &visited, vector<vector<int>> adj){
        if(visited[i]){
            return;
        }

        visited[i]=1;
        for(int nei: adj[i]){
            if(!visited[nei]){
                dfs(nei,visited,adj);
            }
        }
     }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
       for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        int res=0;
        for(int i =0; i<n;i++){
            if(!visited[i]){
                res++;
                dfs(i,visited,adj);
            }
        }
        return res;

    }
};
