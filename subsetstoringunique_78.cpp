#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void getallsubsets(vector<int>& nums,
                       vector<int>& ans,
                       int i,
                       vector<vector<int>>& allsubsets) {

        // Base case
        if (i == nums.size()) {

            allsubsets.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(nums[i]);

        getallsubsets(nums, ans, i + 1, allsubsets);

        // Backtrack
        ans.pop_back();

        // Exclude current element
        getallsubsets(nums, ans, i + 1, allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allsubsets;

        vector<int> ans;

        getallsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = obj.subsets(nums);

    cout << "All subsets are:\n";

    for (auto subset : result) {

        cout << "{ ";

        for (int val : subset) {
            cout << val << " ";
        }

        cout << "}\n";
    }

    return 0;
}