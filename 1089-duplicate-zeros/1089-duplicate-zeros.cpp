
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Count zeros
        for (int x : arr) {
            if (x == 0) {
                zeros++;
            }
        }

        // Initialize two pointers
        int i = n - 1;
        int j = n + zeros - 1;

        // Traverse backwards
        while (i >= 0) {

            if (j < n) {
                arr[j] = arr[i];
            }

            if (arr[i] == 0) {
                j--;

                if (j < n) {
                    arr[j] = 0;
                }
            }

            i--;
            j--;
        }
    }
};
