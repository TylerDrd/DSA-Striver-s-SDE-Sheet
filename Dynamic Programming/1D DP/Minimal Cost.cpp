// int fun(int i,int k,vector<int> &dp,vector<int> &height)
// {
//     if(i==0) return 0;
//     if(dp[i]!=-1) return dp[i];
//     int mini = INT_MAX;
//     for(int j=1;j<=k;j++)
//     {
//         if(i-j < 0 ) continue;
//         mini = min(mini,fun(i-j,k,dp,height) + abs(height[i]-height[i-j]));
//     }
//     return dp[i]=mini;
// }

// int minimizeCost(int n, int k, vector<int> &height){
//     // Write your code here.
//     vector<int> dp(n,-1);
//     return fun(n-1,k,dp,height);
// }
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int mini = INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j < 0 ) continue;
            mini = min(mini,dp[i-j] + abs(height[i]-height[i-j]));
        }
        dp[i]=mini;
    }
    return dp[n-1];
}
