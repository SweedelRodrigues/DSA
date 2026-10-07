class Solution {
public:
    int solve(vector<int>& nums, int index, int sum, int target) {
        
        // base case
        if(index == nums.size()) {
            if(sum == target)
                return 1;
            return 0;
        }

        // choose +
        int add = solve(nums, index + 1, sum + nums[index], target);

        // choose -
        int subtract = solve(nums, index + 1, sum - nums[index], target);

        return add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};