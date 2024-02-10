// int fun(int day,int last,vector<vector<int>> &p,vector<vector<int>> &dp)
// {
//     if(day==0)
//     {
//         int m=0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last) m=max(m,p[day][i]);
//         }
//         return m;
//     }
//     if(dp[day][last]!=-1) return dp[day][last];
//     int maxi = 0;
//     for(int i=0;i<3;i++)
//     {
//         if(i!=last) maxi = max(maxi,p[day][i]+fun(day-1,i,p,dp));
//     }
//     return dp[day][last]=maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n,vector<int> (4,-1));
//     return fun(n-1,3,points,dp);
// }


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],dp[0][0]);
    
    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            int maxi = 0;
            for(int i=0;i<3;i++)
            {
                if(i!=last) maxi = max(maxi,points[day][i]+dp[day-1][i]);
            }
            dp[day][last]=maxi;
        }
    }
    return dp[n-1][3];
}
