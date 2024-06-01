
// class Solution{
//   public:
  
//     int cutRod(int price[], int n) {
//         //code here
//         vector<vector<int>> dp(n,vector<int>(n+1,0));
        
//         for(int j=0;j<=n;j++) dp[0][j]=j*price[0];
        
//         for(int i=1;i<n;i++)
//         {
//             for(int l=1;l<=n;l++)
//             {
//                 int nt = dp[i-1][l];
//                 int t=-1e9;
//                 if(i+1 <= l) t = price[i] + dp[i][l-i-1];
//                  dp[i][l]=max(t,nt);
//             }
//         }
//         return dp[n-1][n];
//     }
// };

class Solution{
  public:
  
    int f(int i,int l,int price[],vector<vector<int>> &dp)
    {
        if(i==0) return l*price[0];
        if(dp[i][l]!=-1) return dp[i][l];
        int nt = f(i-1,l,price,dp);
        int t=-1e9;
        if(i+1 <= l) t = price[i] + f(i,l-(i+1),price,dp);
        return dp[i][l]=max(t,nt);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};
