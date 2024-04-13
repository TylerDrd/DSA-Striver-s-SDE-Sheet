class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        p.push({0,{src,0}});
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        
        while(!p.empty())
        {
            int stop = p.top().first;
            int node = p.top().second.first;
            int ct = p.top().second.second;
            p.pop();
            for(auto it : adj[node])
            {
                if(stop<=k && (ct+it.second < dis[it.first]) )
                {
                    dis[it.first] = ct + it.second;
                    p.push({stop+1,{it.first,ct+it.second}});
                } 
            }
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};
