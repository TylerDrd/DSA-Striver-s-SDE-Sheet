class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
        dis[0][0]=1;
        
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        p.push({1,{0,0}});
        while(!p.empty())
        {
            int d = p.top().first;
            int r = p.top().second.first;
            int c = p.top().second.second;
            p.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0)
                    {
                        if(d + 1 < dis[nr][nc])
                        {
                            dis[nr][nc] = 1+d;
                            p.push({1+d,{nr,nc}});
                        }
                    }
                }
            }
        }
        if(dis[n-1][n-1]==INT_MAX) dis[n-1][n-1]=-1;
        return dis[n-1][n-1];
    }
};
