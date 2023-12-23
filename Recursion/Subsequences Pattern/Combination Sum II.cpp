//time complexity - O(2^n *k)  n - no of distinct elements in array, k = av. length of sub sequence
//space complexity - O(k *x)

class Solution {
public:
    vector<vector<int>> v;
    void generate(int ind,vector<int> &t,vector<int> &c,int target)
    {
        if(target==0)
        {
            v.push_back(t);
            return;
        }
        for(int i=ind;i<c.size();i++)
        {
            if(c[i]>target) break;
            if(i>ind && c[i]==c[i-1]) continue;
            t.push_back(c[i]);
            generate(i+1,t,c,target-c[i]);
            t.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> t;
        sort(candidates.begin(),candidates.end());
        generate(0,t,candidates,target);
        return v;
    }
};
