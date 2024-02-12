class Solution {
public:
    bool fun(int i,int t,vector<int> &a,vector<vector<int>> &dp)
{
    if(t==0) return true;
    if(i==0) return a[0]==t;

    if(dp[i][t]!=-1) return dp[i][t];

    bool t1 = fun(i-1,t,a,dp);
    bool t2 = false;
    if(a[i]<=t) t2 = fun(i-1,t-a[i],a,dp);
    return dp[i][t] = t1 | t2;
}
    bool canPartition(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) s+= nums[i];
        if(s%2 == 1) return false;
        int tt = s/2;
        vector<vector<int>> dp(n,vector<int> (tt +1,-1));
        return fun(n-1,tt,nums,dp);
    }
};
