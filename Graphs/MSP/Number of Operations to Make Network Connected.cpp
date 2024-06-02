class Solution {
public:
    int par(vector<int> &p,int u)
    {
        if(u==p[u]) return u;
        return p[u] = par(p,p[u]);
    }
    void join(vector<int> &p,int u,int v)
    {
        int p_u = p[u];
        int p_v = p[v];
        p[p_u] = p_v;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        int extra = 0;
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if(par(parent,u) == par(parent,v)) extra++;
            else join(parent,u,v);
        }
        int ct = 0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i) ct++;
        }
        int ans = ct-1;
        if(extra>=ans) return ans;
        return -1;
    }
};
