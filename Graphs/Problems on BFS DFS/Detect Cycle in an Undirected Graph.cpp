class Graph {

public:
   bool dfs(int n,int par,vector<int> adj[],vector<int> &vis)
   {
       vis[n]=1;
       for(auto it : adj[n])
       {
           if(!vis[it])
           {
               if(dfs(it,n,adj,vis)==true) return true;
           }
           else if(it != par) return true;
       }
       return false;
   }   
   
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis)==true) return true;
            }
        }
        return false;
    }
};
