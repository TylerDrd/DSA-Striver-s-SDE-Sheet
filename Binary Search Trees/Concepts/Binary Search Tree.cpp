class Solution {
  public:
    bool isBSTTraversal(vector<int>& nums) {
        // your code here
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};
