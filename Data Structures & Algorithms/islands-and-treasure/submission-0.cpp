class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int , int>>q;
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(grid[r][c]==0)
                q.push({r,c});
            }
        }
        int curr_dist = 0;
        vector<pair<int, int>>dirs = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};

        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto[r,c] = q.front(); q.pop();
                //INF or out of bounds skip
                if(r<0 || r>=m || c<0 || c>=n || grid[r][c]<curr_dist) continue;
                grid[r][c] = curr_dist;
                for(auto&d : dirs)
                
                    q.push({r+d.first, c+d.second});
                
               
                            }
                             ++curr_dist;
        }
    }
};
