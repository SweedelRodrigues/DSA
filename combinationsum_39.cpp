#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    set<vector<int>> s;

    void getAllCombinations(vector<int>& arr,
                            int idx,
                            int tar,
                            vector<vector<int>>& ans,
                            vector<int>& combin) {

        if (idx == arr.size() || tar < 0) {
            return;
        }

        if (tar == 0) {

            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }

            return;
        }

        // Include current element once
        combin.push_back(arr[idx]);

        getAllCombinations(arr,
                           idx + 1,
                           tar - arr[idx],
                           ans,
                           combin);

        // Include current element multiple times
        getAllCombinations(arr,
                           idx,
                           tar - arr[idx],
                           ans,
                           combin);

        // Backtracking
        combin.pop_back();

        // Exclude current element
        getAllCombinations(arr,
                           idx + 1,
                           tar,
                           ans,
                           combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        vector<vector<int>> ans;

        vector<int> combin;

        getAllCombinations(arr,
                           0,
                           target,
                           ans,
                           combin);

        return ans;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = obj.combinationSum(arr, target);

    cout << "\nCombinations are:\n";

    for (auto combination : result) {

        cout << "{ ";

        for (int val : combination) {
            cout << val << " ";
        }

        cout << "}\n";
    }

    return 0;
}