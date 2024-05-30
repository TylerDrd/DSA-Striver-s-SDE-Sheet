class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=N-1;i>=1;i--)
        {
            for(int j=i+1;j<=N-1;j++)
            {
                int mini = 1e9;
                for(int k=i;k<j;k++)
                {
                    int st = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(st,mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
    }
};

// class Solution{
// public:
//     int f(int i,int j,int a[],vector<vector<int>> &dp)
//     {
//         if(i==j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int mini = 1e9;
//         for(int k=i;k<j;k++)
//         {
//             int st = a[i-1]*a[k]*a[j] + f(i,k,a,dp) + f(k+1,j,a,dp);
//             mini = min(st,mini);
//         }
//         return mini;
//     }
//     int matrixMultiplication(int N, int arr[])
//     {
//         // code here
//         vector<vector<int>> dp(N,vector<int>(N,-1));
//         return f(1,N-1,arr,dp);
//     }
