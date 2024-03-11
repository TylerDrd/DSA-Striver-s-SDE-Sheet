#define ll long long int 

class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned ll n1=s.size();
        unsigned ll n2=t.size();
        vector<vector<unsigned ll>> dp(n1+1,vector<unsigned ll>(n2+1,0));
        
        for(unsigned ll i=0;i<=n1;i++) dp[i][0]=1;
        for(unsigned ll i=1;i<=n1;i++)
        {
            for(unsigned ll j=1;j<=n2;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n1][n2];
    }
};
