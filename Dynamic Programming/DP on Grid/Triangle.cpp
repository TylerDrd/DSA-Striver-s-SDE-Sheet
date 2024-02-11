// class Solution {
// public:
//     int fun(int i,int j,vector<vector<int>>& t,vector<vector<int>>& dp,int n)
//     {
//         if(i==n-1)
//         {
//             return t[i][j];
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         int d = t[i][j] + fun(i+1,j,t,dp,n);
//         int dr = t[i][j] + fun(i+1,j+1,t,dp,n);
//         return dp[i][j] = min(d,dr);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return fun(0,0,triangle,dp,n);
//     }
// };

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int j=0;j<n;j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d = triangle[i][j] + dp[i+1][j];
                int dr = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dr);
            }
        }
        return dp[0][0];
    }
};
