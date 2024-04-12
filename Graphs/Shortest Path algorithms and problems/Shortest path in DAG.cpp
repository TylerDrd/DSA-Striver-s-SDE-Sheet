#include <bits/stdc++.h>

void dfs(int i, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &s)
{
    vis[i] = 1;
    for (auto neighbor : adj[i])
    {
        int neighborVertex = neighbor.first;
        if (!vis[neighborVertex])
        {
            dfs(neighborVertex, adj, vis, s);
        }
    }
    s.push(i);
}


vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    vector<int> vis(n,0);
    stack<int> s;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,s);
        }
    }
    vector<int> dis(n,1e9);
    dis[0]=0;
    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        for(auto it : adj[t])
        {
            int nd = it.first;
            if(dis[t]+it.second < dis[it.first])
            {
                dis[it.first] = dis[t]+it.second;
            }
        }
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++)
    {
        if(dis[i]!=1e9) ans[i]=dis[i];
    }
    return ans;
}
