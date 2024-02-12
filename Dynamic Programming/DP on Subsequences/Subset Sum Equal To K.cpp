// #include <bits/stdc++.h> 

// bool fun(int i,int t,vector<int> &a,vector<vector<int>> &dp)
// {
//     if(t==0) return true;
//     if(i==0) return a[0]==t;

//     if(dp[i][t]!=-1) return dp[i][t];

//     bool t1 = fun(i-1,t,a,dp);
//     bool t2 = false;
//     if(a[i]<=t) t2 = fun(i-1,t-a[i],a,dp);
//     return dp[i][t] = t1 | t2;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<int>> dp(n,vector<int> (k+1,-1));
//     return fun(n-1,k,arr,dp);
// }

#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool> (k+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            bool t1 = dp[i-1][target];
            bool t2 = false;
            if(arr[i]<=target) t2 = dp[i-1][target-arr[i]];
            dp[i][target]=t1|t2;
        }
    }
    return dp[n-1][k];
}
