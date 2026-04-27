class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>rotQueue;
        int freshCount = 0, minutes = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>>dirs = {{0,-1}, {0, 1}, {-1, 0}, {1,0}};
        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if(grid[r][c]==2)
                rotQueue.push({r,c});
                else if(grid[r][c]==1)
                freshCount++;
            }
        }
        while(freshCount>0 && !rotQueue.empty())
        {
            int len = rotQueue.size();
            for(int i=0; i<len; i++)
            {
                auto[row, col]=rotQueue.front(); rotQueue.pop();
                for(auto [dr, dc]: dirs)
                {
                    int newRow = row+dr, newCol = col+dc;
                    if(newRow>=0 && newCol>=0 && newRow<rows && newCol < cols && grid[newRow][newCol]==1){
                    grid[newRow][newCol]=2;
                    rotQueue.push({newRow, newCol});
                    freshCount--;
                }
            }
        }
        minutes++;
    }
    return freshCount > 0 ? -1 : minutes;
    }
};
