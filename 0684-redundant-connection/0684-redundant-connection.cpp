class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj , int src , int dest, vector<int>& vis){
        vis[src] = 1;
        if(src==dest){
            return true;
        }
        for(int n : adj[src]){
            if(vis[n]) continue;
            if(dfs(adj , n , dest , vis)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int , vector<int>>adj;
        vector<int>vis(n+1);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(adj , u , v , vis)){
                return it;
            }
            fill(vis.begin(), vis.end(), 0);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};