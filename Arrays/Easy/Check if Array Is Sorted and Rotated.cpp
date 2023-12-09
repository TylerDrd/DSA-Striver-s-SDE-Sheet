//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        int t = nums[0];
        bool o = false;
        int i;
        if(nums.size()==1) return true;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[i-1])
            {
                break;
            }
            if(i==nums.size()-1 && nums[i]>=nums[i-1])
            {
                return true;
            }
        }
        if(nums[i]<nums[i-1] && nums[i]>nums[0]) return false;

        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j] < nums[j-1]) return false;
            if(nums[j]>nums[0]) return false;
        }

        return true;
    }
};
