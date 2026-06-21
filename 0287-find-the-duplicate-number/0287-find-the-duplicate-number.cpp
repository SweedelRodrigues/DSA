class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];           // move by 1
            fast = nums[nums[fast]];    // move by 2
        } while (slow != fast);

        // Phase 2: Find entrance of cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];   // move by 1
            fast = nums[fast];   // move by 1
        }

        return slow;
    }
};