int fun(vector<int> &s,int mid,int k,int n)
{
    int ct = 1,prev = s[0];
    for(int i=1;i<n;i++)
    {
        if(s[i] - prev >= mid)
        {
            ct++;
            prev = s[i];
        }
    }
    return ct>=k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int l = 1,h = stalls[n-1]-stalls[0];
    while(h>=l)
    {
        int mid = (l+h)/2;
        bool val = fun(stalls,mid,k,n);
        if(val)
        {
            l = mid+1;
        }
        else h = mid-1;
    }
    return h;
}
