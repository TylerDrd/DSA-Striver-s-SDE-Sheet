class Solution{
    public:
    vector<string> ans;
    
    void findpath(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &m,int n,string s,vector<int> &nr,vector<int> &nc)
    {
        if(r==n-1 && c==n-1)
        {
            ans.push_back(s);
            return;
        }
        string route = "LURD";
        for(int i=0;i<4;i++)
        {
            int nghdr = r+nr[i];
            int nghdc = c+nc[i];
            if(nghdr>=0 && nghdr<n && nghdc>=0 && nghdc<n && m[nghdr][nghdc]==1 && !vis[nghdr][nghdc])
            {
                vis[r][c]=1;
                findpath(nghdr,nghdc,vis,m,n,s+route[i],nr,nc);
                vis[r][c]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s = "";
        vector<vector<int>> vis(n, vector<int> (n,0));
        vector<int> nr = {0,-1,0,1};
        vector<int> nc = {-1,0,1,0};
        if(m[0][0]==1) findpath(0,0,vis,m,n,s,nr,nc);
        return ans;
    }
};
