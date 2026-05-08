class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> dirs = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
        minHeap.push({grid[0][0], 0, 0});

        while (!minHeap.empty()) {
            auto curr = minHeap.top(); minHeap.pop();
            int cost = curr[0], r = curr[1], c = curr[2];
            if (visited[r][c]) continue;
            visited[r][c] = true;
            if (r == ROWS-1 && c == COLS-1) return cost;
            for (auto& dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && !visited[nr][nc]) {
                    minHeap.push({max(cost, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};