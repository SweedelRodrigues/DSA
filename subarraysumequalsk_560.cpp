#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    int subarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();
        int count = 0;

        vector<int> prefixsum(n, 0);

        // Build prefix sum array
        prefixsum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + arr[i];
        }

        unordered_map<int, int> m;

        for (int j = 0; j < n; j++) {

            // Case when subarray starts from index 0
            if (prefixsum[j] == k)
                count++;

            int val = prefixsum[j] - k;

            // Check if required prefix sum exists
            if (m.find(val) != m.end()) {
                count += m[val];
            }

            // Store frequency of current prefix sum
            if (m.find(prefixsum[j]) == m.end()) {
                m[prefixsum[j]] = 0;
            }

            m[prefixsum[j]]++;
        }

        return count;
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

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    int result = obj.subarraySum(arr, k);

    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}