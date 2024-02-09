class Solution {
public:

    int fun(vector<int> &nums)
    {
        int n = nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++)
        {
            int t = nums[i]+prev2;
            int nt = prev;
            int curr = max(t,nt);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> t1,t2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) t1.push_back(nums[i]);
            if(i!=nums.size()-1) t2.push_back(nums[i]);
        }
        return max(fun(t1),fun(t2));
    }
};
