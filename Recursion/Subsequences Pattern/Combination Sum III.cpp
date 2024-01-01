class Solution {
public:

    vector<vector<int>> res;

    void findcomb(int k,int n,vector<int> &temp,int start)
    {
        if(k==0 && n==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=9;i++)
        {
            if(i>n) break;
            if(i<=n)
            {
                temp.push_back(i);
                findcomb(k-1,n-i,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        findcomb(k,n,temp,1);
        return res;
    }
};
