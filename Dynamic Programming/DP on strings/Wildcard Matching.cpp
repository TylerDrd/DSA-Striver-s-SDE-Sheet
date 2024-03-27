class Solution {
public:
    bool fun(string &s,int i,string &p,int j,vector<vector<int>> &dp)
    {
        if(j<0 && i<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=fun(s,i-1,p,j-1,dp);
        else if(p[j]=='*') 
        {
            return dp[i][j]=fun(s,i,p,j-1,dp) || fun(s,i-1,p,j,dp);
        }
        else return dp[i][j]=false;
    }
    
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return fun(s,n1-1,p,n2-1,dp);
    }
};
