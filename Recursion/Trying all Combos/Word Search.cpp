class Solution {
public:
    bool found(vector<vector<char>> &board,int i,int j,vector<vector<int>> &vis,string word,int index)
    {
        int r = board.size();
        int c = board[0].size();
        if(index>=word.size()) return true;

        if(i<0 || j<0 || i>=r || j>=c || board[i][j]!=word[index] || vis[i][j]==1) return false;
        vis[i][j]=1;

        bool left = found(board,i,j-1,vis,word,index+1);
        bool right = found(board,i,j+1,vis,word,index+1);
        bool top = found(board,i-1,j,vis,word,index+1);
        bool bottom = found(board,i+1,j,vis,word,index+1);

        vis[i][j]=0;
        return left||right||top||bottom;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        int index = 0;
        vector<vector<int>> vis(r, vector<int> (c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(found(board,i,j,vis,word,index)) return true;
            }
        }
        return false;
    }
};
