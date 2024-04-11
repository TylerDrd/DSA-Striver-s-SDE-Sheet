#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!

    vector<int> indegree(nodes,0);
    vector<vector<int>> adj(nodes);
    for(int i=0;i<edges;i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    queue<int> q;
    for(int i=0;i<nodes;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<nodes;i++)
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
    return ans;
}
