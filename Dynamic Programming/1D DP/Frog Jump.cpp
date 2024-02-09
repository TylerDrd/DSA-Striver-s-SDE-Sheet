#include <bits/stdc++.h> 
int fun(int n,vector<int> &h,vector<int> &dp)
{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int lh = fun(n-1,h,dp) + abs(h[n]-h[n-1]);
    int rh = INT_MAX;
    if(n>1) rh = fun(n-2,h,dp) + abs(h[n]-h[n-2]);
    return dp[n] = min(lh,rh);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);
    return fun(n-1,heights,dp);
}
