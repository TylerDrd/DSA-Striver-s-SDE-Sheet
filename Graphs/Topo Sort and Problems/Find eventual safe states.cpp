#include <bits/stdc++.h> 
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for(int i=0;i<e;i++)
    {
        adj[edges[i][1]].push_back(edges[i][0]);
        indeg[edges[i][0]]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto it : adj[t])
        {
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
