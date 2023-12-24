class Solution {
public:
    vector<vector<string>> ans;

    void solve(int col,int n,vector<string> &v,vector<int> &leftrow,vector<int> &upperdia,vector<int> &lowerdia)
    {
        if(col>=n)
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(leftrow[i]==0 && lowerdia[col+i]==0 && upperdia[n-1+col-i]==0)
            {
                v[col][i]='Q';
                leftrow[i]=1;
                lowerdia[col+i]=1;
                upperdia[n-1+col-i]=1;
                solve(col+1,n,v,leftrow,upperdia,lowerdia);
                v[col][i]='.';
                leftrow[i]=0;
                lowerdia[col+i]=0;
                upperdia[n-1+col-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            v[i]=s;
        }
        vector<int> leftrow(n,0), upperdia(2*n-1,0), lowerdia(2*n-1);
        solve(0,n,v,leftrow,upperdia,lowerdia);
        return ans;
    }
};
