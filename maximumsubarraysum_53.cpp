#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int currsum = 0;
        int maxsum = INT_MIN;

        for (int val : nums) {

            currsum += val;

            maxsum = max(currsum, maxsum);

            if (currsum < 0) {
                currsum = 0;
            }
        }

        return maxsum;
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

    int result = obj.maxSubArray(nums);

    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}