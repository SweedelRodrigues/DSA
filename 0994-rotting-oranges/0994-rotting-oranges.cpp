class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;

        // Store all rotten oranges and count fresh oranges
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i, j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        // BFS
        while(!q.empty() && fresh > 0)
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                // Up
                if(r > 0 && grid[r - 1][c] == 1)
                {
                    grid[r - 1][c] = 2;
                    fresh--;
                    q.push({r - 1, c});
                }

                // Down
                if(r < rows - 1 && grid[r + 1][c] == 1)
                {
                    grid[r + 1][c] = 2;
                    fresh--;
                    q.push({r + 1, c});
                }

                // Left
                if(c > 0 && grid[r][c - 1] == 1)
                {
                    grid[r][c - 1] = 2;
                    fresh--;
                    q.push({r, c - 1});
                }

                // Right
                if(c < cols - 1 && grid[r][c + 1] == 1)
                {
                    grid[r][c + 1] = 2;
                    fresh--;
                    q.push({r, c + 1});
                }
            }

            minutes++;
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};