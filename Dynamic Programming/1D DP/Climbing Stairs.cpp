class Solution {
public:

    int climb(int i,vector<int> &dp)
    {
        if(i<=1) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = climb(i-1,dp) + climb(i-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int o=climb(n,dp);
        return o;
    }
};
