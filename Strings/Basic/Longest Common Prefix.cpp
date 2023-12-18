class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans = "";
        int n = strs[0].size();
        int k = strs.size()-1;
        int m = strs[k].size();
        int t = min(n,m);

        for(int i=0;i<t;i++)
        {
            if(strs[0][i] != strs[k][i])
            {
                break;
            }
            else
            {
                ans.push_back(strs[0][i]);
            }
        }
        return ans;
    }
};
