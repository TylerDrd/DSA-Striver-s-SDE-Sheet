//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,ct=0;
       
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                maxi=max(ct,maxi);
                ct=0;
            }
            else
            {
                ct++;
            }
        }
        maxi=max(ct,maxi);
        return maxi;
    }
};
