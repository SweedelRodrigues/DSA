class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long flowersNeeded = 1LL * m * k;

        if (flowersNeeded > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int bouquets = 0;
            int count = 0;

            for (int flower : bloomDay) {

                if (flower <= mid) {
                    count++;
                }
                else {
                    count = 0;
                }

                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};