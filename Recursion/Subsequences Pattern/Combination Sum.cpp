//time complexity - O(2^t *k)  t - no of times recursion call at the same index, k - av. length of combination
//space complexity - O(k*x) - x - no. of combinations

class Solution {
public:
    vector<vector<int>> o;

    void generate(int i,vector<int> &t,vector<int> &a,int target,int n)
    {
        if(i==n)
        {
            if(target==0)
            {
                o.push_back(t);
            }
            return;
        }
            if(a[i]<=target)
            {
                t.push_back(a[i]);
                generate(i,t,a,target-a[i],n);
                t.pop_back();
            }

            generate(i+1,t,a,target,n);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int n = candidates.size();
        generate(0,temp,candidates,target,n);
        return o;
    }
};
