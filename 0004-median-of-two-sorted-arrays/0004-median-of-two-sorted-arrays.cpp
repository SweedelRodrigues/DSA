class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>& smaller =
            (nums1.size() <= nums2.size()) ? nums1 : nums2;

        vector<int>& larger =
            (nums1.size() <= nums2.size()) ? nums2 : nums1;

        int totalLength = nums1.size() + nums2.size();

        int low = 0;
        int high = smaller.size();

        while(low <= high) {

            int partitionX = (low + high) / 2;
            int partitionY = (totalLength + 1) / 2 - partitionX;

            int l1 = (partitionX == 0)
                     ? INT_MIN
                     : smaller[partitionX - 1];

            int r1 = (partitionX == smaller.size())
                     ? INT_MAX
                     : smaller[partitionX];

            int l2 = (partitionY == 0)
                     ? INT_MIN
                     : larger[partitionY - 1];

            int r2 = (partitionY == larger.size())
                     ? INT_MAX
                     : larger[partitionY];

            if(l1 <= r2 && l2 <= r1) {

                if(totalLength % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                return max(l1, l2);
            }

            if(l1 > r2) {
                high = partitionX - 1;
            }
            else {
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};