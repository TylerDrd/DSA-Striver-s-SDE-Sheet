// class Solution {
// public:
//     int fun(vector<int> &nums,int i,int prev,vector<vector<int>> &dp)
//     {
//         if(i==nums.size()) return 0;
//         if(dp[i][prev+1]!=-1) return dp[i][prev+1];
//         int len = fun(nums,i+1,prev,dp);
//         if(prev==-1 || nums[i]>nums[prev]) len=max(len,1+fun(nums,i+1,i,dp));
//         return dp[i][prev+1]=len;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return fun(nums,0,-1,dp);
//     }
// };

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int p=i-1;p>=-1;p--)
            {
                int len = dp[i+1][p+1];
                if(p==-1 || nums[i]>nums[p]) len=max(len,1+dp[i+1][i+1]);
                dp[i][p+1]=len;
            }
        }
        return dp[0][0];
    }
};
