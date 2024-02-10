// class Solution {
// public:
//     int fun(int r,int c,vector<vector<int>> &dp,int m,int n)
//     {
//         if(r==0 && c==0) return 1;
//         if(dp[r][c]!=-1) return dp[r][c];
//         int l=0,t=0;
//         if(r-1 >=0) t = fun(r-1,c,dp,m,n);
//         if(c-1>=0) l = fun(r,c-1,dp,m,n);
//         return dp[r][c]=l+t;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int> (n,-1));
//         return fun(m-1,n-1,dp,m,n);
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0) dp[i][j]=1;
                else
                {
                    int l=0,t=0;
                    if(i-1 >=0) t = dp[i-1][j];
                    if(j-1>=0) l = dp[i][j-1];
                    dp[i][j]=l+t;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
