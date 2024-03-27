class Solution {
public:
    
    int fun(vector<int> &p,int i,int b,vector<vector<vector<int>>> &dp,int c)
    {
        if(c==0 || i==p.size()) return 0;
        int profit=0;
        if(dp[i][b][c]!=-1) return dp[i][b][c];
        if(b)
        {
            profit=max(profit-p[i]+fun(p,i+1,0,dp,c),fun(p,i+1,1,dp,c));
        }
        else
        {
            profit=max(profit+p[i]+fun(p,i+1,1,dp,c-1),fun(p,i+1,0,dp,c));
        }
        return dp[i][b][c]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1,capacity=2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(prices,0,buy,dp,capacity);
    }
};
