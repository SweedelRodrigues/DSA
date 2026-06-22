class Solution {
public:
    
    bool isValid(vector<int>& nums, int k, int maxAllowedSum) {
        int subarrays = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            // if single element exceeds mid → impossible
            if(nums[i] > maxAllowedSum) return false;

            if(sum + nums[i] <= maxAllowedSum) {
                sum += nums[i];
            } else {
                // create new subarray
                subarrays++;
                sum = nums[i];
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int start = *max_element(nums.begin(), nums.end());  // same as max(arr)
        int end = accumulate(nums.begin(), nums.end(), 0);   // sum(arr)

        int ans = end;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;   // go left (minimize)
            } else {
                start = mid + 1; // go right
            }
        }

        return ans;
    }
};