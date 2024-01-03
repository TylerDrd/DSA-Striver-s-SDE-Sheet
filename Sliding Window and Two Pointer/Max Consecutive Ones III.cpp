class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int ml=0,c=0;
        while(r<n)
        {
            if(nums[r]==0) c++;
            while(c>k)
            {
                if(nums[l]==0) c--;
                l++;
            }
            if(c<=k)
            {
                ml=max(ml,r-l+1);
                r++;
            } 
        }
        return ml;
    }
};
