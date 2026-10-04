class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;

        while (!nums.empty()) {

            // Get distinct values in sorted order
            set<int> s(nums.begin(), nums.end());

            // Remove one occurrence of each value
            for (int x : s) {
                auto it = find(nums.begin(), nums.end(), x);

                if (it != nums.end()) {
                    nums.erase(it);
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};