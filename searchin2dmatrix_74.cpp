#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool searchMatrix(vector<vector<int>> &matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int sr = 0;
        int er = m - 1;

        // Binary search on rows
        while(sr <= er) {

            int mr = sr + (er - sr) / 2;

            // Target lies in this row
            if(target >= matrix[mr][0] &&
               target <= matrix[mr][n - 1]) {

                return searchInRow(matrix, target, mr);
            }

            // Move downward
            else if(target > matrix[mr][n - 1]) {

                sr = mr + 1;
            }

            // Move upward
            else {

                er = mr - 1;
            }
        }

        return false;
    }

    // Binary search inside row
    bool searchInRow(vector<vector<int>> &matrix,
                     int target,
                     int row) {

        int n = matrix[0].size();

        int st = 0;
        int end = n - 1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(target == matrix[row][mid]) {

                return true;
            }

            else if(target > matrix[row][mid]) {

                st = mid + 1;
            }

            else {

                end = mid - 1;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> matrix = {

        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 3;

    bool ans = obj.searchMatrix(matrix, target);

    if(ans) {

        cout << "Target Found" << endl;

    } else {

        cout << "Target Not Found" << endl;
    }

    return 0;
}