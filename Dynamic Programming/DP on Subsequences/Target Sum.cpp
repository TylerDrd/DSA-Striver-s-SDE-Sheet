class Solution {
public:
    int fun(int i,int t,vector<int>& arr,vector<vector<int>> &dp,int n)
{
        if(i==0)
        {
            if(t==0 && arr[i]==0) return 2;
            if(t==0 || arr[i]==t) return 1;
            return 0;
        }

        if(dp[i][t]!=-1) return dp[i][t];
        int nt = fun(i-1,t,arr,dp,n);
        int tak = 0;
        if(arr[i] <= t) tak = fun(i-1,t-arr[i],arr,dp,n);
        return dp[i][t] = (nt + tak);
}

    
    int findTargetSumWays(vector<int>& nums, int d) {
        int n = nums.size();
        if(n==0) return 0;
    
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum-d<0 || (sum-d)%2==1) return 0;
        vector<vector<int>> dp(n,vector<int>((sum-d)/2 +1,-1));
        return fun(n-1,(sum-d)/2,nums,dp,n);
    }
};
