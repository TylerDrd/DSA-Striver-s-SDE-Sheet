class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool> r(row, false);
        vector<bool> c(col, false);

        for (int i = 0; i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if (matrix[i][j]==0)
                {
                    r[i]=true;
                    c[j]=true;
                }
            }
        }
        for(int i =0; i<r.size();i++)
        {
            if (r[i] == true)
            {
                for(int j=0;j<col;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int j =0; j<c.size();j++)
        {
            if (c[j] == true)
            {
                for(int i=0;i<row;i++)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};
