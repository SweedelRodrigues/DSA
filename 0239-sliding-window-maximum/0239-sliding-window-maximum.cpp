class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Stores indices of useful elements
        deque<int> dq;

        // Stores answer
        vector<int> res;

        // Process first window
        for (int i = 0; i < k; i++) {

            // Remove all smaller elements from the back
            // because they can never become maximum
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Push current index
            dq.push_back(i);
        }

        // Process remaining windows
        for (int i = k; i < nums.size(); i++) {

            // Front of deque is maximum of previous window
            res.push_back(nums[dq.front()]);

            // Remove indices which are outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all smaller elements from back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Push current index
            dq.push_back(i);
        }

        // Store maximum of last window
        res.push_back(nums[dq.front()]);

        return res;
    }
};