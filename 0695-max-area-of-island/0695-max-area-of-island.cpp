class Solution {
public:
    int rows, cols;

    int dfs(vector<vector<int>>& grid, int r, int c) {

        // Base case
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;

        // Mark current cell as visited
        grid[r][c] = 0;

        // Current cell (1) + area of all 4 directions
        return 1
             + dfs(grid, r - 1, c)   // Up
             + dfs(grid, r + 1, c)   // Down
             + dfs(grid, r, c - 1)   // Left
             + dfs(grid, r, c + 1);  // Right
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};