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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> p(n);
        for(int i=0;i<n;i++) p[i]=i;
        unordered_map<string,int> m;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(m.find(mail)==m.end()) m[mail]=i;
                else join(p,m[mail],i);
            }
        }
        vector<string> mail[n];
        for(auto it : m)
        {
            string mail1 = it.first;
            int node = par(p,it.second);
            mail[node].push_back(mail1);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mail[i].size()==0) continue;
            sort(mail[i].begin(),mail[i].end());
            vector<string> t;
            t.push_back(accounts[i][0]);
            t.insert(t.end(),mail[i].begin(),mail[i].end());
            ans.push_back(t);
        }
        return ans;
    }
};
