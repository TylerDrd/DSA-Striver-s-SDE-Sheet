// class Solution {
// public:
//     bool isP(int i,int j,string &s)
//     {
//         while(i<j)
//         {
//             if(s[i++]!=s[j--]) return false;
//         }
//         return true;
//     }

//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n+1,0);
//         for(int i=n-1;i>=0;i--)
//         {
//             int mini = 1e9;
//             for(int j=i;j<n;j++)
//             {
//                 if(isP(i,j,s))
//                 {
//                     int c = 1 + dp[j+1];
//                     mini = min(mini,c);
//                 }
//             }
//              dp[i]=mini;
//         }
//         return dp[0]-1;
//     }
// };

class Solution {
public:
    bool isP(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int f(int i,string &s,int n,vector<int> &dp)
    {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini = 1e9;
        for(int j=i;j<n;j++)
        {
            if(isP(i,j,s))
            {
                int c = 1 + f(j+1,s,n,dp);
                mini = min(mini,c);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s,n,dp)-1;
    }
};
