// class Solution {
// public:
//     int fun(string word1,int n1,string word2,int n2,vector<vector<int>> &dp)
//     {
//         if(n1<0) return n2+1;
//         if(n2<0) return n1+1;
//         if(dp[n1][n2]!=-1) return dp[n1][n2];
//         if(word1[n1]==word2[n2]) return dp[n1][n2] = fun(word1,n1-1,word2,n2-1,dp);
//         else
//         {
//             int a = 1+fun(word1,n1,word2,n2-1,dp); //insert
//             int b = 1+fun(word1,n1-1,word2,n2,dp); //delete
//             int c = 1+fun(word1,n1-1,word2,n2-1,dp); //replace

//             return dp[n1][n2]=min(a,min(b,c));
//         }
//     }
    
//     int minDistance(string word1, string word2) {
//         int n1 = word1.size();
//         int n2 = word2.size();
//         vector<vector<int>> dp(n1,vector<int> (n2,-1));
//         return fun(word1,n1-1,word2,n2-1,dp);
//     }
// };

class Solution {
public:

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        for(int i=0;i<=n2;i++) dp[0][i]=i;
        for(int i=0;i<=n1;i++) dp[i][0]=i;

        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    int a = 1+dp[i][j-1]; //insert
                    int b = 1+dp[i-1][j]; //delete
                    int c = 1+dp[i-1][j-1]; //replace

                     dp[i][j]=min(a,min(b,c));
                }
            }
        }
        return dp[n1][n2];
    }
};
