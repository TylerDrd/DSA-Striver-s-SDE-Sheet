// int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
//         for(int a=0;a<=amount;a++) if(a%coins[0]==0) dp[0][a]=a/coins[0];

//         for(int i=1;i<n;i++)
//         {
//             for(int a=0;a<=amount;a++)
//             {
//                 int nt = dp[i-1][a];
//                 int t = 1e9;
//                 if(a>=coins[i]) t = 1+dp[i][a-coins[i]];
//                  dp[i][a]=min(nt,t);
//             }
//         }
//         long long ans = dp[n-1][amount];
//         if(ans==1e9) return -1;
//         return ans;
//     }

class Solution {
public:
    int f(int i,int a,vector<int> &c,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(a%c[0]==0) return a/c[0];
            else return 1e9;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        int nt = f(i-1,a,c,dp);
        int t = 1e9;
        if(a>=c[i]) t = 1+f(i,a-c[i],c,dp);
        return dp[i][a]=min(nt,t);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        long long ans = f(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};
