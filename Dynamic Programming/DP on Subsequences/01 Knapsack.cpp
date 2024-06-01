//     public:
    
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//        // Your code here
//        vector<vector<int>> dp(n,vector<int>(W+1,0));
//        for(int j=0;j<=W;j++) if(wt[0]<=j) dp[0][j]=val[0];
       
//        for(int i=1;i<n;i++)
//        {
//            for(int w=1;w<=W;w++)
//            {
//                 int nt = dp[i-1][w];
//                 int t = INT_MIN;
//                 if(wt[i] <= w)
//                 {
//                     t = val[i] + dp[i-1][w-wt[i]];
//                 }
//                  dp[i][w]=max(t,nt);
//            }
//        }
//        return dp[n-1][W];
//     }
// };

class Solution
{
    public:
    
    int f(int i,int w,int wt[],int val[],vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(wt[0] <= w) return val[0];
            return 0;
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int nt = f(i-1,w,wt,val,dp);
        int t = INT_MIN;
        if(wt[i] <= w)
        {
            t = val[i] + f(i-1,w-wt[i],wt,val,dp);
        }
        return dp[i][w]=max(t,nt);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return f(n-1,W,wt,val,dp);
    }
};
