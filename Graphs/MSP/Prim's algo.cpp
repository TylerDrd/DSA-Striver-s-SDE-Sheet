#include<bits/stdc++.h>

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
       vector<int> vis(n,0);
       int cost = 0;
       vector<pair<int,int>> adj[n];
       for(auto it : edges)
       {
         adj[it[0]].push_back({it[1],it[2]});
         adj[it[1]].push_back({it[0],it[2]});
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
       p.push({0,0});

       while(!p.empty())
       {
             auto t = p.top();
             p.pop();
             if(vis[t.second]) continue;
             vis[t.second]=1;
             cost+=t.first;
             for(auto it : adj[t.second])
             {
                  if(!vis[it.first])
                  {
                       p.push({it.second,it.first});
                  }
             }
       }
       return cost;
}
