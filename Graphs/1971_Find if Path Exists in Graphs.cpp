class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
        vis[node] = 1;
        for(auto neig: adj[node]){
            if(vis[neig]==0){
                dfs(neig,adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<vector<int>> adj(n);
       for(auto e: edges){
         int u = e[0];
         int v = e[1];
         adj[u].push_back(v);
         adj[v].push_back(u);
       }
       vector<int> vis(n,0);
       dfs(source,adj,vis);
       if (vis[destination]==1){
        return true;
       }
       return false;
        
    }
};
