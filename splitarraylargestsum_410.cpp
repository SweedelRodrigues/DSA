#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:

    bool isValid(vector<int>& nums, int k, int maxAllowedSum) {
        int subarrays = 1;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // If a single element is greater than allowed sum
            if (nums[i] > maxAllowedSum)
                return false;

            if (sum + nums[i] <= maxAllowedSum) {
                sum += nums[i];
            } 
            else {
                // Create new subarray
                subarrays++;
                sum = nums[i];
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;   // Try smaller answer
            } 
            else {
                start = mid + 1; // Increase allowed sum
            }
        }

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

    int k;
    cout << "Enter number of subarrays (k): ";
    cin >> k;

    int result = obj.splitArray(nums, k);

    cout << "Minimum largest subarray sum = " << result << endl;

    return 0;
}