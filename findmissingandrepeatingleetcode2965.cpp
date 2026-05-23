#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> ans;
        unordered_set<int> s;

        int n = grid.size();

        int a, b;

        int expsum = 0, actsum = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                actsum += grid[i][j];

                // Check duplicate element
                if(s.find(grid[i][j]) != s.end()) {

                    a = grid[i][j];
                    ans.push_back(a);
                }

                s.insert(grid[i][j]);
            }
        }

        int total = n * n;

        // Expected sum from 1 to n*n
        expsum = (total * (total + 1)) / 2;

        // Missing number
        b = expsum + a - actsum;

        ans.push_back(b);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {1, 3},
        {2, 2}
    };

    vector<int> result = obj.findMissingAndRepeatedValues(grid);

    cout << "Repeated Number: " << result[0] << endl;
    cout << "Missing Number : " << result[1] << endl;

    return 0;
}