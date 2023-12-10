//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto it : nums)
        {
            x=x^it;
        }
        return x;
    }
};