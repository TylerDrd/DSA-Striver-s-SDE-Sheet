
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	if(n==0) return 0;
	vector<vector<int>> dp(n,vector<int>(k+1,0));
	for(int i=0;i<n;i++) dp[i][0]=1;
	if(arr[0]<=k) dp[0][arr[0]] = 1;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
				int nt = dp[i-1][j]%1000000007;
				int tak = 0;
				if(arr[i] <= j) tak = dp[i-1][j-arr[i]]%1000000007;
			    dp[i][j] = (nt + tak)%1000000007;
		}
	}
	return dp[n-1][k] % 1000000007;
}
/*
   int fun(int i,int t,vector<int>& arr,vector<vector<int>> &dp,int n)
{
	if(t==0) return 1;
	if(i==0) return arr[i]==t;

	if(dp[i][t]!=-1) return dp[i][t];
	int nt = fun(i-1,t,arr,dp,n)%1000000007;
	int tak = 0;
	if(arr[i] <= t) tak = fun(i-1,t-arr[i],arr,dp,n)%1000000007;
	return dp[i][t] = (nt + tak)%1000000007;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	if(n==0) return 0;
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return fun(n-1,k,arr,dp,n) % 1000000007;
}

*/
