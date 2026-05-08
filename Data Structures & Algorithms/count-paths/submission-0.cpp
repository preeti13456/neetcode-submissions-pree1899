class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>VALID(m, vector<int>(n, 0));

//any given row for the first column we can able to move to downward direction
        for(int i=0; i<m; i++) VALID[i][0] = 1;

        for(int j=0; j<n; j++) VALID[0][j] = 1;

        for(int i=1; i<m ; i++)
        {
            for(int j = 1; j<n; j++)   
            {
                VALID[i][j] = VALID[i-1][j] + VALID[i][j-1];
            }     }
            return VALID[m-1][n-1];
    }
};
