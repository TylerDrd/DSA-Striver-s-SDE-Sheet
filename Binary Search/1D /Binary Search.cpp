class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(r>l)
        {
            int mid = (l+r)/2;
            if(nums[mid] >= target)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        if(nums[l]==target) return l;
        else return -1;
    }
};
