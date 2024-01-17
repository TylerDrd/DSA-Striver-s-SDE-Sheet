pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int l=0,h=n-1,ans=n;
	while(l<=h)
	{
		int mid = (l+h)/2;
		if(a[mid]>=x)
		{
			ans=mid;
			h=mid-1;
		}
		else l = mid+1;
	}
	if(a[ans]==x)
                return { x, x };
	else
	{
		if(ans==0) return {-1, a[0]};
		if(ans==n) return {a[ans-1],-1};
                return { a[ans - 1], a[ans] };
    }
}
