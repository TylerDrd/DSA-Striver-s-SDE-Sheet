class Solution {
public:

    int fun(vector<int> &nums,int k)
    {
        int n = nums.size();
        int l=0,r=0,ans=0;
        map<int,int> m;
        while(r<n)
        {
            m[nums[r]]++;
            while(m.size() > k)
            {
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};
