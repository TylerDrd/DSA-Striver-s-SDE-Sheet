vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> ans(n,1e9);
    queue<pair<int,int>> q;
    ans[src]=0;
    q.push({src,0});

    while(!q.empty())
    {
        int top = q.front().first;
        int d = q.front().second;
        q.pop();
        for(auto it : adj[top])
        {
            if(d+1 < ans[it])
            {
                ans[it]=d+1;
                q.push({it,d+1});
            }
        }
    }
    vector<int> r(n,-1);
    for(int i=0;i<n;i++)
    {
        if(ans[i]!=1e9) r[i]=ans[i];
    }
    return r;
}
