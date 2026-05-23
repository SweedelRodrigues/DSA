#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {

            slow = nums[slow];            // move 1 step
            fast = nums[nums[fast]];     // move 2 steps

        } while (slow != fast);

        // Phase 2: Find duplicate number
        slow = nums[0];

        while (slow != fast) {

            slow = nums[slow];
            fast = nums[fast];

        }

        return slow;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3,1,3,4,2};

    int ans = obj.findDuplicate(nums);

    cout << "Duplicate Number is: " << ans << endl;

    return 0;
}