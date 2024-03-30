vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int> dp(n,1),hash(n);
	int maxi=1,last = 0;

	for(int i=0;i<n;i++)
	{
		hash[i]=i;
		for(int prev=0;prev<i;prev++)
		{
			 if(arr[prev] < arr[i] && 1+dp[prev]>dp[i])
			 {
				 dp[i]=1+dp[prev];
				 hash[i]=prev;
			 }
		}
		if(dp[i] > maxi)
		{
			maxi=dp[i];
			last=i;
		}
	}
	vector<int> ans;
	ans.push_back(arr[last]);
	while(hash[last]!=last)
	{
		last=hash[last];
		ans.push_back(arr[last]);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
