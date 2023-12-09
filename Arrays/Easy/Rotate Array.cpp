//Time Complexity - O(d) + O(n-d) + O(n) = O(2n)
//Space Complexity - O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int d = k%nums.size();
        reverse(nums.begin()+(nums.size()-d),nums.end());
        reverse(nums.begin(),nums.begin()+(nums.size()-d));
        reverse(nums.begin(),nums.end());
    }
}; 
