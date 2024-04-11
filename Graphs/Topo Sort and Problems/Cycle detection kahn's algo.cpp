#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.\
   vector<int> indegree(n,0);
    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for(auto it : adj[t])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    if(ans.size()==n) return 0;
    return 1;
}
