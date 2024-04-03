class Solution {
  public:
  
    void dfsf(int n,vector<int> adj[], vector<int> &vis, vector<int> &dfs)
    {
        vis[n]=1;
        dfs.push_back(n);
        for(auto it : adj[n])
        {
            if(vis[it]==0)
            {
                dfsf(it,adj,vis,dfs);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0),dfs;
        dfsf(0,adj,vis,dfs);
        return dfs;
    }
};
