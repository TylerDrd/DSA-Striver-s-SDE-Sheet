// class Solution {
// public:
//     int fun(int i,vector<int> &num,vector<int> &dp,int n)
//     {
//         if(i==0) return num[i];
//         if(i<0) return 0;
//         if(dp[i]!=-1) return dp[i];
//         int tk = num[i]+fun(i-2,num,dp,n);
//         int nt = fun(i-1,num,dp,n);
//         return dp[i]=max(tk,nt);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return fun(n-1,nums,dp,n);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++)
        {
            int t = nums[i]+prev2;
            int nt = prev;
            int curr = max(t,nt);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
