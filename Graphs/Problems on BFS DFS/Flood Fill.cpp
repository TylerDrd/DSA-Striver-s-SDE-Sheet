class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& image,vector<vector<int>>& ans,int ini,vector<int> &nr,vector<int> &nc,int col)
    {
        int n = image.size();
        int m = image[0].size();
        ans[r][c]=col;
        for(int i=0;i<4;i++)
        {
            int ngr = r+nr[i];
            int ngc = c+nc[i];
            if(ngr>=0 && ngr<n && ngc>=0 && ngc<m && image[ngr][ngc]==ini && ans[ngr][ngc]!=col)
            {
                dfs(ngr,ngc,image,ans,ini,nr,nc,col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> nr = {-1,0,1,0};
        vector<int> nc = {0,1,0,-1};
        dfs(sr,sc,image,ans,ini,nr,nc,color);
        return ans;
    }
};
