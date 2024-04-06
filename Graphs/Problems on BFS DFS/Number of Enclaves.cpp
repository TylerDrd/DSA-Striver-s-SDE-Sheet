class Solution {
public:

    void dfs(int r,int c,vector<vector<int>>& b,vector<vector<int>>& vis,vector<int> &rr,vector<int> &cc)
    {
        vis[r][c] = 1;
        int n = b.size();
        int m = b[0].size();
        for(int i=0;i<4;i++)
        {
            int nr = r+rr[i];
            int nc = c+cc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && b[nr][nc]==1)
            {
                dfs(nr,nc,b,vis,rr,cc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m, 0));
        vector<int> rr={-1,0,1,0};
        vector<int> cc = {0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i] && grid[0][i]==1)
            {
                dfs(0,i,grid,vis,rr,cc);
            }
            if(!vis[n-1][i] && grid[n-1][i]==1)
            {
                dfs(n-1,i,grid,vis,rr,cc);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                dfs(i,0,grid,vis,rr,cc);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i,m-1,grid,vis,rr,cc);
            }
        }
        int ct=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1) ct++;
            }
        }
        return ct;
    }
};
