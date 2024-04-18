int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
      int dis[n+1][n+1];
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(i==j) dis[i][i]=0;
              else dis[i][j]=1e9;
          }
      } 
      for(auto it : edges)
      {
          dis[it[0]][it[1]]=it[2];
      }
      for(int k=1;k<=n;k++)
      {
          for(int i=1;i<=n;i++)
          {
              for(int j=1;j<=n;j++)
              {
                  dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
              }
          }
      }
      for(int i=1;i<=n;i++) if(dis[i][i]<0) return -1;
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(dis[i][j]==1e9) dis[i][j]=-1;
          }
      }
}
