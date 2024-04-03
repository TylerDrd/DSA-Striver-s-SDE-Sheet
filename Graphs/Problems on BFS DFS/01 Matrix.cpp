class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                    dis[i][j]=0;
                }
            }
        }
        vector<int> nr={-1,0,1,0};
        vector<int> nc = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            dis[r][c]=d;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int ngr = r+nr[i];
                int ngc = c+nc[i];
                if(ngr>=0 && ngr<n && ngc>=0 && ngc<m && vis[ngr][ngc]==0)
                {
                    q.push({{ngr,ngc},d+1});
                    vis[ngr][ngc]=1;
                }
            }
        }
        return dis;
    }
};
