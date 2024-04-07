#include <bits/stdc++.h>

void dfs(int r,int c,int** a,vector<vector<int>> &vis, vector<pair<int,int>> &v,int r0,int c0,int n,int m)
{
    vis[r][c]=1;
    v.push_back({r-r0,c-c0});
    vector<int> rr = { -1, 0, 1, 0 };
    vector<int> cc = { 0, 1, 0, -1 };
    for(int i=0;i<4;i++)
    {
        int nr = r+rr[i];
        int nc = c+cc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && a[nr][nc]==1)
        {
            dfs(nr,nc,a,vis,v,r0,c0,n,m);
        }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    vector<vector<int>> vis(n,vector<int> (m,0));
    set<vector<pair<int,int>>> s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && arr[i][j]==1)
            {
                vector<pair<int,int>> v;
                dfs(i,j,arr,vis,v,i,j,n,m);
                s.insert(v);
            }
        }
    }
    return s.size();
}
