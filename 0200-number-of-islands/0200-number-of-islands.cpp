class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<char>>& grid, int r, int c) {

        // Base case
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
            return;

        // Mark as visited
        grid[r][c] = '0';

        // Explore all 4 directions
        dfs(grid, r - 1, c); // Up
        dfs(grid, r + 1, c); // Down
        dfs(grid, r, c - 1); // Left
        dfs(grid, r, c + 1); // Right
    }

    int numIslands(vector<vector<char>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};