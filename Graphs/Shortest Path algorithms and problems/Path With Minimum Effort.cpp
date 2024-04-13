#define ppt pair<int,pair<int,int>>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
        int mini = INT_MAX;
        dis[0][0]=0;
        
        priority_queue<ppt,vector<ppt>,greater<ppt>> p;
        p.push({0,{0,0}});

        vector<int> rr = {-1,0,1,0};
        vector<int> cc  = {0,1,0,-1};
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
                    if(nr>=0 && nr<n && nc>=0 && nc<m )
                    {
                        if(max(d,abs(grid[r][c]-grid[nr][nc])) < dis[nr][nc])
                        {
                            dis[nr][nc] = max(d,abs(grid[r][c]-grid[nr][nc]));
                            p.push({max(d,abs(grid[r][c]-grid[nr][nc])),{nr,nc}});
                        }
                    }
                
            }
        }
        return dis[n-1][m-1];
    }
};
