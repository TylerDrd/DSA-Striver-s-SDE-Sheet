// class Solution {
// public:

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         if(obstacleGrid[0][0]==1) return 0;
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m,vector<int> (n,-1));
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(obstacleGrid[i][j]==1) dp[i][j]=0;
//                 else if(i==0 && j==0) dp[i][j]=1;
//                 else
//                 {
//                     int l=0,t=0;
//                     if(j-1>=0) l=dp[i][j-1];
//                     if(i-1>=0) t=dp[i-1][j];
//                     dp[i][j]=l+t;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

class Solution {
public:

    int fun(int r,int c,vector<vector<int>> &o,vector<vector<int>>&dp,int m,int n)
    {
        if(o[r][c]==1) return 0;
        if((r==0 && c==0) ) return 1;

        if(dp[r][c]!=-1) return dp[r][c];
        int l=0,t=0;
        if(c-1>=0) l=fun(r,c-1,o,dp,m,n);
        if(r-1>=0) t=fun(r-1,c,o,dp,m,n);
        return dp[r][c]=l+t;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return fun(m-1,n-1,obstacleGrid,dp,m,n);
    }
};
