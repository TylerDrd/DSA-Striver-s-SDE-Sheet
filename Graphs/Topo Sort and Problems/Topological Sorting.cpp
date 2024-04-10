#include<bits/stdc++.h>

void dfs(int i,vector<vector<int>> &l,vector<int> &vis,stack<int> &s)
    {
        vis[i]=1;
        for(auto it : l[i])
        {
            if(!vis[it])
            {
                dfs(it,l,vis,s);
            }
        }
        s.push(i);
    }

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
       vector<int> ans;
        
        vector<vector<int>> l(nodes);
        for(int i=0;i<edges;i++)
        {
            l[graph[i][0]].push_back(graph[i][1]);
        }

        vector<int> vis(nodes,0);
        stack<int> s;
        for(int i=0;i<nodes;i++)
        {
            if(!vis[i])
            {
                dfs(i,l,vis,s);
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
}
