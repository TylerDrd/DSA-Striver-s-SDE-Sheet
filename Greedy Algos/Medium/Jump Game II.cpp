class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxreach=0,curreach=0,jumps=0;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] + i > maxreach) maxreach = i+nums[i];

            if(i==curreach)
            {
                jumps++;
                curreach=maxreach;
            }
        }
        return jumps;
    }
};
