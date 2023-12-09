//Time complexity - O(nlogn) for ordered map and O(n^2) for unordered map
//Space complexity - O(n)

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    map<int,int> m;
    int sum=0,mlen=0,n=nums.size();

    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum==k) mlen=max(mlen,i+1);

        int rem = sum-k;
        
        if(m.find(rem)!=m.end())
        {
            int len=i-m[rem];
            mlen=max(mlen,len);
        }

        if(m.find(sum)==m.end())
        {
            m[sum]=i;
        }
    }
    return mlen;
}
