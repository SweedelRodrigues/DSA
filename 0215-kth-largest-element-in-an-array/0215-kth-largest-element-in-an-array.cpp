class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for(int j = left; j < right; j++) {
            if(nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);

        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int pivotIndex = partition(nums, left, right);

            if(pivotIndex == target)
                return nums[pivotIndex];

            if(pivotIndex < target)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }

        return -1;
    }
};