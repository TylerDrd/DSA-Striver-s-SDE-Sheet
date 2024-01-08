class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0;
        vector<int> charcount(26,0);
        int maxlen=0,maxchar=0;

        for(int r=0;r<n;r++)
        {
            charcount[s[r]-'A']++;
            maxchar = max(maxchar,charcount[s[r]-'A']);
            while(r-l+1 - maxchar > k) 
            {
                charcount[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
