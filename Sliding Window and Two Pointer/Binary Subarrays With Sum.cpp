class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left = 0, right = 0, sum = 0, ans = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        for (right = 0; right < nums.size(); right++) {
            sum += nums[right];
            if (count.find(sum - goal) != count.end()) {
                ans += count[sum - goal];
            }
            count[sum]++;
        }
        return ans;
    }
};
