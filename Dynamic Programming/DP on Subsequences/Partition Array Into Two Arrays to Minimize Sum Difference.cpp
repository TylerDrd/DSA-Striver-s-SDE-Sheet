class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2, sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> lft[n + 1], rgt[n + 1];

        lft[0] = {0};
        rgt[0] = {0};

        for(int i = 1; i < (1ll << n); ++i)
        {
            int suml = 0, sumr = 0, cnt = 0;
            for(int j = 0; j < n; ++j)
            {
                if((i >> j) & 1)
                {
                    suml += nums[j];
                    sumr += nums[n + j];
                    ++cnt;
                }
            }
            lft[cnt].push_back(suml);
            rgt[cnt].push_back(sumr);
        }

        for(int i = 0; i <= n; ++i)
        {
            sort(rgt[i].begin(), rgt[i].end());
        }

        int ans = 1e9;

        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j < lft[i].size(); ++j)
            {
                int rem_sum = sum/2 - lft[i][j];
                auto it = lower_bound(rgt[n-i].begin(), rgt[n-i].end(), rem_sum);
                
                if(it != rgt[n-i].end())
                {
                    int lsum = lft[i][j] + (*it);
                    int rsum = sum - lsum;
                    ans = min(ans, abs(lsum - rsum));
                }
                else
                {
                    it = prev(it);
                    int lsum = lft[i][j] + (*it);
                    int rsum = sum - lsum;
                    ans = min(ans, abs(lsum - rsum));
                }
                
            }
        }

        return ans;
    }
};
