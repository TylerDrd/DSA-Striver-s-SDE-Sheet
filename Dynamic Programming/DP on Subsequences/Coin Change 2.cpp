class Solution {
public:
    int f(int i,int a,vector<int> &c,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(a%c[0]==0) return 1;
            else return 0;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        int nt = f(i-1,a,c,dp);
        int t = 0;
        if(a>=c[i]) t = f(i,a-c[i],c,dp);
        return dp[i][a]=nt+t;
    }

    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        long long ans = f(n-1,amount,coins,dp);
        return ans;
    }
};
