class Solution {
public:
int row, col;
void dfs(vector<vector<char>>&grid, int i, int j, vector<vector<int>>&vis)
{
    vis[i][j] = 1;
    int nrow[4] = {1, 0, -1, 0};
    int ncol[4] = { 0, 1, 0, -1};
    for(int k=0; k<4; k++)
    {
        int r = nrow[k]+i;
        int c = ncol[k]+j;
        if(r>=0 &&r<row && c>=0 && c<col&& vis[r][c]==0 && grid[r][c]=='1')
        {
            dfs(grid, r, c, vis);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        //1 -> land
        //0 -> water
//          Input: grid = [
//     ["0","1","1","1","0"],
//     ["0","1","0","1","0"],
//     ["1","1","0","0","0"],
//     ["0","0","0","0","0"]
//   ]
int ans = 0;
row = grid.size();
col = grid[0].size();

//[0, 0, 0, 0, 0]
//[0, 0, 0, 0, 0]
//[0, 0, 0, 0, 0]
//[0, 0, 0, 0, 0]
//[0, 0, 0, 0, 0]
vector<vector<int>>vis(row, vector<int>(col, 0));

for(int i=0; i<row; i++)
{
for(int j=0; j<col; j++)
{
    if(vis[i][j] == 0 && grid[i][j]=='1')
    {
        ans++;
        dfs(grid, i, j, vis);
    }
}
}
return ans;
    }
};
