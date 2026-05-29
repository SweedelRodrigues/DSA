#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void getperms(vector<int>& nums,
                  int idx,
                  vector<vector<int>>& ans) {

        if (idx == nums.size()) {

            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            swap(nums[idx], nums[i]);

            getperms(nums, idx + 1, ans);

            // Backtrack
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        getperms(nums, 0, ans);

        return ans;
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

    vector<vector<int>> result = obj.permute(nums);

    cout << "All permutations are:\n";

    for (auto perm : result) {

        cout << "{ ";

        for (int val : perm) {
            cout << val << " ";
        }

        cout << "}\n";
    }

    return 0;
}