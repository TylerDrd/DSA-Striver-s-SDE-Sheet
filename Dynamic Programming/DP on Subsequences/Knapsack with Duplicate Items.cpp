class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int j=0;j<=W;j++) if(wt[0]<=j) dp[0][j]=val[0]*(j/wt[0]);
       
       for(int i=1;i<n;i++)
       {
           for(int w=1;w<=W;w++)
           {
                int nt = dp[i-1][w];
                int t = INT_MIN;
                if(wt[i] <= w)
                {
                    t = val[i] + dp[i][w-wt[i]];
                }
                 dp[i][w]=max(t,nt);
           }
       }
       return dp[n-1][W];
    }
};
