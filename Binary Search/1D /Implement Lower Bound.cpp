int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int l=0,h=n-1,ans=n;
	while(h-l>=0)
	{
		int mid=(l+h)/2;
		if(arr[mid]>=x) 
		{
			ans=mid;
			h=mid-1;
        } 
		else {
            l = mid + 1;
        }
        return ans;
}
