class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dis[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) dis[i][j]=0;
                else dis[i][j]=1e9;
            }
        }
        for(auto it : edges)
        {
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        pair<int,int> p = {INT_MAX,0};
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dis[i][j]<=distanceThreshold) c++;
            }
            if(c < p.first) p = {c,i};
            else if(c==p.first) p.second=max(p.second,i);
        }
        return p.second;
    }
};
