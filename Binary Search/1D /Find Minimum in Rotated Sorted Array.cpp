class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),m=INT_MAX;
        int l=0,h=n-1;
        while(h>=l)
        {
            int mid=(l+h)/2;
            if(nums[l]<=nums[mid]) 
            {
                m=min(m,nums[l]);
                l=mid+1;
            }
            else
            {
                m=min(m,nums[mid]);
                h=mid-1;
            }
        }
        return m;
    }
};
