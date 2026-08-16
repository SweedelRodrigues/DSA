class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, int> count;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        int degree = 0;

        for (int i = 0; i < nums.size(); i++) {

            count[nums[i]]++;

            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }

            last[nums[i]] = i;

            degree = max(degree, count[nums[i]]);
        }

        int ans = nums.size();

        for (auto it : count) {

            int num = it.first;

            if (count[num] == degree) {

                int length = last[num] - first[num] + 1;

                ans = min(ans, length);
            }
        }

        return ans;
    }
};