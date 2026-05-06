class Solution {
public:
//dfs+memoization
//with memoization = optimal 
//we will be recursively checking fr each and every cell/path 
//i pointer move krenge from current cell to next neighbouring cells and neighbouring cells value should not be smaller or equal it needs to be greater 
//strictly greater 
//memoization i to cache proviously recursively call already made doing it 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isValid(int i, int j, vector<vector<int>>&matrix)
{
    //out of bounds 
    if(i<0 || i>=matrix.size() || j<0 || j>= matrix[0].size())
    return false;

    return true;
}
int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp)
{
    int count = 1;
    if(dp[i][j]!=-1)
    return dp[i][j];

    for(int k=0; k<4; k++)
    {
        int x = i+dx[k];
        int y = j+dy[k];
        if(isValid(x, y, matrix) && matrix[x][y]>matrix[i][j])
        {
            //1+count o current position
            //0+1 = 1
            //1+1 =2
            //2+1 = 3
            //3+1 = 4
            count = max(count , 1+solve(x,y, matrix, dp));
        }
    }
    //return the cached value 
    //1
    //2
    //3
    //4

    return dp[i][j] = count;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //m = 3, n = 3
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        int maxPath = 1;
for(int i=0; i<m ; i++)
{
    for(int j=0; j<n; j++)
    {
        maxPath = max(maxPath, solve(i,j, matrix, dp));
    }
}
return maxPath;
    }
};
