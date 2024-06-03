#define ppt pair<int,pair<int,int>>

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<ppt,vector<ppt>,greater<ppt>> p;
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=grid[0][0];
        p.push({grid[0][0],{0,0}});
        vector<int> rr = {0,1,0,-1};
        vector<int> cc = {1,0,-1,0};
        while(!p.empty())
        {
            int d = p.top().first;
            int r = p.top().second.first;
            int c = p.top().second.second;
            p.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r+rr[i];
                int nc = c+cc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n)
                {
                    if(max(d,grid[nr][nc]) < dis[nr][nc])
                    {
                        dis[nr][nc] = max(d,grid[nr][nc]);
                        p.push({max(d,grid[nr][nc]),{nr,nc}});
                    }
                }
            }
        }
        return dis[n-1][n-1];
    }
};
