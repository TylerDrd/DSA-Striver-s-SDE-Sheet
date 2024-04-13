vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<pair<int,int>> adj[vertices];
    for(auto it : edge)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    vector<int> dist(vertices,INT_MAX);
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,source});

    while(!q.empty())
    {
        auto it=q.top();
        q.pop();
        int d =it.first;
        int n =it.second;
        for(auto next : adj[n])
        {
            if(d + next.second < dist[next.first])
            {
                dist[next.first]= d+ next.second;
                q.push({d+ next.second,next.first});
            }
        }
    }
    return dist;

}
