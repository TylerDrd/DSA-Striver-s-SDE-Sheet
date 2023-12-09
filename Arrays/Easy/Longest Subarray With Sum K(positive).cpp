//Time complexity - O(2n)
//Space complexity - O(1)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    long long sum=a[0];
    int maxlen=0;
    int left=0,right=0;
    while(right<a.size())
    {

        while(left<=right && sum>k)
        {
            sum=sum-a[left];
            left++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }

        right++;
        if(right<a.size()) sum+=a[right];
        
    }
    return maxlen;
}
