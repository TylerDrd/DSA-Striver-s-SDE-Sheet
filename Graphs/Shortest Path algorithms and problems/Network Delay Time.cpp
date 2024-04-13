class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        p.push({0,k});
        vector<int> time(n+1,INT_MAX);
        time[k]=0;

        while(!p.empty())
        {
            int t = p.top().first;
            int node = p.top().second;
            p.pop();        
            for(auto it : adj[node])
            {
                if(t+it.second < time[it.first])
                {
                    time[it.first] = t + it.second;
                    p.push({t+it.second,it.first});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i=1;i<=n;i++) maxi=max(maxi,time[i]);
        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};
