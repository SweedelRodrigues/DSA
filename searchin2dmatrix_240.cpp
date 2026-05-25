#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& mat, int tar) {

        int m = mat.size();
        int n = mat[0].size();

        int r = 0;
        int c = n - 1;

        // Start from top-right corner
        while(r < m && c >= 0) {

            // Target found
            if(tar == mat[r][c]) {

                return true;
            }

            // Move left
            else if(tar < mat[r][c]) {

                c--;
            }

            // Move down
            else {

                r++;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat = {

        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target = 5;

    bool ans = obj.searchMatrix(mat, target);

    if(ans) {

        cout << "Target Found" << endl;

    } else {

        cout << "Target Not Found" << endl;
    }

    return 0;
}