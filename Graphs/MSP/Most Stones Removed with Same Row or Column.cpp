class Solution {
public:
    int par(vector<int> &p,int u)
    {
        if(u==p[u]) return u;
        return p[u] = par(p,p[u]);
    }
    void join(vector<int> &p,int u,int v)
    {
        int p_u = par(p,u);
        int p_v = par(p,v);
        p[p_u] = p_v;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int r=0,c=0;
        for(auto it : stones)
        {
            r = max(r,it[0]);
            c = max(c,it[1]);
        }
        vector<int> p(r+c+2,0);
        for(int i=0;i<p.size();i++) p[i]=i;
        unordered_map<int,int> m;
        for(auto it : stones)
        {
            int nr = it[0];
            int nc = it[1] + r + 1;
            join(p,nr,nc);
            m[nr]=1;
            m[nc]=1;
        }
        int ct = 0;
        for(auto it : m)
        {
            if(par(p,it.first)==it.first) ct++;
        }
        return n - ct;
    }
};
