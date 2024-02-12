class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int d=INT_MAX,dr=INT_MAX,dl=INT_MAX;
                d = matrix[i][j] + dp[i-1][j];
                if(j+1 < n)dr = matrix[i][j] + dp[i-1][j+1];
                if(j-1 >=0)dl = matrix[i][j] + dp[i-1][j-1];
                int rr = min(dr,dl);
                dp[i][j] = min(d,rr);
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++) mini=min(mini,dp[n-1][i]);
        return mini;
    }
};
