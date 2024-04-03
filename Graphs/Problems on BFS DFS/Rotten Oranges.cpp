class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m],ct1=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
                if(grid[i][j]==1) ct1++;
            }
        }
        int tm=0,ct2=0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            vector<int> nr = {-1,0,1,0};
            vector<int> nc = {0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int ngr = r+nr[i];
                int ngc = c+nc[i];
                if(ngr>=0 && ngr<n && ngc>=0 && ngc<m && vis[ngr][ngc]!=2 && grid[ngr][ngc]==1)
                {
                    vis[ngr][ngc]=2;
                    q.push({{ngr,ngc},t+1});
                    ct2++;
                    tm = max(tm,t+1);
                }
            }
        }
        if(ct1 != ct2) return -1;
            return tm;
    }
};
