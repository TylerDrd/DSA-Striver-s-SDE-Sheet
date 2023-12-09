//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x1=0,x2=0;
        for(int i=0;i<n;i++)
        {
            x1 = x1^nums[i];
            x2=x2^i;
        }
        x2=x2^n;
        return x2^x1;
    }
};
