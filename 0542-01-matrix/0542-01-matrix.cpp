class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int,int>> q;

        // Push all 0's into the queue
        // Mark all 1's as unvisited (-1)
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            // Up
            if(r > 0 && mat[r-1][c] == -1)
            {
                mat[r-1][c] = mat[r][c] + 1;
                q.push({r-1, c});
            }

            // Down
            if(r < rows-1 && mat[r+1][c] == -1)
            {
                mat[r+1][c] = mat[r][c] + 1;
                q.push({r+1, c});
            }

            // Left
            if(c > 0 && mat[r][c-1] == -1)
            {
                mat[r][c-1] = mat[r][c] + 1;
                q.push({r, c-1});
            }

            // Right
            if(c < cols-1 && mat[r][c+1] == -1)
            {
                mat[r][c+1] = mat[r][c] + 1;
                q.push({r, c+1});
            }
        }

        return mat;
    }
};