#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> m;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i];
            int sec = tar - first;

            // Check if complement exists
            if (m.find(sec) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }

            // Store current element with index
            m[first] = i;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = obj.twoSum(arr, target);

    if (result.size() > 0) {
        cout << "Indices are: ";
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}