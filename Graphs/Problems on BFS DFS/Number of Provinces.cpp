class Solution {
public:
    void dfs(int n,vector<vector<int>> &l,vector<int> &vis)
    {
        vis[n]=1;
        for(auto it : l[n])
        {
            if(!vis[it]) dfs(it,l,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> l(n+1,vector<int> (n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j && isConnected[i-1][j-1]==1)
                {
                    l[i].push_back(j);
                    l[j].push_back(i);
                }
            }
        }
        vector<int> vis(n+1,0);
        int ct=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ct++;
                dfs(i,l,vis);
            }
        }
        return ct;
    }
};
