// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         long long m=grid.size();
//         long long n=grid[0].size();
//         vector<vector<long long>> dp(m,vector<long long> (n,-1));
//         for(long long i=0;i<m;i++)
//         {
//             for(long long j=0;j<n;j++)
//             {
//                 if(i==0 && j==0) dp[0][0]=grid[0][0];
//                 else
//                 {
//                     long long l=INT_MAX,t=INT_MAX;
//                     if(j>0) l = grid[i][j]+dp[i][j-1];
//                     if(i>0) t = grid[i][j]+dp[i-1][j];
//                     dp[i][j] = min(l,t);
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

class Solution {
public:
    int fun(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &dp,int m,int n)
    {
        if(r==0 && c==0)
        {
            return grid[r][c];
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int l=INT_MAX,t=INT_MAX;
        if(c>0) l = grid[r][c]+fun(r,c-1,grid,dp,m,n);
        if(r>0) t = grid[r][c]+fun(r-1,c,grid,dp,m,n);
        return dp[r][c] = min(l,t);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return fun(m-1,n-1,grid,dp,m,n);
    }
};
