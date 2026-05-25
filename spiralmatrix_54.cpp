#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int srow = 0;
        int scol = 0;

        int erow = m - 1;
        int ecol = n - 1;

        vector<int> ans;

        while(srow <= erow && scol <= ecol) {

            // Top row
            for(int j = scol; j <= ecol; j++) {

                ans.push_back(mat[srow][j]);
            }

            // Right column
            for(int i = srow + 1; i <= erow; i++) {

                ans.push_back(mat[i][ecol]);
            }

            // Bottom row
            for(int j = ecol - 1; j >= scol; j--) {

                if(srow == erow) {
                    break;
                }

                ans.push_back(mat[erow][j]);
            }

            // Left column
            for(int i = erow - 1; i >= srow + 1; i--) {

                if(scol == ecol) {
                    break;
                }

                ans.push_back(mat[i][scol]);
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = obj.spiralOrder(mat);

    cout << "Spiral Order: ";

    for(int val : result) {

        cout << val << " ";
    }

    cout << endl;

    return 0;
}