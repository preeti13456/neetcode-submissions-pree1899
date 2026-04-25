class Solution {
public:
void dfs(int i, int j, vector<vector<int>>&grid, int&count)
{
    //boundat case
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()||grid[i][j]==0) return;
    grid[i][j] = 0;
    count++;
    //go to all 4 directions from current cell
    dfs(i+1, j, grid, count);
    dfs(i-1, j, grid, count);
    dfs(i, j+1, grid, count);
    dfs(i, j-1, grid, count);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)

{
    if(grid[i][j]==1)
    {
        int count = 0;
        dfs(i, j, grid, count);
        maxArea = max(maxArea, count);
    }
}        }
return maxArea;
    }
};
