class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i]) adj[it].push_back(i);
        }
        vector<int> ind(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it : adj[i]) ind[it]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto it : adj[t])
            {
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
