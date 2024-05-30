// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n+1,0);
//         for(int i=n-1;i>=0;i--)
//         {
//             int l=0,maxi=-1e9,ans=-1e9;
//             for(int j=i;j<min(n,i+k);j++)
//             {
//                 l++;
//                 maxi = max(maxi,arr[j]);
//                 int sum = l*maxi + dp[j+1];
//                 ans=max(ans,sum);
//             }
//              dp[i]=ans;
//         }
//         return dp[0];
//     }
// };

class Solution {
public:
    int f(int i,vector<int> &a,int n,int k,vector<int> &dp)
    {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int l=0,maxi=-1e9,ans=-1e9;
        for(int j=i;j<min(n,i+k);j++)
        {
            l++;
            maxi = max(maxi,a[j]);
            int sum = l*maxi + f(j+1,a,n,k,dp);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,n,k,dp);
    }
};
