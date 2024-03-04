class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        int n1 = s1.size(),n2 = s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s2[i-1]==s1[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n1-dp[n1][n2];
    }
};
