class Solution {
public:
    int beautySum(string s) {
        long long ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxi = -1, mini = 1e9;
                for(int k = 0; k < 26; k++) {
                    if(freq[k] >= 1) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};
