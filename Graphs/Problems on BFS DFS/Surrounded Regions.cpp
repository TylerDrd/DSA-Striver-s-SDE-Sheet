class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& b,vector<vector<int>>& vis,vector<int> &rr,vector<int> &cc)
    {
        vis[r][c] = 1;
        int n = b.size();
        int m = b[0].size();
        for(int i=0;i<4;i++)
        {
            int nr = r+rr[i];
            int nc = c+cc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && b[nr][nc]=='O')
            {
                dfs(nr,nc,b,vis,rr,cc);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m, 0));
        vector<int> rr={-1,0,1,0};
        vector<int> cc = {0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i] && board[0][i]=='O')
            {
                dfs(0,i,board,vis,rr,cc);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O')
            {
                dfs(n-1,i,board,vis,rr,cc);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                dfs(i,0,board,vis,rr,cc);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O')
            {
                dfs(i,m-1,board,vis,rr,cc);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O') board[i][j] = 'X';
            }
        }
    
    }
};
