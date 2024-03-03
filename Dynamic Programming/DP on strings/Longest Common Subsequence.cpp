class Solution {
public:
    int fun(string text1, string text2,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) return dp[i][j] = 1 + fun(text1,text2,i-1,j-1,dp);
        return dp[i][j] = max(fun(text1,text2,i-1,j,dp),fun(text1,text2,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(),n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

/*
  class Solution {
public:
    int fun(string text1, string text2,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) return dp[i][j] = 1 + fun(text1,text2,i-1,j-1,dp);
        return dp[i][j] = max(fun(text1,text2,i-1,j,dp),fun(text1,text2,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(),n2 = text2.size();
        vector<vector<int>> v(n1,vector<int>(n2,-1));
        return fun(text1,text2,n1-1,n2-1,v);
    }
};
*/
