class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        dp[n][0]=0;dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit=max(profit-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit=max(profit+prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
// class Solution {
// public:
    
//     int fun(vector<int> &p,int i,int b,vector<vector<int>> &dp)
//     {
//         if(i==p.size()) return 0;
//         int profit=0;
//         if(dp[i][b]!=-1) return dp[i][b];
//         if(b)
//         {
//             profit=max(profit-p[i]+fun(p,i+1,0,dp),fun(p,i+1,1,dp));
//         }
//         else
//         {
//             profit=max(profit+p[i]+fun(p,i+1,1,dp),fun(p,i+1,0,dp));
//         }
//         return dp[i][b]=profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int buy = 1;
//         vector<vector<int>> dp(n,vector<int> (2,-1));
//         return fun(prices,0,buy,dp);
//     }
// };
